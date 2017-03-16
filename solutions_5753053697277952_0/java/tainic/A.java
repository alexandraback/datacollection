package y2016.r1c;

import java.io.*;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

/**
 * @author tainic, 5/8/16
 */
public class A {
//    public static final String type = "test";
    public static final String type = "small-attempt0";
//    public static final String type = "large";

    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new BufferedInputStream(new FileInputStream(
            "/home/aurel/repos/cuteants/codejam/src/y2016/r1c/A-" + type + ".in"
        )));
        BufferedWriter out = new BufferedWriter(new FileWriter(
            "/home/aurel/repos/cuteants/codejam/src/y2016/r1c/A-" + type + ".out"
        ));

        int t = in.nextInt();
        for (int ti = 1; ti <= t; ti++) {
            int n = in.nextInt();
            X[] a = new X[n];
            int s = 0;
            for (int i = 0; i < n; i++) {
                a[i] = new X((char) ('A' + i), in.nextInt());
                s += a[i].x;
            }
            StringBuilder sb = new StringBuilder();
            while (s > 0) {
                Arrays.sort(a, new Comparator<X>() {
                    @Override
                    public int compare(X o1, X o2) {
                        return o2.x - o1.x;
                    }
                });
                int d = a[0].x - a[1].x;
                if (d > 1) {
                    sb.append(" ").append(a[0].c).append(a[0].c);
                    s -= 2;
                    a[0].x -= 2;
                } else if ((d == 1) || (s == 3)) {
                    sb.append(" ").append(a[0].c);
                    s--;
                    a[0].x--;
                } else {
                    sb.append(" ").append(a[0].c).append(a[1].c);
                    s -= 2;
                    a[0].x--;
                    a[1].x--;
                }
            }
            out.write("Case #" + ti + ":" + sb.toString() + "\n");
        }

        in.close();
        out.close();
    }

    static class X {
        char c;
        int x;

        public X(char c, int x) {
            this.c = c;
            this.x = x;
        }
    }
}
