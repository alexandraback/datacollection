package com.google.codejam2014.qual;

import java.io.*;
import java.util.*;

public class MagicTrick {
    BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter writer = new PrintWriter(System.out);
    StringTokenizer stringTokenizer;

    MagicTrick() throws IOException {
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

    int[] getRow(int row) throws IOException {
        int[][] a = new int[4][4];
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                a[i][j] = nextInt();
            }
        }
        return a[row - 1];
    }

    void solveTestCase(int testNumber) throws IOException {
        writer.printf("Case #%d: ", testNumber);
        Set<Integer> s = new HashSet<>();
        for(int x : getRow(nextInt())) {
            s.add(x);
        }
        List<Integer> answer = new ArrayList<>();
        for(int x : getRow(nextInt())) {
            if(s.contains(x)) {
                answer.add(x);
            }
        }
        writer.println(answer.isEmpty() ? "Volunteer cheated!" : answer.size() > 1 ? "Bad magician!" : answer.get(0));
    }

    void solve() throws IOException {
        int testsNumber = nextInt();
        for(int i = 1; i <= testsNumber; i++) {
            solveTestCase(i);
        }
        writer.close();
    }

    public static void main(String[] args) throws IOException {
        new MagicTrick().solve();
    }
}
