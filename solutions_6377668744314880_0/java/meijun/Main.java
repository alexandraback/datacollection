import java.util.ArrayList;
import java.util.List;
import java.math.BigInteger;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.TreeSet;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.PrintStream;
import java.util.Comparator;
import java.util.Set;
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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
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
            out.printf("Case #%d:%n", i);
            solve();
        }
    }

    private void solve() {
        int n = in.nextInt();
        P[] ps = new P[n];
        for (int i = 0; i < n; i++) {
            ps[i] = new P(in.nextInt(), in.nextInt());
        }
        P[] cs = P.convexHull(ps.clone());
        int[] res = new int[n];
        Set<P> set = new TreeSet<>();
        for (P p : cs) set.add(p);
        for (int i = 0; i < n; i++) {
            if (!set.contains(ps[i])) {
                int d = n - 1;
                for (int s = 0; s < (1 << n); s++) if ((s & (1 << i)) == 0) {
                    int c = n - Integer.bitCount(s);
                    P[] qs = new P[c];
                    for (int t = 0; t < n; t++) {
                        if ((s & (1 << t)) == 0) {
                            qs[--c] = ps[t];
                        }
                    }
                    boolean f = false;
                    for (P p : P.convexHull(qs)) {
                        if (p.equals(ps[i])) {
                            f = true;
                        }
                    }
                    if (f) d = Math.min(d, Integer.bitCount(s));
                }
                res[i] = d;
            }
        }
        for (int i : res) out.println(i);
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

}

class P implements Comparable<P> {
    public static final double EPS = 1e-9;
    public static double add(double a, double b) {
        if (Math.abs(a + b) < EPS * (Math.abs(a) + Math.abs(b))) return 0;
        return a + b;
    }

    public final double x, y;

    public P(double x, double y) {
        this.x = x;
        this.y = y;
    }

    public P sub(P p) {
        return new P(add(x, -p.x), add(y, -p.y));
    }

    public double det(P p) {
        return add(x * p.y, -y * p.x);
    }

    public String toString() {
        return "(" + x + ", " + y + ")";
    }

    public boolean equals(Object obj) {
        if (this == obj)
            return true;
        if (obj == null)
            return false;
        if (getClass() != obj.getClass())
            return false;
        return compareTo((P) obj) == 0;
    }

    public int compareTo(P p) {
        int b = sig(x - p.x);
        if (b != 0) return b;
        return sig(y - p.y);
    }

    public static int sig(double x) {
        if (Math.abs(x) < EPS) return 0;
        return x < 0 ? -1 : 1;
    }

    //凸包
    //逆时针 不包含线上的点
    //如果需要包含线上的点 将 <= 0 改成 < 0
    //但是需要注意此时不能有重点
    public static P[] convexHull(P[] ps) {
        int n = ps.length, k = 0;
        if (n <= 1) return ps;
        Arrays.sort(ps);
        P[] qs = new P[n * 2];
        for (int i = 0; i < n; qs[k++] = ps[i++]) {
            while (k > 1 && qs[k - 1].sub(qs[k - 2]).det(ps[i].sub(qs[k - 1])) < -EPS) k--;
        }
        for (int i = n - 2, t = k; i >= 0; qs[k++] = ps[i--]) {
            while (k > t && qs[k - 1].sub(qs[k - 2]).det(ps[i].sub(qs[k - 1])) < -EPS) k--;
        }
        P[] res = new P[k - 1];
        System.arraycopy(qs, 0, res, 0, k - 1);
        return res;
    }

}

