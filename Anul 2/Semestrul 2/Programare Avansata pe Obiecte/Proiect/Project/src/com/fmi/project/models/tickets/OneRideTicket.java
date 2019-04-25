package com.fmi.project.models.tickets;

import java.util.Calendar;

public class OneRideTicket extends Ticket {

    public OneRideTicket() {
        super(Calendar.getInstance());
        setAvailabilityPriceAndRides();
    }

    public OneRideTicket(Calendar dateOfAquisition) {
        super(dateOfAquisition);
        setAvailabilityPriceAndRides();
    }

    public OneRideTicket(int numberOfRides, int availabilityInDays, Calendar dateOfAquisition) {
        super(numberOfRides, availabilityInDays, dateOfAquisition);
        price = 2.5;
    }

    @Override
    public void setAvailabilityPriceAndRides() {
        numberOfRides = 1;
        availabilityInDays = 100;
        price = 2.5;
    }
}
