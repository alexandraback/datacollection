import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Repeater {
    private static final String inFile = "A-large.in";
    private static final String outFile = "A-out.txt";

    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(new FileReader(inFile));
        int T = scanner.nextInt();
        FileWriter fw = new FileWriter(outFile);
        for (int t = 1; t <= T; ++t) {
            int n = scanner.nextInt();
            String[] strs = new String[n];
            for (int i = 0; i < n; ++i) {
                strs[i] = scanner.next();
            }
            int res = solve(strs);
            if (res == -1) {
                fw.write(String.format("Case #%d: Fegla Won\n", t));
            } else {
                fw.write(String.format("Case #%d: %d\n", t, res));
            }
        }
        fw.close();
    }

    static class S {
        public S() {
            chars = new ArrayList<Character>();
            counts = new ArrayList<Integer>();
        }

        public List<Character> chars;
        public List<Integer> counts;

        public void add(char c) {
            chars.add(c);
            counts.add(1);
        }

        public void inc() {
            int last = counts.size() - 1;
            int cnt = counts.get(last);
            counts.set(last, cnt + 1);
        }
    }

    static int solve(String[] strs) {
        int n = strs.length;
        S[] ss = new S[n];
        for (int i = 0; i < n; ++i) {
            String str = strs[i];
            char c = str.charAt(0);

            S s = new S();
            s.add(c);

            for (int j = 1; j < str.length(); ++j) {
                char cc = str.charAt(j);
                if (cc != c) {
                    c = cc;
                    s.add(c);
                } else {
                    s.inc();
                }
            }
            ss[i] = s;
        }

        List<Character> chs = ss[0].chars;
        int m = chs.size();
        for (int i = 1; i < n; ++i) {
            List<Character> cchs = ss[i].chars;
            if (cchs.size() != m) {
                return -1;
            }
            for (int j = 0; j < m; ++j) {
                if (!chs.get(j).equals(cchs.get(j))) {
                    return -1;
                }
            }
        }

        int r = 0;
        for (int i = 0; i < m; ++i) {
            int c = Integer.MAX_VALUE;
            for (int k = 1; k <= 100; ++k) {
                int cc = 0;
                for (int j = 0; j < n; ++j) {
                    cc += Math.abs(ss[j].counts.get(i) - k);
                }
                c = Math.min(c, cc);
            }
            r += c;
        }
        return r;
    }





}
