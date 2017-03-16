import java.io.*;
import java.util.*;

class Party {
    int name;
    int count;
}

public class eva {
    private static final String NAME = "A-large";
    private static boolean SUBMIT = true;

    static Party[] ps;

    static int getSingle() {
        int max = ps[0].count;
        if (max <= 0)
            return -1;
        for (int i = ps.length - 1; i >= 0; i--) {
            if (ps[i].count == max) {
                ps[i].count--;
                return ps[i].name;
            }
        }
        return -1;
    }

    static int getMulti() {
        int max = ps[0].count;
        if (max <= 1)
            return -1;
        for (int i = ps.length - 1; i >= 0; i--) {
            if (ps[i].count == max) {
                ps[i].count--;
                return ps[i].name;
            }
        }
        return -1;
    }

    private static void main_eva() throws IOException {
        int n, i, j, k;
        int r;

        n = in.nextInt();
        ps = new Party[n];

        int t = 0;
        for (i = 0; i < n; i++) {
            ps[i] = new Party();
            ps[i].name = i;
            ps[i].count = in.nextInt();
            t += ps[i].count;
        }

        Arrays.sort(ps, new Comparator<Party>() {
            @Override
            public int compare(Party o1, Party o2) {
                return o1.count < o2.count ? 1 : o1.count > o2.count ? -1 : 0;
            }
        });

        while (t > 0) {
            int a, b;
            a = getMulti();
            if (a >= 0) {
                t -= 1;
                b = getMulti();
                if (b >= 0) {
                    out.print(" "
                            + Character.toString((char)('A' + a))
                            + Character.toString((char)('A' + b))
                    );
                    t -= 1;
                } else if (t % 2 == 1) {
                    b = getSingle();
                    out.print(" "
                            + Character.toString((char)('A' + a))
                            + Character.toString((char)('A' + b))
                    );
                    t -= 1;
                } else {
                    out.print(" "
                            + Character.toString((char)('A' + a))
                    );
                }
            } else if (t % 2 == 1) {
                a = getSingle();
                out.print(" "
                        + Character.toString((char)('A' + a))
                );
                t -= 1;
            } else {
                a = getSingle();
                b = getSingle();
                out.print(" "
                        + Character.toString((char)('A' + a))
                        + Character.toString((char)('A' + b))
                );
                t -= 2;
            }
        }

        out.println();
    }

    private static InputReader in;
    private static PrintWriter out;

    public static void main(String[] args) throws IOException {
        if (SUBMIT) {
            in = new InputReader(new FileInputStream(new File(NAME + ".in")));
            out = new PrintWriter(new BufferedWriter(new FileWriter(NAME + ".out")));
        } else {
            in = new InputReader(System.in);
            out = new PrintWriter(System.out, true);
        }
        int numCases = in.nextInt();
        for (int test = 1; test <= numCases; test++) {
            out.print("Case #" + test + ":");
            main_eva();
        }
        out.close();
        System.exit(0);
    }

    private static class InputReader {
        private BufferedReader reader;
        private StringTokenizer tokenizer;

        InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }
    }
}