package com.fmi.project.services;

import com.fmi.project.TransportationTypes;
import com.fmi.project.models.*;
import com.fmi.project.models.subscriptions.Subscription;
import com.fmi.project.models.tickets.Ticket;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class TransportationService {
    private List<TransportationMethod> transportationMethods;

    public TransportationService(List<TransportationMethod> transportationMethods) {
        this.transportationMethods = new ArrayList<>();
        this.transportationMethods.addAll(transportationMethods);
    }

    public void listTransportationMethods(TransportationTypes t) {
        for (TransportationMethod tm : transportationMethods) {
            if (t.equals(TransportationTypes.SUBSCRIPTION)) {
                if (tm instanceof Subscription) {
                    System.out.println(tm.toString());
                }
            } else if (t.equals(TransportationTypes.TICKET)) {
                if (tm instanceof Ticket) {
                    System.out.println(tm.toString());
                }
            } else if (t.equals(TransportationTypes.ANY)) {
                System.out.println(tm.toString());
            }
        }
    }

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

        for (int i : indicesToBeRemoved) {
            transportationMethods.remove(i);
        }

        System.out.println("Updated finished successfully");
    }
}
