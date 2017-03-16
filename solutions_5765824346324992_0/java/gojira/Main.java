import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(System.in);
        //PrintWriter out = new PrintWriter(System.out);
        PrintWriter out = new PrintWriter(new File("/Users/eldar/Documents/B.out"));
        int T = in.nextInt();
        for(int t = 1; t <= T; t++) {
            int m = in.nextInt();
            int n = in.nextInt();
            int[] x = new int[m];
            for(int i = 0; i < m; i++) {
                x[i] = in.nextInt();
            }
            out.println("Case #" + t + ": " + solve(n, x));
        }
        out.flush();
        out.close();
    }

    static long f(long tm, int[] x) {
        long total = 0;
        for(int y : x) {
            total += tm / y + 1;
        }
        return total;
    }

    static int solve(int n, int[] x) {
        long l = -1, r = n * 100000L, mid;
        while(l < r - 1) {
            mid = (l + r) / 2;
            if (f(mid, x) < n)
                l = mid;
            else
                r = mid;
        }
        long before = f(l, x);
        for(int i = 0; i < x.length; i++) {
            if (r % x[i] > 0) continue;
            ++before;
            if (before == n) return i + 1;
        }
        return -1;
    }
}
