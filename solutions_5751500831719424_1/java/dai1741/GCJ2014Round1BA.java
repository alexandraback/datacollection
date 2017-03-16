import java.util.ArrayList;
import java.util.Scanner;


public class GCJ2014Round1BA {

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int i = 1; i <= t; i++) {
            System.out.printf("Case #%d: %s%n", i, new GCJ2014Round1BA().solve(sc));
        }
    }

    private String solve(Scanner sc) throws Exception {
        int n = sc.nextInt();
        String[] ss = new String[n];
        for (int i = 0; i < n; i++) {
            ss[i] = sc.next();
        }
        String bs = ss[0];
        ArrayList<Character> chars = new ArrayList<>();
        char curChar = 0;
        for (int i = 0; i < bs.length(); i++) {
            char c = bs.charAt(i);
            if (curChar != c) {
                chars.add(c);
                curChar = c;
            }
        }
        int numChars = chars.size();
        int[][] numRepeats = new int[n][numChars];
        for (int i = 0; i < n; i++) {
            String s = ss[i];
            curChar = 0;
            int charsI = -1;
            for (int ci = 0; ci < s.length(); ci++) {
                char c = s.charAt(ci);
                if (curChar != c) {
                    curChar = c;
                    charsI++;
                    if (charsI >= numChars || chars.get(charsI) != c) return "Fegla Won";
                }
                numRepeats[i][charsI]++;
            }
            if (charsI != numChars -1) return "Fegla Won";
        }
        int ans = 0;
        for (int ci = 0; ci < numChars; ci++) {
            int bestNumTurns = 100000000;
            for (int aveCount = 1; aveCount <= 100; aveCount++) {
                int numTurns = 0;
                for (int i = 0; i < n; i++) {
                    numTurns += Math.abs(numRepeats[i][ci] - aveCount);
                }
                bestNumTurns = Math.min(bestNumTurns, numTurns);
            }
            ans += bestNumTurns;
        }
        return Integer.toString(ans);
    }
}
