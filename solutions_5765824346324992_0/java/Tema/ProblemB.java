package com.google.codejam.r2015a;

import java.io.BufferedReader;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintStream;
import java.util.Arrays;

public class ProblemB {

    private static final String PATH = "/Users/danilova/dev/projects/misc/codejam/src/com/google/codejam/r2015a/";
    //private static String PROBLEM_NAME = PATH + "B-large";
    private static String PROBLEM_NAME = PATH + "B-small-attempt1";
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
        String[] firstLine = reader.readLine().split(" ");
        int B = Integer.valueOf(firstLine[0]);
        int N = Integer.valueOf(firstLine[1]) - 1;
        String[] mLine = reader.readLine().split(" ");
        int[] b = new int[B];
        for (int i = 0; i < mLine.length; i++) {
            b[i] = Integer.valueOf(mLine[i]);
        }

        int nod = 1;
        L:for (; nod < Integer.MAX_VALUE; nod++) {
            for (int k : b) {
                if (nod % k != 0) {
                    continue L;
                }
            }
            break;
        }

        int cycle = 0;
        for (int k : b) {
            cycle += nod / k;
        }

        N = N % cycle + 1;


        int[] work = new int[B];
        int minIndex = 0;

        for (int i = 0; i < N; i++) {
            int min = work[0];
            minIndex = 0;
            for (int j = 1; j < B; j++) {
                if (work[j] < min) {
                    min = work[j];
                    minIndex = j;
                }
            }
            for (int j = 0; j < B; j++) {
                work[j] -= min;
            }
            work[minIndex] = b[minIndex];
        }

        return (minIndex + 1) + "";
    }


    private static String printResult(PrintStream out, int caseN, String result) {
        String str = "Case #" + caseN + ": " + result;
        System.out.println(str);
        out.println(str);
        return null;
    }
}
