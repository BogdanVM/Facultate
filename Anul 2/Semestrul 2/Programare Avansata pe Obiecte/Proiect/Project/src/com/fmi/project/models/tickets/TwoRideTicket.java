package com.fmi.project.models.tickets;

import java.util.Calendar;
import java.util.Date;

public class TwoRideTicket extends Ticket {

    public TwoRideTicket() {
        super(Calendar.getInstance());
        setAvailabilityPriceAndRides();
    }

    public TwoRideTicket(Calendar dateOfAquisition) {
        super(dateOfAquisition);
        setAvailabilityPriceAndRides();
    }

    @Override
    public void setAvailabilityPriceAndRides() {
        numberOfRides = 2;
        availabilityInDays = 100;
        price = 5.0;
    }
}
