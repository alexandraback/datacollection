import java.io.PrintWriter;
import java.util.*;

public class B {

  public static void main(String[] args) {
    new B().run();
  }

  private void run() {
    Scanner in = new Scanner(System.in);
    PrintWriter out = new PrintWriter(System.out);

    int tests = in.nextInt();
    for (int test = 0; test < tests; test++) {
      int r = in.nextInt(), c = in.nextInt(), n = in.nextInt();
      int ans = solve(r, c, n);
      out.println(String.format("Case #%d: %s", test + 1, ans));
      out.flush();
    }

    in.close();
    out.close();
  }

  private int solve(int r, int c, int n) {
    boolean[][] occupied = new boolean[r][c];
    int min = Integer.MAX_VALUE;
    for (int mask = 0; mask < (1 << (r * c)); mask++) {
      for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
          int ii = i * c + j;
          occupied[i][j] = ((mask >> ii) & 1) == 1;
        }
      }
      int flats = 0;
      for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
          if (occupied[i][j]) {
            flats++;
          }
        }
      }
      if (flats != n) {
        continue;
      }
      int unhappy = 0;
      for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
          if (i + 1 < r) {
            if (occupied[i][j] && occupied[i + 1][j]) {
              unhappy++;
            }
          }
          if (j + 1 < c) {
            if (occupied[i][j] && occupied[i][j + 1]) {
              unhappy++;
            }
          }
        }
      }
      min = Math.min(min, unhappy);
    }
    return min;
  }
}
