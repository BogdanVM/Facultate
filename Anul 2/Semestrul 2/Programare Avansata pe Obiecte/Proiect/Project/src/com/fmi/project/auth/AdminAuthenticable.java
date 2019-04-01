package com.fmi.project.auth;

public class AdminAuthenticable implements Authenticable{
    private String userName;
    private String password;

    public AdminAuthenticable(String userName, String password) {
        this.userName = userName;
        this.password = password;
    }

    @Override
    public String getUserName() {
        return userName;
    }

    @Override
    public String getPassword() {
        return password;
    }
}
