import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.time.Duration;
import java.time.LocalTime;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * @author Roman Nefyodov
 */
public class A {

    private static class Part {
        public final char c;
        public final int qty;

        public Part(char c, int qty) {
            this.c = c;
            this.qty = qty;
        }
    };

    List<Part> dissolve(String str) {
        Pattern p = Pattern.compile("([a-z])\\1*");
        Matcher m = p.matcher(str);
        List<Part> res = new ArrayList<Part>();
        while (m.find()) {
            String ss = m.group();
            res.add(new Part(ss.charAt(0), ss.length()));
        }
        return res;
    }

    public void solveCase() {
        int N = nextInt();
        String[] arr  = new String[N];
        List<Part>[] parts = new List[N];
        for (int i = 0; i < N; ++i) {
            arr[i] = next();
            parts[i] = dissolve(arr[i]);
        }
        boolean ok = true;
        for (int i = 0; i + 1 < N; ++i) {
            if (parts[i].size() != parts[i + 1].size())
                ok = false;
            else {
                for (int j = 0; j < parts[i].size(); ++j) {
                    if (parts[i].get(j).c != parts[i + 1].get(j).c)
                        ok = false;
                }
            }
        }
        if (!ok)
            pw.print("Fegla Won");
        else {
            long ans = 0;
            for (int i = 0; i < parts[0].size(); ++i) {
                int minVal = 1, maxVal = 1;
                for (int j = 0; j < parts.length; ++j)
                    maxVal = Math.max(maxVal, parts[j].get(i).qty);

                int best = Integer.MAX_VALUE;
                for (int to = minVal; to <= maxVal; ++to) {
                    int cur = 0;
                    for (int j = 0; j < parts.length; ++j)
                        cur += Math.abs(parts[j].get(i).qty - to);

                    best = Math.min(best, cur);
                }
                ans += best;

            }
            pw.print(ans);
        }

    }

    public void solve() {
        int T = nextInt();
        for (int i = 0; i < T; ++i) {
            pw.printf("Case #%d: ", i + 1);
            LocalTime start = LocalTime.now();
            pwerr.printf("Case %d started..\n", i + 1);
            pwerr.flush();
            solveCase();
            Duration duration = Duration.between(start, LocalTime.now());
            pwerr.printf("Case %d finished (%ds)..\n", i + 1, duration.getSeconds());
            pwerr.flush();
            pw.print('\n');
            pw.flush();
        }
    }

    public static void main(String[] args) {
        new A().run(args);
    }

    public void run(String[] args) {
        try {
            if (args.length == 1) {
                String filename = args[0];
                in = new BufferedReader(new FileReader(filename + ".in.txt"));
                pw = new PrintWriter(filename + ".out.txt");
            } else {
                in = new BufferedReader(new InputStreamReader(System.in));
                pw = new PrintWriter(System.out);
            }
            pwerr = new PrintWriter(System.err);
            st = new StringTokenizer("");
            solve();
            pw.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(-1);
        }
    }

    private StringTokenizer st;
    private BufferedReader in;
    private PrintWriter pw;
    private PrintWriter pwerr;

    int curCase;

    boolean hasNext() {
        try {
            while (!st.hasMoreTokens()) {
                String line = in.readLine();
                if (line == null)
                    return false;
                st = new StringTokenizer(line);
            }
            return st.hasMoreTokens();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    String next() {
        return hasNext() ? st.nextToken() : null;
    }

    int nextInt() {
        return Integer.parseInt(next());
    }

    double nextDouble() {
        return Double.parseDouble(next());
    }
}

