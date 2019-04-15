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

    @Override
    public void setAvailabilityPriceAndRides() {
        numberOfRides = 1;
        availabilityInDays = 100;
        price = 2.5;
    }
}
