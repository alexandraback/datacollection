import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class Mushroom {

  public static void main(String[] args) {

    new Mushroom().solve(args[0]);
  }

  void solve(String path) {
    BufferedReader reader = null;
    try {
      reader = new BufferedReader(new FileReader(path));
      int n = Integer.parseInt(reader.readLine());
      for (int i = 1; i <= n; ++i) {
        reader.readLine();
        solveOne(reader.readLine().split(" "), i);
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

  void solveOne(String[] array, int order) {
    List<Integer> intArray = new ArrayList<Integer>();
    for (String s : array) {
      intArray.add(Integer.parseInt(s));
    }
    int x = 0;
    int max = 0;
    for (int i = 1; i < intArray.size(); ++i) {
      if (intArray.get(i) < intArray.get(i - 1)) {
        int d = intArray.get(i - 1) - intArray.get(i);
        x += d;
        max = Math.max(max, d);
      }
    }
    int y = 0;
    for (int i = 1; i < intArray.size(); ++i) {
      y += Math.min(max, intArray.get(i - 1));
    }
    System.out.println("Case #" + order + ": " + x + " " + y);
  }

}