package com.rotciv.rounda.a;

import com.rotciv.utils.Converter;

import java.io.*;
import java.util.ArrayList;

/**
 * Created by Administrator on 2015/4/18.
 */
public class EatMushrooms {

    public static void main(String[] args) {

        ArrayList<String[]> list = readFromConsole();
        int sum1, sum2;
        int[] temp;

        for (int i = 0; i < list.size(); i++) {

            temp = Converter.toIntArray(list.get(i));
            sum1 = nolinearEating(temp);
            sum2 = linearEating(temp);

            System.out.println("Case #" + (i + 1) + ": " + sum1 + " " + sum2);
        }
    }

    private static ArrayList<String[]> readFromConsole() {

        BufferedReader reader = null;
        try {
            reader = new BufferedReader(new FileReader("E:\\CODE\\JAVA\\TakeARest\\src\\com\\rotciv\\rounda\\A-small-attempt0 (2).in"));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }

        String temp = "";
        int i = 0;
        int size = 0;
        ArrayList<String[]> list = new ArrayList<String[]>();

        while (true) {
            try {
                temp = reader.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }

            if (i == 0)
                size = Integer.parseInt(temp);

            if (i != 0 && i % 2 == 0) {
                String[] numArr = temp.split(" ");
                list.add(numArr);
            }

            if (size * 2 == i)
                break;

            i++;
        }

        return list;
    }

    private static int linearEating(int[] temp) {

        int sum = 0;
        int maxOffset = 0;

        maxOffset = getMaxOffset(temp);
        for (int j = 0; j < temp.length - 1; j++) {
            if (temp[j] < maxOffset) {
                sum += temp[j];
            } else {
                sum += maxOffset;
            }
        }

        return sum;
    }

    private static int getMaxOffset(int[] arr) {
        int max = 0;
        for (int i = 1; i < arr.length; i++) {
            if (arr[i - 1] - arr[i] > max) {
                max = arr[i - 1] - arr[i];
            }
        }
        return max;
    }

    private static int nolinearEating(int[] temp) {

        int sum = 0;

        for (int j = 1; j < temp.length; j++) {
            if (temp[j] < temp[j - 1]) {
                sum += temp[j - 1] - temp[j];
            }
        }

        return sum;
    }
}
