package Round1A2015;

import java.io.*;
import java.util.Arrays;
import java.util.Locale;
import java.util.Random;
import java.util.StringTokenizer;
import java.util.concurrent.Callable;
import java.util.concurrent.Future;
import java.util.concurrent.ScheduledThreadPoolExecutor;

public class B implements Runnable {

    private PrintWriter out;

    final String file = "/Users/sayghosh/code/GCJ/src/Round1A2015/B-small-attempt2";
    Random rnd = new Random(42);

    static class InputData {

        int B, N;
        int[] M, store;
        int min = Integer.MAX_VALUE;
        int loc = 0;

        InputData(FastReader in) throws IOException {
            B = in.nextInt();
            N = in.nextInt();

            M = new int[B];
            store = new int[B];
            for (int i = 0; i < B; i++) {
                M[i] = in.nextInt();
                store[i] = M[i];
                if (M[i] < min) {
                    min = M[i];
                    loc = i;
                }

            }
        }

        void solve(PrintWriter out) {

            int newMin = Integer.MAX_VALUE;
            if (N <= B)
                out.println(N);
            else {
                N = N - B;
                while (N >= 1) {
                    int min = findMin(store);
                    for (int j = 0; j < B; j++) {
                        store[j]=store[j]-min;
                        if (store[j] == 0 && N == 1) {

                            out.println(j + 1);
                            N--;
                            break;
                        } else if (store[j] == 0) {
                            store[j] = M[j];
                            N--;
                        }
                    }
                    // min = newMin;
                }
            }

            // out.println(Y+" "+Z);

        }

        int findMin(int[] A) {
            int min = Integer.MAX_VALUE;
            for (int i = 0; i < A.length; i++) {
                if(A[i]<min)
                    min = A[i];
            }
            return min;
        }

        void solve1(PrintWriter out) {

            int newMin = Integer.MAX_VALUE;
            while (N > 0) {
                for (int j = 0; j < B; j++) {
                    store[j] = store[j] - min;
                    if (store[j] == 0 && N == 1) {
                        out.println(N);
                        break;
                    } else if (store[j] == 0 && N > 1) {
                        store[j] = M[j];
                        N--;
                    }
                    if (store[j] < newMin) {
                        newMin = store[j];
                    }

                }
                min = newMin;
            }
            // out.println(Y+" "+Z);

        }

    }

    static class Solver implements Callable<String> {

        InputData data;

        Solver(InputData data) {
            this.data = data;
        }

        @Override
        public String call() throws Exception {
            StringWriter out = new StringWriter();
            data.solve(new PrintWriter(out));
            return out.toString();
        }

    }

    public void run() {
        try {
            FastReader in = new FastReader(new BufferedReader(new FileReader(file + ".in")));
            out = new PrintWriter(file + ".out");

            ScheduledThreadPoolExecutor service = new ScheduledThreadPoolExecutor(7);

            int tests = in.nextInt();
            Future<String>[] ts = new Future[tests];
            System.out.println(tests);
            for (int test = 0; test < tests; ++test) {
                ts[test] = service.submit(new Solver(new InputData(in)));
            }
            for (int test = 0; test < tests; ++test) {
                while (!ts[test].isDone()) {
                    Thread.sleep(500);
                }
                System.err.println("Test " + test);
                out.print("Case #" + (test + 1) + ": ");
                out.print(ts[test].get());
            }
            service.shutdown();

            out.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    static class FastReader {
        public FastReader(BufferedReader in) {
            this.in = in;
            eat("");
        }

        private StringTokenizer st;
        private BufferedReader in;

        void eat(String s) {
            st = new StringTokenizer(s);
        }

        String next() throws IOException {
            while (!st.hasMoreTokens()) {
                String line = in.readLine();
                if (line == null) {
                    return null;
                }
                eat(line);
            }
            return st.nextToken();
        }

        int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        long nextLong() throws IOException {
            return Long.parseLong(next());
        }

        double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }
    }

    public static void main(String[] args) {
        Locale.setDefault(Locale.US);
        new B().run();
    }

}
