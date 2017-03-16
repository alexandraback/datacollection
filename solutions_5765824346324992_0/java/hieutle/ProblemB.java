import java.util.Comparator;
import java.util.TreeMap;
import java.util.Scanner;
import java.io.PrintWriter;
import java.io.FileReader;
import java.io.FileNotFoundException;
import java.util.PriorityQueue;

public class ProblemB {
  
  public static void main(String[] args) throws FileNotFoundException {
    Scanner in = new Scanner(new FileReader("B-small-attempt4.in"));
    PrintWriter out = new PrintWriter("B-small-4.out");
//    Scanner in = new Scanner(System.in);
//    PrintWriter out = new PrintWriter(System.out);
    TaskB solver = new TaskB();
    int t = in.nextInt();
    for (int i = 1; i <= t; i++)
      solver.solve(i, in, out);
    out.close();
  }
}

class TaskB {
  
  public void solve(int testNumber, Scanner in, PrintWriter out) {
    int b = in.nextInt();
    int n = in.nextInt();
    PriorityQueue<Barber> q = new PriorityQueue<Barber>(b, new BarberComparator());  
    int product = 1;
    int[] m = new int[b];
    for (int i = 1; i <= b; i++) {
      int x = in.nextInt();
      m[i - 1] = x;
      product = product * x;
      q.add(new Barber(i, x));
    }
    int sum = 0;
    for (int i = 0; i < b; i++) 
      sum += product / m[i];
    int[] DP = new int[sum + 1];
    for (int i = 1; i <= sum; i++) {
      Barber finish = q.poll();
      DP[i] = finish.index;
      finish.capacity = finish.capacity + finish.time;
      q.add(finish);
    }
    DP[0] = DP[sum];
    int index = n % (sum);
    out.printf("Case #%d: %d\n", testNumber, DP[index]);
    
  }
}

class Barber {
  public int index;
  public int capacity;
  public int time;
  
  public Barber(int index, int time)
  {
    this.index = index;
    this.time = time;
  }
}

class BarberComparator implements Comparator<Barber> {
  public int compare(Barber x, Barber y) {
    if (x.capacity < y.capacity)
      return -1;
    if (x.capacity > y.capacity)
      return 1;
    if (x.capacity == y.capacity) {
      if (x.index < y.index)
        return -1;
      else
        return 1;
    }
    return 0;
  }
}

