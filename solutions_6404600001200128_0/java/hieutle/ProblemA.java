import java.util.Scanner;
import java.io.PrintWriter;
import java.io.FileReader;
import java.io.FileNotFoundException;

public class ProblemA {
  
  public static void main(String[] args) throws FileNotFoundException {
    Scanner in = new Scanner(new FileReader("A-small-attempt0.in"));
    PrintWriter out = new PrintWriter("A-small-0.out");
//    Scanner in = new Scanner(System.in);
//    PrintWriter out = new PrintWriter(System.out);
    TaskA solver = new TaskA();
    int t = in.nextInt();
    for (int i = 1; i <= t; i++)
      solver.solve(i, in, out);
    out.close();
  }
}

class TaskA {
  
  public void solve(int testNumber, Scanner in, PrintWriter out) {
    int n = in.nextInt();
    int[] m = new int[n];
    for (int i = 0; i < n; i++)
      m[i] = in.nextInt();
    int randomEat = 0;
    for (int i = 0; i < n - 1; i++)
      if (m[i] > m[i + 1]) randomEat += (m[i] - m[i + 1]);
    int maxDelta = Integer.MIN_VALUE;
    for (int i = 0; i < n - 1; i++) 
      maxDelta = Math.max(maxDelta, m[i] - m[i + 1]);
    int regularEat = 0;
    for (int i = 0; i < n - 1; i++)
      regularEat += Math.min(maxDelta, m[i]); 
    out.printf("Case #%d: %d %d\n", testNumber, randomEat, regularEat);
  }
}
