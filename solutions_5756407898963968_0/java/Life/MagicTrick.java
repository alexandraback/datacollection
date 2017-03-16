package codejam2014;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class MagicTrick {
    public static void main(String[] args) throws IOException {

        String fileName;

        fileName = "A-small-attempt0.in";

        try (BufferedReader r = new BufferedReader(new FileReader(fileName));
             BufferedWriter w = new BufferedWriter(new FileWriter(fileName.replace(".in", ".out")));) {
            Scanner s = new Scanner(r);
            int T = s.nextInt();
            long startTotal = System.currentTimeMillis();
            for (int i = 0; i < T; i++) {
                int ans1 = s.nextInt();
                int[][] board1 = readBoard(s);
                int ans2 = s.nextInt();
                int[][] board2 = readBoard(s);

                w.write("Case #" + (i + 1) + ": " + calc(ans1, board1, ans2, board2) +"\n");
                System.out.println("case " + +(i + 1) + ". time: " + (System.currentTimeMillis() - startTotal));
            }
            System.out.println("Total time: " + (System.currentTimeMillis() - startTotal));
        }

    }

    private static int[][] readBoard(Scanner s) {
        int[][] board = new int[4][4];
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                board[j][k] = s.nextInt();
            }
        }
        return board;
    }

    private static String calc(int ans1, int[][] board1, int ans2, int[][] board2) {
        int[] cand1 = board1[ans1-1];
        int[] cand2 = board2[ans2-1];


        int res = -1;
        int count = 0;
        for (int i = 0; i < cand1.length; i++) {
            for (int j = 0; j < cand2.length; j++) {
                if(cand1[i] == cand2[j]) {
                    res = cand1[i];
                    count++;
                }
            }
        }
        if(count == 1) {
            return  "" + res;
        } else if(count == 0)  {
            return "Volunteer cheated!";
        } else {
            return "Bad magician!";
        }
    }
}
