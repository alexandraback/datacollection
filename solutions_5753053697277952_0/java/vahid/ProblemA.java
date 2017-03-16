package com.vahid.codejam.codejam2016.round1c;

import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


public class ProblemA {
    public static void main(String[] args) throws IOException {
        Scanner scanner = null;
        BufferedWriter output = null;
        try {
            scanner = new Scanner(new BufferedReader(
                    new FileReader("input.txt")));
            output = new BufferedWriter(new FileWriter("output.txt"));

        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }

        int n = scanner.nextInt();
        scanner.nextLine();

        for (int i=0; i < n; i++){
            int x = scanner.nextInt();
            int[] p = new int[x];
            for (int j=0; j< x; j++) {
                p[j] = scanner.nextInt();
            }
            output.write( "Case #"+(i+1)+": " + solve(x, p));
            output.newLine();
        }

        output.close();
    }

    private static String solve(int n, int[] p) {
        int sum = 0;
        for (int i= 0; i< n; i++) {
            sum += p[i];
        }
        String response = "";
        String part = "";
        while (sum > 0) {
            int maxIndex = maxIndex(p);
            p[maxIndex]--;
            sum --;
            if ((part.length()>0) && problem(p, sum)) {
                response += part + " ";
                part = "";
            }
            part += letter(maxIndex);
            if (part.length()>1) {
                response += part +" ";
                part="";
            }
        }

        response += part;

        return response.trim();
    }

    private static boolean problem(int[] p, int sum) {
        for (int i=0; i< p.length; i++) {
            if (p[i] * 2 > sum)
                return true;
        }
        return false;
    }

    private static String letter(int maxIndex) {
        int ch = 'A';
        return String.valueOf((char) (ch + maxIndex));
    }

    private static int maxIndex(int[] p) {

        int max = 0;
        for (int i=1; i< p.length; i++) {
            if (p[i] > p[max])
                max = i;
        }
        return max;
    }

}
