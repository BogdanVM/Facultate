package com.fmi.store;

import com.fmi.store.model.*;

public class Main {

    public static void main(String[] args) throws CloneNotSupportedException {

        Product product = new Product();
        product.setName("Produs 1");

        FoodProduct foodProduct = new FoodProduct();
        foodProduct.setName("Produs 2");

        System.out.println(product.getName());
        System.out.println(foodProduct.getName());

        Product foodProduct_2 = new FoodProduct();
        foodProduct_2.setName("Produs 3");

        System.out.println(foodProduct_2.getName());

        User user1 = new User(24, "user1", "pwd1");
        User user2 = new User(24, "user2", "pwd2");

        System.out.println(user1.equals(user2));

        Product productDuplicate = (Product) foodProduct.clone();
        System.out.println(productDuplicate);
    }
}
