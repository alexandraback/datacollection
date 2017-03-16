import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class B {

  static final String FILENAME = "B-small-attempt0";
  static final String IN = FILENAME + ".in";
  static final String OUT = FILENAME + ".out";
  Scanner sc;
  BufferedWriter out;

  class Mark {
    long v;
    int n;

    Mark(long v, int n) {
      this.v = v;
      this.n = n;
    }
  }

  private void solve() throws IOException {
    int ans = -1;
    int B = sc.nextInt();
    long N = sc.nextLong();
    long[] M = new long[B];
    for (int i = 0; i < B; i++) {
      M[i] = sc.nextLong();
    }
    long l = 0;
    long r = 100000 * N;
    while (l + 1 < r) {
      long m = (l + r) / 2;
      long sum = 0;
      for (int i = 0; i < B; i++) {
        sum += (m + M[i] - 1) / M[i];
      }
      if (sum < N) {
        l = m;
      } else {
        r = m;
      }
    }

    Mark[] rest = new Mark[B];
    long sum = 0;
    for (int i = 0; i < B; i++) {
      rest[i] = new Mark(r - l / M[i] * M[i], i);
      sum += l / M[i];
    }
    Arrays.sort(rest, new Comparator<Mark>() {
      public int compare(Mark a, Mark b) {
        if (a.v > b.v || (a.v == b.v && a.n < b.n)) {
          return -1;
        } else if (a.v == b.v && a.n == b.n) {
          return 0;
        } else {
          return 1;
        }
      }
    });
    ans = rest[(int) (N - sum - 1)].n + 1;

    out.write(Integer.toString(ans));
    out.newLine();
    out.flush();
  }

  private void run() throws IOException {
    sc = new Scanner(new File(IN));
    out = new BufferedWriter(new FileWriter(OUT));
    int t = sc.nextInt();
    for (int i = 1; i <= t; i++) {
      out.write("Case #" + i + ": ");
      solve();
    }
    sc.close();
    out.close();
  }

  public static void main(String args[]) throws Exception {
    new B().run();
  }
}
