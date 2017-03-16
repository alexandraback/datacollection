import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.*;

public class Haircut {
    Scanner sc = new Scanner(getClass().getResourceAsStream(IN));
    static final String FILENAME = "B-small-attempt1";
    static final String IN = FILENAME + ".in";
    static final String OUT = FILENAME + ".out";
    PrintStream out = System.out;

    private void solve(int Mi[], int N) {
        int[] Ti = new int[Mi.length];
        List<Integer> pattern = new ArrayList<Integer>();
        int n = 1;
        Set<Integer> cache = new HashSet<Integer>();
        while(n <= N) {
            Integer key = Arrays.hashCode(Ti);
            if(cache.contains(key)) {
                int ans = pattern.get((N - n) % (n - 1));
                out.println(ans);
                return;
            }
            cache.add(key);
            int min = Integer.MAX_VALUE;
            int i;
            for(i = 0; i < Ti.length; i++) {
                min = Math.min(min, Ti[i]);
                if(Ti[i] == 0) {
                    if(n == N) { out.println(i+1); return; }
                    pattern.add(i + 1);
                    break;
                }
            }
            if(i == Ti.length) {
                for(int j = 0; j < Ti.length; j++) {
                    Ti[j] -= min;
                }
            } else {
                Ti[i] = Mi[i];
                n++;
            }
        }
    }

    private void run() throws Exception {
        out = new PrintStream(new FileOutputStream(OUT));
        int t = sc.nextInt();
        for (int tc = 1; tc <= t; tc++) {
            System.out.println("Test Case " + tc + "...");
            int B = sc.nextInt(), N = sc.nextInt();
            int[] Mi = new int[B];
            for(int i = 0; i < B; i++) {
                Mi[i] = sc.nextInt();
            }
            out.print("Case #" + tc + ": ");
            solve(Mi, N);
        }
        sc.close();
        out.close();
    }

    public static void main(String args[]) throws Exception {
        new Haircut().run();
    }
}
