package com.fmi.project.models.subscriptions;

import com.fmi.project.models.TransportationMethod;

import java.util.Calendar;

public abstract class Subscription implements TransportationMethod {
    protected int availabilityInDays;
    protected double price;
    protected Calendar dateOfAquisition;

    public Subscription() {

    }

    public Subscription(Calendar dateOfAquisition) {
        this.dateOfAquisition = dateOfAquisition;
    }

    public Subscription(int availabilityInDays, Calendar dateOfAquisition) {
        this.availabilityInDays = availabilityInDays;
        this.dateOfAquisition = dateOfAquisition;
    }

    public abstract void setAvailabilityAndPrice();

    @Override
    public int getAvailabilityInDays() {
        return availabilityInDays;
    }

    @Override
    public double getPrice() {
        return price;
    }

    @Override
    public Calendar getAquisitionDay() {
        return dateOfAquisition;
    }

    public void setDateOfAquisition(Calendar dateOfAquisition) {
        this.dateOfAquisition = dateOfAquisition;
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

    @Override
    public String toString() {
        return "Subscription " +
                availabilityInDays +
                " days left, " + price +
                " lei, " + dateOfAquisition.get(Calendar.DAY_OF_MONTH) + "." +
                dateOfAquisition.get(Calendar.MONTH) + "." + dateOfAquisition.get(Calendar.YEAR);
    }
}
