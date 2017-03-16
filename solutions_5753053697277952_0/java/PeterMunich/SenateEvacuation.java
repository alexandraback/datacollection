
package codejam2016_1c;


import java.io.File;
import java.util.Scanner;


public class SenateEvacuation {
  public static void main(String[] args) {
    try {
      SenateEvacuation senateEvacuation = new SenateEvacuation();
//      senateEvacuation.executeBatch("src/codejam2016_1c/SenateEvacuationExample.txt");
      senateEvacuation.executeBatch("src/codejam2016_1c/A-small-attempt0.in");
//      senateEvacuation.executeBatch("src/codejam2016_1c/A-large.in");
    }
    catch (Exception exception) {
      System.out.println(exception.getMessage());
      exception.printStackTrace();
    }
  }

  private void executeBatch(String filename) throws Exception {
    Scanner scanner = new Scanner(new File(filename));
    int testCases = scanner.nextInt();
    for (int testCase = 1; testCase <= testCases; ++testCase)
      execute(testCase, scanner);
  }

  private void execute(int testCase, Scanner scanner) {
    int n = scanner.nextInt();

    int senators = 0;
    int[] parties = new int[n];
    for (int i = 0; i < n; ++i) {
      int party = scanner.nextInt();
      parties[i] = party;
      senators += party;
    }

    System.out.printf("Case #%d:", testCase);
    while (senators != 0) {
      int party = max(parties);
      --senators;
      System.out.printf(" %c", (char) ('A' + party));

      if (senators % 2 == 1) {
        party = max(parties);
        --senators;
        System.out.printf("%c", (char) ('A' + party));
      }
    }
    System.out.printf("\n");
  }

  private int max(int[] parties) {
    int party = 0;
    int max = parties[party];
    for (int i = 1; i < parties.length; ++i)
      if (parties[i] > max) {
        party = i;
        max = parties[party];
      }
    --parties[party];
    return party;
  }
}
