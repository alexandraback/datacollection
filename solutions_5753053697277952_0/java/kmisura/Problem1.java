import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class Problem1 {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(new File("data/A-small-attempt0.in"));
        PrintWriter pw = new PrintWriter(new File("data/A-small-attempt0.out"));

        int T = sc.nextInt();

        for (int tc = 1; tc <= T; tc++) {
            int n = sc.nextInt();
            int total = 0;
            Party[] parties = new Party[n];
            for (int i = 0; i < n; i++) {
                int x = sc.nextInt();
                parties[i] = new Party(i, x);
                total += x;
            }
            StringBuilder sb = new StringBuilder();
            while (total > 0) {
                Arrays.sort(parties);
                if (sb.length() > 0) {
                    sb.append(" ");
                }
                sb.append((char) ('A' + parties[0].idx));
                parties[0].count--;
                total--;
                if (total == 0)
                    break;
                Arrays.sort(parties);
                if (n > 1 && parties[1].count <= (total - 1) / 2) {
                    parties[0].count--;
                    total--;
                    sb.append((char) ('A' + parties[0].idx));
                }
            }
            pw.println("Case #" + tc + ": " + sb.toString());
        }

        pw.close();
    }

    static class Party implements Comparable<Party> {
        int idx;
        int count;

        public Party(int idx, int count) {
            super();
            this.idx = idx;
            this.count = count;
        }

        @Override
        public int compareTo(Party o) {
            int r1 = o.count - this.count;
            if (r1 != 0)
                return r1;
            return this.idx - o.idx;
        }
    }
}
