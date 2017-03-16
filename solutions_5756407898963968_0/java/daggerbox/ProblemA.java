package com.forthgo.contest.g2014r0;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
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
        int r1 = in.nextInt();
        Set<Integer> s1 = new HashSet<>();
        for (int i = 0; i < (r1 - 1) * 4; i++) {
            in.nextInt();
        }
        for (int i = 0; i < 4; i++) {
            int k = in.nextInt();
            s1.add(k);
        }
        for (int i = 0; i < 16 - (r1 - 1) * 4 - 4; i++) {
            in.nextInt();
        }
        int r2 = in.nextInt();
        Set<Integer> s2 = new HashSet<>();
        for (int i = 0; i < (r2 - 1) * 4; i++) {
            in.nextInt();
        }
        for (int i = 0; i < 4; i++) {
            int k = in.nextInt();
            s2.add(k);
        }
        for (int i = 0; i < 16 - (r2 - 1) * 4 - 4; i++) {
            in.nextInt();
        }
        s1.retainAll(s2);
        if (s1.size() == 1)
            out.print(s1.iterator().next());
        else if (s1.size() == 0)
            out.print("Volunteer cheated!");
        else
            out.print("Bad magician!");
    }

}

