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

    public TwoRideTicket(int numberOfRides, int availabilityInDays, Calendar dateOfAquisition) {
        super(numberOfRides, availabilityInDays, dateOfAquisition);
        price = 5.0;
    }

    @Override
    public void setAvailabilityPriceAndRides() {
        numberOfRides = 2;
        availabilityInDays = 100;
        price = 5.0;
    }
}
