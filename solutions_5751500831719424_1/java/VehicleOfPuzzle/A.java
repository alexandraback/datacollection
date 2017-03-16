import java.util.*;

class A {
  public static void main(String[] arg) {
    Scanner sc = new Scanner(System.in);
    for (int tcc = sc.nextInt(), tc = 1; tc <= tcc; ++tc) {
      int n = sc.nextInt();
      String[] arr = new String[n];
      for (int i = 0; i < n; ++i) arr[i] = sc.next();
      String p = profile(arr[0]);
      boolean canWin = true;
      for (String s: arr) if (!profile(s).equals(p)) {
        canWin = false;
        break;
      }
      if (!canWin) {
        System.out.printf("Case #%d: Fegla Won%n", tc);
        continue;
      }
      int ans = 0;
      int[][] lengths = new int[n][];
      for (int i = 0; i < n; ++i) lengths[i] = lengths(arr[i]);
      for (int j = 0; j < p.length(); ++j) {
        int best = Integer.MAX_VALUE;
        for (int k = 1; k <= 100; ++k) {
          int cur = 0;
          for (int i = 0; i < n; ++i) {
            cur += Math.abs(lengths[i][j] - k);
          }
          best = Math.min(best, cur);
        }
        ans += best;
      }
      System.out.printf("Case #%d: %d%n", tc, ans);
    }
  }

  static String profile(String s) {
    return s.replaceAll("([a-z])\\1*", "$1");
  }

  static int[] lengths(String s) {
    String[] parts = s.replaceAll("(([a-z])\\2*)", "$1 ").trim().split(" ");
    int[] ret = new int[parts.length];
    for (int i = 0; i < ret.length; ++i) ret[i] = parts[i].length();
    return ret;
  }
}
