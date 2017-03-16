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
            int N = scan.nextInt();
            int[] arr = new int[M];
            for (int i = 0; i < M; ++i) {
                arr[i] = scan.nextInt();
            }
            int res = -1;
            long low = 0;
            long high = (long) 1e16;
            int[] candidates = new int[M];
            while (low < high) {
                long mid = low + (high - low) / 2;
                long cut = 0;
                int available = 0;
                for (int i = 0; i < M; ++i) {
                    cut += mid / arr[i];
                    if (mid % arr[i] == 0) {
                        candidates[available] = i + 1;
                        ++available;
                    } else {
                        ++cut;
                    }
                }

                if (cut >= N) {
                    high = mid;
                } else if (cut + available < N) {
                    low = mid + 1;
                } else {
                    res = candidates[N - (int) cut - 1];
                    high = mid;
                }
            }

            System.out.println(String.format("Case #%d: %d", taskIndex, res));
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