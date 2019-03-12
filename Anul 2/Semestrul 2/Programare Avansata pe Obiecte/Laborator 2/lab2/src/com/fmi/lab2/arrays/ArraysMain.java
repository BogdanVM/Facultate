package com.fmi.lab2.arrays;

import java.util.Arrays;

public class ArraysMain {

    public static void printArr(Integer[] arr) {
        for(int i = 0; i < arr.length; ++i) {
            System.out.println(arr[i]);
        }
    }

    public static Integer[] addArrays(Integer[] v1, Integer[] v2) {
        Integer[] res = new Integer[v1.length];

        try {
            if(v1.length != v2.length) {
                throw new Exception("Different sizes");
            }

            for(int i = 0; i < v1.length; ++i) {
                res[i] = v1[i] + v2[i];
            }
        } catch (Exception ex) {
            System.err.println(ex.getMessage());
        } finally {
            return res;
        }
    }

    public static void main(String[] args) {
//        Integer[] v = {1, 2, 3, 4, 5};
//        printArr(v);
//
//        Integer[][] mat = {{1, 2, 3, 4}, {3, 5, 7}, {20, 21, 22}};
//        System.out.println();
//
//        for(Integer[] row : mat) {
//            System.out.println(Arrays.toString(row));
//        }
//
//        String[] strings = {"my1", "my2", "my3", "abc"};
//        Arrays.sort(strings);
//        System.out.println(Arrays.binarySearch(strings, "abc"));

        Integer[] v1 = {1, 2, 3, 4};
        Integer[] v2 = {2, 3, 4, 5};
        Integer[] res = addArrays(v1, v2);

        if(res[0] != null) {
            System.out.println(Arrays.toString(res));
        }
    }
}
