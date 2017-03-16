import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.InputMismatchException;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws Exception {
        FastScanner scan = new FastScanner(System.in);
        int taskCount = scan.nextInt();
        for (int taskIndex = 1; taskIndex <= taskCount; ++taskIndex) {
            int M = scan.nextInt();
            int[] arr = new int[M];
            for (int i = 0; i < M; ++i) {
                arr[i] = scan.nextInt();
            }
            int first = 0;
            for (int i = 1; i < M; ++i) {
                first += Math.max(0, arr[i - 1] - arr[i]);
            }
            int diff = 0;
            for (int i = 1; i < M; ++i) {
                diff = Math.max(diff, arr[i - 1] - arr[i]);
            }
            int rate = diff;
            int second = 0;
            if (rate > 0) {
                for (int i = 0; i < M - 1; ++i) {
                    second += Math.min(arr[i], rate);
                }
            }
            System.out.println(String.format("Case #%d: %d %d", taskIndex, first, second));
        }
    }
}

class FastScanner {
    BufferedReader in;
    StringTokenizer tok;

    public FastScanner(InputStream in) {
        this.in = new BufferedReader(new InputStreamReader(in));
        tok = new StringTokenizer("");
    }

    private String tryReadNextLine() {
        try {
            return in.readLine();
        } catch (Exception e) {
            throw new InputMismatchException();
        }
    }

    public String nextToken() {
        while (!tok.hasMoreTokens()) {
            tok = new StringTokenizer(nextLine());
        }
        return tok.nextToken();
    }

    public String nextLine() {
        String newLine = tryReadNextLine();
        if (newLine == null)
            throw new InputMismatchException();
        return newLine;
    }

    public int nextInt() {
        return Integer.parseInt(nextToken());
    }

    public long nextLong() {
        return Long.parseLong(nextToken());
    }

}