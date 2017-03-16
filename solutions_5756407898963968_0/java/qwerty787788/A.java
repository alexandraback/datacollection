import java.io.*;
import java.util.*;

public class A {
    FastScanner in;
    PrintWriter out;

    Random rnd = new Random(123);

    void solve() throws IOException {
        int[] cnt = new int[17];
        for (int it = 0; it < 2; it++) {
            int r1 = in.nextInt() - 1;
            int[][] a = new int[4][4];
            for (int i = 0; i < 4; i++)
                for (int j = 0; j < 4; j++)
                    a[i][j] = in.nextInt();
            for (int i = 0; i < 4; i++)
                cnt[a[r1][i]]++;
        }
        int cntOk = 0;
        for (int i = 0; i < 17; i++)
            if (cnt[i] == 2)
                cntOk++;
        if (cntOk == 0) {
            out.println("Volunteer cheated!");
        } else {
            if (cntOk > 1) {
                out.println("Bad magician!");
            } else {
                for (int i = 0; i < 17; i++)
                    if (cnt[i] == 2)
                        out.println(i);
            }
        }

    }

    void run() throws IOException {
        try {
            in = new FastScanner(new File("A.in"));
            out = new PrintWriter(new File("A.out"));

            int testNumber = in.nextInt();
            for (int test = 1; test <= testNumber; test++) {
                out.print("Case #" + (test) + ": ");
                solve();
                System.out.println(test);
            }

            out.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    void runIO() {

        in = new FastScanner(System.in);
        out = new PrintWriter(System.out);

        try {
            solve();
        } catch (IOException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }

        out.close();
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        public FastScanner(InputStream f) {
            br = new BufferedReader(new InputStreamReader(f));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return null;
                st = new StringTokenizer(s);
            }
            return st.nextToken();
        }

        boolean hasMoreTokens() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return false;
                st = new StringTokenizer(s);
            }
            return true;
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }
    }

    public static void main(String[] args) throws IOException {
        new A().run();
    }
}