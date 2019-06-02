package com.fmi.project.services;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class ReadService {
    private static ReadService instance = null;

    private BufferedReader bufferedReader;
    private String path;

    private ReadService(String path) {
        try {
            bufferedReader = new BufferedReader(new FileReader(path));
        } catch (FileNotFoundException ex) {
            System.err.println("The path specified is invalid");
            bufferedReader = null;
        }

        Runtime.getRuntime().addShutdownHook(new Thread(() -> closeReader()));
    }

    public static ReadService getInstance(String path) throws FileNotFoundException {
        if (instance == null) {
            instance = new ReadService(path);
        }

        if (!instance.getPath().equalsIgnoreCase(path)) {
            instance.setPath(path);
            instance.setBufferedReader(new BufferedReader(new FileReader(path)));
        }

        return instance;
    }

    private void closeReader() {
        try {
            bufferedReader.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void setBufferedReader(BufferedReader bufferedReader) {
        this.bufferedReader = bufferedReader;
    }

    public String getPath() {
        return path;
    }

    public void setPath(String path) {
        this.path = path;
    }


    /**
     * Method that reads an entire line using the bufferedReader member data
     * and splits the line by ','.
     *
     * @return list of strings containing the words on the current line read by the BufferedReader obj
     * (split by ','). IF EOF => RETURN NULL;
     * @throws IOException in case of a problem with reading from the file.
     */
    public List<String> readLine() throws IOException {
        if (bufferedReader != null) {
            String line = bufferedReader.readLine();

            if (line == null) {
                return null;
            }

            String[] separatedValues = line.split(",");
            return new ArrayList<>(Arrays.asList(separatedValues));
        }

        return null;
    }


}
