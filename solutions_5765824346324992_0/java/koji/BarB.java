import static java.util.stream.Collectors.*;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Arrays;
import java.util.List;
import java.util.stream.IntStream;
import java.util.stream.Stream;

public class BarB {
  public static void main(String[] args) throws IOException {
    try (Stream<String> lines = Files.lines(Paths.get("CodeJam/in/AA.in"))) {
      List<String> inputs = lines.collect(toList());
      int count = Integer.parseInt(inputs.get(0));
      for (int i = 0; i < count; i++) {
        int[] l1 = Arrays.stream(inputs.get(i * 2 + 1).split("\\s"))
            .mapToInt(Integer::parseInt)
            .toArray();
        int[] l2 = Arrays.stream(inputs.get(i * 2 + 2).split("\\s"))
            .mapToInt(Integer::parseInt)
            .toArray();
        int result = solve(l1[1], l2);
        System.out.println("Case #" + (i + 1) + ": " + result);
      }
    }

  }

  private static int solve(int count, int[] l2) {
    int[] o = new int[l2.length];
    System.arraycopy(l2, 0, o, 0, l2.length);
    count -= l2.length;
    int[] sorted = IntStream.of(l2).sorted().toArray();
    long r = 1;
    for (int i = 0; i < sorted.length; i++) {
      int l = sorted[i];
      r *= l;
      for (int j = i; j < sorted.length; j++) {
        if (sorted[j] % l == 0) {
          sorted[j] /= l;
        }
      }
      sorted = IntStream.of(sorted).sorted().toArray();
    }
    int sum = 0;
    for (int i = 0; i < l2.length; i++) {
      sum += r / l2[i];
    }
    count = count % sum;
    if (count == 0) {
      return l2.length;
    }

    while (true) {
      int min = IntStream.of(l2).min().getAsInt();
      for (int i = 0; i < l2.length; i++) {
        l2[i] -= min;
        if (l2[i] == 0) {
          count--;
          l2[i] = o[i];
          if (count == 0) {
            return i + 1;
          }
        }
      }
    }
  }
}