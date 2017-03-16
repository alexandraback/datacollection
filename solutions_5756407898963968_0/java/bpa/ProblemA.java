import java.io.*;
import java.util.*;

public class ProblemA implements Runnable {

    void solveMultiTest() throws IOException {
        int testCases = nextInt();
        for (int testCase = 1; testCase <= testCases; testCase++) {
            out.println("Case #" + testCase + ": " + solveOneTest());
        }
    }

    String solveOneTest() throws IOException {
        Integer a = getMask() & getMask();
        int n = Integer.bitCount(a);
        if (n > 1)
            return "Bad magician!";
        if (n < 1)
            return "Volunteer cheated!";
        return Integer.toBinaryString(a >> 1).length() + "";

    }

    int getMask() throws IOException {
        int mask = 0;
        int n = nextInt();
        for (int i = 1; i <= 4; i++) {
            for (int j = 1; j <= 4; j++) {
                int x = nextInt();
                if (i == n)
                    mask |= 1 << x;
            }
        }
        return mask;
    }

    BufferedReader br;
    StringTokenizer st;
    PrintWriter out;

    public void run() {
        try {
            InputStream input = System.in;
            PrintStream output = System.out;
            File file = new File("a.in");
            if (file.exists() && file.canRead()) {
                input = new FileInputStream(file);
                output = new PrintStream(new File("a.out"));
            }
            br = new BufferedReader(new InputStreamReader(input));
            out = new PrintWriter(output);
            solveMultiTest();
            out.close();
        } catch (IOException e) {
        }
    }

    long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    String nextToken() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            String line = br.readLine();
            if (line == null) {
                return null;
            }
            st = new StringTokenizer(line);
        }
        return st.nextToken();
    }

    public static void main(String[] args) {
        new Thread(new ProblemA()).run();
    }
}