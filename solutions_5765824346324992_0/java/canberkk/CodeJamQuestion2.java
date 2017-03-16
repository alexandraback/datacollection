/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package codejamquestion2;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 *
 * @author Canberk
 */
public class CodeJamQuestion2 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        try {
            Scanner in = new Scanner(new File("B-small-attempt0.in"));
            PrintWriter out = new PrintWriter("B-small-attempt0.out");

            int cases = Integer.parseInt(in.nextLine());

            for (int c = 1; c <= cases; c++) {
                String answer = "Case #" + c + ": ";
                String[] line = in.nextLine().split(" ");
                int b = Integer.parseInt(line[0]);
                int n = Integer.parseInt(line[1]);
                line = in.nextLine().split(" ");
                long[] barbers = new long[b];
                for (int i = 0; i < b; i++) {
                    barbers[i] = Integer.parseInt(line[i]);
                }
                long[] current = new long[b];
                for (int i = 0; i < current.length; i++) {
                    current[i] = 0;
                }
                
                long lcm = lcm(barbers);
                int reduce = 0;
                for (int i = 0; i < barbers.length; i++) {
                    reduce += lcm/barbers[i];
                }
                
                n = n%reduce + reduce;

                while (n > 0) {
                    long min = current[0];
                    for (int i = 1; i < current.length; i++) {
                        if (current[i] < min) {
                            min = current[i];
                        }
                    }
                    for (int i = 0; i < current.length; i++) {
                        current[i] -= min;
                        if (current[i] == 0) {
                            n--;
                            current[i] = barbers[i];
                        }
                        if (n == 0) {
                            out.println(answer + (i + 1));
                            n--;
                        }
                    }
                }

            }

            in.close();
            out.close();
        } catch (FileNotFoundException ex) {
            System.out.println("ERROR");
        }

    }

    private static long lcm(long a, long b) {
        return a * (b / gcd(a, b));
    }

    private static long lcm(long[] input) {
        long result = input[0];
        for (int i = 1; i < input.length; i++) {
            result = lcm(result, input[i]);
        }
        return result;
    }

    private static long gcd(long a, long b) {
        while (b > 0) {
            long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

}
