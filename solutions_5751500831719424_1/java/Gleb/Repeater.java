import java.io.*;
import java.util.Scanner;

public class Repeater implements Runnable {
  private static final String NAME = "rep";

  int nextInt(BufferedReader in) throws Exception {
    return Integer.parseInt(in.readLine());
  }
  @Override
  public void run() {
    try {
      BufferedReader in = new BufferedReader(new FileReader(new File(NAME + ".in")));
      PrintWriter out = new PrintWriter(NAME + ".out");


      int tests = nextInt(in);

      for (int test = 1; test <= tests; test++) {
        int n = nextInt(in);
        String[] s = new String[n];
        for (int i = 0; i < n; i++) s[i] = in.readLine();
        int[] cur = new int[n];
        int res = 0;
        boolean end = false;
        while (!end) {
          int[] len = new int[n];
          if (cur[0] >= s[0].length()) {
            res = -1;
            break;
          }
          char c = s[0].charAt(cur[0]);
          int max = 1;
          for (int i = 0; i < n; i++) {
            if (cur[i] >= s[i].length() || s[i].charAt(cur[i]) != c) {
              res = -1;
              break;
            }
            while (cur[i] < s[i].length() && s[i].charAt(cur[i]) == c) {
              cur[i]++;
              len[i]++;
            }
            max = Math.max(len[i], max);
          }
          if (res == -1) break;

          int delta = Integer.MAX_VALUE - 1;
          for (int k = 1; k <= max; k++) {
            int curD = 0;
            for (int i = 0; i < n; i++) curD += Math.abs(k - len[i]);
            if (curD < delta) delta = curD;
          }
          res += delta;

          end = true;
          for (int i = 0; i < n; i++) {
            if (cur[i] < s[i].length()) end = false;
          }
        }
        out.print("Case #" + test + ": ");
        if (res < 0) {
          out.println("Fegla Won");
        } else {
          out.println(res);
        }
      }

      out.close();
    } catch (Exception e) {
      throw new RuntimeException(e);
    }
  }

  public static void main(String[] args) {
    new Thread(new Repeater()).start();
  }
}
