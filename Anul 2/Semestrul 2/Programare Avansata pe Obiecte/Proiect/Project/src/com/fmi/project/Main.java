package com.fmi.project;

import com.fmi.project.auth.AdminAuthenticable;
import com.fmi.project.auth.UserAuthenticable;
import com.fmi.project.models.User;
import com.fmi.project.services.UserService;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;

public class Main {
    static List<UserAuthenticable> users;
    static AdminAuthenticable admin;

    private static void addUsers() {
        users.add(new UserAuthenticable(new User("John", "Doe", "20/01/1998"),
                "1234"));
        users.add(new UserAuthenticable(new User("James", "Jones", "02/03/1980"),
                "abcd"));
        users.add(new UserAuthenticable(new User("Roger", "Barnes", "25/06/1992"),
                "2345"));

        admin = new AdminAuthenticable("admin", "1234");
    }

    private static void displayLoggedMenu() {
        System.out.println();
        System.out.println("Choose one of the following options: ");
        System.out.println();

        System.out.println("1) See your available tickets;");
        System.out.println("2) See your available subscriptions;");
        System.out.println("3) Buy new subscription;");
        System.out.println("4) Buy new ticket;");
        System.out.println("5) Use ticket ride;");
        System.out.println("6) Change account;");
        System.out.println("7) Update account information;");
        System.out.println("8) Change personal information;");
        System.out.println("9) Update subscriptions and tickets;");
        System.out.println("10) View all subscriptions and tickets;");
        System.out.println("11) Change password;");

        System.out.println();
        System.out.println("0) Exit;");
    }

    public static void displayNonLoggedMenu() {
        System.out.println();
        System.out.println("1) Log In");
        System.out.println("2) Sign Up");

        System.out.println();
        System.out.println("0) Exit");
        System.out.println();
        System.out.println("Choose your option: ");
    }

    public static void main(String[] args) {
        users = new ArrayList<>();
        addUsers();

        while (true) {
            displayNonLoggedMenu();

            BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
            int option;

            try {
                option = Integer.parseInt(bufferedReader.readLine());
            } catch (IOException e) {
                System.err.println("Wrong option selected");
                continue;
            }

            if (option == 1) {
                try {
                    System.out.println("Username: ");
                    String username = bufferedReader.readLine();
                    String[] name = username.split(" ");

                    System.out.println("Password: ");
                    String password = bufferedReader.readLine();

                    UserService userService = new UserService(new UserAuthenticable(
                            new User(name[0], name[1]), password));

                    User user = null;
                    for (UserAuthenticable userAuth : users) {
                        if (userService.authenticateUser(userAuth)) {
                            user = userAuth.getUser();
                            break;
                        }
                    }

                    if (user != null) {
                        System.out.println();
                        System.out.printf("------------------ LOGGED IN SUCCESSFULLY AS %s ------------------",
                                user.getFirstName() + " " + user.getLastName());
                        System.out.println();

                        while (true) {

                        }
                    } else {
                        System.err.println("Wrong login credentials");
                    }
                } catch (IOException e) {
                    System.err.println("Something went wrong. Please try again!");
                }
            } else if (option == 2){

            } else if (option == 0) {
                break;
            } else {
                System.err.println("Wrong option selected");
                continue;
            }
        }
    }
}
