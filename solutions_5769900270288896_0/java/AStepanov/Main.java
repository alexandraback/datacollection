import java.io.*;
import static java.lang.Math.*;

import java.lang.reflect.Array;
import java.util.*;
import java.util.function.*;
import java.lang.*;

public class Main {
    final static boolean debug = false;
    final static String fileName = "";
    final static boolean useFiles = false;

    public static void main(String[] args) throws FileNotFoundException {
        long start;
        if (debug)
            start = System.nanoTime();
        InputStream inputStream;
        OutputStream outputStream;
        if (useFiles) {
            inputStream = new FileInputStream(fileName + ".in");
            outputStream = new FileOutputStream(fileName + ".out");
        } else {
            inputStream = System.in;
            outputStream = System.out;
        }
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        Task solver = new Task(in, out);
        solver.solve();
        if(debug)
            out.println((System.nanoTime() - start) / 1e+9);
        out.close();
    }
}

class InputReader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream), 32768);
        tokenizer = null;
    }

    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return tokenizer.nextToken();
    }

    public double nextDouble(){
        return Double.parseDouble(next());
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    public long nextLong(){
        return Long.parseLong(next());
    }

    public byte nextByte(){
        return Byte.parseByte(next());
    }
}

class Task {
//    int reverse(int x) {
//        int result = 0;
//        for (; x != 0; ) {
//            result = result * 10 + x % 10;
//            x /= 10;
//        }
//        return result;
//    }
//    public void solve() {
//        final int maxN = (int) (1e6 + 1);
//        int[] d = new int[maxN];
//        Arrays.fill(d, Integer.MAX_VALUE);
//        d[1] = 1;
//        for (int i = 1; i < maxN; i++) {
//            d[i + 1] = min(d[i + 1], d[i] + 1);
//            int rev = reverse(i);
//            d[rev] = min(d[rev], d[i] + 1);
//        }
//        int t = in.nextInt();
//        for (int i = 1; i <= t; i++) {
//            int n = in.nextInt();
//            out.println("Case #" + i + ": " + d[n]);
//        }
//    }

    void solve() {
        final int maxN = 16;
        int[][][] d = new int[maxN + 1][maxN + 1][maxN + 1];
        for (int r = 1; r <= maxN; r++){
            for (int c = 1; c <= maxN / r; c++){
                Arrays.fill(d[r][c], Integer.MAX_VALUE);
                boolean[][] a = new boolean[r][c];
                int[] dx = new int[]{1, 0};
                int[] dy = new int[]{0, 1};
                for (int mask = 0; mask < (1 << (r * c)); mask++) {
                    int bits = 0;
                    for (int i = 0; i < r * c; i++) {
                        boolean bit = (mask & (1 << i)) > 0;
                        a[i / c][i % c] = bit;
                        bits += bit ? 1 : 0;
                    }
                    int count = 0;
                    for (int i = 0; i < r; i++) {
                        for (int j = 0; j < c; j++) {
                            if (a[i][j]) {
                                for (int k = 0; k < 2; k++) {
                                    int x = i + dx[k];
                                    int y = j + dy[k];
                                    if (0 <= x && x < r && 0 <= y && y < c && a[x][y])
                                        count++;
                                }
                            }
                        }
                    }
                    d[r][c][bits] = min(d[r][c][bits], count);
                }
            }
        }

        int t = in.nextInt();
        for (int test = 1; test <= t; test++) {
            int r = in.nextInt();
            int c = in.nextInt();
            int n = in.nextInt();
            out.println("Case #" + test + ": " + d[r][c][n]);
        }
    }

    private InputReader in;
    private PrintWriter out;

    Task(InputReader in, PrintWriter out) {
        this.in = in;
        this.out = out;
    }
}
