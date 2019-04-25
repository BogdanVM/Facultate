package com.fmi.project.models.subscriptions;

import java.util.Calendar;
import java.util.Date;

public class OneMonthSubscription extends Subscription {

    public OneMonthSubscription() {
        super(Calendar.getInstance());
        setAvailabilityAndPrice();
    }

    public OneMonthSubscription(Calendar dateOfAquisition) {
        super(dateOfAquisition);
        setAvailabilityAndPrice();
    }

    public OneMonthSubscription(int availabilityInDays, Calendar dateOfAquisition) {
        super(availabilityInDays, dateOfAquisition);
        price = 70.0;
    }

    @Override
    public void setAvailabilityAndPrice() {
        availabilityInDays = 30;
        price = 70.0;
    }
}
