package com.fmi.project;

import com.fmi.project.services.GUIService;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.*;

public class LoginService implements ActionListener {

    private JFrame frame;
    private JLabel message;
    private JTextField userNameField;
    private JPasswordField pwdField;

    private final String DRIVER_NAME = "";
    private Connection connection;

    public LoginService(JFrame frame, JLabel message, JTextField userNameField, JPasswordField pwdField) {
        this.message = message;
        this.userNameField = userNameField;
        this.pwdField = pwdField;
        this.frame = frame;

        try {
            connection = DriverManager.getConnection(DRIVER_NAME);
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    private boolean checkCredentials(String username, String password) {
        try {
            PreparedStatement pst = connection.prepareStatement(
                    "SELECT * FROM USERS WHERE Username = ? AND Password = ?"
            );

            ResultSet rst = pst.executeQuery();
            if (rst.getFetchSize() != 0) {
                return true;
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }

        return false;
    }

    @Override
    public void actionPerformed(ActionEvent actionEvent) {
        String username = userNameField.getText().trim();
        String password = new String(pwdField.getPassword()).trim();

        if (username.equals("12") && password.equals("12")) {
            frame.getContentPane().removeAll();
            frame.repaint();

            GUIService.buildMainMenuWindow();
        } else {
            message.setText(username + " " + password);
        }
    }
}
