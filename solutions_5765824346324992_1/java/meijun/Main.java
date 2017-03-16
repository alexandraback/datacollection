import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.math.BigInteger;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.util.StringTokenizer;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author shu_mj @ http://shu-mj.com
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		Scanner in = new Scanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
    Scanner in;
    PrintWriter out;

    public void solve(int testNumber, Scanner in, PrintWriter out) {
        this.in = in;
        this.out = out;
        run();
    }

    void run() {
        int t = in.nextInt();
        for (int i = 1; i <= t; i++) {
            out.printf("Case #%d: ", i);
            solve();
        }
    }

    private void solve() {
        int b = in.nextInt();
        int n = in.nextInt();
        int[] bs = in.nextIntArray(b);
        long l = 0, r = 100000L * 10000000000L;
        while (l < r) {
            long m = (l + r) / 2;
            long c = 0;
            for (int i : bs) c += (m + i - 1) / i;
            if (c < n) l = m + 1;
            else r = m;
        }
        long dw = 0;
        for (int i : bs) {
            dw += (l + i - 2) / i;
        }
        int c = 0;
        for (int i = 0; i < b; i++) {
            if ((l - 1) % bs[i] == 0) {
                c++;
                if (c == n - dw) {
                    out.println(i + 1);
                    return;
                }
            }
        }
    }
}

class Scanner {
    BufferedReader br;
    StringTokenizer st;

    public Scanner(InputStream in) {
        br = new BufferedReader(new InputStreamReader(in));
        eat("");
    }

    private void eat(String s) {
        st = new StringTokenizer(s);
    }

    public String nextLine() {
        try {
            return br.readLine();
        } catch (IOException e) {
            return null;
        }
    }

    public boolean hasNext() {
        while (!st.hasMoreTokens()) {
            String s = nextLine();
            if (s == null)
                return false;
            eat(s);
        }
        return true;
    }

    public String next() {
        hasNext();
        return st.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    public int[] nextIntArray(int n) {
        int[] is = new int[n];
        for (int i = 0; i < n; i++) {
            is[i] = nextInt();
        }
        return is;
    }

}

