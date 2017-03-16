import java.io.*;
import java.util.*;

public class B {
  public static void main(String[] args) throws Exception {
    Scanner s = new Scanner(System.in);
    int T = s.nextInt();
    for (int t = 1; t <= T; t++) {
      int C = s.nextInt(), R = s.nextInt(), n = s.nextInt();
      if (C > R) {
        int tmp = C;
        C = R;
        R = tmp;
      }
      int m = 1 << C;
      int[][] a = new int[m][n + 1], b = new int[m][n + 1];
      for (int i = 0; i < m; i++) {
        for (int j = 1; j <= n; j++) {
          a[i][j] = b[i][j] = -1;
        }
        int count = count(i), cost = cost(i);
        if (count <= n) {
          a[i][count] = b[i][count] = cost;  
        }
      }
      for (int r = 1; r < R; r++) {
        for (int k = 0; k < m; k++) {
          int used = count(k);
          for (int j = used; j <= n; j++) {
            // calc b[k, j]
            int min = -1, cost0 = cost(k);
            for (int i = 0; i < m; i++) {
              if (a[i][j - used] != -1) {
                int cost1 = cost(i, k) + a[i][j - used];
                if (min == -1 || min > cost0 + cost1) {
                  min = cost0 + cost1;
                }
              }
            }
            b[k][j] = min;
          }
        }
        for (int i = 0; i < m; i++) {
          for (int j = 0; j <= n; j++) {
            a[i][j] = b[i][j];
            b[i][j] = -1;
          }
        }
      }
      int ans = -1;
      for (int i = 0; i < m; i++) {
        if (a[i][n] != -1 && (ans == -1 || ans > a[i][n])) {
          ans = a[i][n];
        }
      }
      System.out.println(String.format("Case #%d: %d", t, ans));
    }
  }

  public static int count(int k) {
    int ret = 0;
    int o = k;
    while (k != 0) {
      k = k & (k - 1);
      ret++;
    }
    return ret;
  }

  public static int cost(int k) {
    int ret = 0;
    boolean prev = false;
    while (k != 0) {
      boolean cur = (k & 1) == 1;
      if (prev && cur) {
        ret++;
      }
      prev = cur;
      k /= 2;
    }
    return ret;
  }

  public static int cost(int a, int b) {
    return count(a & b);
  }
}