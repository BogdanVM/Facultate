package com.fmi.store.model;

public class Category implements Cloneable{
    private String name;
    private String description;
    private Category parent;

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getDescription() {
        return description;
    }

    public void setDescription(String description) {
        this.description = description;
    }

    public Category getParent() {
        return parent;
    }

    public void setParent(Category parent) {
        this.parent = parent;
    }

    @Override
    public Object clone() throws CloneNotSupportedException {
        return super.clone();
    }
}
