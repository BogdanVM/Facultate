package com.fmi.project.services;

import java.io.*;
import java.sql.Timestamp;
import java.text.SimpleDateFormat;
import java.time.Instant;
import java.util.Calendar;
import java.util.Date;

public class AuditService {
    private static final String LOG_LOCATION = "./audit.csv";
    private static PrintWriter printWriter;

    private static AuditService instance = new AuditService();

    public static AuditService getInstance() {
        return instance;
    }

    private AuditService() {
        try {
            printWriter = new PrintWriter(LOG_LOCATION);
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }

        Runtime.getRuntime().addShutdownHook(new Thread(() -> closeWriter()));
    }

    public void write(String actionPerformed) {
        printWriter.println(actionPerformed + ", " + Timestamp.from(Instant.now()));
    }

    private void closeWriter() {
        printWriter.flush();
        printWriter.close();


    }
}
