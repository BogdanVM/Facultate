package com.fmi.store.model;

public class FoodProduct extends Product{

    public FoodProduct() {
    }

    public FoodProduct(Category category, Price price, String name, String descript) {
        super(category, price, name, descript);
    }

    @Override
    public String getName() {
        return "FoodProduct - name: " + super.getName();
    }

    @Override
    public String toString() {
        return "FoodProduct{ }" + super.getName() + " " + super.getSmallDescription();
    }
}
