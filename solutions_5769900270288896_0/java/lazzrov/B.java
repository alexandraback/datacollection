import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class B {

  public static void main(String[] args) throws FileNotFoundException {
    Scanner in = new Scanner(new File("B-small-attempt0.in"));
    PrintWriter out = new PrintWriter(new File("B-small-attempt0.out"));

    int T = in.nextInt();
    for (int t = 1; t <= T; t++) {
      
      best = Integer.MAX_VALUE;
      R = in.nextInt();
      C = in.nextInt();
      N = in.nextInt();
      
      int mask[] = new int[R];
      
      System.out.println("TEST");
      gen(mask, 0);
      
      out.println("Case #" + t + ": " + best);
    }

    out.close();
  }


  static int best;
  static int R;
  static int C;
  static int N;

  private static void gen(int[] mask, int row) {
    if (row == R) {
      solve(mask);
      return ;
    }
    
    for (int i = 0; i < 1 << C; i++) {
      mask[row] = i;
      gen(mask, row + 1);
    }
    
  }

  private static void solve(int[] mask) {
    int count = 0;
    for (int i = 0; i < mask.length; i++) {
      count += Integer.bitCount(mask[i]);
    }
    if (count != N) return;
    
    int res = 0;
    for (int i = 0; i < mask.length; i++) {
      for (int j = 0; j < C - 1; j++) {
        int bit1 = mask[i] & (1 << j);
        int bit2 = mask[i] & (1 << (j+1));
        if (bit1 > 0 && bit2 > 0) res++;
      }
    }
    for (int i = 0; i < mask.length - 1; i++) {
      for (int c = 0; c < C; c++) {
        int bit1 = mask[i] & (1 << c);
        int bit2 = mask[i+1] & (1 << c);
        if (bit1 > 0 && bit2 > 0) res++;
      }
    }
//    System.out.println(Arrays.toString(mask));
//    System.out.println(res);
    best = Math.min(best, res);
  }
}
