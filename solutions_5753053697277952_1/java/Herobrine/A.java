package gcj2016.roundC;

import java.io.*;
import java.util.*;

public class A {

    public static final boolean FAST_SAVE = true;
    public static PrintWriter writer;

    public static void main(String[] args) throws Exception {
        if (FAST_SAVE) {
            writer = new PrintWriter("H:\\out.txt");
        }

        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskS solver = new TaskS();
        int tasks = in.nextInt();
        for (int i = 0; i < tasks; i++) {
            solver.solve(i+1, in, out);
        }
        out.close();
        if (FAST_SAVE) {
            writer.flush();
            writer.close();
        }
    }


    static class TaskS {

        int n;
        int m;
        int[] a;
        int[] b;

        private char toC(int i) {
            return   (char)(i+'A');
        }

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            n = in.nextInt();

            int[] sen = new int[n];
            int sleft = 0;
            for (int i = 0; i < n; i++) {
                sen[i] = in.nextInt();
                sleft += sen[i];
            }
            StringBuilder res = new StringBuilder();
            while (sleft > 0) {
                int max = -1;
                int imax = -1;
                int nextMax = -1;
                int inextMax = -1;
                for (int i = 0; i < n; i++) {
                    if (sen[i] >= max) {
                        nextMax = max;
                        inextMax = imax;
                        max = sen[i];
                        imax = i;
                        continue;
                    }
                    if (sen[i] > nextMax) {
                        nextMax = sen[i];
                        inextMax = i;
                    }
                }

                if (max >= nextMax+2) {
                    res.append(toC(imax));
                    res.append(toC(imax));
                    res.append(' ');
                    sen[imax] -= 2;
                    sleft -= 2;
                    continue;
                }

                if (max == nextMax) {
                    if (sleft != 3) {
                        res.append(toC(imax));
                        res.append(toC(inextMax));
                        res.append(' ');
                        sen[imax] -= 1;
                        sen[inextMax] -= 1;
                        sleft -= 2;
                    } else {
                        res.append(toC(imax));
                        res.append(' ');
                        sen[imax] -= 1;
                        sleft -= 1;
                    }
                    continue;
                }

                //if (max >= nextMax+1) {
                    res.append(toC(imax));
                    res.append(' ');
                    sen[imax] -= 1;
                    sleft -= 1;
                    continue;
                //}

            }

            String result = "Case #" + testNumber + ": " + res;
            out.println(result);
            if (FAST_SAVE) {
                writer.println(result);
            }
        }

        private boolean f() {
            return true;
        }
    }

    static class InputReader {
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

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public int[] readIntArray(int n) {
            int[] ret = new int[n];
            for (int i = 0; i < n; i++) {
                ret[i] = nextInt();
            }
            return ret;
        }
    }
}