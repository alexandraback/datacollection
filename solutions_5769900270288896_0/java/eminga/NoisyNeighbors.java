
import java.util.Scanner;

public class NoisyNeighbors {

    static int r, c, min;

    static boolean[][] house;

    static void allocate(int x, int a) {
        if (x == 0) {
            evaluate();
            return;
        }
        
        for (int i = a; i < r * c - (x - 1); i++) {
            house[i / c][i % c] = true;
            allocate(x - 1, i + 1);
            house[i / c][i % c] = false;
        }
        
    }

    static void evaluate() {
        int result = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (house[i][j]) {
                    if (i + 1 < r && house[i + 1][j]) {
                        result++;
                    }
                    if (j + 1 < c && house[i][j + 1]) {
                        result++;
                    }
                }
            }
        }
        if (result < min) {
            min = result;
        }
    }

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int t = s.nextInt();
        for (int i = 1; i <= t; i++) {
            r = s.nextInt();
            c = s.nextInt();
            int n = s.nextInt();
            house = new boolean[r][c];
            min = Integer.MAX_VALUE;
            allocate(n, 0);
            System.out.println("Case #" + i + ": " + min);
        }
    }

}
