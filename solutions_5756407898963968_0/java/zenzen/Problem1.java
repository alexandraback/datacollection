package codejam;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Problem1 {

  public static void main(String[] args) throws FileNotFoundException {

    String fileName = Problem1.class.getResource("/input.txt").getPath();

    File problemFile = new File(fileName);

    Scanner scanner = new Scanner(problemFile);

    int cases = getOneInt(scanner);

    for (int i = 0; i < cases; i++) {
      int row = getOneInt(scanner);
      String[] firstLine = getLine(scanner, row);
      Set<String> first = new HashSet<String>(Arrays.asList(firstLine));

      row = getOneInt(scanner);
      String[] secondLine = getLine(scanner, row);

      String found = "";

      for (String nr : secondLine) {
        if (first.contains(nr)) {
          if (!found.isEmpty()) {
            found = "Bad magician!";
            break;
          } else {
            found = nr;
          }
        }
      }

      if (found.isEmpty()) {
        found = "Volunteer cheated!";
      }

      System.out.println("Case #" + (i + 1) + ": " + found);
    }


  }

  private static int getOneInt(Scanner s) {
    return Integer.parseInt(s.nextLine().split(" ")[0]);
  }

  private static String[] getLine(Scanner scanner, int row) {
    String[] result = null;
    for (int j = 0; j < 4; j++) {
      final String line = scanner.nextLine();
      if (row == j + 1) {
        result = line.split(" ");
      }
    }
    return result;
  }

}
