import java.util.Scanner;

public class SolutionRecursive {

  private static class Solver {
    long r, c, n;

    public Solver(long r, long c, long n) {
      this.r = r;
      this.c = c;
      this.n = n;
    }

    private int recurse(boolean[][] m, int remaining, int currentSum, int best) {
      int row, col, newSum, res;
      if (remaining == 0) {
        return currentSum;
      }

      for (col = 0; col < c; col++) {
        for (row = 0; row < r; row++) {
          if (!m[row][col]) {
            newSum = currentSum;
            newSum += (row > 0 && m[row - 1][col]) ? 1 : 0;
            newSum += (row < r - 1 && m[row + 1][col]) ? 1 : 0;

            newSum += (col > 0 && m[row][col  - 1]) ? 1 : 0;
            newSum += (col < c - 1 && m[row][col + 1]) ? 1 : 0;

            if (newSum < best) {
              m[row][col] = true;
              res = recurse(m, remaining - 1, newSum, best);

              if (res < best) {
                best = res;
              }

              m[row][col] = false;
            }
          }
        }
      }

      return best;
    }

    public long getSolution() {
      boolean[][] m0 = new boolean[(int)r][(int)c];
      boolean[][] m1 = new boolean[(int)r][(int)c];

      int rem0 = (int)n;
      int rem1 = (int)n;

      for (int row = 0; row < r; row++) {
        for (int col = 0; col < c; col++) {
          if ((row + col) % 2 == 0) {
            m0[row][col] = true;
            rem0--;
          } else {
            m1[row][col] = true;
            rem1--;
          }
        }
      }

      if (rem0 <= 0 || rem1 <= 0) {
        return 0;
      }

      int best0 = recurse(m0, (int)rem0, 0, (int)(r * c * 4));
      int best1 = recurse(m1, (int)rem1, 0, best0);
      return best0 < best1 ? best0 : best1;
    }

    public static Solver fromScanner(Scanner scanner) {
      long r, c, n;
      r = scanner.nextLong();
      c = scanner.nextLong();
      n = scanner.nextLong();
      return new Solver(r, c, n);
    }
  }

  public static void main(String[] args) {
    // try {
    //     System.setIn(new java.io.FileInputStream("B-small-attempt2.in"));
    // } catch (java.io.FileNotFoundException e) {
    // }
    // try {
    //     System.setOut(new java.io.PrintStream(new java.io.File("B-small-attempt2.out")));
    // } catch (java.io.FileNotFoundException e) {
    // }
    Scanner scanner = new Scanner(System.in);

    int t = scanner.nextInt();

    for (int tc = 1; tc <= t; tc++) {
      Solver s = Solver.fromScanner(scanner);
      System.out.println("Case #" + String.valueOf(tc) + ": " + String.valueOf(s.getSolution()));
    }
  }
}
