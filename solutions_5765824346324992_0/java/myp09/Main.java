import java.io.*;
import java.util.*;

public class Main {
  public static void main(String[] args) throws Exception {
    InputStreamReader isr = new InputStreamReader(System.in);
    BufferedReader br = new BufferedReader(isr);
    int T = Integer.parseInt(br.readLine());
    for (int t = 1; t <= T; t++) {
      StringTokenizer st = new StringTokenizer(br.readLine());
      int b = Integer.parseInt(st.nextToken());
      int n = Integer.parseInt(st.nextToken()) - 1;
      st = new StringTokenizer(br.readLine());
      int[] m = new int[b];
      for (int i = 0; i < b; i++) {
        m[i] = Integer.parseInt(st.nextToken());
      }
      Set<Integer> set = new HashSet<Integer>();
      int[] a = new int[b];
      int count = 0;
      ArrayList<Integer> list = new ArrayList<Integer>();
      while (true) {
        int loc = 0;
        for (int i = 0; i < b; i++) {
          if (a[i] < a[loc]) {
            loc = i;
          }
        }
        int min = a[loc];
        for (int i = 0; i < b; i++) {
          a[i] -= min;
        }
        a[loc] = m[loc];

        int p = 0;
        for (int i = 0; i < b; i++) {
          p = p * (m[i] + 1) + a[i];
        }
        if (set.contains(p) ) {
          break;
        }

        set.add(p);
        list.add(loc);
        count++;
        if (p < 0) {
          System.out.println("ERROR");
        }
      }
      System.out.println(String.format("Case #%d: %d", t, list.get(n % count) + 1));
    }
  }
}