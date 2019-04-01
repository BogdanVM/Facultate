package com.fmi.project.services;

import com.fmi.project.TransportationTypes;
import com.fmi.project.auth.Authenticable;
import com.fmi.project.auth.UserAuthenticable;
import com.fmi.project.factories.AbstractTransportationFactory;
import com.fmi.project.factories.FactoryProducer;
import com.fmi.project.models.TransportationMethod;
import com.fmi.project.models.tickets.Ticket;

import java.util.List;

public class UserService {
    private UserAuthenticable authenticable;

    public UserService(UserAuthenticable authenticable) {
        this.authenticable = authenticable;
    }

    public boolean authenticateUser(Authenticable authenticable) {
        if (this.authenticable.getUserName().equals(authenticable.getUserName())) {
            if (this.authenticable.getPassword().equals(authenticable.getPassword())) {
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    }

    public void listAllTransportationMethods(TransportationTypes t) {
        List<TransportationMethod> userList = authenticable.getUser().getTransportationMethods();

        for (TransportationMethod tm : userList) {
            if (t.equals(TransportationTypes.TICKET)) {
                if (tm instanceof Ticket) {
                    
                }
            } else if (t.equals(TransportationTypes.SUBSCRIPTION)) {

            } else {

            }
        }
    }

}
