package com.fmi.project.services;

import com.fmi.project.enums.TransportationTypes;
import com.fmi.project.models.Account;
import com.fmi.project.models.User;

public class BillingService {
    private User user;

    public BillingService(User user) {
        this.user = user;
    }

    public void buyNewTransportationMethod(TransportationTypes t) {
        Account account = user.getAccount();

        if (t.equals(TransportationTypes.SUBSCRIPTION)) {

        }
    }
}
