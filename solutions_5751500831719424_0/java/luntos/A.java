import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class A {
    private static int[][] amounts = new int[100][100];
    private static String removeRepeats(String str, int i) {
        String res = "";
        int j = 1;
        int k = 0;
        amounts[i][k] = 1;
        res += str.charAt(0);
        while (j < str.length()) {
            while ((j < str.length()) && (str.charAt(j) == str.charAt(j - 1))) {
                amounts[i][k]++;
                j++;
            }
            if (j < str.length()) {
                k++;
                amounts[i][k] = 1;
                res += str.charAt(j);
                j++;
            }
        }

        return res;
    }
    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(new File("A-small-attempt0.in"));
        PrintWriter writer = new PrintWriter("A-small-attempt0.out");
        int cases = sc.nextInt();
        for (int i = 0; i < cases; i++) {
            writer.print("Case #" + (i + 1) + ": ");
            int n = sc.nextInt();
            sc.nextLine();
            String[] strings = new String[n];
            String f = null;
            boolean won = false;
            for (int j = 0; j < n; j++) {
              strings[j] = sc.nextLine();
              if (j == 0) {
                  f = removeRepeats(strings[j], j);
              } else {
                  String str = removeRepeats(strings[j], j);
                  if (!str.equals(f)) {
                      writer.println("Fegla Won");
                      won = true;
                      break;
                  }
              }
            }

            if (won) {
                continue;
            }
            int minSum = 0;
            for (int d = 0; d < f.length(); d++) {
                int min = Integer.MAX_VALUE;
                for (int a = 1; a <= 100; a++) {
                    int sum = 0;
                    for (int j = 0; j < n; j++) {
                        sum += Math.abs(amounts[j][d] - a);
                    }
                    if (sum < min) {
                        min = sum;
                    }
                }
                minSum += min;
            }
            writer.println(minSum);
        }

        writer.flush();
        writer.close();
    }
}
