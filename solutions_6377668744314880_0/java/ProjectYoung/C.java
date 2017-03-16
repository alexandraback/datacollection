import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class C {

  static final String FILENAME = "C-small-attempt0";
  static final String IN = FILENAME + ".in";
  static final String OUT = FILENAME + ".out";
  Scanner sc;
  BufferedWriter out;
  
  private void solve() throws IOException {
    int N = sc.nextInt();
    long[] x = new long[N];
    long[] y = new long[N];
    for(int i = 0; i < N; i++) {
      x[i] = sc.nextLong();
      y[i] = sc.nextLong();
    }
    for(int i = 0; i < N; i++) {
      int min = Integer.MAX_VALUE;
      for(int j = 0; j < N; j++) {
        if(j == i) {
          continue;
        }
        int cnt1 = 0;
        int cnt2 = 0;
        for(int k = 0; k < N; k++) {
          if(k == i || k == j) {
            continue;
          }
          long pdct = (x[k] - x[i]) * (y[i] - y[j]) + (y[k] - y[i]) * (x[j] - x[i]); 
          if(pdct < 0) {
            cnt1 ++;
          } else if(pdct > 0) {
            cnt2 ++;
          }
        }
        if(min > Math.min(cnt1, cnt2)) {
          min = Math.min(cnt1, cnt2);
        }
      }
      if(N < 3) {
        min = 0;
      }
      out.newLine();
      out.write(Integer.toString(min));
    }
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
    new C().run();
  }
}
