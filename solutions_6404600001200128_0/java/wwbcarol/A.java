package carol.cj2015.r1A;

import java.io.*;
import java.util.*;

public class A {

    static final String TYPE = "A";
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
        Name("A-small-attempt0");

        Scanner in = new Scanner(new File(root, inputFile));
        PrintWriter out = new PrintWriter(new File(root, outputFile));

        int T = in.nextInt();

        for (int i = 0; i < T; i++) {
            int N = in.nextInt();
            int[] m = new int[N];
            for (int j = 0; j < N; j++) {
                m[j] = in.nextInt();
            }

            int res1 = 0;
            int rate = 0;
            for (int j = 1; j < N; j++) {
                if (m[j] < m[j - 1]) {
                    int sub = m[j - 1] - m[j];
                    res1 += sub;
                    if (sub > rate) {
                        rate = sub;
                    }
                }
            }

            int res2 = 0;
            System.out.println(i + 1 + ": " + rate);
            int sum = 0;
            for (int j = 0; j < N - 1; j++) {
                // sum += m[j];
                // if (sum >= rate) {
                // sum = sum - rate;
                // res2 += rate;
                // } else {
                // res2 += sum;
                // sum = 0;
                // }
                if (m[j] > rate) {
                    res2 += rate;
                } else {
                    res2 += m[j];
                }
            }
            out.println("Case #" + (i + 1) + ": " + res1 + " " + res2);

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