package com.fmi.store.model;

import java.util.Date;

public class Price implements Cloneable{
    private Double price;
    private Date startFrom;
    private Date endFrom;

    public Double getPrice() {
        return price;
    }

    public void setPrice(Double price) {
        this.price = price;
    }

    public Date getStartFrom() {
        return startFrom;
    }

    public void setStartFrom(Date startFrom) {
        this.startFrom = startFrom;
    }

    public Date getEndFrom() {
        return endFrom;
    }

    public void setEndFrom(Date endFrom) {
        this.endFrom = endFrom;
    }

    @Override
    public Object clone() throws CloneNotSupportedException {
        return super.clone();
    }
}
