/*
 * Copyright (c) 2015. Made just for fun.
 */

package round1a;

import java.util.*;

/**
 * @author Tomik
 */
public class B {

    static class P {
        int idx;
        long time;

        public P(int idx, long time) {
            this.idx = idx;
            this.time = time;
        }
    }

    static long gcd(long a, long b) {
        if (b == 0) {
            return a;
        }
        if (b > a) {
            return gcd(b, a);
        }
        return gcd(b, a%b);
    }

    static long lcm(long a, long b) {
        return a*b / gcd(a,b);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for (int i = 1; i <= T; i++) {
            int B = sc.nextInt();
            long N = sc.nextLong();
            long[] M = new long[B];
            long maxb = 0;
            long[] st = new long[B];
            long[] per = new long[B];
            long perc = 0;
            for (int j = 0; j < B; j++) {
                M[j] = sc.nextLong();
                maxb = Math.max(maxb, M[j]);
            }

            Queue<P> queue = new PriorityQueue<P>(B, new Comparator<P>() {
                @Override
                public int compare(P o1, P o2) {
                    long dt = o1.time - o2.time;
                    if (dt < 0) {
                        return -1;
                    } if (dt > 0) {
                        return 1;
                    }
                    return o1.idx - o2.idx;
                }
            });

            for (int j = 0; j < B; j++) {
                queue.add(new P(j, 0));
            }


            long l = 1;
            for (int j = 0; j < B; j++) {
                l = lcm(l, M[j]);
            }


            long t = 0;
            for (int j = 0; j < B; j++) {
                t += l/M[j];
            }
            N %= t;
            if (N == 0) {
                N = t;
            }

            for (long j = 1; j < N; j++) {
                P curr = queue.poll();
                curr.time += M[curr.idx];
                queue.add(curr);
            }

            int mb = queue.poll().idx;
            System.out.println("Case #" + i + ": " + (mb+1));
        }
    }
}
