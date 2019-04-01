package com.fmi.project.models.tickets;

import java.util.Date;

public class OneRideTicket implements Ticket {

    private int numberOfRides;
    private int availabilityInDays;
    private double price;
    private Date dateOfAquisition;

    public OneRideTicket() {
        numberOfRides = 1;
        availabilityInDays = 100;
        price = 2.5;

        dateOfAquisition = new Date();
    }

    @Override
    public int getNumberOfRides() {
        return numberOfRides;
    }

    @Override
    public int getAvailabilityInDays() {
        return availabilityInDays;
    }

    @Override
    public double getPrice() {
        return price;
    }

    @Override
    public Date getAquisitionDay() {
        return dateOfAquisition;
    }
}
