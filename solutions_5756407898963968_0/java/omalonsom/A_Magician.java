package gcj2014;

import java.io.File;
import java.io.PrintStream;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class A_Magician {

  public static void main(String[] args) throws Exception {
    Scanner in = new Scanner(new File("/Users/omalonsom/Downloads/A-small-attempt0.in"));
    //Scanner in = new Scanner(System.in);
    System.setOut(new PrintStream("/Users/omalonsom/Downloads/A.out"));

    int T = in.nextInt();
    for (int t = 1; t <= T; ++t) {
      Set<Integer> vals1 = readRow(in, in.nextInt());
      Set<Integer> vals2 = readRow(in, in.nextInt());
      vals1.retainAll(vals2);
      int res = vals1.size();
      
      if(res == 0) {
        System.out.printf("Case #%s: Volunteer cheated!\n", t);
      } else if (res == 1) {
        System.out.printf("Case #%s: %s\n", t,vals1.iterator().next());
      } else {
        System.out.printf("Case #%s: Bad magician!\n", t);
      }
      
    }
  }

  static Set<Integer> readRow(Scanner in, int row) {
    row--;
    Set<Integer> vals = new HashSet<>();
    for (int i = 0; i < 16; ++i) {
      int v = in.nextInt();
      if (i/4 == row) vals.add(v);
    }
    return vals;
  }
}
