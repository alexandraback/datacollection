package com.andreytim.jafar.problems.googlecodejam.y2015.round1B;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Scanner;

/**
 * Created by tim on 02/05/15.
 */
public class B {

    private static int numOnes(int n) {
        int count = 0;
        while (n > 0) {
            count += n % 2;
            n /= 2;
        }
        return count;
    }

    private static int calcNoise(int n, int R, int C) {
        String bin = Integer.toBinaryString(n);
        while (bin.length() < R*C) bin = "0" + bin;
        char[][] house = new char[R][C];
        for (int i = 0; i < R; i++) house[i] = bin.substring(i*C, (i+1)*C).toCharArray();
        int noise = 0;
        for (int i = 0; i < R-1; i++) {
            for (int j = 0; j < C-1; j++) {
                if (house[i][j] == '1' && house[i][j+1] == '1') noise++;
                if (house[i][j] == '1' && house[i+1][j] == '1') noise++;
            }
        }
        for (int i = 0; i < C-1; i++)
            if (house[R-1][i] == '1' && house[R-1][i+1] == '1') noise++;
        for (int i = 0; i < R-1; i++)
            if (house[i][C-1] == '1' && house[i+1][C-1] == '1') noise++;
        return noise;
    }

    private static int solve(Scanner in) {
        int R = in.nextInt(), C = in.nextInt(), N = in.nextInt();
        if (N == 0) return 0;
        int noise = R*C*2;
        for (int i = 0; i < (1 << R*C); i++) {
            if (numOnes(i) == N) noise = Math.min(noise, calcNoise(i, R, C));
        }
        return noise;
    }

    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(new FileInputStream("in.txt"));
        PrintStream out = new PrintStream(new FileOutputStream("out.txt"));
//        PrintStream out = System.out;
        int T = in.nextInt();
        for (int i = 0; i < T; i++) {
            out.printf("Case #%d: %d\n", i+1, solve(in));
        }
        out.close();
    }

}
