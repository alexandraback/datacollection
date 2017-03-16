package exoA;

import exoD.*;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author jean
 */
public class ExoA {

    public static void main(String[] args) {


        String base = "/home/jean/gcj2014/1b/ExoA/";
        String input = base + "s3.in";
        String output = base + "s3.out";

        try {
            Scanner sc = new Scanner(new FileReader(input));
            PrintWriter pw = new PrintWriter(output);

            int n = sc.nextInt();
            sc.nextLine();
            for (int c = 0; c < n; c++) {
                System.out.println("Test case " + (c + 1) + "...");
                pw.print("Case #" + (c + 1) + ": ");
                test(sc, pw);
                pw.println();
            }
            pw.println();
            pw.flush();
            pw.close();
            sc.close();
        } catch (FileNotFoundException ex) {
            Logger.getLogger(ExoA.class.getName()).log(Level.SEVERE, null, ex);
        }

    }

    private static void test(Scanner sc, PrintWriter pw) {
        int N = sc.nextInt();
        sc.nextLine();

        String[] str = new String[N];

        for (int i = 0; i < N; i++) {
            str[i] = sc.nextLine();
        }

        char[][] chars = new char[N][101];
        int[][] numbers = new int[N][101];
        int km = 0;

        for (int i = 0; i < N; i++) {
            String s = str[i];
            int l = str[i].length();
            char c = ' ';
            int k = 0;
            for (int j = 0; j < l; j++) {
                char cc = s.charAt(j);
                if (cc == c) {
                    numbers[i][k]++;
                } else {
                    k++;
                    chars[i][k] = cc;
                    numbers[i][k] = 1;
                    c = cc;
                    if (i != 0) {
                        if (chars[i][k] != chars[0][k]) {
                            pw.print("Fegla Won");
                            return;
                        }
                    }
                }
            }
            if (i == 0) {
                km = k;
            } else if (km != k) {
                pw.print("Fegla Won");
                return;
            }

        }

        int st = 0;
        for (int k = 1; k <= km; k++) {
            int sm = 100000;
            for (int a = 1; a <= 100; a++) {
                int s = 0;
                for (int i = 0; i < N; i++) {
                    s += Math.abs(numbers[i][k] - a);
                }
                if (s < sm) {
                    sm = s;
                }
            }

            System.out.println("k = " + k + " c = " + chars[0][k] + ", sm = " + sm);
            st += sm;
        }

        pw.print(st);

    }
}
