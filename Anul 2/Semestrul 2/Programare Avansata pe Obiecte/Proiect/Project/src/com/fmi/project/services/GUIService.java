package com.fmi.project.services;

import com.fmi.project.LoginService;
import com.fmi.project.MainMenuService;
import com.fmi.project.enums.TransportationTypes;
import com.fmi.project.factories.SubscriptionFactory;
import com.fmi.project.factories.TicketFactory;
import com.fmi.project.models.subscriptions.OneDaySubscription;
import com.fmi.project.models.subscriptions.OneMonthSubscription;
import com.fmi.project.models.subscriptions.OneWeekSubscription;
import com.fmi.project.models.tickets.OneRideTicket;
import com.fmi.project.models.tickets.TenRideTicket;
import com.fmi.project.models.tickets.TwoRideTicket;

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

        seeSubsBtn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                frame.getContentPane().removeAll();
                frame.repaint();
                GUIService.buildDisplayWindow(TransportationTypes.SUBSCRIPTION);
            }
        });

        seeTickBtn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                frame.getContentPane().removeAll();
                frame.repaint();
                GUIService.buildDisplayWindow(TransportationTypes.TICKET);
            }
        });
        seeBtn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                frame.getContentPane().removeAll();
                frame.repaint();
                GUIService.buildDisplayWindow(TransportationTypes.ANY);
            }
        });

        buySubscription.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                frame.getContentPane().removeAll();
                frame.repaint();
                GUIService.buildBuyWindow(TransportationTypes.SUBSCRIPTION);
            }
        });

        buyTicket.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                frame.getContentPane().removeAll();
                frame.repaint();
                GUIService.buildBuyWindow(TransportationTypes.TICKET);
            }
        });

        logoutBtn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                frame.setVisible(false);
                frame.dispose();
                GUIService.buildLoginWindow();

            }
        });

        frame.add(panel);
        frame.setVisible(true);
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

        JPanel panelCombo = new JPanel();
        JPanel panelList = new JPanel();

        panelCombo.add(comboBox);
        panelList.add(list);

        jPanel.add(panelCombo);
        jPanel.add(new JScrollPane(panelList));

        comboBox.addActionListener(actionEvent -> {
            String item = (String) comboBox.getSelectedItem();

            if (item.equals("Subscriptions")) {
                data[0] = jdbcService.getTransportationMethods(TransportationTypes.SUBSCRIPTION);
            } else if (item.equals("Tickets")) {
                data[0] = jdbcService.getTransportationMethods(TransportationTypes.TICKET);
            } else {
                data[0] = jdbcService.getTransportationMethods(TransportationTypes.ANY);
            }

            list.setListData(data[0]);
        });

        JButton jButton = new JButton("Back");
        JPanel panelButton = new JPanel();

        panelButton.add(jButton);
        jPanel.add(panelButton);

        jButton.addActionListener(actionEvent -> {
            frame.getContentPane().removeAll();
            frame.repaint();
            GUIService.buildMainMenuWindow();
        });
        frame.add(jPanel);
        frame.setVisible(true);
    }

    public static void buildBuyWindow(TransportationTypes t) {
        JPanel jPanel = new JPanel(new GridLayout(3, 1));

        String[] transportationMethods;
        if (t.equals(TransportationTypes.SUBSCRIPTION)) {
            transportationMethods = new String[] {"1 month", "1 week", "1 day"};
        } else {
            transportationMethods = new String[] {"1 ride", "2 rides", "10 rides"};
        }

        JComboBox<String> comboBox = new JComboBox<>(transportationMethods);
        JPanel panelCombo = new JPanel();
        panelCombo.add(comboBox);
        jPanel.add(panelCombo);

        JButton buyButton = new JButton("Buy");
        JPanel buyPanel = new JPanel();
        buyPanel.add(buyButton);
        jPanel.add(buyPanel);

        JButton jButton = new JButton("Back");
        JPanel panelButton = new JPanel();
        panelButton.add(jButton);
        jPanel.add(panelButton);

        frame.add(jPanel);
        frame.setVisible(true);

        buyButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String subtype = (String) comboBox.getSelectedItem();
                if (t.equals(TransportationTypes.SUBSCRIPTION)) {
                    SubscriptionFactory sf = new SubscriptionFactory();
                    if (subtype.equalsIgnoreCase("1 day")) {
                        OneDaySubscription s = (OneDaySubscription) sf.getTransportationMethod("one day");
                        JDBCService.getInstance().insertTransportationMethod(s);
                    } else if (subtype.equalsIgnoreCase("1 week")) {
                        OneWeekSubscription s = (OneWeekSubscription) sf.getTransportationMethod("one week");
                        JDBCService.getInstance().insertTransportationMethod(s);
                    } else {
                        OneMonthSubscription s = (OneMonthSubscription) sf.getTransportationMethod("one month");
                        JDBCService.getInstance().insertTransportationMethod(s);
                    }
                } else {
                    TicketFactory tf = new TicketFactory();
                    if (subtype.equalsIgnoreCase("1 ride")) {
                        OneRideTicket s = (OneRideTicket) tf.getTransportationMethod("one ride");
                        JDBCService.getInstance().insertTransportationMethod(s);
                    } else if (subtype.equalsIgnoreCase("2 rides")) {
                        TwoRideTicket s = (TwoRideTicket) tf.getTransportationMethod("two rides");
                        JDBCService.getInstance().insertTransportationMethod(s);
                    } else {
                        TenRideTicket s = (TenRideTicket) tf.getTransportationMethod("ten rides");
                        JDBCService.getInstance().insertTransportationMethod(s);
                    }
                }

                JOptionPane.showMessageDialog(null, "Successful insert");

            }
        });

        jButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                frame.getContentPane().removeAll();
                frame.repaint();
                GUIService.buildMainMenuWindow();
            }
        });
    }
}
