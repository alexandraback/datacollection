import java.util.*;

class A {

  static int N;

  static String reduce(String x) {
    String reduced = "";
    reduced += x.charAt(0);
    for (int i = 1; i < x.length(); i++) {
      if (x.charAt(i) == x.charAt(i-1)) {
        continue;
      }
      reduced += x.charAt(i);
    }
    return reduced;
  }

  static int dis(String x, String y) {
    int distance = 0;
    int pX = 1, pY = 1;
    while(pX < x.length() && pY < y.length()) {
      if (x.charAt(pX) == y.charAt(pY)) {
        pX++;pY++;
      } else if (x.charAt(pX) == x.charAt(pX-1)) {
        pX++;
        distance++;
      } else {
        pY++;
        distance++;
      }
    }
    while (pX < x.length()) {
      pX++;
      distance++;
    }
    while (pY < y.length()) {
      pY++;
      distance++;
    }
    return distance;
  }

  public static void main(String[] args) {
    Scanner input = new Scanner(System.in);
    int T = input.nextInt();
    for (int t = 1; t <= T; t++) {
      System.out.print("Case #" + t + ": ");
      N = input.nextInt();
      String[] str = new String[N];
      boolean ok = true;
      String reduced = "";
      for (int i = 0; i < N; i++) {
        str[i] = input.next();
        String temp = reduce(str[i]);
        if ("".equals(reduced) || temp.equals(reduced)) {
          reduced = temp;
        } else {
          ok = false;
        }
      }
      if (!ok) {
        System.out.println("Fegla Won");
        continue;
      }
      int sol = 100 * 100;
      for (int i = 0; i < N; i++) {
        int tempsol = 0;
        for (int j = 0; j < N; j++) {
          tempsol += dis(str[i], str[j]);
        }
        if (tempsol < sol) {
          sol = tempsol;
        }
      }
      int tempsol = 0;
      for (int i = 0; i < N; i++) {
        tempsol += dis(str[i], reduced);
      }
      if (tempsol < sol) {
        sol = tempsol;
      }
      System.out.println(sol);
    }
  }
}
