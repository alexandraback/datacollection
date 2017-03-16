import java.io.*;
import java.util.*;

/**
 */

public class A
{

  public static int method1(int[] m) {
    int sum = 0;
    for(int i = 1; i < m.length; i++) {
      if(m[i - 1] - m[i] > 0)
        sum += m[i - 1] - m[i];
    }
    return sum;
  }

  public static int method2(int[] m) {
    int rate = 0;
    for(int i = 1; i < m.length; i++) {
      if(m[i - 1] - m[i] > 0)
        rate = Math.max(rate, m[i - 1] - m[i]);
    }

    int sum = 0;
    for(int i = 0; i < m.length - 1; i++) {
      sum += Math.min(m[i], rate);
    }

    return sum;
  }

	public static void main(String[] args) throws IOException
	{
    Scanner sc = new Scanner(System.in);
    int T = sc.nextInt();
    sc.nextLine();
    for(int t = 1; t <= T; t++) {
      int[] m = new int[sc.nextInt()];
      sc.nextLine();
      for(int i = 0; i < m.length; i++)
        m[i] = sc.nextInt();
      sc.nextLine();
      System.out.format("Case #%d: %d %d\n", t, method1(m), method2(m));
    }
    sc.close();
	}
}
