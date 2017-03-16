import static java.lang.Math.*;
import static java.util.Arrays.*;

import java.io.*;
import java.util.*;

public class B {
  Scanner sc = new Scanner(System.in);

  int R, C, N;
  int[] v;

  void input() {
    R = sc.nextInt();
    C = sc.nextInt();
    N = sc.nextInt();
  }

  void solve() {
    int upto = 1 << (R * C);
    int rest = R * C - N;
    int min = Integer.MAX_VALUE;
    for (int i = 0; i < upto; i++) {
      if (Integer.bitCount(i) != N) continue;
      boolean[][] empty = new boolean[R][C];
      int cur = i;
      for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
          empty[r][c] = ((cur & 1) == 0);
          cur >>= 1;
        }
      }
      int val = 0;
      for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
          if (empty[r][c]) continue;
          val += check(r, c, empty);
        }
      }
      min = Math.min(min, val);
    }
    // int full = (R - 1) * C + (C - 1) * R;
    System.out.println(min/2);
  }

  /*
   * void rec(int rest, boolean[][] empty, int val) { if (rest == 0) { max =
   * Math.max(max, val); } for (int r = 0; r < R; r++) { for (int c = 0; c < C;
   * c++) { if (empty[r][c]) continue; empty[r][c] = true; rec(rest - 1, empty,
   * val + check(r, c, empty)); empty[r][c] = false; } } }
   */

  int check(int r, int c, boolean[][] empty) {
    int ret = 0;
    if (c - 1 >= 0 && !empty[r][c - 1]) ret++;
    if (c + 1 < C && !empty[r][c + 1]) ret++;
    if (r - 1 >= 0 && !empty[r - 1][c]) ret++;
    if (r + 1 < R && !empty[r + 1][c]) ret++;
    return ret;
  }

  void start() {
    int T = sc.nextInt();
    for (int caseNum = 1; caseNum <= T; caseNum++) {
      input();
      System.out.printf("Case #%d: ", caseNum);
      solve();
      System.out.flush();
    }
    sc.close();
  }

  void debug(Object... os) {
    System.err.println(deepToString(os));
  }

  public static void main(String[] args) throws Exception {
    System
        .setIn(new FileInputStream(args.length > 0 ? args[0] : ("sample.in")));
    new B().start();
  }

}
