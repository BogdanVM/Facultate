package com.company;

import java.util.Calendar;
import java.util.Date;

public class Main {

    public static void main(String[] args) {
        Calendar myCalendar = Calendar.getInstance();
        myCalendar.set(2015, 7, 5);
        Integer dayOfWeek = myCalendar.get(Calendar.DAY_OF_WEEK);

        System.out.println(dayOfWeek + " " + Calendar.SATURDAY);
    }
}
