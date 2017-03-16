package com.google.codejam.r2015a;

import java.io.BufferedReader;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.List;

public class ProblemA {

    private static final String PATH = "/Users/danilova/dev/projects/misc/codejam/src/com/google/codejam/r2015a/";
    private static String PROBLEM_NAME = PATH + "A-large";
    //private static String PROBLEM_NAME = PATH + "A-small-attempt0";
    //private static String PROBLEM_NAME = "/Users/danilova/dev/projects/misc/codejam/test";

    public static void main(String[] args) throws IOException {
        try (BufferedReader reader = new BufferedReader(new FileReader(PROBLEM_NAME + ".in"));
            PrintStream out = new PrintStream(new FileOutputStream(PROBLEM_NAME + ".txt"))) {
            int t = Integer.parseInt(reader.readLine());
            for (int i = 1; i <= t; i++) {
                String result = solve(reader, out, i);
                if (result != null) {
                    printResult(out, i, result);
                }
            }
        }
    }

    private static String solve(BufferedReader reader, PrintStream out, int caseN) throws IOException {
        int n = Integer.valueOf(reader.readLine());
        String[] line = reader.readLine().split(" ");
        int y = 0;
        int last = -1;
        int[] mArray = new int[n];
        int max = 0;
        int i = 0;
        for (String s : line) {
            int m = Integer.valueOf(s);
            if (last != -1) {
                int delta = last - m;
                if (delta > 0) {
                    y += delta;
                }
                mArray[i++] = last;
                max = Math.max(max, delta);
            }
            last = m;
        }

        if (max == 0) {
            return "0 0";
        }

        int z = 0;
        for (int m : mArray) {
            if (m < max) {
                z+= m;
            } else {
                z+= max;
            }
        }


        return y + " " + z;
    }


    private static String printResult(PrintStream out, int caseN, String result) {
        String str = "Case #" + caseN + ": " + result;
        System.out.println(str);
        out.println(str);
        return null;
    }
}
