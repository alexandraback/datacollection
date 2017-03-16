package carol.cj2015.r1A;

import java.io.*;
import java.util.*;

public class B {

    static final String TYPE = "B";
    static String inputFile;
    static String outputFile;
    static String keyFile;

    private static void Name(String s) {
        inputFile = s + ".in";
        outputFile = s + ".out";
        keyFile = s + ".key";
    }

    public static void main(String[] args) throws FileNotFoundException {

        String root = "data/CJ2015/r1A";

        // Test
        // Name(TYPE + "-test");
        Name("B-small-attempt0");

        Scanner in = new Scanner(new File(root, inputFile));
        PrintWriter out = new PrintWriter(new File(root, outputFile));

        int T = in.nextInt();

        for (int i = 0; i < T; i++) {

            int B = in.nextInt();
            long N = in.nextLong();
            int[] m = new int[B];
            for (int j = 0; j < B; j++) {
                m[j] = in.nextInt();
            }

            long s = 0;
            long e = (long)Math.pow(10, 14);
            long res = 0;
            while (s < e) {
                // System.out.println(s);
                // System.out.println(e);
                long mid = s + (e - s) / 2;
                long sum = 0;
                for (int j = 0; j < B; j++) {
                    sum += (long)Math.ceil((mid + 1) / (double)m[j]);
                }
                if (sum < N) {
                    s = mid + 1;
                } else if (sum >= N) {
                    e = mid;
                }
            }
            long sum = 0;
            for (int j = 0; j < B; j++) {
                sum += (long)Math.ceil((e + 1) / (double)m[j]);
            }
            // System.out.println(sum);
            long a = sum - N;
            for (int j = B - 1; j >= 0; j--) {
                if (e % m[j] == 0) {
                    if (a == 0) {
                        res = j + 1;
                    }
                    a--;
                }
            }
            // System.out.println(res);
            out.println("Case #" + (i + 1) + ": " + res);

        }

        in.close();
        out.close();

        // check(root);

    }

    public static List<String> check(String root) {

        Scanner key = null;
        Scanner out = null;
        List<String> diffs = new ArrayList<String>();
        try {
            key = new Scanner(new File(root, keyFile));
            out = new Scanner(new File(root, outputFile));
            String lineKey = "";
            String lineOut = "";
            int lineNum = 0;
            while (key.hasNext() && out.hasNext()) {
                lineKey = key.nextLine();
                lineOut = out.nextLine();
                lineNum++;
                if (!lineKey.equals(lineOut)) {
                    diffs.add("Differ at line " + lineNum + ": \n\tOutput : " + lineOut + "\n\tKey    : " + lineKey);
                }
            }

            while (!key.hasNext() && out.hasNext()) {
                lineOut = out.nextLine();
                lineNum++;
                diffs.add("Output has extra lines at line " + lineNum + ": \n\tOutput : " + lineOut);
            }

            while (key.hasNext() && !out.hasNext()) {
                lineKey = key.nextLine();
                lineNum++;
                diffs.add("Key has extra lines at line " + lineNum + ": \n\tKey    : " + lineKey);
            }
        } catch (Exception e) {
            System.out.println(e);

        } finally {
            if (key != null) {
                key.close();
            }

            if (out != null) {
                out.close();
            }
        }

        for (String line : diffs) {
            System.out.println(line);
        }

        return diffs;
    }

}