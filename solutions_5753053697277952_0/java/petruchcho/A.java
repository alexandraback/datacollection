import java.io.*;
import java.util.Locale;
import java.util.StringTokenizer;

public class A implements Runnable {

    private static final boolean ONLINE_JUDGE = System.getProperty("ONLINE_JUDGE") != null;

    private BufferedReader in;
    private PrintWriter out;
    private StringTokenizer tok = new StringTokenizer("");

    private void init() throws FileNotFoundException {
        Locale.setDefault(Locale.US);
        String fileName = "";
        if (ONLINE_JUDGE && fileName.isEmpty()) {
            in = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(System.out);
        } else {
            if (fileName.isEmpty()) {
                in = new BufferedReader(new FileReader("input.txt"));
                out = new PrintWriter("output.txt");
            } else {
                in = new BufferedReader(new FileReader(fileName + ".in"));
                out = new PrintWriter(fileName + ".out");
            }
        }
    }

    String readString() {
        while (!tok.hasMoreTokens()) {
            try {
                tok = new StringTokenizer(in.readLine());
            } catch (Exception e) {
                return null;
            }
        }
        return tok.nextToken();
    }

    int readInt() {
        return Integer.parseInt(readString());
    }

    long readLong() {
        return Long.parseLong(readString());
    }

    double readDouble() {
        return Double.parseDouble(readString());
    }

    int[] readIntArray(int size) {
        int[] a = new int[size];
        for (int i = 0; i < size; i++) {
            a[i] = readInt();
        }
        return a;
    }

    public static void main(String[] args) {
        //new Thread(null, new _Solution(), "", 128 * (1L << 20)).start();
        new A().run();
    }

    long timeBegin, timeEnd;

    void time() {
        timeEnd = System.currentTimeMillis();
        System.err.println("Time = " + (timeEnd - timeBegin));
    }

    @Override
    public void run() {
        try {
            timeBegin = System.currentTimeMillis();
            init();
            solve();
            out.close();
            time();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(-1);
        }
    }

    String caseNum(int number) {
        return "Case #" + number + ": ";
    }

    private void solve() {
        int T = readInt();
        for (int test = 1; test <= T; test++) {
            int n = readInt();

            int[] p = readIntArray(n);

            int count = 0;
            for (int i = 0; i < n; i++) {
                count += p[i];
            }

            out.print(caseNum(test));

            if (n == 2) {
                while (p[0] > p[1]) {
                    out.print("A ");
                    p[0]--;
                }
                while (p[1] > p[0]) {
                    out.print("B ");
                    p[1]--;
                }
                while (p[0] > 0) {
                    out.print("AB ");
                    p[0]--;
                }
            } else {
                while (count > 2) {
                    int max = 0;
                    int maxIndex = -1;
                    for (int i = 0; i < n; i++) {
                        if (max < p[i]) {
                            max = p[i];
                            maxIndex = i;
                        }
                    }
                    p[maxIndex]--;
                    count--;
                    out.print((char)('A' + maxIndex) + " ");
                }
                for (int i = 0; i < n; i++) {
                    if (p[i] == 1) {
                        out.print((char)('A' + i));
                    }
                }
            }
            out.println();
        }
    }
}
