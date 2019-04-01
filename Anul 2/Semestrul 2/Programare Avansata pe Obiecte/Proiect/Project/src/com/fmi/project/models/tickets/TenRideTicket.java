package com.fmi.project.models.tickets;

import java.util.Date;

public class TenRideTicket implements Ticket {

    private int numberOfRides;
    private int availabilityInDays;
    private double price;
    private Date dateOfAquisition;

    public TenRideTicket() {
        numberOfRides = 10;
        availabilityInDays = 100;
        price = 20.0;

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

    @Override
    public String toString() {
        return "Ticket " +
                numberOfRides + " rides left " +
                ", " + availabilityInDays +
                " days left, " + price +
                " lei, " + dateOfAquisition;
    }
}
