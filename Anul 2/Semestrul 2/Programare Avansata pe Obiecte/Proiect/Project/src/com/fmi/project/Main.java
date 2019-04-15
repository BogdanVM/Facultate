package com.fmi.project;

import com.fmi.project.factories.SubscriptionFactory;
import com.fmi.project.factories.TicketFactory;
import com.fmi.project.models.TransportationMethod;
import com.fmi.project.services.TransportationService;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    private static List<TransportationMethod> transportationMethods;

    private static void displayLoggedMenu() {
        System.out.println();
        System.out.println("Choose one of the following options: ");
        System.out.println();

        System.out.println("1) See your available tickets;");
        System.out.println("2) See your available subscriptions;");
        System.out.println("3) Buy new subscription;");
        System.out.println("4) Buy new ticket;");
        System.out.println("5) Use ticket ride;");
        System.out.println("6) Change account;");
        System.out.println("7) Update account information;");
        System.out.println("8) Change personal information;");
        System.out.println("9) Update subscriptions and tickets;");
        System.out.println("10) View all subscriptions and tickets;");
        System.out.println("11) Change password;");

        System.out.println();
        System.out.println("0) Exit;");
    }

    public static void main(String[] args) {
        transportationMethods = new ArrayList<>();
        initTickets();
        initSubscriptions();

        TransportationService transportationService = new TransportationService(transportationMethods);

        while (true) {
            BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
            int option;

            try {
                displayLoggedMenu();
                option = Integer.parseInt(bufferedReader.readLine());
            } catch (IOException e) {
                System.err.println("Something went wrong");
                continue;
            }

            if (option == 0) {
                break;
            } else if (option == 1){
                transportationService.listTransportationMethods(TransportationTypes.TICKET);
            } else if (option == 2) {
                transportationService.listTransportationMethods(TransportationTypes.SUBSCRIPTION);
            } else if (option == 3) {

            } else if (option == 4) {

            } else if (option == 5) {

            } else if (option == 6) {

            } else if (option == 7) {

            } else if (option == 8) {

            } else if (option == 9) {
                transportationService.updateTransportationMethods();
            } else if (option == 10) {
                transportationService.listTransportationMethods(TransportationTypes.ANY);
            } else if (option == 11) {

            } else {
                System.err.println("Wrong option selected");
                continue;
            }

            System.out.println();
            System.out.println("Press enter to continue");
            try {
                bufferedReader.readLine();
            } catch (IOException e) {
                System.err.println("Something went wrong");
            }
        }
    }

    private static void initSubscriptions() {
        SubscriptionFactory subscriptionFactory = new SubscriptionFactory();
        transportationMethods.add(subscriptionFactory.getTransportationMethod("one day"));
        transportationMethods.add(subscriptionFactory.getTransportationMethod("one week"));
        transportationMethods.add(subscriptionFactory.getTransportationMethod("one week"));
        transportationMethods.add(subscriptionFactory.getTransportationMethod("one day"));
        transportationMethods.add(subscriptionFactory.getTransportationMethod("one month"));
        transportationMethods.add(subscriptionFactory.getTransportationMethod("one month"));
        transportationMethods.add(subscriptionFactory.getTransportationMethod("one week"));
    }

    private static void initTickets() {
        TicketFactory ticketFactory = new TicketFactory();
        transportationMethods.add(ticketFactory.getTransportationMethod("one ride"));
        transportationMethods.add(ticketFactory.getTransportationMethod("ten rides"));
        transportationMethods.add(ticketFactory.getTransportationMethod("two rides"));
        transportationMethods.add(ticketFactory.getTransportationMethod("two rides"));
        transportationMethods.add(ticketFactory.getTransportationMethod("ten rides"));
    }
}
