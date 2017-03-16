import java.util.Scanner;

public class Solution
{

  static final int NUM_ROW = 4;
  static final int NUM_COL = 4;
  static final int NUM_CARD = NUM_ROW * NUM_COL;

  private boolean[] first;
  private boolean[] second;

  public Solution (Scanner sc)
  {
    first = mark(sc);
    second = mark(sc);
  }

  public void solve ()
  {
    System.out.format(" %s\n", guess());
  }

  private boolean[] mark (Scanner sc)
  {
    boolean[] flag = new boolean[NUM_CARD];
    int row = sc.nextInt() - 1;
    sc.nextLine();
    for (int i = 0; i < NUM_ROW; ++i)
    {
      if (i == row)
      {
        for (int j = 0; j < NUM_COL; ++j)
          flag[sc.nextInt() - 1] = true;
      }
      sc.nextLine();
    }
    return flag;
  }

  private String guess ()
  {
    int guess = -1;
    for (int i = 0; i < NUM_CARD; ++i)
      if (first[i] && second[i])
      {
        if (guess != -1)
          return "Bad magician!";
        guess = i;
      }
    if (guess == -1)
      return "Volunteer cheated!";
    return Integer.toString(guess + 1);
  }

  public static void main (String[] args)
  {
    Scanner sc = new Scanner(System.in);
    int T = sc.nextInt();
    for (int t = 1; t <= T; ++t)
    {
      Solution sol = new Solution(sc);
      System.out.format("Case #%d:", t);
      sol.solve();
    }
    sc.close();
  }

}
