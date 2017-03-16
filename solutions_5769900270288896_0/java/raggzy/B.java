package codejam.y2015.round1b;

import codejam.template.Runner;
import codejam.template.Solver;

import java.io.PrintStream;
import java.util.LinkedList;
import java.util.Scanner;

/**
 * Created by bistrashkin on 5/2/15.
 */
public class B extends Solver {
    public B(Scanner in, PrintStream out, int TC) {
        super(in, out, TC);
    }

    private static class Cell {
        int x;
        int y;

        private Cell(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    @Override
    public void solve() {
        int R = in.nextInt();
        int C = in.nextInt();
        int N = in.nextInt();
        int allCombinations = 1 << (R * C);
        int result = Integer.MAX_VALUE;
        for (int comb = 0; comb < allCombinations; comb++) {
            boolean[][] hasGuy = new boolean[R][C];
            int count = 0;
            for (int i = 0; i < R * C; i++) {
                // i - is ok
                if (((1 << i) & comb) > 0) {
                    int x = i % R;
                    int y = i / R;
                    hasGuy[x][y] = true;
                    count++;
                }
            }
            if (count == N) {
                int unhappiness = countUnhappiness(R, C, hasGuy);
                if (unhappiness < result) {
                    result = unhappiness;
                }
            }
        }
        println("Case #%d: %d", TC, result);
    }

    private static int countUnhappiness(int r, int c, boolean[][] hasGuy) {
        int unhappiness = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (hasGuy[i][j]) {
                    if ((i + 1 < r) && hasGuy[i + 1][j]) {
                        unhappiness++;
                    }
                    if ((j + 1 < c) && hasGuy[i][j + 1]) {
                        unhappiness++;
                    }
                }
            }
        }
        return unhappiness;
    }

    private int tryChess(int r, int c, int n, boolean eq) {
        boolean[][] hasGuy = new boolean[r][c];
        int placed = 0;
        int unhappiness = 0;
        // chess
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if ((i % 2 == j % 2) == eq) {
                    hasGuy[i][j] = true;
                    placed++;
                }
            }
        }
        // corners
        LinkedList<Cell> cells = new LinkedList<Cell>();
        if (!hasGuy[0][0]) {
            cells.add(new Cell(0, 0));
        }
        if (!hasGuy[0][c - 1]) {
            cells.add(new Cell(0, c - 1));
        }
        if (!hasGuy[r - 1][0]) {
            cells.add(new Cell(r - 1, 0));
        }
        if (!hasGuy[r - 1][c - 1]) {
            cells.add(new Cell(r - 1, c - 1));
        }
        // lines
        for (int i = 1; i < r - 1; i++) {
            if (!hasGuy[i][0]) {
                cells.add(new Cell(i, 0));
            }
            if (!hasGuy[i][c - 1]) {
                cells.add(new Cell(i, c - 1));
            }
        }
        for (int j = 1; j < c - 1; j++) {
            if (!hasGuy[0][j]) {
                cells.add(new Cell(0, j));
            }
            if (!hasGuy[r - 1][j]) {
                cells.add(new Cell(r - 1, j));
            }
        }
        // other
        for (int i = 1; i < r - 1; i++) {
            for (int j = 1; j < c - 1; j++) {
                if (!hasGuy[i][j]) {
                    cells.add(new Cell(i, j));
                }
            }
        }
        while (n - placed > 0) {
            Cell cell = cells.pollFirst();
            if (cell.x > 0 && hasGuy[cell.x - 1][cell.y]) {
                unhappiness++;
            }
            if (cell.x < r - 1 && hasGuy[cell.x + 1][cell.y]) {
                unhappiness++;
            }
            if (cell.y > 0 && hasGuy[cell.x][cell.y - 1]) {
                unhappiness++;
            }
            if (cell.y < c - 1 && hasGuy[cell.x][cell.y + 1]) {
                unhappiness++;
            }
            placed++;
            hasGuy[cell.x][cell.y] = true;
        }
        return unhappiness;
    }

    public static void main(String[] args) throws Exception {
        Runner.main(B.class);
    }
}
