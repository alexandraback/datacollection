import static java.lang.Math.*;
import static java.util.Arrays.*;

import java.io.*;
import java.util.*;

public class A {
  Scanner sc = new Scanner(System.in);

  int N;
  int[] m;

  void input() {
    N = sc.nextInt();
    m = new int[N];
    for (int i = 0; i < N; i++) {
      m[i] = sc.nextInt();
    }
  }

  void solve() {
    // for step1
    int sum1 = 0;
    int max = -1;
    for (int i = 1; i < N; i++) {
      if (m[i] < m[i - 1]) {
        sum1 += (m[i - 1] - m[i]);
        max = Math.max(max, m[i - 1] - m[i]);
      }
    }
    int sum2 = 0;
    if (max == -1) {
      System.out.println(sum1 + " 0");
      return;
    }
    int rest = m[0];
    for (int i = 1; i < N; i++) {
      int eat = Math.min(rest, max);
      sum2 += eat;
      rest = m[i];
    }
    System.out.println(sum1 + " " + sum2);
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
    new A().start();
  }

}
