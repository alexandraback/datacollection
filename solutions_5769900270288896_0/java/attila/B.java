package de.jaki.codejam.two015.round1.B;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.*;

public class B {
    private static final String PATTERN = "CASE #%d: %s";
    private static final String PROBLEM = "B";

    //private static final String NAME = PROBLEM + ".in";
    private static final String NAME = PROBLEM+"-small-attempt0.in";
    //private static final String NAME = PROBLEM+"-large.in";
    //private static final String OUT = PROBLEM + ".out";
    private static final String OUT = PROBLEM+"-small-attempt0.out";
    //private static final String OUT = PROBLEM+"-large.out";

    private static Map<List<Boolean>, Integer> cache = new HashMap<>();

    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(new File(NAME));
        PrintWriter pw = new PrintWriter(OUT);
        int testCount = sc.nextInt();
        for (int i = 0; i < testCount; i++) {
            String sol = solve(sc);
            System.out.println(String.format(PATTERN, i + 1, sol));
            pw.println(String.format(PATTERN, i + 1, sol));
        }
        pw.flush();
        pw.close();
    }

    private static String solve(Scanner sc) {
        cache.clear();
        int r = sc.nextInt();
        int c = sc.nextInt();
        int n = sc.nextInt();
        return "" + solve2(r, c, n);
    }

    private static int solve2(int r, int c, int n) {
        if (n * 2 <= r * c) {
            return 0;
        }
        if (r % 2 == 1 && c % 2 == 1) {
            if (n <= (r * c / 2 + 1)) {
                return 0;
            }
        }

        boolean[][] empty = new boolean[r][c];
        return calc(empty, r * c, n);
    }

    private static int calc(boolean[][] empty, int total, int n) {
        if (total == n) {
            return badCount(empty);
        }
        List<Boolean> ser = seri(empty);
        if (cache.containsKey(ser)) {
            return cache.get(ser);
        }
        int min = 99999999;
        for (int i = 0; i < empty.length * empty[0].length; i++) {
            int r0 = i / empty[0].length;
            int c0 = i % empty[0].length;
            boolean[][] e2 = copy(empty);
            if (e2[r0][c0]) {
                continue;
            }
            e2[r0][c0] = true;
            min = Math.min(min, calc(e2, total - 1, n));
        }
        cache.put(ser, min);
        return min;
    }

    private static List<Boolean> seri(boolean[][] empty) {
        List<Boolean> list = new ArrayList<>();
        for (int i = 0; i < empty.length; i++) {
            for (int j = 0; j < empty[0].length; j++) {
                list.add(empty[i][j]);
            }
        }
        return list;
    }

    private static int badCount(boolean[][] empty) {
        int total = 0;
        for (int i = 0; i < empty.length; i++) {
            for (int j = 0; j < empty[0].length; j++) {
                if (empty[i][j]) {
                    continue;
                }
                if (i > 0 && !empty[i - 1][j]) {
                    total++;
                }
                if (j > 0 && !empty[i][j - 1]) {
                    total++;
                }
                if (i < empty.length - 1 && !empty[i + 1][j]) {
                    total++;
                }
                if (j < empty[0].length - 1 && !empty[i][j + 1]) {
                    total++;
                }
            }
        }
        return total / 2;
    }

    private static boolean[][] copy(boolean[][] empty) {
        boolean[][] x = new boolean[empty.length][empty[0].length];
        for (int i = 0; i < empty.length; i++) {
            x[i] = Arrays.copyOf(empty[i], empty[i].length);
        }
        return x;
    }
}
