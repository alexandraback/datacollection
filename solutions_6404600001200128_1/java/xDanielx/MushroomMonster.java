package mushroommonster;

import java.util.Scanner;

public class MushroomMonster {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int numTestCases = sc.nextInt();
    for (int testCase = 1; testCase <= numTestCases; ++testCase) {
      int n = sc.nextInt();
      int[] mushroomsOnPlate = new int[n];
      for (int i = 0; i < n; ++i)
        mushroomsOnPlate[i] = sc.nextInt();
      System.out.printf("Case #%d: %d %d\n", testCase,
          minMushrooms1(mushroomsOnPlate),
          minMushrooms2(mushroomsOnPlate));
    }
  }

  private static int minMushrooms1(int[] mushroomsOnPlate) {
    int eaten = 0;
    for (int i = 1; i < mushroomsOnPlate.length; ++i) {
      int drop = mushroomsOnPlate[i - 1] - mushroomsOnPlate[i];
      if (drop > 0) eaten += drop;
    }
    return eaten;
  }

  private static int minMushrooms2(int[] mushroomsOnPlate) {
    int eatRate = 0;
    for (int i = 1; i < mushroomsOnPlate.length; ++i) {
      int drop = mushroomsOnPlate[i - 1] - mushroomsOnPlate[i];
      eatRate = Math.max(eatRate, drop);
    }

    int eaten = 0;
    for (int i = 0; i < mushroomsOnPlate.length - 1; ++i) {
      eaten += Math.min(mushroomsOnPlate[i], eatRate);
    }
    return eaten;
  }
}
