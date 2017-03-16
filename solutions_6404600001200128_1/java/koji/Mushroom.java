import static java.util.stream.Collectors.*;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Stream;

public class Mushroom {
  public static void main(String[] args) throws IOException {
    try (Stream<String> lines = Files.lines(Paths.get("CodeJam/in/AA.in"))) {
      List<String> inputs = lines.collect(toList());
      int count = Integer.parseInt(inputs.get(0));
      for (int i = 0; i < count; i++) {
        String[] repeat = inputs.get(i * 2 + 2).split("\\s");
        int[] nums = Arrays.stream(repeat).mapToInt(Integer::parseInt).toArray();

        String result = solve(nums);
        System.out.println("Case #" + (i + 1) + ": " + result);
      }
    }
  }

  private static String solve(int[] nums) {
    int prev = 0;
    int s1 = 0;
    for (int i = 0; i < nums.length; i++) {
      if (prev > nums[i]) {
        s1 += prev - nums[i];
      }
      prev = nums[i];
    }
    int max = 0;
    for (int i = 0; i < nums.length - 1; i++) {
      int diff = nums[i] - nums[i + 1];
      if (diff > 0 && max < diff) {
        max = diff;
      }
    }
    int s2 = 0;
    for (int i = 0; i < nums.length - 1; i++) {
      s2 += Math.min(max, nums[i]);
    }

    return s1 + " " + s2;
  }
}
