package com.company;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader("A-small-attempt3.in"));
        StringTokenizer tokens = new StringTokenizer(in.readLine());
        PrintWriter out = new PrintWriter("A-small-attempt3.out");
        int t = Integer.parseInt(tokens.nextToken());
        for (int tt = 1; tt <= t; tt++) {
            tokens = new StringTokenizer(in.readLine());
            int n = Integer.parseInt(tokens.nextToken());
            String[] strings = new String[n];
            for (int i = 0; i < n; i++) {
                strings[i] = in.readLine();
            }
            int[] start = new int[n];
            int[] amount = new int[n];
            for (int i = 0; i < n; i++) {
                start[i] = 0;
                amount[i] = 0;
            }
            boolean gameOver = false;
            int answer = 0;
            while (!gameOver) {
                gameOver = start[0] == strings[0].length();
                if (!gameOver) {
                    char c = strings[0].charAt(start[0]);
                    amount[0] = 0;
                    while (start[0] < strings[0].length() && strings[0].charAt(start[0]) == c) {
                        start[0]++;
                        amount[0]++;
                    }
                    for (int i = 1; i < n; i++) {
                        gameOver |= start[i] == strings[i].length() || strings[i].charAt(start[i]) != c;
                        if (!gameOver) {
                            amount[i] = 0;
                            while (start[i] < strings[i].length() && strings[i].charAt(start[i]) == c) {
                                start[i]++;
                                amount[i]++;
                            }
                        }
                    }
                    if (!gameOver) {
                        int min = 0;
                        for (int i = 0; i < n; i++) {
                            min += amount[i] - 1;
                        }
                        for (int left = 2; left <= 100; left++) {
                            int cur = 0;
                            for (int i = 0; i < n; i++) {
                                cur += Math.abs(amount[i] - left);
                            }
                            if (cur < min) {
                                min = cur;
                            }
                        }
                        answer += min;
                    }
                }
            }
            boolean goodGameOver = true;
            for (int i = 0; i < n; i++) {
                goodGameOver &= start[i] == strings[i].length() && strings[i].charAt(strings[i].length() - 1) == strings[0].charAt(strings[0].length() - 1);
            }
            out.print("Case #" + tt +": ");
            if (goodGameOver) {
                out.println(answer);
            } else {
                out.println("Fegla Won");
            }
        }
        in.close();
        out.close();
    }
}
