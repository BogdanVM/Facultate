package com.fmi.project.models.tickets;

import com.fmi.project.models.TransportationMethod;

public interface Ticket extends TransportationMethod {
    int getNumberOfRides();
}
