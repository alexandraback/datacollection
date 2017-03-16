import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class A {

  static final String FILENAME = "A-small-attempt0";
  static final String IN = FILENAME + ".in";
  static final String OUT = FILENAME + ".out";
  Scanner sc;
  BufferedWriter out;

  private void solve() throws IOException {
    int n = sc.nextInt();
    int[] m = new int[n];
    for(int i = 0; i < n; i++) {
      m[i] = sc.nextInt();
    }
    int sum1 = 0;
    int cur = m[0];
    for(int i = 1; i < n; i++) {
      if(m[i] < cur) {
        sum1 += cur - m[i];
      }
      cur = m[i];
    }
    out.write(Integer.toString(sum1) + " ");
    
    int max = 0;
    for(int i = 1; i < n; i++) {
      if(max < m[i - 1] - m[i]) {
        max = m[i - 1] - m[i];
      }
    }
    int sum2 = 0;
    for(int i = 0; i < n - 1; i++) {
      sum2 += Math.min(max, m[i]);
    }
    out.write(Integer.toString(sum2));
    out.newLine();
    out.flush();
  }

  private void run() throws IOException {
    sc = new Scanner(new File(IN));
    out = new BufferedWriter(new FileWriter(OUT));
    int t = Integer.parseInt(sc.nextLine());
    for (int i = 1; i <= t; i++) {
      out.write("Case #" + i + ": ");
      solve();
    }
    sc.close();
    out.close();
  }

  public static void main(String args[]) throws Exception {
    new A().run();
  }
}
