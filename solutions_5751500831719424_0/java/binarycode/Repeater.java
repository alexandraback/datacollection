import java.util.*;
import java.io.*;

public class Repeater {
  private Scanner in;

  public Repeater() {
    in = new Scanner(System.in);

    int T = in.nextInt();

    for (int t = 1; t <= T; t++) {
      int N = in.nextInt();

      int[][] shifts = new int[N][100];
      boolean failed = false;

      String origin = "";
      String word;
      String origin2;
      in.nextLine();

      for (int i = 0; i < N; i++) {
        word = in.nextLine();
        origin2 = "";

        if (!failed) {

          boolean first = true;
          char currentSymbol = 'a';
          int position = -1;

          for (int j = 0; j < word.length(); j++) {
            char symbol = word.charAt(j);

            if (first || (symbol != currentSymbol)) {
              position++;
              shifts[i][position] = 0;
              currentSymbol = symbol;
              first = false;
              origin2 += symbol;
            } else {
              shifts[i][position]++;
            }
          }

          if (origin.length() == 0) origin = origin2;

          if (!origin.equals(origin2)) failed = true;
        }
      }


      //System.out.println(shifts);

      //for (int i = 0; i < N; i++) {
        //for (int j = 0; j < 5; j++) {
          //System.out.print("" + shifts[i][j] + " ");
        //}
        //System.out.println();
      //}

      if (failed) {
        System.out.println("Case #" + t + ": Fegla Won");
      } else {
        int originLen = origin.length();
        long dist = 0;

        for (int i = 0; i < originLen; i++) {
          long sum = 0;
          for (int j = 0; j < N; j++) {
            sum += shifts[j][i];
          }
          long avg = sum / N;

          for (int j = 0; j < N; j++) {
            dist += Math.abs(avg - shifts[j][i]);
          }
        }

        System.out.println("Case #" + t + ": " + dist);
      }
    }
  }

  public static void main(String[] args) {
    new Repeater();
  }
}
