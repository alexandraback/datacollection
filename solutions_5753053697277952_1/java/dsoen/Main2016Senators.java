package com.codejam;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Scanner;

/**
 * Created by dx on 3/30/16.
 */
public class Main2016Senators {



    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));

        Long t = Long.parseLong(in.nextLine());
        for (int i =1; i <= t; ++i) {
            int n = in.nextInt();
            int fn[] = new int[n];
            for(int j=0; j < n; ++j) {
                fn[j] = in.nextInt();
            }

            String output = "";
            while(total(fn, n) > 0) {
                for(int j=0; j < n; ++j) {
                    for(int k=j; k < n; ++k) {
                        if (!takeOneOne(fn, j, k, n)) {
                            char charRep1 = (char) (j + 65);
                            char charRep2 = (char) (k + 65);
                            output += Character.toString(charRep1) + Character.toString(charRep2) + " ";
                        }
                        else if (!takeOne(fn, j, n)) {
                            char charRep1 = (char) (j + 65);
                            output += Character.toString(charRep1) + " ";
                        }
                        else if (!takeOne(fn, k, n)) {
                            char charRep2 = (char) (k + 65);
                            output += Character.toString(charRep2) + " ";
                        }
                    }
                }
            }

            System.out.print("Case #" + i + ": " + output );
            System.out.println();
        }
    }

    private static int total(int[] fn, int n) {
        int total = 0;
        for(int i = 0; i < n; i++) {
            total += fn[i];
        }
        return total;
    }

    private static boolean takeOneOne(int[] fn, int i, int j, int n) {
        boolean isMajority = false;

        if(i == j && fn[i] < 2) return true;
        if(fn[i] < 1 || fn[j] < 1) return true;

        fn[i] -= 1;
        fn[j] -= 1;
        int halfN = total(fn, n) / 2;
        for(int k = 0; k < n; k++) {
            isMajority = fn[k] > halfN;
            if(isMajority) {
                fn[i] += 1;
                fn[j] += 1;
                break;
            }
        }

        return isMajority;
    }

    /**
     * True if taking two of these is not causing absolute majority
     * @param fn
     * @param i
     * @return
     */
    private static boolean takeTwo(int[] fn, int i, int n) {
        boolean isMajority = false;

        if(fn[i] < 2) return true;

        fn[i] -= 2;
        int halfN = total(fn, n) / 2;
        for(int j = 0; j < n; j++) {
            isMajority = fn[j] > halfN;
            if(isMajority) {
                fn[i] += 2;
                break;
            }
        }

        return isMajority;
    }

    private static boolean takeOne(int[] fn, int i, int n) {
        boolean isMajority = false;

        if(fn[i] < 1) return true;

        fn[i] -= 1;
        int halfN = total(fn, n) / 2;
        for(int j = 0; j < n; j++) {
            isMajority = fn[j] > halfN;
            if(isMajority) {
                fn[i] += 1;
                break;
            }
        }

        return isMajority;
    }

}
