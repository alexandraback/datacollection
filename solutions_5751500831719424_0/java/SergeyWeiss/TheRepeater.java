package com.google.codejam2014.round1b;

import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class TheRepeater {
    BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter writer = new PrintWriter(System.out);
    StringTokenizer stringTokenizer;

    TheRepeater() throws IOException {
        reader = new BufferedReader(new FileReader("input.txt"));
        writer = new PrintWriter(new FileWriter("output.txt"));
    }

    String next() throws IOException {
        while (stringTokenizer == null || !stringTokenizer.hasMoreTokens()) {
            stringTokenizer = new StringTokenizer(reader.readLine());
        }
        return stringTokenizer.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }

    void solveTestCase(int testNumber) throws IOException {
        writer.printf("Case #%d: ", testNumber);
        int n = nextInt();
        String[] s = new String[n];
        for(int i = 0; i < n; i++) {
            s[i] = next();
        }
        String lose = "Fegla Won";
        int ans = 0;
        while(s[0].length() != 0) {
            char c = s[0].charAt(0);
            int[] q = new int[n];
            for(int i = 0; i < n; i++) {
                while(q[i] < s[i].length() && c == s[i].charAt(q[i])) {
                    q[i]++;
                }
                if(q[i] == 0) {
                    writer.println(lose);
                    return;
                }
                s[i] = s[i].substring(q[i]);
            }
            int maxq = 1;
            for(int x : q) {
                maxq = Math.max(maxq, x);
            }
            int t = Integer.MAX_VALUE;
            for(int k = 1; k <= maxq; k++) {
                int sum = 0;
                for(int x : q) {
                    sum += Math.abs(x - k);
                }
                t = Math.min(t, sum);
            }
            ans += t;
        }
        for(String t : s) {
            if(!"".equals(t)) {
                writer.println(lose);
                return;
            }
        }
        writer.println(ans);
    }

    void solve() throws IOException {
        int testsNumber = nextInt();
        for(int i = 1; i <= testsNumber; i++) {
            solveTestCase(i);
        }
        writer.close();
    }

    public static void main(String[] args) throws IOException {
        new TheRepeater().solve();
    }
}
