package com.fmi.project.models;

import java.util.Calendar;

public interface TransportationMethod {
    int getAvailabilityInDays();
    double getPrice();
    Calendar getAquisitionDay();
}
