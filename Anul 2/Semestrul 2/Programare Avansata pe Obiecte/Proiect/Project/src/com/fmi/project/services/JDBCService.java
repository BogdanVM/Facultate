package com.fmi.project.services;

import com.fmi.project.enums.TransportationTypes;
import com.fmi.project.factories.SubscriptionFactory;
import com.fmi.project.factories.TicketFactory;
import com.fmi.project.models.TransportationMethod;
import com.fmi.project.models.subscriptions.Subscription;
import com.fmi.project.models.tickets.Ticket;

import java.sql.*;
import java.util.ArrayList;
import java.util.List;

public class JDBCService {

    private static JDBCService instance = new JDBCService();
    private final String DRIVER_NAME = "";
    private Connection connection;

    private JDBCService() {
        try {
            connection = DriverManager.getConnection(DRIVER_NAME);
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    public static JDBCService getInstance() { return instance; }



    public String[] getTransportationMethods(TransportationTypes t) {
        List<String> tms = new ArrayList<>();
        if (t.equals(TransportationTypes.ANY)) {
            TicketFactory ticketFactory = new TicketFactory();
            SubscriptionFactory subscriptionFactory = new SubscriptionFactory();

            try {
                PreparedStatement pst = connection.prepareStatement("SELECT * FROM TRANSPORT");
                ResultSet rs = pst.executeQuery();

                while (rs.next()) {
                    TransportationMethod tm;
                    if (rs.getString("Type").equals("Ticket")) {
                        Ticket ticket = (Ticket) ticketFactory.getTransportationMethod(rs.getString("Subtype"));
                        tms.add(ticket.toString());
                    } else {
                        Subscription subscription = (Subscription) subscriptionFactory.getTransportationMethod(
                                rs.getString("Subtype")
                        );

                        tms.add(subscription.toString());
                    }
                }
                return tms.toArray(new String[0]);

            } catch (SQLException e) {
                e.printStackTrace();
                return new String[] {""};
            }
        }

        String type;
        if (t.equals(TransportationTypes.SUBSCRIPTION)) {
            type = "Subscription";
        } else {
            type = "Ticket";
        }

        try {
            PreparedStatement pst = connection.prepareStatement("SELECT * FROM TRANSPORT WHERE" +
                    " Type = ?");
            pst.setString(1, type);

            ResultSet rs = pst.executeQuery();

            SubscriptionFactory subscriptionFactory = new SubscriptionFactory();
            TicketFactory ticketFactory = new TicketFactory();

            while (rs.next()) {
                if (type.equals("Subscription")) {
                    Subscription subscription = (Subscription) subscriptionFactory.getTransportationMethod(
                            rs.getString("Subtype")
                    );

                    tms.add(subscription.toString());
                } else {
                    Ticket ticket = (Ticket) ticketFactory.getTransportationMethod(rs.getString("Subtype"));
                    tms.add(ticket.toString());
                }
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }

        return tms.toArray(new String[0]);
    }

    public void insertTransportationMethod(TransportationMethod tm) {
        String type = "";
        String subtype = "";
        if (tm instanceof Ticket) {
            Ticket ticket = (Ticket) tm;
            if (ticket.getNumberOfRides() == 1) {
                subtype = "one ride";
            } else if (ticket.getNumberOfRides() == 2) {
                subtype = "two rides";
            } else {
                subtype = "ten rides";
            }

            type = "Ticket";

        } else {
            Subscription subscription = (Subscription) tm;
            if (subscription.getAvailabilityInDays() == 1) {
                subtype = "one day";
            } else if (subscription.getAvailabilityInDays() == 7) {
                subtype = "one week";
            } else {
                subtype = "one month";
            }

            type = "Subscription";
        }

        try {
            PreparedStatement pst = connection.prepareStatement("INSERT INTO TRANSPORT(Type, Subtype) VALUES(?, ?)");
            pst.setString(1, type);
            pst.setString(2, subtype);

            pst.executeQuery();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    public void deleteTransportationMethod(TransportationMethod tm) {

    }
}
