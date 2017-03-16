import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;


public class TheRepeater {

    private static final String inputName = "e:/downloads/A-small-attempt1.in";
    private static final String outputName = "C:/workspaces/algo/GCJ/src/prolemA.out";

    private static List<Character> getChars(String str) {
        int ind = 0;
        char prevCh = 0;
        int count = 0;
        List<Character> chars = new ArrayList<>();
        List<Integer> counts = new ArrayList<>();
        while (ind < str.length()) {
            char ch = str.charAt(ind);
            if (ch == prevCh) {
                count++;
            } else {
                if (prevCh != 0) {
                    chars.add(prevCh);
                    counts.add(count);
                }
                count = 0;
                prevCh = ch;
            }
            ind++;
        }
        chars.add(prevCh);
        counts.add(count);
        count = 0;
        return chars;
    }

    private static List<Integer> getCounts(String str) {
        int ind = 0;
        char prevCh = 0;
        int count = 0;
        List<Character> chars = new ArrayList<>();
        List<Integer> counts = new ArrayList<>();
        while (ind < str.length()) {
            char ch = str.charAt(ind);
            if (ch == prevCh) {
                count++;
            } else {
                if (prevCh != 0) {
                    chars.add(prevCh);
                    counts.add(count);
                }
                prevCh = ch;
                count = 1;
            }
            ind++;
        }
        chars.add(prevCh);
        counts.add(count);
        count = 0;
        return counts;
    }

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(new FileReader(inputName));
        // Scanner sc = new Scanner(System.in);
        BufferedWriter bw = new BufferedWriter(new FileWriter(outputName));
        int T = sc.nextInt();
        for (int t = 0; t < T; t++) {
            int N = sc.nextInt();
            String[] strs = new String[N];
            for (int i = 0; i < N; i++) {
                strs[i] = sc.next();
            }
            String res = solve(strs);
            String str = String.format("Case #%s: %s\n", t + 1, res);
            bw.write(str);
            System.out.print(str);
        }
        bw.close();
    }

    private static String solve(String[] strs) {
        Set<Integer> sizes = new HashSet<>();
        char[][] strChars = new char[strs.length][];
        for (int i = 0; i < strs.length; i++) {
            String str = strs[i];
            List<Character> chars = getChars(str);
            strChars[i] = new char[chars.size()];
            for (int j = 0; j < chars.size(); j++) {
                strChars[i][j] = chars.get(j);
            }
            sizes.add(chars.size());
        }
        if (sizes.size() > 1) {
            return "Fegla Won";
        }
        for (int i = 0; i < strChars[0].length; i++) {
            Set<Character> chars = new HashSet<>();
            for (int j = 0; j < strs.length; j++) {
                chars.add(strChars[j][i]);
            }
            if (chars.size() > 1) {
                return "Fegla Won";
            }
        }
        int charQuantity = getCounts(strs[0]).size();
        int[][] charCounts = new int[charQuantity][strs.length];
        for (int i = 0; i < strs.length; i++) {
            List<Integer> counts = getCounts(strs[i]);
            for (int j = 0; j < charQuantity; j++) {
                charCounts[j][i] = counts.get(j);
            }
        }
        int res = 0;
        for (int i = 0; i < charQuantity; i++) {
            int charRes = Integer.MAX_VALUE;
            for (int k = 1; k <= 200; k++) {
                int tempRes = 0;
                for (int j = 0; j < strs.length; j++) {
                    tempRes += Math.abs(charCounts[i][j] - k);
                }
                charRes = Math.min(tempRes, charRes);
            }
            res += charRes;
        }
        return "" + res;
    }


}
