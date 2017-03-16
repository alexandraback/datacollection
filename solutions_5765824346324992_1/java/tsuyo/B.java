import static java.lang.Math.*;
import static java.util.Arrays.*;

import java.io.*;
import java.util.*;

public class B {
  Scanner sc = new Scanner(System.in);

  int B, N;
  int[] M;

  void input() {
    B = sc.nextInt();
    N = sc.nextInt();
    M = new int[B];
    for (int i = 0; i < B; i++) {
      M[i] = sc.nextInt();
    }
  }

  void solve() {
    long L = 0;
    long R = 1000000000L * 100000L;
    // 1000 times should be enough
    for (int j = 0; j < 1000; j++) {
      long mid = (L + R) / 2;
      long num = check(mid);
      if (num < N) {
        L = mid + 1;
      } else {
        R = mid;
      }
    }
    // wait for R time
    long sofar = 0;
    for (int i = 0; i < B; i++) {
      sofar += (R/M[i]);
      if (R % M[i] != 0) sofar++;
    }
    long diff = N - sofar; 
    for (int i = 0; i < B; i++) {
      if (R % M[i] == 0) {
        diff--;
        if (diff == 0) {
          System.out.println(i+1);
          return;
        }
      }
    }
    throw new RuntimeException();
  }

  long check(long time) {
    long ret = 0;
    for (int i = 0; i < B; i++) {
      ret += ((long) time / M[i]) + 1;
    }
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
