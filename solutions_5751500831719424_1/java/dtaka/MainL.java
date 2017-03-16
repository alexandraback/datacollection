import java.io.*;
import java.util.*;

public class MainL{
  static final String ANSWER = "Case #%d: %d\n";
  static final String FEGRAW = "Case #%d: Fegla Won\n";
  
  public static void main(String args[]) throws Exception {
    BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
    String line;
    String[] prms;
    int T = Integer.parseInt(stdin.readLine());
    for (int t = 1; t <= T; t++) {
      line = stdin.readLine();
      int N = Integer.parseInt(line);
      String[] str = new String[N];
      for (int i = 0; i < N; i++) {
        str[i] = stdin.readLine();
      }
      
      int[][] cnt = new int[N][100];
      StringBuffer[] buf = new StringBuffer[N];
      for (int i = 0; i < N; i++) {
        buf[i] = new StringBuffer();
        int n = str[i].length();
        char ch0 = 0;
        int idx = 0;
        for (int j = 0; j < n; j++) {
          char ch = str[i].charAt(j);
          if (ch != ch0) {
            buf[i].append(ch);
            idx++;
          } else {
            cnt[i][idx-1]++;
          }
          ch0 = ch;
        }
      }
      
      boolean flag = true;
      String s = buf[0].toString();
      for (int i = 1; i < N; i++) {
        if (!s.equals(buf[i].toString())) {
          flag = false;
          break;
        }
      }
      
      if (!flag) {
        System.out.printf(FEGRAW, t);
      } else {
        int ans = 0;
        for (int i = 0; i < 100; i++) {
          int min = 1000000;
          for (int j = 0; j < N; j++) {
            int c = 0;
            for (int k = 0; k < N; k++) {
              c += Math.abs(cnt[k][i]-cnt[j][i]);
            }
            min = Math.min(min, c);
          }
          ans += min;
        }
        System.out.printf(ANSWER, t, ans);
      }
    }
  }
}
