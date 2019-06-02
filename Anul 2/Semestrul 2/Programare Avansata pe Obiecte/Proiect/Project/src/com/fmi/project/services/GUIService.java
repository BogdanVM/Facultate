package com.fmi.project.services;

import com.fmi.project.LoginService;
import com.fmi.project.MainMenuService;
import com.fmi.project.enums.TransportationTypes;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Scanner;

public abstract class GUIService {

    private static JFrame frame;

    public static void buildLoginWindow() {
        frame = new JFrame("Main Window");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JPanel loginPanel = new JPanel(new GridLayout(4, 1));

        JPanel titlePanel = new JPanel();
        JPanel userNamePanel = new JPanel();
        JPanel pwdPanel = new JPanel();
        JPanel btnsPanel = new JPanel();

        /* TITLE */
        JLabel titleLabel = new JLabel("Login", SwingConstants.CENTER);
        titlePanel.add(titleLabel);

        /* USERNAME */
        JLabel userNameLabel = new JLabel("Username");
        JTextField userNameField = new JTextField("", 15);
        userNamePanel.add(userNameLabel);
        userNamePanel.add(userNameField);

        /* PASSWORD */
        JLabel pwdLabel = new JLabel("Password");
        JPasswordField pwdField = new JPasswordField("", 15);
        pwdPanel.add(pwdLabel);
        pwdPanel.add(pwdField);

        /* BUTTON AND MESSAGE */
        JButton loginBtn = new JButton("Login");
        JLabel message = new JLabel();
        btnsPanel.add(message);
        btnsPanel.add(loginBtn);

        loginPanel.add(titlePanel);
        loginPanel.add(userNamePanel);
        loginPanel.add(pwdPanel);
        loginPanel.add(btnsPanel);

        loginBtn.addActionListener(new LoginService(frame, message, userNameField, pwdField));

        frame.add(loginPanel, BorderLayout.CENTER);
        frame.setLocationRelativeTo(null);
        frame.setSize(400, 200);

        frame.setVisible(true);
    }

    public static void buildMainMenuWindow() {
        frame.setTitle("Main Menu");
        frame.setLocationRelativeTo(null);
        frame.setSize(600, 400);

        JPanel panel = new JPanel(new GridLayout(7, 1, 10, 10));

        JButton seeSubsBtn = new JButton("Available Subscriptions");
        JButton seeTickBtn = new JButton("Available Tickets");
        JButton seeBtn = new JButton("Subscriptions and Tickets");
        JButton buySubscription = new JButton("Buy subscription");
        JButton buyTicket = new JButton("Buy ticket");
        JButton changePwdBtn = new JButton("Change Password");
        JButton logoutBtn = new JButton("Log out");

        panel.add(seeSubsBtn);
        panel.add(seeTickBtn);
        panel.add(seeBtn);
        panel.add(buySubscription);
        panel.add(buyTicket);
        panel.add(changePwdBtn);
        panel.add(logoutBtn);

        seeSubsBtn.addActionListener(new MainMenuService(frame, 0));
        seeTickBtn.addActionListener(new MainMenuService(frame, 1));
        seeBtn.addActionListener(new MainMenuService(frame, 2));
        logoutBtn.addActionListener(new MainMenuService(frame, 6));

        frame.add(panel);
    }

    public static void buildDisplayWindow(TransportationTypes t) {
        JPanel jPanel = new JPanel(new GridLayout(3, 1));

        String[] transportationMethods = new String[] {"Subscriptions", "Tickets", "All"};
        JComboBox<String> comboBox = new JComboBox<>(transportationMethods);

        final String[][] data = new String[1][1];
        JDBCService jdbcService = JDBCService.getInstance();

        if (t.equals(TransportationTypes.SUBSCRIPTION)) {
            comboBox.setSelectedIndex(0);
            data[0] = jdbcService.getTransportationMethods(TransportationTypes.SUBSCRIPTION);
        } else if (t.equals(TransportationTypes.TICKET)) {
            comboBox.setSelectedIndex(1);
            data[0] = jdbcService.getTransportationMethods(TransportationTypes.TICKET);
        } else {
            comboBox.setSelectedIndex(2);
            data[0] = jdbcService.getTransportationMethods(TransportationTypes.ANY);
        }

        JList<String> list = new JList<>(data[0]);
        jPanel.add(comboBox);
        jPanel.add(list);

        comboBox.addActionListener(actionEvent -> {
            String item = (String) comboBox.getSelectedItem();

            if (item.equals("Subscription")) {
                data[0] = jdbcService.getTransportationMethods(TransportationTypes.SUBSCRIPTION);
            } else if (item.equals("Ticket")) {
                data[0] = jdbcService.getTransportationMethods(TransportationTypes.TICKET);
            } else {
                data[0] = jdbcService.getTransportationMethods(TransportationTypes.ANY);
            }

            list.setListData(data[0]);
        });

        JButton jButton = new JButton("Back");
        jPanel.add(jButton);

        jButton.addActionListener(actionEvent -> {
            frame.getContentPane().removeAll();
            frame.repaint();
            GUIService.buildMainMenuWindow();
        });
        frame.add(jPanel);
    }
}
