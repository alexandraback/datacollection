import java.util.*;

class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int tcc = sc.nextInt();
    for (int tc = 1; tc <= tcc; ++tc) {
      int r = sc.nextInt();
      int c = sc.nextInt();
      int n = sc.nextInt();
      int ans = Integer.MAX_VALUE;
      for (int mask = 0; mask < (1 << (r * c)); ++mask) {
        int bits = 0;
        for (int pow = 1; pow <= mask; pow <<= 1) if ((mask & pow) != 0) ++bits;
        if (bits != n) continue;
        boolean[][] grid = new boolean[r][c];
        for (int pow = 0; pow <= (r * c); ++pow) if ((mask & (1 << pow)) != 0) {
          grid[pow / c][pow % c] = true;
        }
        int cur = 0;
        for (int i = 1; i < r; ++i) for (int j = 0; j < c; ++j) {
          if (grid[i][j] && grid[i-1][j]) ++cur;
        }
        for (int i = 0; i < r; ++i) for (int j = 1; j < c; ++j) {
          if (grid[i][j] && grid[i][j-1]) ++cur;
        }
        ans = Math.min(ans, cur);
      }
      System.out.printf("Case #%d: %s\n", tc, ans);
    }
  }
}
