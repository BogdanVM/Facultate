package com.fmi.project.factories;

import com.fmi.project.models.TransportationMethod;

public abstract class AbstractTransportationFactory {
    abstract TransportationMethod getTransportationMethod(String transportationType);
}
