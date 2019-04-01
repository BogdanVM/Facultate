package com.fmi.project.factories;

import com.fmi.project.models.TransportationMethod;
import com.fmi.project.models.tickets.*;

public class TicketFactory extends AbstractTransportationFactory{
    @Override
    public TransportationMethod getTransportationMethod(String transportationType) {
        if (transportationType.equalsIgnoreCase("one ride")) {
            return new OneRideTicket();
        } else if (transportationType.equalsIgnoreCase("two rides")) {
            return new TwoRideTicket();
        } else if (transportationType.equalsIgnoreCase("ten rides")) {
            return new TenRideTicket();
        }

        return null;
    }
}
