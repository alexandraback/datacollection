import java.io.*;
import java.util.*;
import java.math.*;

public class A implements Runnable {

    public void run() {
        long startTime = System.nanoTime();

        int t = nextInt();
        M:
        for (int cs = 0; cs < t; cs++) {

            int n = nextInt();
            String skellet = null;
            int[][] cnt = null;

            for (int i = 0; i < n; i++) {
                char[] s = nextToken().toCharArray();
                String cur = "";
                for (int j = 0; j < s.length; j++) {
                    if (j == 0 || s[j] != s[j - 1]) {
                        cur += s[j];
                    }
                }
                if (skellet == null) {
                    cnt = new int[(skellet = cur).length()][n];
                }
                if (!cur.equals(skellet)) {
                    while (++i < n) {
                        nextToken();
                    }
                    printf("Case #%d: %s\n", cs + 1, "Fegla Won");
                    continue M;
                }
                for (int j = 0, k = -1; j < s.length; j++) {
                    if (j == 0 || s[j] != s[j - 1]) {
                        k++;
                    } else {
                        cnt[k][i]++;
                    }
                }
            }

            int res = 0;
            for (int[] a : cnt) {
                Arrays.sort(a);
                for (int x : a) {
                    res += Math.abs(x - a[a.length >> 1]);
                }
            }
            printf("Case #%d: %d\n", cs + 1, res);

        }

        if (fileIOMode) {
            System.out.println((System.nanoTime() - startTime) / 1e9);
        }
        out.close();
    }

    //-----------------------------------------------------------------------------------

    private static boolean fileIOMode;
    private static String problemName = "a";
    private static BufferedReader in;
    private static PrintWriter out;
    private static StringTokenizer tokenizer;

    public static void main(String[] args) throws Exception {
        fileIOMode = args.length > 0 && args[0].equals("!");
        if (fileIOMode) {
            in = new BufferedReader(new FileReader(problemName + ".in"));
            out = new PrintWriter(problemName + ".out");
        } else {
            in = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(System.out);
        }
        tokenizer = new StringTokenizer("");

        new Thread(new A()).start();
    }

    private static String nextLine() {
        try {
            return in.readLine();
        } catch (IOException e) {
            return null;
        }
    }

    private static String nextToken() {
        while (!tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(nextLine());
        }
        return tokenizer.nextToken();
    }

    private static int nextInt() {
        return Integer.parseInt(nextToken());
    }

    private static long nextLong() {
        return Long.parseLong(nextToken());
    }

    private static double nextDouble() {
        return Double.parseDouble(nextToken());
    }

    private static BigInteger nextBigInteger() {
        return new BigInteger(nextToken());
    }

    private static void print(Object o) {
        if (fileIOMode) {
            System.out.print(o);
        }
        out.print(o);
    }

    private static void println(Object o) {
        if (fileIOMode) {
            System.out.println(o);
        }
        out.println(o);
    }

    private static void printf(String s, Object... o) {
        if (fileIOMode) {
            System.out.printf(s, o);
        }
        out.printf(s, o);
    }
}
