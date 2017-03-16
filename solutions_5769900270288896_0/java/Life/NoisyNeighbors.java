package codejam2015.B1;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class NoisyNeighbors {
    public static void main(String[] args) throws IOException {
        String fileName;

        fileName = "B-small-attempt1.in";
        // fileName = "C-small-attempt0.in";
        // fileName = "C-large.in";

        try (BufferedReader r = new BufferedReader(new FileReader(fileName));
             BufferedWriter w = new BufferedWriter(new FileWriter(fileName.replace(".in", ".out")))) {
            Scanner sc = new Scanner(r);
            int T = sc.nextInt();
            long startTotal = System.currentTimeMillis();
            for (int i = 0; i < T; i++) {
                int R = sc.nextInt();
                int C = sc.nextInt();
                int N = sc.nextInt();
                w.write("Case #" + (i + 1) + ": " + calc(R, C, N) + "\n");
                System.out.println("case " + +(i + 1) + ". time: " + (System.currentTimeMillis() - startTotal));
            }
            System.out.println("Total time: " + (System.currentTimeMillis() - startTotal));
        }

    }

    private static String calc(int r, int c, int n) {
        int[][] f;
        int res = Integer.MAX_VALUE;
        for (int mask = 0; mask < 1 << (r * c); mask++) {
            if (Integer.bitCount(mask) != n) {
                continue;
            }
            f = new int[r][c];
            for (int j = 0; j < r; j++) {
                for (int k = 0; k < c; k++) {
                    if ((mask & (1 << (j * c + k))) != 0) {
                        f[j][k] = 1;
                    }
                }
            }
            res = Math.min(res, countN(r, c, f));
        }

        return "" + res;
    }

    private static int countN(int r, int c, int[][] f) {

        int count = 0;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (i > 0 && f[i][j] == 1 && f[i - 1][j] == 1)
                    count++;
                if (j > 0 && f[i][j] == 1 && f[i][j - 1] == 1)
                    count++;
            }
        }
        return count;
    }

}
