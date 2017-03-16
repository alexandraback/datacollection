import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.List;

public class A {
  public static void main(String[] args) throws Exception {
    if (args.length != 2) {
      System.err.println("Usage: java " + A.class.getName()
          + " [input] [output]");
      System.exit(1);
    }
    BufferedReader br = new BufferedReader(new FileReader(args[0]));
    BufferedWriter bw = new BufferedWriter(new FileWriter(args[1]));
    int testCases = Integer.parseInt(br.readLine());
    for (int testCase = 1; testCase <= testCases; testCase++) {
      bw.write("Case #" + testCase + ": ");
      boolean feglaWon = false;
      int n = Integer.parseInt(br.readLine());
      String pattern = null;
      List<List<Integer>> allCounts = new ArrayList<List<Integer>>();
      for (int i = 0; i < n; i++) {
        String line = br.readLine();
        char lastChar = '*';
        List<Integer> counts = new ArrayList<Integer>();
        int count = 0;
        StringBuilder sb = new StringBuilder();
        for (char c : line.toCharArray()) {
          if (lastChar == '*') {
            lastChar = c;
            sb.append(c);
            count = 1;
          } else if (lastChar == c) {
            count++;
          } else {
            counts.add(count);
            sb.append(c);
            lastChar = c;
            count = 1;
          }
        }
        counts.add(count);
        allCounts.add(counts);
        if (pattern == null) {
          pattern = sb.toString();
        } else if (!pattern.equals(sb.toString())) {
          feglaWon = true;
        }
      }
      if (feglaWon) {
        bw.write("Fegla Won\n");
      } else {
        int result = 0;
        for (int i = 0; i < pattern.length(); i++) {
          List<Integer> current = new ArrayList<Integer>();
          int min = 100, max = 1;
          for (List<Integer> counts : allCounts) {
            int next = counts.get(i);
            current.add(next);
            min = Math.min(min, next);
            max = Math.max(max, next);
          }
          int minTotal = Integer.MAX_VALUE;
          for (int j = min; j <= max; j++) {
            int total = 0;
            for (int c : current) {
              total += Math.abs(c - j);
            }
            minTotal = Math.min(minTotal, total);
          }
          result += minTotal;
        }
        bw.write(result + "\n");
      }
    }
    br.close();
    bw.close();
  }
}
