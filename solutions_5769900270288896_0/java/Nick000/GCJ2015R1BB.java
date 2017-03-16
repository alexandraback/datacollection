package gcj2015.round1b.b;

import java.io.*;
import java.util.Map;
import java.util.StringTokenizer;
import java.util.concurrent.ConcurrentHashMap;
import java.util.concurrent.Semaphore;

/**
 * Created by numnikov on 4/11/15.
 */
public class GCJ2015R1BB implements Runnable {

    private static final String FILE = "B-small-attempt0";

    Map<Integer, Object> results = new ConcurrentHashMap<Integer, Object>();

    void solve() throws IOException, InterruptedException {
        int t = nextInt();
        final Semaphore semaphore = new Semaphore(t);
        for (int i = 0; i < t; ++i) {
            final int temp = i;
            final int r = nextInt();
            final int c = nextInt();
            final int n = nextInt();
            semaphore.acquire();
            new Thread(new Runnable() {
                @Override
                public void run() {
                    try {
                        doSolve(temp, r, c, n);
                        semaphore.release();
                    } catch (IOException e) {
                        System.out.println("TEST " + temp);
                        e.printStackTrace();
                    }
                }
            }).start();
        }
        semaphore.acquire(t);
        for (Map.Entry<Integer, Object> entry : results.entrySet()) {
            writer.println("Case #" + (entry.getKey() + 1) + ": " + entry.getValue());
        }
    }

    void doSolve(int t, int r, int c, int n) throws IOException {
        int result = Integer.MAX_VALUE;
        boolean[][] a = new boolean[r][c];
        for (int i = 0; i < 1 << r * c; ++i) {
            int count = Integer.bitCount(i);
            if (count == n) {
                int temp = i;
                int j = 0;
                int k = 0;
                boolean[][] arr = new boolean[r][c];
                while (temp > 0) {
                    if (j == c) {
                        j = 0;
                        ++k;
                    }
                    if ((temp & 1) == 1) {
//                        int rr = j / (c - 1);
//                        int cc = j - rr * (c - 1);
                        arr[k][j] = true;
                    }
                    temp >>= 1;
                    ++j;
                }
                result = Math.min(count(arr), result);
            }
        }
//        int result = go(a, n);
        results.put(t, result);
    }

    int go(boolean[][] c, int n) {
        if (n == 0) {
           return count(c);
        }
        int min = Integer.MAX_VALUE;
        for (int i = 0; i < c.length; ++i) {
            for (int j = 0; j < c[0].length; ++j) {
                if (!c[i][j]) {
//                    boolean[][] copy = copy(c);
                    c[i][j] = true;
                    min = Math.min(go(c, n - 1), min);
                    c[i][j] = false;
                }
            }
        }
        return min;
    }

    boolean[][] copy(boolean[][] c) {
        boolean[][] copy = new boolean[c.length][];
        for (int i = 0; i < c.length; ++i) {
            copy[i] = c[i].clone();
        }
        return copy;
    }

    int count(boolean[][] c) {
        int count = 0;
        for (int i = 0; i < c.length; ++i) {
            for (int j = 0; j < c[0].length; ++j) {
                if (c[i][j]) {
                    if (i < c.length - 1 && c[i + 1][j]) {
                        ++count;
                    }
                    if (j < c[0].length - 1 && c[i][j + 1]) {
                        ++count;
                    }
                }
            }
        }
        return count;
    }

    String nextToken() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    BufferedReader reader;
    PrintWriter writer;
    StringTokenizer tokenizer;
    @Override
    public void run() {
        try {
            reader = new BufferedReader(new FileReader(new File("src/gcj2015/round1b/b/" + FILE + ".in")));
            writer = new PrintWriter(new FileWriter(new File("src/gcj2015/round1b/b/" + FILE + ".out")));
            solve();
            reader.close();
            writer.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    public static void main(String[] args) {
        new GCJ2015R1BB().run();
    }
}
