import java.util.*;

class BarbAvail implements Comparable<BarbAvail> {
  long avail;
  int bi;

  public BarbAvail(long a, int b) {
    avail = a;
    bi = b;
  }

  public int compareTo(BarbAvail other) {
    int ret = Long.valueOf(avail).compareTo(other.avail);
    if (ret == 0) ret = bi - other.bi;
    return ret;
  }

  public String toString() {
    return (bi + 1) + " @ " + avail;
  }
}

class Main {
  public static void main(String[] arg) {
    Scanner sc = new Scanner(System.in);
    int tcc = sc.nextInt();
    for (int tc = 1; tc <= tcc; ++tc) {
      int b = sc.nextInt();
      long n = sc.nextLong();
      long[] arr = new long[b];
      long largest = 0;
      for (int i = 0; i < b; ++i) {arr[i] = sc.nextLong(); largest = Math.max(largest, arr[i]);}
      double rate = 0;
      for (long m: arr) rate += 1.0 / m;
      long optim = (long) Math.floor((n - 1) / rate) - 1;
//      System.err.println(optim);

      long served = 0;
      PriorityQueue<BarbAvail> q = new PriorityQueue<BarbAvail>();
      for (int i = 0; i < b; ++i) {
        long ds = optim / arr[i];
        served += ds;
        long avail = ds * arr[i];
        optim = Math.min(avail, optim);
//        System.err.println((i + 1) + " will serve " + ds + " and avail at " + avail);
        q.add(new BarbAvail(avail, i));
      }

//      System.err.println(q);

      while (n > served + 1) {
        ++served;
        BarbAvail ba = q.poll();
        long newAvail = ba.avail + arr[ba.bi];
//        System.err.println((ba.bi + 1) + " will serve #" + served + " and avail at " + newAvail);
        q.add(new BarbAvail(newAvail, ba.bi));
      }

      System.out.printf("Case #%d: %d%n", tc, q.peek().bi + 1);
    }
  }
}
