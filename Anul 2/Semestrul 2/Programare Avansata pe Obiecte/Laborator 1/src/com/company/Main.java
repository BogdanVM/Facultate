package com.company;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

//        while (scanner.hasNext()) {
//            System.out.println("word " + scanner.nextInt());
//            System.out.println("Introduce an integer: ");
//        }

//        for(int i = 0; i < 5; ++i) {
//            System.out.println("Give me an integer: ");
//        }

//        while (scanner.hasNext()) {
//            if(scanner.hasNextInt()) {
//                int i = scanner.nextInt();
//                System.out.println("Your integer: " + i);
//            } else {
//                System.err.println("No integer. I'm leaving!");
//                break;
//            }
//        }
//        scanner.close();
//
//


        Scanner scannerFromString = new Scanner("primul al-doilea al-treilea");
        scannerFromString.useDelimiter(" ");

        do {

            String word = scannerFromString.next();
            switch (word) {
                case "primul": {
                    System.out.println("Primul cuvant");
                    break;
                }

                case "al-doilea": {
                    System.out.println("Al doilea cuvant");
                    break;
                }

                case "al-treilea": {
                    System.out.println("Al treilea cuvant");
                    break;
                }
            }

        } while (scannerFromString.hasNext());

        scannerFromString.close();
    }
}
