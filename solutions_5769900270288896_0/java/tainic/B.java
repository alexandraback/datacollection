package y2015.r1B;

import java.io.*;
import java.util.Scanner;

/**
 * @author aurel, 5/2/15
 */
public class B {
    //public static final String type = "test";
    public static final String type = "small-attempt3";
    //public static final String type = "large";

    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new BufferedInputStream(new FileInputStream(
            "/home/aurel/repos/cuteants/codejam/src/y2015/r1B/B-" + type + ".in"
        )));
        BufferedWriter out = new BufferedWriter(new FileWriter(
            "/home/aurel/repos/cuteants/codejam/src/y2015/r1B/B-" + type + ".out"
        ));

        int t = in.nextInt();
        for (int ti = 1; ti <= t; ti++) {
            out.write("Case #" + ti + ": " + solve(in) + "\n");
        }

        in.close();
        out.close();
    }

    private static int solve(Scanner in) {
        int r = in.nextInt(), c = in.nextInt(), n = in.nextInt();
        int[][] a = new int[r][c],
                b = new int[r][c];
        int[] aa = new int[5], bb = new int[5];
        for (int i = 0; i < r; i++) {
            for (int j = i % 2; j < c; j += 2) {
                a[i][j] = 1;
                aa[0]++;
            }
            for (int j = (i + 1) % 2; j < c; j += 2) {
                b[i][j] = 1;
                bb[0]++;
            }
        }
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (a[i][j] != 1) {
                    int s = 0;
                    if (i > 0) s++;
                    if (j > 0) s++;
                    if (i + 1 < r) s++;
                    if (j + 1 < c) s++;
                    aa[s]++;
                }
                if (b[i][j] != 1) {
                    int s = 0;
                    if (i > 0) s++;
                    if (j > 0) s++;
                    if (i + 1 < r) s++;
                    if (j + 1 < c) s++;
                    bb[s]++;
                }
            }
        }

        int min1 = 0;
        int m = n;

        for (int i = 0; i < 5; i++) {
            if (m <= aa[i]) {
                min1 += i * m;
                break;
            } else {
                min1 += i * aa[i];
                m -= aa[i];
            }
        }

        int min2 = 0;
        m = n;
        for (int i = 0; i < 5; i++) {
            if (m <= bb[i]) {
                min2 += i * m;
                break;
            } else {
                min2 += i * bb[i];
                m -= bb[i];
            }
        }

//        if (m <= aa[0]) return 0;
//        m -= aa[0];
//        if (m <= aa[1]) {
//            min1 = m;
//        } else {
//            min1 = aa[1];
//            m -= aa[1];
//            if (m <= aa[2]) {
//                min1 += 2 * m;
//            } else {
//                min1 += 2 * aa[2];
//                m -= aa[2];
//                if (m <= aa[3]) {
//                    min1 += 3 * m;
//                } else {
//                    min1 += 3 * aa[3];
//                    m -= aa[3];
//                    min1 += 4 * m;
//                }
//            }
//        }
//
//        int min2;
//        m = n;
//        if (m <= bb[0]) return 0;
//        m -= bb[0];
//        if (m <= bb[1]) {
//            min2 = m;
//        } else {
//            min2 = bb[1];
//            m -= bb[1];
//            if (m <= bb[2]) {
//                min2 += 2 * m;
//            } else {
//                min2 += 2 * bb[2];
//                m -= bb[2];
//                if (m <= bb[3]) {
//                    min2 += 3 * m;
//                } else {
//                    min2 += 3 * bb[3];
//                    m -= bb[3];
//                    min2 += 4 * m;
//                }
//            }
//        }

        return Math.min(min1, min2);
    }
}
