import java.util.*;
import java.io.*;

public class B {

    public static void main(String[] args) throws FileNotFoundException {
        new B().solve();
    }

    public void solve() throws FileNotFoundException{
        //Scanner in = new Scanner(System.in);
        Scanner in = new Scanner(new File("b.in"));
        PrintWriter out = new PrintWriter("b.out");
        int t = in.nextInt();
        for (int test = 1; test <= t; test++) {
            ArrayList<Integer> a = new ArrayList<Integer>();
            int b = in.nextInt();
            int n = in.nextInt();
            int[] w = new int[b + 1];
            int[] c = new int[b + 1];
            for (int j = 1; j <= b; j++)
                w[j] = in.nextInt();
            c = w.clone();
            for (int i = 1; i <= b; i++)
                a.add(i);

            while (keepGoing(w)) {
                for (int i = 1; i <= b; i++)
                    if (w[i] == 0) {
                        a.add(i);
                        w[i] = c[i];
                    }
            }
            int idx = n % a.size() - 1;
            if (idx < 0) idx = a.size() - 1;
            int res = a.get(idx);
            //System.out.println("Case #" + test + ": " + res);
            out.println("Case #" + test + ": " + res);
        }

        out.close();
    }

    public boolean keepGoing(int[] w) {
        int min = Integer.MAX_VALUE;
        for (int i = 1; i < w.length; i++)
            min = Math.min(min, w[i]);
        for (int i = 1; i < w.length; i++)
            w[i] -= min;
        boolean allZero = true;
        for (int i = 1; i < w.length; i++)
            if (w[i] != 0) allZero = false;
        return !allZero;
    }
}