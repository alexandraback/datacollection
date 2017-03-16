package com.google.codejam2015.round1b;

import java.io.BufferedReader;
import java.io.Closeable;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;
import java.util.concurrent.atomic.AtomicInteger;
import java.util.concurrent.atomic.AtomicReferenceArray;

public class NoisyNeighbors implements Closeable {
    BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter writer = new PrintWriter(System.out);
    private final Object readLock = new Object();

    NoisyNeighbors() throws IOException {
        reader = new BufferedReader(new FileReader("input.txt"));
        writer = new PrintWriter(new FileWriter("output.txt"));
    }

    StringTokenizer stringTokenizer;

    String next() throws IOException {
        synchronized (readLock) {
            while (stringTokenizer == null || !stringTokenizer.hasMoreTokens()) {
                stringTokenizer = new StringTokenizer(reader.readLine());
            }
            return stringTokenizer.nextToken();
        }
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    void run() throws IOException, InterruptedException {
        final int testsNumber = nextInt();
        final AtomicReferenceArray<String> answers = new AtomicReferenceArray<>(testsNumber);
        final AtomicInteger currentTest = new AtomicInteger(-1);
        abstract class Solver implements Runnable {
            @Override
            public final void run() {
                int testNumber;
                synchronized (readLock) {
                    testNumber = currentTest.incrementAndGet();
                    try {
                        readInput();
                    } catch (IOException e) {
                        throw new RuntimeException(e);
                    }
                }
                answers.set(testNumber, solve());
                System.out.println("Test " + testNumber + " complete");
            }

            abstract protected String solve();

            abstract protected void readInput() throws IOException;
        }
        final int availableProcessors = Runtime.getRuntime().availableProcessors();
        System.out.println("Number of available processors: " + availableProcessors);
        final ExecutorService executorService = Executors.newFixedThreadPool(availableProcessors + 1);
        for(int i = 0; i < testsNumber; i++) {
            executorService.execute(new Solver() {
                int R, C, N;

                int naive() {
                    int ret = R * (C - 1) + C * (R - 1);
                    int[] d = {-1, 0, 1, 0};
                    for(int mask = 0; mask < 1 << (R * C); mask++) {
                        if(Integer.bitCount(mask) != N) {
                            continue;
                        }
                        int[][] a = new int[R + 2][C + 2];
                        int ix = 0;
                        for(int r = 1; r <= R; r++) {
                            for(int c = 1; c <= C; c++) {
                                a[r][c] = (mask >> ix++) % 2;
                            }
                        }
                        int u = 0;
                        for(int r = 1; r <= R; r++) {
                            for(int c = 1; c <= C; c++) {
                                if(a[r][c] == 1) {
                                    for(int k = 0; k < 4; k++) {
                                        if(a[r + d[k]][c + d[k + 1 & 3]] == 1) {
                                            u++;
                                        }
                                    }
                                }
                            }
                        }
                        ret = Math.min(ret, u / 2);
                    }
                    return ret;
                }

                @Override
                protected String solve() {
                    class Utils {
                        int valid(int r, int c) {
                            return r >= 0 && r < R && c >= 0 && c < C ? 1 : 0;
                        }

                        int countNeighbors(int r, int c) {
                            int[] d = {0, -1, 0, 1};
                            int nc = 0;
                            for(int i = 0; i < 4; i++) {
                                nc += valid(r + d[i], c + d[i + 1 & 3]);
                            }
                            return nc;
                        }

                        int solve(int diag, int empty) {
                            List<Integer> h = new ArrayList<>();
                            for(int i = 0; i < R; i++) {
                                for(int j = 0; j < C; j++) {
                                    if((i + j) % 2 == diag) {
                                        h.add(countNeighbors(i, j));
                                    }
                                }
                            }
                            Collections.sort(h, Collections.reverseOrder());
                            int unhappiness = R * (C - 1) + C * (R - 1);
                            if(unhappiness == 0) {
                                return 0;
                            }
                            if(empty >= h.size()) {
                                return 0;
                            }
                            for(int i = 0; i < empty; i++) {
                                unhappiness -= h.get(i);
                            }
                            return unhappiness;
                        }
                    }
                    Utils utils = new Utils();
                    int answer = Math.min(utils.solve(0, R * C - N), utils.solve(1, R * C - N));
                   /* if(answer != naive()) {
                        System.out.println(String.format("Wrong for R = %d, C = %d, N = %d", R, C, N));
                    } */
                    return Integer.toString(answer);
                }

                @Override
                protected void readInput() throws IOException {
                    R = nextInt();
                    C = nextInt();
                    N = nextInt();
                }
            });
        }
        executorService.shutdown();
        executorService.awaitTermination(10, TimeUnit.MINUTES);
        for(int i = 0; i < testsNumber; i++) {
            writer.println(String.format("Case #%d: %s", i + 1, answers.get(i)));
        }
    }

    public static void main(String[] args) throws IOException, InterruptedException {
        try(NoisyNeighbors a = new NoisyNeighbors()) {
            a.run();
        }
    }

    @Override
    public void close() throws IOException {
        reader.close();
        writer.close();
    }
}
