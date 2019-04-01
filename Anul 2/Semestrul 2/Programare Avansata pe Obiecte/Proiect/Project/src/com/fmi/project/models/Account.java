package com.fmi.project.models;

public class Account {
    private Integer money;
    private String number;

    public Account() {
    }

    public Account(Integer money, String number) {
        this.money = money;
        this.number = number;
    }

    public Integer getMoney() {
        return money;
    }

    public void setMoney(Integer money) {
        this.money = money;
    }

    public String getNumber() {
        return number;
    }

    public void setNumber(String number) {
        this.number = number;
    }
}
