package c;

import java.io.File;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;

public class TheRepeater {

    public static void main(String[] args) throws Exception {
//        String testCase = "A-small-attempt0";
        String testCase = "A-large";
        Scanner scanner = new Scanner(new File("input/" + testCase + ".in"));
        PrintStream output = new PrintStream(new File("output/" + testCase + ".out"));

        int cases = scanner.nextInt();
        for (int i = 1; i <= cases; i++) {
            int line = scanner.nextInt();
            String[] lines = readLines(scanner, line);
            try {
                output.println("Case #" + i + ": " + calculate(lines));
            } catch (Exception ignored) {
                output.println("Case #" + i + ": Fegla Won");
            }
            output.flush();
        }
        scanner.close();
        output.close();
    }

    private static String[] readLines(Scanner scanner, int line) {
        String[] lines = new String[line];
        for (int i = 0; i < line; i++) lines[i] = scanner.next();
        return lines;
    }

    private static int calculate(String[] lines) throws Exception {
        int operations = 0;
        while (!allEmpty(lines)) {
            String[] segments = new String[lines.length];
            int[] counts = new int[lines.length];
            for (int i = 0; i < lines.length; i++) {
                segments[i] = findSegment(lines[i], 0);
                lines[i] = lines[i].substring(segments[i].length());
                if (i > 0 && segments[i].charAt(0) != segments[i - 1].charAt(0)) throw new Exception();
                counts[i] = segments[i].length();
            }
            Arrays.sort(counts);

            int target = counts[lines.length / 2];
            for (String segment : segments) {
                operations += Math.abs(target - segment.length());
            }
        }
        return operations;
    }

    private static boolean allEmpty(String[] lines) {
        for (String line : lines) {
            if (line.length() > 0) return false;
        }
        return true;
    }

    private static String findSegment(String line, int offset) {
        char c = line.charAt(offset);
        for (int i = offset + 1; i < line.length(); i++) {
            if (line.charAt(i) != c) return line.substring(offset, i);
        }
        return line.substring(offset);
    }
}