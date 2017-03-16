package com.rotciv.rounda.b;

import com.rotciv.utils.Converter;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;

/**
 * Created by Administrator on 2015/4/18.
 */
public class Haircut {

    private Haircut() {}

    public static void main(String[] args) {
        readFormFile();
    }

    private static void readFormFile() {

        BufferedReader reader = null;
        try {
            reader = new BufferedReader(new FileReader("E:\\CODE\\JAVA\\TakeARest\\src\\com\\rotciv\\rounda\\b\\B-small-attempt1.in"));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }

        int i = 0;
        String temp = "";
        int size = 0;
        int position = 0;
        String[] barberTime;
        int mutiple;

        while(true) {
            try {
                temp = reader.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }

            if (i == 0) {
                size = Integer.parseInt(temp);
                System.out.println(size);
            } else if (i % 2 == 1) {
                position = Integer.parseInt(temp.split(" ")[1]);
            } else {
                barberTime = temp.split(" ");
                mutiple = getMutiple(Converter.toIntArray(barberTime));


                if (position - barberTime.length > mutiple) {
                    position = (position - barberTime.length) % mutiple + barberTime.length;
                }
                outputResult(i / 2, barberTime, position);
            }

            if (i == size * 2)
                break;

            i++;
        }
    }

    private static void outputResult(int testCase, String[] times, int position) {

        ArrayList<Barber> barberList = new ArrayList<Barber>();
        Barber barber;
        int index;
        int cutNum;

        if (times.length >= position) {
            index = position;
        } else {
            for (int i = 0; i < times.length; i++) {
                barber = new Barber(i + 1, Integer.parseInt(times[i]));
                barberList.add(barber);
            }

            cutNum = barberList.size();

            while(true) {

                index = getNextBarber(barberList);
                cutNum++;

                if (cutNum == position)
                    break;
            }
        }

        System.out.println("Case #" + testCase + ": " + index);
    }

    private static int getNextBarber(ArrayList<Barber> barberList) {

        int minTime = barberList.get(0).getRemain();
        int index = 1;

        for (Barber barber : barberList) {
            if (minTime > barber.getRemain()) {
                minTime = barber.getRemain();
                index = barber.getIndex();
            }
        }

        for (Barber barber : barberList) {
            barber.decreaseTime(minTime);
        }

        barberList.get(index - 1).resetRemain();

        return index;
    }

    private static int getMutiple(int[] data) {

        int mutiple;
        int max = 0;
        boolean muti;
        int size = 0;


        for (int i = 0; i < data.length; i++) {
            if (max < data[i])
                max = data[i];
        }

        mutiple = max;

        while (true) {
            muti = true;
            for (int i = 0; i < data.length; i++) {
                if (mutiple % data[i] != 0) {
                    muti = false;
                    break;
                }
            }

            if (muti)
                break;

            mutiple += max;
        }

        for (int i = 0; i < data.length; i++) {
            size += mutiple / data[i];
        }

        return size;
    }
}
