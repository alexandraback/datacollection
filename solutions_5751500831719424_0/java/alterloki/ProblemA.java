package y2014.contest.r1b;

import common.ParseUtil;

import java.util.*;

/**
 * Created with IntelliJ IDEA.
 * User: ashevenkov
 * Date: 03.05.14
 * Time: 19:54
 */
public class ProblemA {

    static String INPUT =
            "5\n" +
                    "2\n" +
                    "mmaw\n" +
                    "maw\n" +
                    "2\n" +
                    "gcj\n" +
                    "cj\n" +
                    "3\n" +
                    "aaabbb\n" +
                    "ab\n" +
                    "aabb\n" +
                    "2\n" +
                    "abc\n" +
                    "abc\n" +
                    "3\n" +
                    "aabc\n" +
                    "abbc\n" +
                    "abcc";

    public static void main(String[] args) {
        //new ProblemA().run(INPUT);
        new ProblemA().run(ParseUtil.parseFile("A-small-attempt0.in"));
    }

    private void run(String input) {
        String[] lines = input.split("\n");
        int ln = 0;
        int n = Integer.parseInt(lines[ln++]);
        for (int i = 0; i < n; i++) {
            String line = lines[ln++];
            int num = Integer.parseInt(line);
            List<String> inStrings = new ArrayList<String>();
            for (int k = 0; k < num; k++) {
                line = lines[ln++];
                inStrings.add(line);
            }
            System.out.println("Case #" + (i + 1) + ": " + solve(num, inStrings));
        }
    }

    private String solve(int n, List<String> inStrings) {
        String first = uniq(inStrings.get(0));
        for (String inString : inStrings) {
            if (!first.equals(uniq(inString))) {
                return "Fegla Won";
            }
        }
        char[] ca = first.toCharArray();
        int[][] lettersCount = new int[inStrings.size()][];
        for (int i = 0; i < n; i++) {
            lettersCount[i] = new int[ca.length];
            String word = inStrings.get(i);
            char[] worda = word.toCharArray();
            int letterIndex = 0;
            for (int j = 0; j < worda.length; j++) {
                char c = worda[j];
                if (j != 0) {
                    if (c != worda[j - 1]) {
                        letterIndex++;
                    }
                }
                lettersCount[i][letterIndex]++;
            }
        }
        int[] maxLetterCount = new int[ca.length];
        for (int i = 0; i < lettersCount.length; i++) {
            int[] wordLettersCount = lettersCount[i];
            for (int j = 0; j < wordLettersCount.length; j++) {
                int let = wordLettersCount[j];
                if(maxLetterCount[j] < let) {
                    maxLetterCount[j] = let;
                }
            }
        }
        int result = 0;
        for (int i = 0; i < maxLetterCount.length; i++) {
            int maxCount = maxLetterCount[i];
            if(maxCount > 1) {
                int minSteps = Integer.MAX_VALUE;
                for(int j = 1; j <= maxCount; j++) {
                    int steps = 0;
                    for(int k = 0; k < n; k++) {
                        steps += Math.abs(lettersCount[k][i] - j);
                    }
                    if(steps < minSteps) {
                        minSteps = steps;
                    }
                }
                result += minSteps;
            }
        }
        return Integer.toString(result);
    }

    private String uniq(String in) {
        StringBuilder result = new StringBuilder();
        char[] ina = in.toCharArray();
        for (int i = 0; i < ina.length; i++) {
            char c = ina[i];
            if (i == 0) {
                result.append(c);
            } else {
                if (c != ina[i - 1]) {
                    result.append(c);
                }
            }
        }
        return result.toString();
    }
}
