import java.io.*;
import java.util.*;
import java.math.*;

public class A implements Runnable {
  static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  static PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
  static StringTokenizer st = new StringTokenizer("");

  public static String next() {
    try {
    while (!st.hasMoreTokens()) {
      String s = br.readLine();
      if (s == null)
        return null;
      st = new StringTokenizer(s);
    }
    return st.nextToken();
    } catch(Exception e)  {
      return  null;
    }
  }

  public static void main(String[] asda) throws Exception {
    new Thread(null, new A(), "A", 1<<26).start();
  }

  public void run() {
    int cases = Integer.parseInt( next() );
    for (int k = 0; k < cases; k++) {
      String ans = solveCase();
      out.println("Case #" + (k+1) + ":" + ans);
    }
    //
    out.flush();
    System.exit(0);
  }

  String solveCase()  {
    int N = Integer.parseInt( next() );
    int[] cnt = new int[N];
    int sum = 0;
    for (int k = 0; k < N; k++) {
      cnt[k] = Integer.parseInt( next() );
      sum += cnt[k];
    }

    String ans = "";
    while(sum > 0)  {
      int best = getMax(cnt);
      ans += " " + (char)(best + 'A');
      sum--;
      cnt[best]--;
      int next = getInvalid(cnt, sum/2);
      if (next >= 0) {
        ans += (char)(next + 'A');
        sum--;
        cnt[next]--;
      }

      if (getInvalid(cnt, sum/2) >= 0) {
        throw new RuntimeException("Wrong state");
      }
    }
    return ans;
  }

  int getInvalid(int[] cnt, int limit) {
    for (int k = 0; k < cnt.length; k++) if (cnt[k] > limit) {
      return k;
    }
    return -1;
  }

  int getMax(int[] cnt) {
    int best = 0;
    for (int k = 0; k < cnt.length; k++) if (cnt[k] > cnt[best]) {
      best = k;
    }
    return best;
  }
}
