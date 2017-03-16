import java.io.*;
import java.text.DecimalFormat;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

/**
 * Created by Rafal on 4/12/14.
 */
public class A {

    public static void main(String[] args) {
        try {

            InputStream in = new FileInputStream("c:/codejam/A.in");
            Scanner scanner = new Scanner(in);
            OutputStream out = new FileOutputStream("c:/codejam/A.out");
            PrintWriter writer = new PrintWriter(new OutputStreamWriter(out, "utf8"));
            int t = scanner.nextInt();
            for (int i = 0; i < t; i++) {
                solve(scanner, i+1, writer);
            }
            writer.close();
        } catch (Exception e) {
            System.out.println("Error: " + e);
            e.printStackTrace();
        }
    }


    public static void solve(Scanner scanner, int t, PrintWriter out) {
        int row1 = scanner.nextInt();
        Set<Integer> set = new HashSet<Integer>();
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                int x = scanner.nextInt();
                if (i == row1 - 1) {
                    set.add(x);
                }
            }
        }
        Integer result = null;
        boolean badMagician = false;
        int row2 = scanner.nextInt();
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                int x = scanner.nextInt();
                if (i == row2 - 1) {
                    if (set.contains(x)) {
                        if (result == null) {
                            result = x;
                        } else {
                            badMagician = true;
                        }
                    }
                }
            }
        }

        String resultTxt;
        if (badMagician) {
            resultTxt = "Bad magician!";
        } else if (result == null) {
            resultTxt = "Volunteer cheated!";
        } else {
            resultTxt = "" + result;
        }
        System.out.println("Case #" + t + ": " + resultTxt);
        out.println("Case #" + t + ": " + resultTxt);
    }

}
