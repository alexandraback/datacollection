import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.time.Duration;
import java.time.LocalTime;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
import java.util.StringTokenizer;
import java.util.stream.Collectors;

/**
 * @author Roman Nefyodov
 */
public class A {

    public void solveCase() {
        int f1 = nextInt();
        List<Set<Integer>> s1 = new ArrayList<>();
        for (int i = 0; i < 4; ++i) {
            s1.add(new HashSet<>());
            for (int j = 0; j < 4; j++)
                s1.get(i).add(nextInt());
        }

        int f2 = nextInt();
        List<Set<Integer>> s2 = new ArrayList<>();
        for (int i = 0; i < 4; ++i) {
            s2.add(new HashSet<>());
            for (int j = 0; j < 4; j++)
                s2.get(i).add(nextInt());
        }

        List<Integer> c = s1.get(f1 - 1).stream().filter(x -> s2.get(f2 - 1).contains(x)).collect(Collectors.toList());
        switch (c.size()) {
            case 0:
                pw.print("Volunteer cheated!");
                break;
            case 1:
                pw.print(c.get(0));
                break;
            default:
                pw.print("Bad magician!");
                break;
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
                in = new BufferedReader(new FileReader(filename + ".in"));
                pw = new PrintWriter(filename + ".out");
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

