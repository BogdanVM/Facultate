package com.fmi.project.services;

import com.fmi.project.enums.TransportationTypes;
import com.fmi.project.models.*;
import com.fmi.project.models.subscriptions.Subscription;
import com.fmi.project.models.tickets.Ticket;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class TransportationService {
    private List<TransportationMethod> transportationMethods;

    public TransportationService(List<TransportationMethod> transportationMethods) {
        this.transportationMethods = new ArrayList<>();
        this.transportationMethods.addAll(transportationMethods);
    }

    /**
     *
     * Method that displays all the methods of transportation, filtering them by the parameter t.
     *
     * @param t TransportationType = SUBSCRIPTION / TICKET / ANY. By this parameter, we see what the user wants
     *          to be displayed.
     */
    public void listTransportationMethods(TransportationTypes t) {
        int i = 1;
        for (TransportationMethod tm : transportationMethods) {
            if (t.equals(TransportationTypes.SUBSCRIPTION)) {
                if (tm instanceof Subscription) {
                    System.out.println(i + ". " + tm.toString());
                    i++;
                }
            } else if (t.equals(TransportationTypes.TICKET)) {
                if (tm instanceof Ticket) {
                    System.out.println(i + ". " + tm.toString());
                    i++;
                }
            } else if (t.equals(TransportationTypes.ANY)) {
                System.out.println(i + ". " + tm.toString());
                i++;
            }
        }
    }

    /**
     * Method that checks all the transportation methods for their availability in days.
     * If availabiltyInDays == 0 => that ticket / subscription will be eliminated from the list and the .csv file
     */
    public void updateTransportationMethods() {
        System.out.println();

        List<Integer> indicesToBeRemoved = new ArrayList<>();
        for (int i = 0; i < transportationMethods.size(); ++i) {
            if (transportationMethods.get(i).getAvailabilityInDays() == 0) {
                indicesToBeRemoved.add(i);
            }
        }

        if (indicesToBeRemoved.size() == 0) {
            System.out.println("No tickets and subscriptions were updated");
            return;
        }

        WriteService writeService = WriteService.getInstance("src/transport.csv");
        for (int i : indicesToBeRemoved) {
            transportationMethods.remove(i);

            try {
                writeService.deleteLine(i);
            } catch (IOException e) {
                System.err.println("An error occurred while writing to file");
            }
        }

        System.out.println("Update finished successfully");
    }

    /**
     * <p>Method that reduces the number of rides by 1, for the i-th ticket in the list.</p>
     * <p>It iterates through the entire list searching amongst the tickets, until it finds the i-th ticket.</p>
     * <p>Then we store the position inside the list of that ticket and reduce its numberOfRides by 1.</p>
     *
     * <p>Finally, if the numberOfRides == 0 => delete that ticket (both from the file and the list);</p>
     * <p>else => update the number of rides (both in the file and in the list).</p>
     *
     * @param i index of the ticket (>= 1). NOT THE POSITION INSIDE THE LIST.
     */
    public void useTicketRide(int i) {
        /* We see which ticket the user chose to use */
        int currTicket = 1, ticketIndex = 0;
        Ticket ticket = null;
        for (int i1 = 0; i1 < transportationMethods.size(); i1++) {
            TransportationMethod tm = transportationMethods.get(i1);

            if (tm instanceof Ticket) {
                if (currTicket++ == i) {
                    ticket = (Ticket) tm;
                    ticketIndex = i1; // save the list index of the ticket
                    break;
                }
            }
        }

        if (ticket == null) {
            System.err.println("Not a valid index.");
            return;
        }

        ticket.setNumberOfRides(ticket.getNumberOfRides() - 1);

        WriteService writeService = WriteService.getInstance("src/transport.csv");
        if (ticket.getNumberOfRides() == 0) {
            transportationMethods.remove(ticketIndex);

            try {
                writeService.deleteLine(ticketIndex);
            } catch (IOException e) {
                System.err.println("An error occurred while writing to file");
            }
        } else {
            transportationMethods.set(ticketIndex, ticket);

            try {
                /* Update the number of tickets inside the file, we know it's located on the 4th column */
                writeService.updateLine(ticketIndex, 3, Integer.toString(ticket.getNumberOfRides()));
            } catch (IOException e) {
                System.err.println("An error occurred while writing to file");
            }
        }
    }
}
