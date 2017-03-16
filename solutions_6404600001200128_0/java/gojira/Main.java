import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(System.in);
        //PrintWriter out = new PrintWriter(System.out);
        PrintWriter out = new PrintWriter(new File("/Users/eldar/Documents/A.out"));
        int T = in.nextInt();
        for(int t = 1; t <= T; t++) {
            int n = in.nextInt();
            int[] x = new int[n];
            for(int i = 0; i < n; i++) {
                x[i] = in.nextInt();
            }
            out.println("Case #" + t + ": " + solve1(x) + " " + solve2(x));
        }
        out.flush();
        out.close();
    }

    static int solve1(int[] x) {
        int ret = 0;
        for(int i = 1; i < x.length; i++) {
            ret += Math.max(0, x[i - 1] - x[i]);
        }
        return ret;
    }

    static int solve2(int[] x) {
        int rate = 0;
        for(int i = 1; i < x.length; i++) {
            rate = Math.max(rate, x[i - 1] - x[i]);
        }
        int ret = 0;
        for(int i = 1; i < x.length; i++) {
            ret += Math.min(rate, x[i - 1]);
        }
        return ret;
    }

}
