package com.fmi.project.models.subscriptions;

import java.util.Calendar;

public class OneDaySubscription extends Subscription{

    public OneDaySubscription() {
        super(Calendar.getInstance());
        setAvailabilityAndPrice();
    }

    public OneDaySubscription(Calendar dateOfAquisition) {
        super(dateOfAquisition);
        setAvailabilityAndPrice();
    }

    @Override
    public void setAvailabilityAndPrice() {
        availabilityInDays = 1;
        price = 8.0;
    }
}
