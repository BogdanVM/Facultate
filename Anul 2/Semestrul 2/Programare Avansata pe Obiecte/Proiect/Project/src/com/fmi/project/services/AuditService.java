package com.fmi.project.services;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.sql.Timestamp;
import java.text.SimpleDateFormat;
import java.time.Instant;
import java.util.Calendar;
import java.util.Date;

public class AuditService {
    private String path;

    public AuditService(String path) {
        this.path = path;
    }

    public void write(String actionPerformed) {
        try (BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(path, true))){
            bufferedWriter.write(actionPerformed + ", " + Timestamp.from(Instant.now()) + "\n");
        } catch (IOException ex) {
            System.err.println("An error has occurred while writing to file");
        }
    }
}
