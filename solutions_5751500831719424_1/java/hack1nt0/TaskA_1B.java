package contest;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.*;

/**
 * Created by DaiYang on 2014/4/13.
 */
public class TaskA_1B {
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new FileInputStream("TaskA_1B.in"));
        PrintWriter out = new PrintWriter(new FileOutputStream("TaskA_1B.out"));
        //PrintWriter out = new PrintWriter(System.out);
        int T = in.nextInt();
        for (int Case = 1; Case <= T; ++Case) {
            out.print("Case #" + Case + ": ");
            int N = in.nextInt();
            List<Integer>[] compact = new ArrayList[N];
            for (int i = 0; i < N; ++i) {
                compact[i] = new ArrayList<Integer>();
                String s = in.next() + "$";
                for (int j = 0, k = 0; k < s.length(); ++k) {
                    if (s.charAt(k) == s.charAt(j)) continue;
                    compact[i].add(s.charAt(j) * 101 + k - j);
                    j = k;
                }
            }
            boolean fail = false;
            for (int i = 0; i < N; ++i) {
                if (i < N - 1 && compact[i].size() != compact[i + 1].size()) {
                    out.println("Fegla Won");
                    fail = true;
                    break;
                }
            }
            if (fail) continue;

            for (int i = 0; i < compact[0].size(); ++i) {
                for (int j = 0; j < N; ++j) {
                    if (j < N - 1 && compact[j].get(i) / 101 != compact[j + 1].get(i) / 101) {
                        out.println("Fegla Won");
                        fail = true;
                        break;
                    }
                }
                if (fail) break;
            }
            if (fail) continue;

            int res = 0;
            for (int i = 0; i < compact[0].size(); ++i) {
                int[] cnts = new int[N];
                for (int j = 0; j < N; ++j)
                    cnts[j] = compact[j].get(i) % 101;
                Arrays.sort(cnts);
                for (int cnt: cnts)
                    res += Math.abs(cnt - cnts[N / 2]);
            }
            out.println(res);

        }
        out.close();
    }
}
