package com.fmi.project.models.subscriptions;

import java.util.Date;

public class OneMonthSubscription implements Subscription {
    private int availabilityInDays;
    private double price;
    private Date dateOfAquisition;

    public OneMonthSubscription() {
        availabilityInDays = 30;
        price = 8.0;
        dateOfAquisition = new Date();
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
