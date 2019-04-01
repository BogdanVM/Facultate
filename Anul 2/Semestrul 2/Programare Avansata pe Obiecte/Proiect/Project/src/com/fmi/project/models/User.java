package com.fmi.project.models;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;

public class User {
    private String firstName;
    private String lastName;
    private Date dateOfBirth;
    private Account account;
    private List<TransportationMethod> transportationMethods;

    public User(String firstName, String lastName) {
        this.firstName = firstName;
        this.lastName = lastName;

        dateOfBirth = new Date();
        account = new Account();
        transportationMethods = new ArrayList<>();
    }

    public User(String firstName, String lastName, String dateOfBirth) {
        this.firstName = firstName;
        this.lastName = lastName;

        try {
            this.dateOfBirth = new SimpleDateFormat("dd/MM/yyyy").parse(dateOfBirth);
        } catch (ParseException e) {
            System.err.println("Date was passed in the incorrect format. Required format: dd/MM/yyyy");
        }

        this.transportationMethods = new ArrayList<>();
    }

    public User() {
        transportationMethods = new ArrayList<>();
        dateOfBirth = new Date();
    }

    public String getFirstName() {
        return firstName;
    }

    public void setFirstName(String firstName) {
        this.firstName = firstName;
    }

    public Account getAccount() {
        return account;
    }

    public List<TransportationMethod> getTransportationMethods() {
        return transportationMethods;
    }

    public String getLastName() {
        return lastName;
    }

    public void setLastName(String lastName) {
        this.lastName = lastName;
    }

    public Date getDateOfBirth() {
        return dateOfBirth;
    }

    public void setDateOfBirth(Date dateOfBirth) {
        this.dateOfBirth = dateOfBirth;
    }

    public void addNewTrasnportationMethod(TransportationMethod tm) {
        transportationMethods.add(tm);
    }
}
