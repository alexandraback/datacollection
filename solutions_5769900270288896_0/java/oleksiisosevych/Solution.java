package B;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Scanner;

public class Solution {
    public void doMain() throws Exception {
        Scanner sc = new Scanner(new FileReader("input.txt"));
        PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));

        int caseCnt = sc.nextInt();

        for (int caseNum = 0; caseNum < caseCnt; caseNum++) {
            pw.print("Case #" + (caseNum + 1) + ": ");

            int R = sc.nextInt();
            int C = sc.nextInt();
            int N = sc.nextInt();

            int dir_x[] = {1, 0, 0, -1};
            int dir_y[] = {0, 1, -1, 0};

            boolean[][] board = new boolean[R][C];
            int[][] unhappy = new int[R][C];
            for (int i = 0; i < R; i++) {
                for (int j = 0; j < C; j++) {
                    int unh = 0;
                    for (int d = 0; d < 4; d++) {
                        int newx = i + dir_x[d];
                        int newy = j + dir_y[d];
                        if (newx >= 0 && newx < R && newy >= 0 && newy < C) {
                            unh++;
                        }
                    }
                    unhappy[i][j] = unh;

                }
            }

            int needToRemove = R * C - N;

            while (needToRemove >= 4) {
                int x = -1;
                int y = -1;
                for (int i = 0; i < R; i++) {
                    for (int j = 0; j < C; j++) {
                        if (unhappy[i][j] == 4) {
                            x = i;
                            y = j;
                        }
                    }
                }
                if (x == -1) break;

                for (int dd = 0; dd < 4; dd++) {
                    int xx = x + dir_x[dd];
                    int yy = y + dir_y[dd];
                    unhappy[xx][yy] = 0;
                    for (int d = 0; d < 4; d++) {
                        int newx = xx + dir_x[d];
                        int newy = yy + dir_y[d];
                        if (newx >= 0 && newx < R && newy >= 0 && newy < C && unhappy[newx][newy] > 0) {
                            unhappy[newx][newy]--;
                        }
                    }
                }
                needToRemove -= 4;

            }

            for (int count = 0; count < needToRemove; count++) {
                int maxUnh = -1;
                int maxx = -1;
                int maxy = -1;
                for (int i = 0; i < R; i++) {
                    for (int j = 0; j < C; j++) {
                        if (unhappy[i][j] > maxUnh) {
                            maxUnh = unhappy[i][j];
                            maxx = i;
                            maxy = j;
                        }
                    }
                }

                unhappy[maxx][maxy] = 0;
                for (int d = 0; d < 4; d++) {
                    int newx = maxx + dir_x[d];
                    int newy = maxy + dir_y[d];
                    if (newx >= 0 && newx < R && newy >= 0 && newy < C && unhappy[newx][newy] > 0) {
                        unhappy[newx][newy]--;
                    }
                }
            }

            int sum = 0;

            for (int i = 0; i < R; i++) {
                for (int j = 0; j < C; j++) {
                    if (unhappy[i][j] > 0) {
                        for (int d = 0; d < 2; d++) {
                            int newx = i + dir_x[d];
                            int newy = j + dir_y[d];
                            if (newx >= 0 && newx < R && newy >= 0 && newy < C && unhappy[newx][newy] > 0) {
                                sum++;
                            }
                        }
                    }
                }
            }

            pw.println(sum);

        }

        pw.flush();
        pw.close();
        sc.close();
    }

    public static void main(String[] args) throws Exception {
        new Solution().doMain();
    }
}