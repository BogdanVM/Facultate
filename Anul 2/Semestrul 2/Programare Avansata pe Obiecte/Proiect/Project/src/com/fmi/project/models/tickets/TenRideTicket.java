package com.fmi.project.models.tickets;

import java.util.Calendar;

public class TenRideTicket extends Ticket {

    public TenRideTicket() {
        super(Calendar.getInstance());
        setAvailabilityPriceAndRides();
    }

    public TenRideTicket(Calendar dateOfAquisition){
        super(dateOfAquisition);
        setAvailabilityPriceAndRides();
    }

    public TenRideTicket(int numberOfRides, int availabilityInDays, Calendar dateOfAquisition) {
        super(numberOfRides, availabilityInDays, dateOfAquisition);
        price = 20.0;
    }

    @Override
    public void setAvailabilityPriceAndRides() {
        numberOfRides = 10;
        availabilityInDays = 100;
        price = 20.0;
    }
}
