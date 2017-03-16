package codejam.v2015;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class R1AB {

    public static void main(String args[]) {

        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        for (int t = 1; t <= T; t++) {

            final int B = in.nextInt();
            final long N = in.nextInt();

            int[] M = new int[B];

            int max = 0;

            for(int i = 0; i < B; i++) {
                M[i] = in.nextInt();
                if(M[i] > max) {
                    max = M[i];
                }
            }

            long m = N * (max / B + 1);
            int x = find(B, M, N, 0, m);

            System.out.format("Case #%d: %d\n", t, x);
        }
    }

    public static int find(int B, int[] M, long N, long min, long max) {
        if (max < min) {
            // error...
            return 0;
        }

        long mid = (min + max) / 2;

        long served = 0;
        List<Integer> serving = new ArrayList<>();
        for (int i = 0; i < B; i++) {
            long c = (mid - 1) / M[i] + 1;
            served += c;
            if (mid % M[i] == 0) {
                // the i-th barker is serving
                serving.add(i);
            }
            // mid is too low, served too much
            if (N <= served) {
                break;
            }
        }

        long upper = served + serving.size();
        if (N > served && N <= upper) {
            // found
            int index = new Long(N - served - 1).intValue();
            return serving.get(index) + 1;
        } else if (N <= served) {
            return find(B, M, N, min, mid - 1);
        } else {
            return find(B, M, N, mid + 1, max);
        }
    }

}




