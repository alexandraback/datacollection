import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;


public class Solution {
    public static void main(String args[]) throws FileNotFoundException {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(new File("output"));
        //PrintWriter out = new PrintWriter(System.out);
        int T = in.nextInt();
        int i, j, k;
        for (int curTest = 1; curTest <= T; curTest++) {
            int n = in.nextInt();
            String[] s = new String[n];
            for (i = 0; i < n; i++) {
                s[i] = in.next();
            }

            String canonical = getCanonical(s[0]);
            boolean feglaWon = false;
            for (i = 0; i < n; i++) {
                if (!canonical.equals(getCanonical(s[i]))) {
                    feglaWon = true;
                }
            }

            out.print("Case #" + curTest + ": ");
            if (feglaWon) {
                out.println("Fegla won");
                continue;
            }

            int[][] nums = new int[n][canonical.length()];
            for (i = 0; i < n; i++) {
                nums[i] = getNums(s[i], canonical.length());
            }
            int ans = 0;
            for (i = 0; i < canonical.length(); i++) {
                int best = 1000000;
                for (j = 0; j <= 100; j++) {
                    int cur = 0;
                    for (k = 0; k < n; k++) {
                        cur += Math.abs(j - nums[k][i]);
                    }
                    best = Math.min(best, cur);
                }
                ans += best;
            }
            out.println(ans);
        }
        in.close();
        out.close();
    }

    static String getCanonical(String s) {
        String ret = "";
        char last = '0';
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) != last) {
                ret += s.charAt(i);
                last = s.charAt(i);
            }
        }
        return ret;
    }

    static int[] getNums(String s, int canonicalLength) {
        int[] ret = new int[canonicalLength];
        int curIndex = 0;
        int curLen = 0;
        char last = s.charAt(0);
        for (int i = 0; i < s.length(); i++) {
            if (last != s.charAt(i)) {
                ret[curIndex++] = curLen;
                curLen = 1;
                last = s.charAt(i);
            } else {
                curLen++;
            }
        }
        ret[curIndex] = curLen;
        return ret;
    }

}