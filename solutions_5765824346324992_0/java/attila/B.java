package de.jaki.codejam.two015.round1.A;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.TreeSet;

public class B {
    private static final String PATTERN = "CASE #%d: %s";
    private static final String PROBLEM = "B";

    //private static final String NAME = PROBLEM + ".in";
    private static final String NAME = PROBLEM+"-small-attempt0.in";
    //private static final String NAME = PROBLEM+"-large.in";
    //private static final String OUT = PROBLEM + ".out";
    private static final String OUT = PROBLEM+"-small-attempt0.out";
    //private static final String OUT = PROBLEM+"-large.out";

    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(new File(NAME));
        PrintWriter pw = new PrintWriter(OUT);
        int testCount = sc.nextInt();
        sc.nextLine();
        for (int i = 0; i < testCount; i++) {
            String sol = solve(sc);
            System.out.println(String.format(PATTERN, i + 1, sol));
            pw.println(String.format(PATTERN, i + 1, sol));
        }
        pw.flush();
        pw.close();
    }

    private static String solve(Scanner sc) {
        int b = sc.nextInt();
        long n = sc.nextLong();
        int[] t = new int[b];
        BigInteger[] t2 = new BigInteger[b];
        for (int i = 0; i < b; i++) {
            t[i] = sc.nextInt();
            t2[i] = new BigInteger("" + t[i]);
        }
        return "" + solve2(n, t, t2);
    }

    private static long orderFor(long maxTime, int[] t, BigInteger[] t2) {
        long rez = 0;
        for (int x : t) {
            rez += maxTime / x;
        }
        return rez;
    }

    private static Integer solve2(long n, int[] t, BigInteger[] t2) {
        long maxTime = Long.parseLong("10000000000000000");
        long c = 0;
        while (true) {
            long curr = orderFor(maxTime, t, t2);
            if (curr < n && curr + 100000 >= n) {
                c = curr;
                break;
            } else if (curr < n) {
                maxTime += 50000;
            } else {
                maxTime /= 2;
            }
        }

        //System.out.println("use: " + maxTime);

        TreeSet<X> next = new TreeSet<X>();
        for (int i = 0; i < t.length; i++) {
            long nextBest = (maxTime / t[i]);
            next.add(new X(new BigInteger("" + (nextBest * t[i])), i));
        }
        return solve6(n, t2, next, c);
    }

    private static Integer solve6(long n, BigInteger[] t2, TreeSet<X> next, long c) {
        while (c++ <= n) {
           // System.out.println(next);
            X now = next.pollFirst();
            if (c == n) {
                return now.getId() + 1;
            }
            next.add(new X(now.getTime().add(t2[now.getId()]), now.getId()));
        }
        throw new RuntimeException();
    }

    private static class X implements Comparable<X> {
        private BigInteger time;
        private Integer id;

        public X(BigInteger time, int id) {
            this.time = time;
            this.id = id;
        }


        @Override
        public int compareTo(X o) {
            int r0 = time.compareTo(o.time);
            if (r0 == 0) return id.compareTo(o.id);
            else return r0;
        }

        public BigInteger getTime() {
            return time;
        }

        public Integer getId() {
            return id;
        }

        @Override
        public String toString() {
            return id.toString() + " " + time;
        }
    }
}
