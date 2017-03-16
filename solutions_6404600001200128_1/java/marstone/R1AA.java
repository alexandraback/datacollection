package codejam.v2015;

import java.util.Scanner;

public class R1AA {

    public static void main(String args[]) {

        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        for (int t = 1; t <= T; t++) {

            final int N = in.nextInt();
            int[] remains = new int[N];

            int max = 0;

            int m1 = 0;
            int m2 = 0;

            for(int i = 0; i < N; i++) {
                remains[i] = in.nextInt();
                if(i > 0) {
                    int sub = remains[i - 1] - remains[i];
                    if(sub > max) {
                        max = sub;
                    }
                    if(sub > 0) {
                        m1 += sub;
                    }
                }
            }

            for(int i = 0; i < N - 1; i++) {
                int eat = Math.min(max, remains[i]);
                m2 += eat;
            }

            System.out.format("Case #%d: %d %s\n", t, m1, m2);
        }
    }

}
