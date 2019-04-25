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

    public Ticket(int numberOfRides, int availabilityInDays, Calendar dateOfAquisition) {
        this.numberOfRides = numberOfRides;
        this.availabilityInDays = availabilityInDays;
        this.dateOfAquisition = dateOfAquisition;
    }

    @Override
    public int getAvailabilityInDays() {
        return availabilityInDays;
    }

    public void setDateOfAquisition(Calendar dateOfAquisition) {
        this.dateOfAquisition = dateOfAquisition;
    }

    public int getNumberOfRides() {
        return numberOfRides;
    }

    public void setNumberOfRides(int numberOfRides) {
        this.numberOfRides = numberOfRides;
    }

    public void setAvailabilityInDays(int availabilityInDays) {
        this.availabilityInDays = availabilityInDays;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    public Calendar getDateOfAquisition() {
        return dateOfAquisition;
    }

    public abstract void setAvailabilityPriceAndRides();

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

    @Override
    public boolean equals(Object o) {
        if (o instanceof Ticket) {
            Ticket t = (Ticket) o;

            if (t.numberOfRides == this.numberOfRides) {
                if (t.availabilityInDays == this.availabilityInDays) {
                    return t.price == this.price;
                }
            }
        }

        return false;
    }
}
