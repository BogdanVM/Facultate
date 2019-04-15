package com.fmi.project.models.tickets;

import com.fmi.project.models.TransportationMethod;

import java.util.Calendar;

public abstract class Ticket implements TransportationMethod {
    protected int numberOfRides;
    protected int availabilityInDays;
    protected double price;
    protected Calendar dateOfAquisition;

    public Ticket() {
    }

    public Ticket(Calendar dateOfAquisition) {
        this.dateOfAquisition = dateOfAquisition;
    }

    @Override
    public int getAvailabilityInDays() {
        return availabilityInDays;
    }

    public void setDateOfAquisition(Calendar dateOfAquisition) {
        this.dateOfAquisition = dateOfAquisition;
    }

    @Override
    public double getPrice() {
        return price;
    }

    @Override
    public Calendar getAquisitionDay() {
        return dateOfAquisition;
    }

    @Override
    public String toString() {
        return "Ticket " +
                numberOfRides + " rides left " +
                ", " + availabilityInDays +
                " days left, " + price +
                " lei, " + dateOfAquisition.get(Calendar.DAY_OF_MONTH) + "." +
                dateOfAquisition.get(Calendar.MONTH) + "." + dateOfAquisition.get(Calendar.YEAR);
    }

    public abstract void setAvailabilityPriceAndRides();
}
