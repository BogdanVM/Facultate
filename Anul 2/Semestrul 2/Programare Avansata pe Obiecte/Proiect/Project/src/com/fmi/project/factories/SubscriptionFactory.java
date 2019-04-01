package com.fmi.project.factories;

import com.fmi.project.models.TransportationMethod;
import com.fmi.project.models.subscriptions.*;

public class SubscriptionFactory extends AbstractTransportationFactory {

    @Override
    public TransportationMethod getTransportationMethod(String transportationType) {
        if (transportationType.equalsIgnoreCase("one day")) {
            return new OneDaySubscription();
        } else if (transportationType.equalsIgnoreCase("one week")) {
            return new OneWeekSubscription();
        } else if (transportationType.equalsIgnoreCase("one month")) {
            return new OneMonthSubscription();
        }
        return null;
    }
}
