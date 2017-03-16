package com.example;

import java.io.BufferedInputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

import static java.util.Arrays.deepToString;

public class solution {
    static PrintWriter out = null;
    static FileInputStream in = null;
    Scanner sc;

    byte[][] building;
    Integer R, C, N2;

    void read() {
        R = sc.nextInt();
        C = sc.nextInt();
        N2 = sc.nextInt();
    }

    int solve(boolean greed) {
        building = new byte[R][C];
        Integer N = N2;
        int row = 0, col = 0;
        while (N > 0) {
            N--;

            if (row < R) {
                if (col >= C) {
                    row++;
                    col = row % 2;
                    N++;
                    continue;
                }
                if ((row == 0 || row == R - 1) || (col == 0 || col == C - 1)) {
                    building[row][col] = 1;
                    col += 2;
                } else {
                    N++;
                    col += 2;
                }
                if (col >= C) {
                    row++;
                    col = row % 2;
                }
            } else {
                if (!greed) {
                    // dont greed :)
                    if (building[0][C - 1] == 0) {
                        building[0][C - 1] = 1;
                        continue;
                    }
                    if (building[R - 1][0] == 0) {
                        building[R - 1][0] = 1;
                        continue;
                    }
                    if (building[R - 1][C - 1] == 0) {
                        building[R - 1][C - 1] = 1;
                        continue;
                    }
                    boolean assigned = false;
                    for (int i = 0; i < C; i++) {
                        if (building[0][i] == 0) {
                            building[0][i] = 1;
                            assigned = true;
                            break;
                        }
                        if (building[R - 1][i] == 0) {
                            building[R - 1][i] = 1;
                            assigned = true;
                            break;
                        }
                    }
                    if (assigned) {
                        continue;
                    }
                    for (int i = 0; i < R; i++) {
                        if (building[i][0] == 0) {
                            building[i][0] = 1;
                            assigned = true;
                            break;
                        }
                        if (building[i][C - 1] == 0) {
                            building[i][C - 1] = 1;
                            assigned = true;
                            break;
                        }
                    }
                    if (assigned) {
                        continue;
                    }
                }
                int best = -1, temp, bestI = -1, bestJ = -1;
                for (int i = 0; i < R; i++) {
                    for (int j = 0; j < C; j++) {
                        if (building[i][j] == 0) {
                            building[i][j] = 1;
                            temp = unhappiness();
                            if (best == -1 || temp < best) {
                                best = temp;
                                bestI = i;
                                bestJ = j;
                            }
                            building[i][j] = 0;
                        }
                    }
                }
                building[bestI][bestJ] = 1;
            }
        }

        return unhappiness();
    }

    int unhappiness() {
        int solution = 0;
        for (int i = 0; i < R; i++) {
            boolean prev = false;
            for (int j = 0; j < C; j++) {
                if (building[i][j] == 1) {
                    if (prev) {
                        solution++;
                    }
                    prev = true;
                } else {
                    prev = false;
                }
            }
        }

        for (int i = 0; i < C; i++) {
            boolean prev = false;
            for (int j = 0; j < R; j++) {
                if (building[j][i] == 1) {
                    if (prev) {
                        solution++;
                    }
                    prev = true;
                } else {
                    prev = false;
                }
            }
        }
        return solution;
    }

    void output(int a) {
        out.println(a);
        System.out.println(a);
    }

    void run() {
        try {
            in = new FileInputStream("src/com/resources/smallInput.txt");
            out = new PrintWriter("src/com/resources/output.txt");
        } catch (FileNotFoundException e) {
            e.printStackTrace();  //To change body of catch statement use File | Settings | File Templates.
        }
        sc = new Scanner(in);
        int caseN = sc.nextInt();
        for (int caseID = 1; caseID <= caseN; caseID++) {
            read();
            out.printf("Case #%d: ", caseID);
            System.out.printf("Case #%d: ", caseID);
            int a = solve(true);
            int b = solve(false);
            if(a < b) output(a);
            else output(b);
            System.out.flush();
        }
        out.close();
    }

    void debug(Object... os) {
        System.err.println(deepToString(os));
    }

    public static void main(String[] args) {
        try {
            System.setIn(new BufferedInputStream(new FileInputStream(args.length > 0 ? args[0] : (solution.class.getName() + ".in"))));
        } catch (Exception e) {
        }
        new solution().run();
    }

    private static long gcd(long a, long b) {
        while (b > 0) {
            long temp = b;
            b = a % b; // % is remainder
            a = temp;
        }
        return a;
    }
}
