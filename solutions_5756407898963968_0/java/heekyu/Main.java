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

        Qual_A solver = new Qual_A();
        int T = in.nextInt();
        for (int i = 0; i < T; i++) {
            solver.solve(i+1, in, out);
        }
        out.close();
    }
}

class Qual_A {
    public void solve(int testNumber, InputReader in, PrintWriter out) throws Exception {
        TreeSet<Integer> candidates = new TreeSet<Integer>();
        int r = in.nextInt()-1;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                int v = in.nextInt();
                if (i == r) {
                    candidates.add(v);
                }
            }
        }
        r = in.nextInt()-1;
        TreeSet<Integer> realcandi = new TreeSet<Integer>();
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                int v = in.nextInt();
                if (i == r && candidates.contains(v)) {
                    realcandi.add(v);
                }
            }
        }
        out.print("Case #" + testNumber + ": ");
        if (realcandi.isEmpty()) {
            out.println("Volunteer cheated!");
        } else if (realcandi.size() == 1) {
            out.println(realcandi.first());
        } else {
            out.println("Bad magician!");
        }
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
