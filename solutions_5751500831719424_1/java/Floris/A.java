import java.io.*;
import java.util.*;

public class A {
    private static String NP = "NOT POSSIBLE";
    public static void main(String[] args) throws Exception {
//        InputStream in = System.in;
        InputStream in = new FileInputStream("/home/floris/Downloads/A-large.in");
        System.setOut(new PrintStream("/home/floris/temp/codejam2014/src/A.out"));
        Scanner sc = new Scanner(in);

        for (int c = 1, cases = sc.nextInt(); c <= cases; c++) {
            int N = sc.nextInt();
            String[] lines = new String[N];
            for (int i = 0; i < N; i++) lines[i] = sc.next();
            if (!possible(lines)) {
                System.out.printf("Case #%d: %s%n", c, "Fegla Won");
                continue;
            }
            int result = 0;
            String first = reduce(lines[0]);
            int[] pos = new int[N];
            for (int i = 0; i < first.length(); i++) {
                int[] count = new int[N];
                int max = 0;
                for (int j = 0; j < N; j++) {
                    for (int x = pos[j]; x < lines[j].length() && lines[j].charAt(x) == first.charAt(i); x++, count[j]++);
                    max = Math.max(max, count[j]);
                    pos[j] += count[j];
                }
                result += optimum(max, count);
            }
            System.out.printf("Case #%d: %d%n", c, result);
        }
    }

    private static boolean possible(String[] lines) {
        StringBuilder sb = new StringBuilder();
        String first = reduce(lines[0]);
        for (int i= 1; i < lines.length; i++) {
            if (!first.equals(reduce(lines[i]))) return false;
        }
        return true;
    }

    private static String reduce(String string) {
        char x = 0;
        StringBuilder sb= new StringBuilder();
        for (char c : string.toCharArray()) {
            if (c!=x) sb.append(c);
            x = c;
        }
        return sb.toString();
    }

    private static int optimum(int max, int[] count) {
        int min = Integer.MAX_VALUE;
        for (int i = 0; i <= max; i++) {
            int x = 0;
            for (int j = 0; j < count.length; j++) {
                x+= Math.abs(i - count[j]);
            }
            min = Math.min(min, x);
        }
        return min;
    }
}
