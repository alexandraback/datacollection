/*
 * Copyright (c) 2015. Made just for fun.
 */

package round1a;

import java.util.Scanner;
import java.util.regex.Pattern;

/**
 * @author Tomik
 */
public class A {


    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for (int i = 1; i <= T; i++) {
            int N = sc.nextInt();
            int[] m = new int[N];
            for (int j = 0; j < N; j++) {
                m[j] = sc.nextInt();
            }

            int an = 0;
            for (int j = 0; j < N-1; j++) {
                an += Math.max(m[j] - m[j + 1], 0);
            }
            int cn = 0;
            int mn = 0;
            for (int j = 0; j < N-1; j++) {
                mn = Math.max(mn, m[j] - m[j+1]);
            }
            for (int j = 0; j < N - 1; j++) {
                cn += Math.min(mn, m[j]);
            }

            System.out.println("Case #" + i + ": " + an + " " + cn);
        }
    }

}
