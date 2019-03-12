package com.fmi.lab2.shapes;

public class Circle {
    private String name;
    private Integer dimension1;
    private Integer dimension2;
    private String secretField;

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public Integer getDimension1() {
        return dimension1;
    }

    public void setDimension1(Integer dimension1) {
        this.dimension1 = dimension1;
    }

    public Integer getDimension2() {
        return dimension2;
    }

    public void setDimension2(Integer dimension2) {
        this.dimension2 = dimension2;
    }

    public String getSecretField() {
        return secretField;
    }

    public void setSecretField(String secretField) {
        this.secretField = secretField;
    }
}
