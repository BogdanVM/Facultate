package com.fmi.project;

import com.fmi.project.enums.TransportationTypes;
import com.fmi.project.services.GUIService;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowEvent;

/**
 * Implements the click listeners from MainMenu Window.
 * i = the index of the button which was clicked
 */
public class MainMenuService implements ActionListener {
    private JFrame frame;
    private int i;

    public MainMenuService(JFrame frame, int i) {
        this.i = i;
        this.frame = frame;
    }

    @Override
    public void actionPerformed(ActionEvent actionEvent) {
        frame.getContentPane().removeAll();
        frame.repaint();

        switch (i) {
            case 1: {
                /* SUBSCRIPTIONS */
                frame.getContentPane().removeAll();
                frame.repaint();
                GUIService.buildDisplayWindow(TransportationTypes.SUBSCRIPTION);
            }

            case 2: {
                /* TICKETS */
                frame.getContentPane().removeAll();
                frame.repaint();
                GUIService.buildDisplayWindow(TransportationTypes.TICKET);
            }

            case 3: {
                /* ALL TRANSPORTATION*/
                frame.getContentPane().removeAll();
                frame.repaint();
                GUIService.buildDisplayWindow(TransportationTypes.ANY);
            }

            case 4: {
                /* BUY SUBSCRIPTION */
                frame.getContentPane().removeAll();
                frame.repaint();
            }

            case 5: {
                /* CHANGE PASSWORD */
                frame.getContentPane().removeAll();
                frame.repaint();
            }

            case 6: {
                /* LOGOUT */
                GUIService.buildLoginWindow();
                frame.setVisible(false);
                frame.dispose();
            }

            case 7: {
                /* BUY TICKET */
            }
        }
    }
}
