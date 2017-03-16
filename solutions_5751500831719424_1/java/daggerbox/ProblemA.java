package com.forthgo.contest.g2014.r1b;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.*;


public class ProblemA {
    public static void main(String[] args) {
        try {
            Scanner in = new Scanner(new File("A.in.txt"));
            PrintWriter out = new PrintWriter(new FileWriter("A.out.txt"));
//            PrintWriter out = new PrintWriter(System.out);
            int n = in.nextInt();
            in.nextLine();
            for (int i = 0; i < n; i++) {
                out.printf("Case #%d: ", i + 1);
                solve(in, out);
                out.println();
                out.flush();
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }

    }

    private static void solve(Scanner in, PrintWriter out) {
        int N = in.nextInt();
        in.nextLine();
        char[] letter = new char[100];
        int[][] count = new int[N][100];
        boolean possible = true;
        int nLetter = 0;
        for (int i = 0; i < N; i++) {
            String s = in.nextLine();
            int k = -1;
            for (int j = 0; j < s.length(); j++) {
                if (j == 0 || s.charAt(j) != s.charAt(j - 1)) {
                    k++;
                    if (i == 0) {
                        letter[k] = s.charAt(j);
                    }
                    else if (letter[k] != s.charAt(j)) {
                        possible = false;
                    }
                }
                count[i][k]++;
            }
            if (i == 0)
                nLetter = k + 1;
            else if (nLetter != k + 1 && possible)
                possible = false;
//                throw new RuntimeException();
        }
        if (!possible) {
            out.print("Fegla Won");
            return;
        }
        int moves = 0;
        for (int k = 0; k < nLetter; k++) {
            int min = 0;
            int max = 0;
            for (int i = 0; i < N; i++) {
                min = Math.min(min, count[i][k]);
                max = Math.max(max, count[i][k]);
            }
            int best = 100;
            for (int target = min; target <= max; target++) {
                int cost = 0;
                for (int i = 0; i < N; i++) {
                    cost += Math.abs(count[i][k] - target);
                }
                if (cost < best) {
                    best = cost;
                }

            }
            moves += best;
        }
        out.print(moves);
    }

}

