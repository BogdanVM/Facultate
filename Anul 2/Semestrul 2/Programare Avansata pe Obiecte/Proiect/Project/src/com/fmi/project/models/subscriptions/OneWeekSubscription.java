package com.fmi.project.models.subscriptions;

import java.util.Calendar;
import java.util.Date;

public class OneWeekSubscription extends Subscription {

    public OneWeekSubscription() {
        super(Calendar.getInstance());
        setAvailabilityAndPrice();
    }

    public OneWeekSubscription(Calendar dateOfAquisition) {
        super(dateOfAquisition);
        setAvailabilityAndPrice();
    }

    public OneWeekSubscription(int availabilityInDays, Calendar dateOfAquisition) {
        super(availabilityInDays, dateOfAquisition);
        price = 25.0;
    }

    @Override
    public void setAvailabilityAndPrice() {
        availabilityInDays = 7;
        price = 25.0;
    }
}
