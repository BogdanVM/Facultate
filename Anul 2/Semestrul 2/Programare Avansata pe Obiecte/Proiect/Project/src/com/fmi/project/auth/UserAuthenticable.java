package com.fmi.project.auth;

import com.fmi.project.models.User;

public class UserAuthenticable implements Authenticable {
    private User user;
    private String password;

    public UserAuthenticable(User user, String password) {
        this.user = user;
        this.password = password;
    }

    @Override
    public String getUserName() {
        return user.getFirstName() + " " + user.getLastName();
    }

    @Override
    public String getPassword() {
        return password;
    }

    public User getUser() {
        return user;
    }
}
