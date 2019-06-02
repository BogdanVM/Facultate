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

    private final String DRIVER_NAME = "jdbc:postgresql://localhost:5432/PAO";
    private Connection connection;

    public LoginService(JFrame frame, JLabel message, JTextField userNameField, JPasswordField pwdField) {
        this.message = message;
        this.userNameField = userNameField;
        this.pwdField = pwdField;
        this.frame = frame;

        try {
            connection = DriverManager.getConnection(DRIVER_NAME, "postgres", "1234");
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    private boolean checkCredentials(String username, String password) {
        try {
            PreparedStatement pst = connection.prepareStatement(
                    "SELECT * FROM USERS WHERE Username = ? AND Password = ?"
            );

            pst.setString(1, username);
            pst.setString(2, password);
            ResultSet rst = pst.executeQuery();
            if (!rst.next()) {
                return false;
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }

        return true;
    }

    @Override
    public void actionPerformed(ActionEvent actionEvent) {
        String username = userNameField.getText().trim();
        String password = new String(pwdField.getPassword()).trim();

        if (checkCredentials(username, password)) {
            frame.getContentPane().removeAll();
            frame.repaint();

            GUIService.buildMainMenuWindow();
        } else {
            message.setText("Invalid data");
        }
    }
}
