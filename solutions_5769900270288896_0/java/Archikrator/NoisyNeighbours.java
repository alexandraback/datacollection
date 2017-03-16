package google.codejam_2015;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class NoisyNeighbours {

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int t = s.nextInt();

        for (int i = 0; i < t; i++) {
            int r = s.nextInt();
            int c = s.nextInt();
            int n = s.nextInt();
            
            System.out.printf("Case #%d: %s%n", i + 1, solveNaive(r,c,n));
        }
    }

    private static int solveNaive(int r, int c, int n) {
        List<Pair> pairs = new ArrayList<Pair>(r * c);
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                pairs.add(new Pair(i, j));
            }
        }
        return combinations(pairs, new ArrayList<Pair>(), -1, n, r, c);


    }

    private static int combinations(List<Pair> pairs, List<Pair> chosen, int prevIdx, int n, int r, int c) {
        if (chosen.size() == n) {
            return evaluate(r, c, chosen);
        }
        int best = Integer.MAX_VALUE;
        for (int i = prevIdx + 1; i < pairs.size(); i++) {
            chosen.add(pairs.get(i));
            best = Math.min(best, combinations(pairs, chosen, i, n, r, c));
            chosen.remove(pairs.get(i));
        }
        return best;
    }

    private static int combinations(boolean[][] matrix, int prevRow, int prevCol, int trues, int n) {
        if (trues == n) {
            return evaluate(matrix);
        }
        int best = Integer.MAX_VALUE;
        for (int i = prevCol + 1; i < matrix[0].length; i++) {
            matrix[prevRow][i] = true;
            best = Math.min(best, combinations(matrix, prevRow, i, trues + 1, n));
            matrix[prevRow][i] = false;
        }

        for (int i = prevRow + 1; i < matrix.length; i++) {
            for (int j = 0; j < matrix[0].length; j++) {
                matrix[i][j] = true;
                best = Math.min(best, combinations(matrix, i, j, trues + 1, n));
                matrix[i][j] = false;
            }
        }
        return best;
    }

    private static int evaluate(int r, int c, List<Pair> chosen) {
        boolean[][] matrix = new boolean[r][c];
        for (Pair p : chosen) {
            matrix[p.x][p.y] = true;
        }
        return evaluate(matrix);
    }

    private static int evaluate(boolean[][] matrix) {
        int result = 0;
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[0].length; j++) {
                if (matrix[i][j] && i < matrix.length - 1 && matrix[i + 1][j]) {
                    result++;
                }
                if (matrix[i][j] && j < matrix[0].length - 1 && matrix[i][j + 1]) {
                    result++;
                }

            }
        }
        return result;
    }

    static class Pair {

        int x, y;

        public Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
}
