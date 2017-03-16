/**
 * Created by heekyu on 2014. 4. 12..
 */
import java.io.InputStreamReader;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.*;
import java.io.InputStream;

public class Main {

    public static void main(String[] args) throws Exception {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);

        Round1B_1 solver = new Round1B_1();
        int T = in.nextInt();
        for (int i = 0; i < T; i++) {
            solver.solve(i+1, in, out);
        }
        out.close();
    }
}

class Round1B_1 {
    public void solve(int testNumber, InputReader in, PrintWriter out) throws Exception {
        out.print("Case #" + testNumber + ": ");
        int N = in.nextInt();
        int[] mask = new int[101];
        int mcount = 0;
        int[][] cnt = new int[N][101];
        boolean valid = true;
        for (int i = 0; i < N; i++) {
            String s = in.next();
            int mycount = 0;
            for (int j = 0; j < s.length(); j++) {
                if (i == 0) {
                    char c = s.charAt(j);
                    if (j > 0 && s.charAt(j-1) == c) {
                        cnt[i][mcount-1]++;
                    } else {
                        mask[mcount++] = c - 'a';
                        cnt[i][mcount-1]++;
                    }
                } else {
                    if (!valid) continue;
                    char c = s.charAt(j);
                    if (j > 0 && s.charAt(j-1) == c) {
                        cnt[i][mycount-1]++;
                    } else {
                        if (mcount == mycount || mask[mycount] != (c - 'a')) {
                            valid = false;
                            break;
                        }
                        mycount++;
                        cnt[i][mycount-1]++;
                    }
                }
            }
            if (i > 0 && mycount != mcount) {
                valid = false;
            }
        }
        if (!valid) {
            out.println("Fegla Won");
            return;
        }
        int ret = 0;
        for (int i = 0; i < mcount; i++) {
            int best = 1000000;
            for (int candi = 1; candi <= 100; candi++) {
                int cur = 0;
                for (int j = 0; j < N; j++) {
                    cur += Math.abs(cnt[j][i] - candi);
                }
                if (cur < best) {
                    best = cur;
                } else {
                    break;
                }
            }
            ret += best;
        }
        out.println(ret);
    }
}

class InputReader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream));
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

    public int nextInt() {
        return Integer.parseInt(next());
    }

    public double nextDouble() {
        return Double.parseDouble(next());
    }

    public long nextLong() {
        return Long.parseLong(next());
    }
}
