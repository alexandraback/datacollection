import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;


public class Solution {
    public static void main(String args[]) throws FileNotFoundException {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(new File("/Users/ebogdanov/Downloads/output"));
        int T = in.nextInt();
        int i, j, k;
        for (int curTest = 1; curTest <= T; curTest++) {
            int answer1 = in.nextInt() - 1;
            int[][] board1 = new int[4][4];
            for (i = 0; i < 4; i++) {
                for (j = 0; j < 4; j++) {
                    board1[i][j] = in.nextInt();
                }
            }
            int answer2 = in.nextInt() - 1;
            int[][] board2 = new int[4][4];
            for (i = 0; i < 4; i++) {
                for (j = 0; j < 4; j++) {
                    board2[i][j] = in.nextInt();
                }
            }

            int ans = -1;
            for (k = 1; k <= 16; k++) {
                if (find(k, board1) == answer1 && find(k, board2) == answer2) {
                    if (ans == -1) {
                        ans = k;
                    } else {
                        ans = -2;
                    }
                }
            }

            out.print("Case #" + curTest + ": ");
            if (ans == -1) {
                out.println("Volunteer cheated!");
            } else if (ans == -2) {
                out.println("Bad magician!");
            } else {
                out.println(ans);
            }
        }
        out.close();
    }

    private static int find(int num, int[][] board) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (board[i][j] == num) {
                    return i;
                }
            }
        }

        return -1;
    }
}