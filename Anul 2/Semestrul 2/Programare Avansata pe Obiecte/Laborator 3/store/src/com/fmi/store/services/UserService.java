package com.fmi.store.services;

import com.fmi.store.model.User;

public class UserService {
    private static final User[] userList = new User[4];
    private static final UserService ourInstance = new UserService();

    public static UserService getInstance() {
        return ourInstance;
    }

    private UserService() {
        userList[0] = new User(1, "User1", "pwd1");
        userList[1] = new User(2, "User2", "pwd2");
        userList[2] = new User(3, "User3", "pwd3");
        userList[3] = new User(4, "User4", "pwd4");
    }

    public static User getOne(String userName) {
        for(User user : userList) {
            if(user.getUserName().equals(userName)) {
                return user;
            }
        }
        return null;
    }

    public static User getOne(Integer id) {
        for(User user : userList) {
            if(user.getId().equals(id)) {
                return user;
            }
        }
        return null;
    }
}
