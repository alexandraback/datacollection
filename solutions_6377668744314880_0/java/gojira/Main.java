import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(System.in);
        //PrintWriter out = new PrintWriter(System.out);
        PrintWriter out = new PrintWriter(new File("/Users/eldar/Documents/C.out"));
        int T = in.nextInt();
        for(int t = 1; t <= T; t++) {
            int n = in.nextInt();
            int[] x = new int[n];
            int[] y = new int[n];
            for(int i = 0; i < n; i++) {
                x[i] = in.nextInt();
                y[i] = in.nextInt();
            }
            out.println("Case #" + t + ":");
            for(int i = 0; i < n; i++)
                out.println(solve(x, y, i));
        }
        out.flush();
        out.close();
    }

    static int solve(int[] x, int[] y, int index) {
        int n = x.length, i, j;
        int ret = n - 1;
        for(i = 0; i < x.length; i++) {
            if (i == index) continue;
            long A = y[i] - y[index];
            long B = x[index] - x[i];
            long C = A * x[index] + B * y[index];
            int a = 0, b = 0;
            for(j = 0; j < x.length; j++) {
                long t = A * x[j] + B * y[j] - C;
                if (t < 0)
                    ++a;
                if (t > 0)
                    ++b;
            }
            ret = Math.min(ret, a);
            ret = Math.min(ret, b);
        }
        return ret;
    }

}
