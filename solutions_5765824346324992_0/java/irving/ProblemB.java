package codejam.codejam2015.round1a;

import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Haircut
 */
public class ProblemB {

    private static final String ID = "gcj2015round1A/B-small-attempt1";

    private static Scanner input;
    private static PrintWriter output;

    private static void run() {
        long time = System.currentTimeMillis();
        solve();
        output.flush();
        output.close();
        input.close();
        time = System.currentTimeMillis() - time;
        System.out.printf("[%s] finished in %d ms\n", ID, time);
    }

    public static void main(String[] args) {
        try {
            input = new Scanner(new File("data/" + ID + ".in"));
            output = new PrintWriter(new FileWriter("data/" + ID + ".out"));
            run();
        } catch (Exception ex) {
            ex.printStackTrace(System.out);
        }
    }

    private static void solve() {
        int T = input.nextInt();
        for (int t = 1; t <= T; t++) {
//            System.out.println();
//            System.out.printf("Case %d\n", t);
            int B = input.nextInt();
            int N = input.nextInt();

            int[] M = new int[B];
            int[] m = new int[B];
            int min = 100001;
            for (int i = 0; i < B; i++) {
                M[i] = input.nextInt();
                m[i] = M[i];
                if (M[i] < min) {
                    min = M[i];
                }
            }

            int lcm = lcm(M);
            int round = 0;
            for (int i : M) {
                round += lcm / i;
            }
            N = N % round;
            if (N == 0) {
                N = round;
            }
//            System.out.printf("lcm: %d\nround: %d\nstarting N: %d\n", lcm, round, N);

//            System.out.println("Starting min: " + min);
            int answer = -1;
            if (N <= B) {
                answer = N;
            } else {
                N -= B;
                boolean done = false;
                while (!done) {
//                    System.out.println(Arrays.toString(m));
                    int newMin = 100001;
                    for (int i = 0; i < B; i++) {
                        if (m[i] == min) {
//                            System.out.printf("Barber %d finished\n", i + 1);
                            if (N == 1) {
                                answer = i + 1;
                                done = true;
                                break;
                            } else {
                                N--;
                                m[i] = M[i];
                            }
                        } else {
                            m[i] -= min;
                        }
                        if (m[i] < newMin) {
                            newMin = m[i];
                        }
                    }
                    min = newMin;
                }
            }

            output.printf("Case #%d: %d\n", t, answer);
            System.out.printf("Case #%d: %d\n", t, answer);
        }
    }

    private static int lcm(int[] arr) {
        if (arr.length < 2) {
            return arr[0];
        } else {
            int lcm = lcm(arr[0], arr[1]);
            for (int i = 2; i < arr.length; i++) {
                lcm = lcm(lcm, arr[i]);
            }
            return lcm;
        }
    }

    private static int lcm(int m, int n) {
        int lcm = (n == m || n == 1) ? m :(m == 1 ? n : 0);
        if (lcm == 0) {
           int mm = m, nn = n;
           while (mm != nn) {
               while (mm < nn) { mm += m; }
               while (nn < mm) { nn += n; }
           }
           lcm = mm;
        }
        return lcm;
    }

}
