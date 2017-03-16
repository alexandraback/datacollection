import java.io.*;
import java.text.DecimalFormat;
import java.util.*;

/**
 * Created by Rafal on 4/12/14.
 */
public class A {

    public static void main(String[] args) {
        try {

            InputStream in = new FileInputStream("c:/projekty/codejam/src/A.in");
            Scanner scanner = new Scanner(in);
            OutputStream out = new FileOutputStream("c:/projekty/codejam/src/A.out");
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
        int n = scanner.nextInt();
        scanner.nextLine();
        String []strings = new String[n];
        for (int i = 0; i < n; i++) {
            strings[i] = scanner.nextLine();
        }


        int []idx = new int[n];
        // go through each unique character in
        boolean lost = false;
        int result = 0;
        while (true) {
            if (idx[0] >= strings[0].length()) {
                // check if all are at end
                for (int i = 0; i < n; i++) {
                    if (strings[i].length() != idx[i]) {
                        lost = true;
                    }
                }
                break;
            } else {
                // check character at X
                char c = strings[0].charAt(idx[0]);
                int lens[] = new int[n];
                int minLen = 9999999;
                int maxLen = 0;
                for (int i = 0; i < n; i++) {
                    int len = getLen(strings[i], idx[i], c);
                    if (len == -1) {
                        lost = true;
                        break;
                    }
                    lens[i] = len;
                    idx[i] += len;
                    if (len > maxLen) {
                        maxLen = len;
                    }
                    if (len < minLen) {
                        minLen = len;
                    }
                }
                result += getBest(minLen, maxLen, lens);
            }
            if (lost) {
                break;
            }

        }
        String resultTxt = "";
        if (lost) {
            resultTxt = "Fegla Won";
        } else {
            resultTxt = "" + result;
        }
        System.out.println("Case #" + t + ": " + resultTxt);
        out.println("Case #" + t + ": " + resultTxt);
    }

    private static int getBest(int minLen, int maxLen, int[] lens) {
        int result = 0;
        int bestResult = -1;
        for (int i = minLen; i <= maxLen; i++) {
            result = 0;
            for (int j = 0; j < lens.length; j++) {
                int diff = Math.abs(lens[j] - i);
                result += diff;
            }
            if (bestResult == -1 || result < bestResult) {
                bestResult = result;
            }
        }
        return bestResult;
    }

    private static int getLen(String string, int pos, char c) {

        if (pos >= string.length()) {
            return -1;
        }
        if (string.charAt(pos) != c) {
            return -1;
        }
        int cnt = 1;
        pos++;
        while (pos < string.length() && string.charAt(pos) == c) {
            cnt++;
            pos++;
        }
        return cnt;
    }

}
