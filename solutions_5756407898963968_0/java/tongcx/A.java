import java.util.*;

class A {
  static Scanner cin;

  static void readGrid(int[][] grid) {
    for (int i = 0; i < 4; i++)
      for (int j = 0; j < 4; j++)
        grid[i][j] = cin.nextInt();
  }

  public static void main(String[] args) {
    cin = new Scanner(System.in);
    int T = cin.nextInt();
    for (int caseNo = 1; caseNo <= T; caseNo++) {
      int row;
      int[][] grid = new int[4][4];

      TreeSet<Integer> s1 = new TreeSet<Integer>();
      row = cin.nextInt()-1;
      readGrid(grid);
      for (int j = 0; j < 4; j++)
        s1.add(grid[row][j]);

      TreeSet<Integer> s2 = new TreeSet<Integer>();
      row = cin.nextInt()-1;
      readGrid(grid);
      for (int j = 0; j < 4; j++)
        s2.add(grid[row][j]);

      s1.retainAll(s2);
      System.out.format("Case #%d: ", caseNo);
      if (s1.isEmpty())
        System.out.println("Volunteer cheated!");
      else if (s1.size() > 1)
        System.out.println("Bad magician!");
      else
        System.out.println(s1.first());
    }
  }
}
