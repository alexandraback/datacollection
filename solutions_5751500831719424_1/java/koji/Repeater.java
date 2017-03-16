import java.io.IOException;
import java.nio.file.FileSystems;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

/**
 * Created by kojilin on 2014/05/04.
 */
public class Repeater {

  public static void main(String[] args) throws IOException {
    Path path = FileSystems.getDefault().getPath("GCJ", "r1.txt");
    List<String> lines = Files.lines(path).collect(Collectors.toList());
    int count = 1;
    int i = 1;
    while (i < lines.size()) {
      int wordsCount = Integer.parseInt(lines.get(i));
      ++i;
      List<String> words = new ArrayList<>();
      for (int j = 0; j < wordsCount; ++j) {
        words.add(lines.get(i));
        ++i;
      }
      System.out.println("Case #" + (count) + ": " + solve(words));
      count++;
    }
  }

  private static String solve(final List<String> words) {

    int total = -1;
    char[] tombs = null;
    int[][] count = new int[words.size()][100];
    int[] max = new int[100];
    for (int i1 = 0; i1 < words.size(); i1++) {
      final String word = words.get(i1);
      char[] chars = new char[word.length()];
      int index = 0;
      for (int i = 0; i < word.length(); ++i) {
        char t = word.charAt(i);
        if (i == 0) {
          chars[index] = t;
          count[i1][index] = 1;
        } else {
          if (chars[index] != t) {
            index++;
            chars[index] = t;
            count[i1][index] = 1;
          } else {
            count[i1][index] += 1;
          }
        }
        max[index] = Math.max(max[index], count[i1][index]);
      }
      if (total == -1) {
        total = index + 1;
        tombs = new char[index + 1];
        System.arraycopy(chars, 0, tombs, 0, index + 1);
      } else if (index + 1 != total) {
        return "Fegla Won";
      } else {
        for (int i = 0; i < total; ++i) {
          if (tombs[i] != chars[i]) {
            return "Fegla Won";
          }
        }
      }
    }

    int result = 0;
    for (int i = 0; i < tombs.length; ++i) {
      int r = Integer.MAX_VALUE; //every tomb
      for (int k = 1; k <= max[i]; ++k) {
        int kr = 0;
        for (int j = 0; j < count.length; ++j) {
          int target = count[j][i];
          if (target == 0) {
            throw new RuntimeException("WTF");
          }
          kr += Math.abs(k - target);
        }
        r = Math.min(r, kr);
      }
      result += r;
    }

    return result + "";
  }
}
