import java.io.*;
import java.util.*;

/**
 */

public class B
{

  public static int gcd(int a, int b) {
    while(a != b) {
      if(a > b)
        a = a - b;
      else
        b = b - a;
    }
    return a;
  }

  public static int lcm(int a, int b) {
    return a * b / gcd(a, b);
  }


  public static int simulate(int[] m, int n) {
    PriorityQueue<Barber> pq = new PriorityQueue<Barber>(m.length, 
        (Barber b1, Barber b2) -> {
          if(b1.finishingTime != b2.finishingTime)
            return b1.finishingTime < b2.finishingTime ? -1 : 1;
          else return b1.id - b2.id;
        }
    );
    for(int i = 0; i < m.length; i++)
      pq.add(new Barber(i + 1, m[i]));

    // System.out.println(pq);
    for(int i = 1; i < n; i++) {
      Barber b = pq.poll();
      b.finishingTime += b.rate;
      pq.add(b);
    }
    return pq.poll().id;
  }

  public static int barber(int[] m, int n) {
    int C = m[0];
    for(int i = 1; i < m.length; i++) {
      C = lcm(C, m[i]);
    }

    int cutsPerCycle = 0;
    for(int i = 0; i < m.length; i++) {
      cutsPerCycle += C/m[i];
    }

    // System.out.println("Cuts/cycle: " + cutsPerCycle);

    n = n % cutsPerCycle;
    if(n == 0) n = cutsPerCycle;

    // System.out.println("n = " + n);

    return simulate(m, n);
  }

	public static void main(String[] args) throws IOException
	{
    Scanner sc = new Scanner(System.in);
    int T = sc.nextInt();
    sc.nextLine();
    for(int t = 1; t <= T; t++) {
      int B = sc.nextInt();
      int N = sc.nextInt();
      int[] m = new int[B];
      sc.nextLine();
      for(int i = 0; i < m.length; i++)
        m[i] = sc.nextInt();
      sc.nextLine();
      System.out.format("Case #%d: %d\n", t, barber(m, N));
    }
    sc.close();
	}

}


class Barber {
  int id;
  long finishingTime;
  int rate;
  public Barber(int id, int rate) {
    this.id = id;
    this.rate = rate;
    finishingTime = 0;
  }
  public String toString() {
    return id + "";
  }
}

