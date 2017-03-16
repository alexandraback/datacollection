package contest;

import java.util.*;
import java.io.*;
import java.math.*;

public class MagicTrick {
    final static String PROBLEM_NAME = "magic";
    final static String WORK_DIR = "D:\\GCJ\\" + PROBLEM_NAME + "\\";

    void solve(Scanner sc, PrintWriter pw) {
        int row1 = sc.nextInt() - 1;
        int[][] data1 = new int[4][4];
        int[][] data2 = new int[4][4];
        for (int i=0; i<4; i++) {
            for (int j=0; j<4; j++) {
                data1[i][j] = sc.nextInt();
            }
        }
        int row2 = sc.nextInt() - 1;
        for (int i=0; i<4; i++) {
            for (int j=0; j<4; j++) {
                data2[i][j] = sc.nextInt();
            }
        }
        int ans = -1, cnt = 0;
        for (int x = 1; x <= 16; x++) {
            boolean find1 = false, find2 = false;
            for (int i=0; i<4; i++) {
                if (data1[row1][i] == x) {
                    find1 = true;
                }
                if (data2[row2][i] == x) {
                    find2 = true;
                }
            }
            if (find1 && find2) {
                cnt++;
                ans = x;
            }
        }
        if (cnt == 0) {
            pw.println("Volunteer cheated!");
        } else if (cnt > 1) {
            pw.println("Bad magician!");
        } else {
            pw.println(ans);
        }
    }

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new FileReader(WORK_DIR + "input.txt"));
        PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + "output.txt"));
        int caseCnt = sc.nextInt();
        for (int caseNum=0; caseNum<caseCnt; caseNum++) {
            System.out.println("Processing test case " + (caseNum + 1));
            pw.print("Case #" + (caseNum+1) + ": ");
            new MagicTrick().solve(sc, pw);
        }
        pw.flush();
        pw.close();
        sc.close();
    }
}
