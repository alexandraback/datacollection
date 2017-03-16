import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;

public class Barber {

  public static void main(String[] args) {
    new Barber().solve(args[0]);
  }

  void solve(String path) {
    BufferedReader reader = null;
    try {
      reader = new BufferedReader(new FileReader(path));
      int n = Integer.parseInt(reader.readLine());
      for (int i = 1; i <= n; ++i) {

        solveOne(Integer.parseInt(reader.readLine().split(" ")[1]), reader
            .readLine().split(" "), i);
      }
    } catch (Exception e) {
      e.printStackTrace();
    } finally {
      if (reader != null) {
        try {
          reader.close();
        } catch (IOException e) {
          e.printStackTrace();
        }
      }
    }
  }

  void solveOne(int n, String[] array, int order) {
    int[] barber = new int[array.length];
    List<Value> a = new ArrayList<Value>();
    for (int i = 0; i < array.length; ++i) {
      barber[i] = Integer.parseInt(array[i]);
      a.add(new Value(0, i));
    }

    double inverseSum = 0d;
    for (int i : barber) {
      inverseSum += 1d / i;
    }
    if (n - 1 - barber.length > 0) {
      double h = (n - 1 - barber.length) / inverseSum;
      for (int i = 0; i < a.size(); ++i) {
        int k = (int) Math.ceil(h / barber[i]);
        a.get(i).value = k * barber[i];
        n -= k;
      }
    }
    int res = 0;
    PriorityQueue<Value> heap = new PriorityQueue<Value>(a);
    while (n-- > 0) {
      Value top = heap.poll();
      res = top.index;
      top.value += barber[res];
      heap.offer(top);
    }
    System.out.println("Case #" + order + ": " + (res + 1));
  }

  private static class Value implements Comparable<Value> {
    int value;
    int index;

    Value(int v, int i) {
      value = v;
      index = i;
    }

    @Override
    public int compareTo(Value o) {
      if (value == o.value) {
        return index - o.index;
      }
      return value - o.value;
    }

  }
}