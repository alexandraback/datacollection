import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.*;

public class NoisyNeighbors {
    Scanner sc = new Scanner(getClass().getResourceAsStream(IN));
    static final String FILENAME = "B-small-attempt0";
    static final String IN = FILENAME + ".in";
    static final String OUT = FILENAME + ".out";

    PrintStream out = System.out;

    boolean[][] grid;
    int unhappiness;
    int n, numTrue, R, C;
    private void solveBrute(int R, int C, int N) {
        //System.out.println("R, C, N = " + R + ", " + C + ", " + N);
        this.R = R;
        this.C = C;
        n = N;
        grid = new boolean[R][C];
        unhappiness = Integer.MAX_VALUE;
        numTrue = 0;
        backtrack();
        out.println(unhappiness);
    }

    private void backtrack() {
        if(numTrue == n) {
            unhappiness = Math.min(unhappiness, computeUnhappiness());
            return;
        }

        int i;
        for(i = R*C - 1; i >= 0; i--) {
            int r = computeR(i), c = computeC(i);
            if(grid[r][c]) break;
        }

        //System.out.println(Arrays.deepToString(grid));

        for(int j = i + 1; j < R*C; j++) {
            int r = computeR(j), c = computeC(j);

            grid[r][c] = true;
            numTrue++;
            backtrack();
            numTrue--;
            grid[r][c] = false;
        }
    }

    private int computeC(int j) {
        return j % C;
    }

    private int computeR(int i) {
        return i / C;
    }

    private int computeUnhappiness() {
        int unhap = 0;
        for(int row = 0; row < grid.length; row++) {
            for(int col = 1; col < grid[0].length; col++) {
                if(grid[row][col] && grid[row][col - 1]) unhap++;
            }
        }
        for(int row = 1; row < grid.length; row++) {
            for(int col = 0; col < grid[0].length; col++) {
                if(grid[row][col] && grid[row-1][col]) unhap++;
            }
        }
        return unhap;
    }

    private void run() throws Exception {
        out = new PrintStream(new FileOutputStream(OUT));
        int t = sc.nextInt();
        for (int i = 1; i <= t; i++) {
            System.out.println("******************* TC" + i + " ********************");
            int R = sc.nextInt(), C = sc.nextInt(), N = sc.nextInt();
            out.print("Case #" + i + ": ");
            solveBrute(R, C, N);
        }
        sc.close();
        out.close();
    }

    public static void main(String args[]) throws Exception {
        new NoisyNeighbors().run();
    }

}
