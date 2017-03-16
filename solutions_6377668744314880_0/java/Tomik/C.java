/*
 * Copyright (c) 2015. Made just for fun.
 */

package round1a;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

/**
 * @author Tomik
 */
public class C {

    static class Point implements Comparable<Point> {
        long x, y;
        int idx;

        public Point(long x, long y, int idx) {
            this.x = x;
            this.y = y;
            this.idx = idx;
        }

        public int compareTo(Point p) {
            if (this.x == p.x) {
                long dy = this.y - p.y;
                if (dy < 0) {
                    return -1;
                } else if (dy > 0) {
                    return 1;
                }
                return 0;
            } else {
                long dx = this.x - p.x;
                if (dx < 0) {
                    return -1;
                } else if (dx > 0) {
                    return 1;
                }
                return 0;
            }
        }

    }

    public static long cross(Point O, Point A, Point B) {
        return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
    }

    public static Point[] convexHull(Point[] P) {
        if (P.length > 1) {
            int n = P.length, k = 0;
            Point[] H = new Point[2 * n];

            Arrays.sort(P);

            // Build lower hull
            for (int i = 0; i < n; ++i) {
                while (k >= 2 && cross(H[k - 2], H[k - 1], P[i]) < 0)
                    k--;
                H[k++] = P[i];
            }

            // Build upper hull
            for (int i = n - 2, t = k + 1; i >= 0; i--) {
                while (k >= t && cross(H[k - 2], H[k - 1], P[i]) < 0)
                    k--;
                H[k++] = P[i];
            }
            if (k > 1) {
                H = Arrays.copyOfRange(H, 0, k - 1);
            }
            return H;
        } else if (P.length <= 1) {
            return P;
        } else{
            return null;
        }
    }

    static int N;
    static int[] mins;

    static void compute(int k, Point[] points, List<Point> lp) {
        if (k == N) {
            Point[] pp = lp.toArray(new Point[lp.size()]);
            Point[] ch = convexHull(pp);
            for (int i = 0; i < ch.length; i++) {
                mins[ch[i].idx] = Math.min(mins[ch[i].idx], N - pp.length);
            }
            return;
        }

        List<Point> nlp = new ArrayList<Point>(lp);
        compute(k+1, points, nlp);

        nlp = new ArrayList<Point>(lp);
        nlp.add(points[k]);
        compute(k + 1, points, nlp);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for (int i = 1; i <= T; i++) {
            N = sc.nextInt();
            long[] X = new long[N];
            long[] Y = new long[N];
            Point[] points = new Point[N];
            for (int j = 0; j < N; j++) {
                X[j] = sc.nextLong();
                Y[j] = sc.nextLong();
                points[j] = new Point(X[j], Y[j], j);
            }
            mins = new int[N];
            Arrays.fill(mins, N);

            compute(0, points, new ArrayList<Point>());


            System.out.println("Case #" + i + ":");
            for (int j = 0; j < N; j++) {
                System.out.println(mins[j]);
            }
        }
    }
}
