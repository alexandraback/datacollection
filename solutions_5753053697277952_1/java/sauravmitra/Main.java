import java.util.Scanner;
import java.util.PriorityQueue;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int t = sc.nextInt();
    for (int i = 1; i <= t; i++) {
      int n = sc.nextInt();
      PriorityQueue<Pair> pq = new PriorityQueue<>();
      for (int j = 0; j < n; j++) {
        pq.add(new Pair((char) ('A' + j), sc.nextInt())); 
      }
      String res = "";
      while (!pq.isEmpty()) {
        if (!res.equals("")) {
          res += " ";
        }
        Pair a = pq.poll();
        String step = "" + a.party;
        a.num--;
        if (a.num > 0) {
          pq.add(a);
        }
        if (!pq.isEmpty() && !(pq.peek().num == 1 && pq.size() == 2)) {
          Pair b = pq.poll();
          step += b.party;
          b.num--;
          if (b.num > 0) {
            pq.add(b);
          }
        }
        res += step;
      }
      System.out.println("Case #" + i + ": " + res);
    }
  }

  static class Pair implements Comparable<Pair> {
    char party;
    Integer num;
    public Pair(char party, int num) {
      this.party = party;
      this.num = num;
    }

    @Override
    public int compareTo(Pair other) {
      return other.num.compareTo(num);
    }
  }
}
