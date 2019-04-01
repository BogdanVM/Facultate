package com.fmi.project.factories;

public abstract class FactoryProducer {
    public static AbstractTransportationFactory getFactory (boolean ticket) {
        if (ticket) {
            return new TicketFactory();
        } else {
            return new SubscriptionFactory();
        }
    }
}
