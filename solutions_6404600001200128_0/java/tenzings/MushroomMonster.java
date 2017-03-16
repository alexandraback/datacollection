import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Scanner;

public class MushroomMonster {
    Scanner sc = new Scanner(getClass().getResourceAsStream(IN));
    static final String FILENAME = "A-small-attempt0";
    static final String IN = FILENAME + ".in";
    static final String OUT = FILENAME + ".out";
    PrintStream out = System.out;

    private void solve(int mi[]) {
        long eat1 = 0, eat2 = 0;

        long maxDiff = 0;

        for(int i = 1; i < mi.length; i++) {
            int diff = mi[i - 1] - mi[i];
            eat1 += Math.max(diff, 0);
            maxDiff = Math.max(diff, maxDiff);
        }

        for(int i = 1; i < mi.length; i++) {
            eat2 += Math.min(maxDiff, mi[i-1]);
        }

        out.print(eat1 + " ");
        out.println(eat2);
    }

    private void run() throws Exception {
        out = new PrintStream(new FileOutputStream(OUT));
        int t = sc.nextInt();
        for (int tc = 1; tc <= t; tc++) {
            System.out.println("Test Case " + tc + "...");
            int N = sc.nextInt();
            int[] mi = new int[N];
            for(int i = 0; i < N; i++) {
                mi[i] = sc.nextInt();
            }
            out.print("Case #" + tc + ": ");
            solve(mi);
        }
        sc.close();
        out.close();
    }

    public static void main(String args[]) throws Exception {
        new MushroomMonster().run();
    }
}
