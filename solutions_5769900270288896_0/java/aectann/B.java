package com.company;

import java.io.*;
import java.util.Scanner;

public class B {

    public static void main(String[] args) throws Exception {
        Scanner s = new Scanner(new FileInputStream("B-local.in"));
        OutputStream os = new FileOutputStream("B-small.out");
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(os));
        int testsCount = s.nextInt();
        for (int test = 0; test < testsCount; test++) {
            int r = s.nextInt();
            int c = s.nextInt();
            int n = s.nextInt();
            bw.write("Case #" + (test + 1) + ": " + solve(r, c, n) + "\n");
        }
        bw.flush();
        os.close();
        s.close();
    }

    private static final boolean[] DATA = new boolean[16*16];

    private static int solve(int r, int c, int n) {
        if (r == 0 || c == 0 || n == 0) return 0;
        return solve(r, c, 0, n);
    }

    private static int solve(int r, int c, int ind, int n) {
        int minUnhappinessLevel = Integer.MAX_VALUE;
        for (int i = ind; i <= (r * c - n); i++) {
            DATA[i] = true;
            if (n == 1) {
                minUnhappinessLevel = Math.min(minUnhappinessLevel, countCurrentLevel(r, c));
            } else {
                minUnhappinessLevel = Math.min(minUnhappinessLevel, solve(r, c, i + 1, n - 1));
            }
            DATA[i] = false;
        }
        return minUnhappinessLevel;
    }

    private static int countCurrentLevel(int r, int c) {
        int level = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (DATA[i * c + j]) {
                    if (j < c - 1 && DATA[i * c + j + 1]) {
                        level++;
                    }
                    if (i < r - 1 && DATA[(i + 1) * c + j]) {
                        level++;
                    }
                }
            }
        }
        return level;
    }
}