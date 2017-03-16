import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;


public class A {

  static String inputFile = "A-small-attempt1.in";
  static String outputFile = "A-small-attempt1.out";
  
  public static void main(String[] args) throws FileNotFoundException {
    Scanner in = new Scanner(new File(inputFile));
    PrintWriter out = new PrintWriter(new File(outputFile));
    
    int T = in.nextInt();
    for (int t = 1; t <= T; t++) {
      out.println("Case #" + t + ": " + solve(in));
    }
    out.close();
  }

  private static String solve(Scanner in) {
    int n = 4;
    
    int row1 = in.nextInt() - 1;
    int map1[][] = new int[n][n];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        map1[i][j] = in.nextInt();
      }
    }
    
    int row2 = in.nextInt() - 1;
    int map2[][] = new int[n][n];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        map2[i][j] = in.nextInt();
      }
    }
    
    int count[] = new int[17];
    for (int i = 0; i < n; i++) {
      count[map1[row1][i]]++;
      count[map2[row2][i]]++;
    }
    
    int can = 0;
    int canRes = 0;
    for (int i = 0; i < count.length; i++) {
      if(count[i] == 2) {
        can++;
        canRes = i;
      }
    }
    if(can == 0) return "Volunteer cheated!";
    else if(can == 1) return canRes + "";
    return "Bad magician!";
  }

}
