package com.fmi.project.models;

import java.util.Date;

public interface TransportationMethod {
    int getAvailabilityInDays();
    double getPrice();
    Date getAquisitionDay();
}
