import java.io.*;
import java.util.*;

public class BSmall {
    BufferedReader br;
    StringTokenizer in;
    PrintWriter out;
    int ans;

    public String nextToken() throws IOException {
        while (in == null || !in.hasMoreTokens()) {
            in = new StringTokenizer(br.readLine());
        }
        return in.nextToken();
    }

    public int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    public double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    public long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    public static void main(String[] args) throws IOException {
        new BSmall().run();
    }

    int check(int r, int c, boolean[][] a) {
        int res = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (i + 1 < r && a[i][j] && a[i + 1][j]) {
                    res++;
                }
                if (j + 1 < c && a[i][j] && a[i][j + 1]) {
                    res++;
                }
            }
        }
        return res;
    }

    void gen(boolean[][] a, int x, int y, int r, int c, int n) {
        if (n == 0) {
            ans = Math.min(ans, check(r, c, a));
            return;
        }
        if (x >= r) {
            return;
        }
        int nx = x;
        int ny = y;
        ny++;
        if (ny == c) {
            ny = 0;
            nx++;
        }
        gen(a, nx, ny, r, c, n);
        a[x][y] = true;
        gen(a, nx, ny, r, c, n - 1);
        a[x][y] = false;
    }

    public void solve() throws IOException {
        int t = nextInt();
        for (int ii = 1; ii <= t; ii++) {
            System.out.println(ii);
            int r = nextInt();
            int c = nextInt();
            int n = nextInt();
            ans = Integer.MAX_VALUE;
            gen(new boolean[r][c], 0, 0, r, c, n);
            out.println("Case #" + ii + ": " + ans);
        }
    }

    public void run() {
        try {
            br = new BufferedReader(new FileReader("b-small.in"));
            out = new PrintWriter("b-small.txt");

            solve();

            out.close();
        } catch (IOException e) {
            e.printStackTrace();
            System.exit(1);
        }
    }
}