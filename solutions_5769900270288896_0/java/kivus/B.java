import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.PriorityQueue;
import java.util.Scanner;

/**
 *
 *
 */
public class B {
    public static void main(String[] args) {
         try {
             Scanner scanner = (new Scanner(new File("c:/users/rafal/ideaprojects/src/Bin.txt")));


             FileOutputStream out = new FileOutputStream("c:/users/rafal/ideaprojects/src/Bout.txt");

             int numberOfCases;
             numberOfCases = scanner.nextInt();
             scanner.nextLine();

             PrintWriter wr = new PrintWriter(out);
             for (int i = 0; i < numberOfCases; i++) {
                 doCase(i + 1, scanner, wr);
                 if (i < numberOfCases - 1)
                    scanner.nextLine();
             }
             wr.close();
             out.close();

         } catch (IOException e) {
             System.out.println("Error: " + e);
         }
     }

    private static void doCase(int caseNumber, Scanner scanner, PrintWriter wr) {
        int r, c, n;
        r = scanner.nextInt();
        c = scanner.nextInt();
        n = scanner.nextInt();
        if (r < c) {
            int cc = c;
            c = r;
            r = cc;
        }

        int result = solve(r, c, n);

        wr.println("Case #" + caseNumber + ": " + result);
        System.out.println("Case #" + caseNumber + ": " + result);
        // ...

    }

    private static int solve(int r, int c, int n) {
        int [][]i = new int[r][c];

//        int minUhnappy = Integer.MAX_VALUE;

        return solve2(i, r, c, n, 0, 0);
    }

    private static int solve2(int[][] b, int r, int c, int n, int ii, int jj) {
        if (n > 0) {
            int minUnhappy = Integer.MAX_VALUE;
            for (int i = ii; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    if (b[i][j] == 0) {
                        b[i][j] = 1;
                        int v = solve2(b, r, c, n-1, i, 0);
                        if (v < minUnhappy) {
                            minUnhappy = v;
                        }
                        b[i][j] = 0;
                    }
                }
            }
            return minUnhappy;
        } else {
            return getUnhappy(b, r, c);
        }
    }


    private static int getUnhappy(int [][]b, int r, int c) {
        int unhappy = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (b[i][j] == 1) {
                    if (j > 0) {
                        // check unhappy back
                        if (b[i][j-1] == 1) {
                            unhappy++;
                        }
                    }
                    if (i > 0) {
                        if (b[i-1][j] == 1) {
                            unhappy++;
                        }
                    }
                }
            }
        }
        return unhappy;
    }


}