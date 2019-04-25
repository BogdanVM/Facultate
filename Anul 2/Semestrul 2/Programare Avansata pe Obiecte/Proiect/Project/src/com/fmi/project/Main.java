package com.fmi.project;

import com.fmi.project.factories.SubscriptionFactory;
import com.fmi.project.factories.TicketFactory;
import com.fmi.project.models.TransportationMethod;
import com.fmi.project.models.subscriptions.Subscription;
import com.fmi.project.models.tickets.Ticket;
import com.fmi.project.services.ReadService;
import com.fmi.project.services.TransportationService;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    private static List<TransportationMethod> transportationMethods;

    private static void displayLoggedMenu() {
        System.out.println();
        System.out.println("Choose one of the following options: ");
        System.out.println();

        System.out.println("1) See your available tickets;");
        System.out.println("2) See your available subscriptions;");
        System.out.println("3) Buy new subscription;");
        System.out.println("4) Buy new ticket;");
        System.out.println("5) Use ticket ride;");
        System.out.println("6) Change account;");
        System.out.println("7) Update account information;");
        System.out.println("8) Change personal information;");
        System.out.println("9) Update subscriptions and tickets;");
        System.out.println("10) View all subscriptions and tickets;");
        System.out.println("11) Change password;");

        System.out.println();
        System.out.println("0) Exit;");
    }

    /**
     * <p>Method that reads all the values in the transport.csv file.</p>
     * <p>At each step, it checks the object read (Ticket / Subscription).</p>
     * <p>Then, the object is added to the transportationMethods list</p>
     */
    private static void initValues() {
        ReadService readService;
        readService = new ReadService("src/transport.csv");

        try {
            SubscriptionFactory subscriptionFactory = new SubscriptionFactory();
            TicketFactory ticketFactory = new TicketFactory();

            List<String> values = readService.readLine();

            while (values != null) {
                if (values.get(0).equalsIgnoreCase("ticket")) {
                    Ticket ticket = (Ticket) ticketFactory.getTransportationMethod(values.get(1).trim());

                    ticket.setNumberOfRides(Integer.parseInt(values.get(3).trim()));
                    ticket.setAvailabilityInDays(Integer.parseInt(values.get(2).trim()));

                    transportationMethods.add(ticket);
                } else if (values.get(0).equalsIgnoreCase("subscription")) {
                    Subscription subscription = (Subscription) subscriptionFactory.getTransportationMethod(values
                            .get(1).trim());

                    subscription.setAvailabilityInDays(Integer.parseInt(values.get(2).trim()));

                    transportationMethods.add(subscriptionFactory.getTransportationMethod(values.get(1).trim()));
                }

                values = readService.readLine();
            }
        } catch (IOException e) {
            System.err.println("Something went wrong while reading the values");
        }
    }

    public static void main(String[] args) {
        transportationMethods = new ArrayList<>();

        initValues();
        TransportationService transportationService = new TransportationService(transportationMethods);

        while (true) {
            BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
            int option;

            try {
                displayLoggedMenu();
                option = Integer.parseInt(bufferedReader.readLine());
            } catch (IOException e) {
                System.err.println("Something went wrong");
                continue;
            }

            if (option == 0) {
                break;
            } else if (option == 1){
                transportationService.listTransportationMethods(TransportationTypes.TICKET);
            } else if (option == 2) {
                transportationService.listTransportationMethods(TransportationTypes.SUBSCRIPTION);
            } else if (option == 3) {
                /* TODO implement with database */
            } else if (option == 4) {
                /* TODO implement with database */
            } else if (option == 5) {
                transportationService.listTransportationMethods(TransportationTypes.TICKET);

                int chosenTicket;
                System.out.println("Choose your ticket (number): ");

                try {
                    chosenTicket = Integer.parseInt(bufferedReader.readLine());
                    transportationService.useTicketRide(chosenTicket);
                } catch (IOException e) {
                    System.err.println("An error occurred");
                }
            } else if (option == 6) {
                /* TODO implement with database */
            } else if (option == 7) {
                /* TODO implement with database */
            } else if (option == 8) {
                /* TODO implement with database */
            } else if (option == 9) {
                transportationService.updateTransportationMethods();
            } else if (option == 10) {
                transportationService.listTransportationMethods(TransportationTypes.ANY);
            } else if (option == 11) {
                /* TODO implement with database */
            } else {
                System.err.println("Wrong option selected");
                continue;
            }

            System.out.println();
            System.out.println("Press enter to continue");
            try {
                bufferedReader.readLine();
            } catch (IOException e) {
                System.err.println("Something went wrong");
            }
        }
    }
}
