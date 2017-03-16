import java.io.File;
import java.io.PrintStream;
import java.util.Scanner;

public class MainA {

    public static void main(String... args) throws Exception {
        Scanner sc = new Scanner(System.in);
//        PrintStream out = System.out;
		PrintStream out = new PrintStream(new File("f.out"));
        int t, T;
        int n;
        for (t = 1, T = sc.nextInt(); t <= T; t++) {
            n = sc.nextInt();
            String s[] = new String[n];
            for (int i = 0; i < n; i++) {
                s[i] = sc.next();
            }
            int pos[] = new int[n];
            int res = 0;
            while (true) {
                if (pos[0] >= s[0].length()) {
                    for (int i = 0; i < n; i++) {
                        if (pos[i] < s[i].length()) {
                            res = -1;
                            break;
                        }
                    }
                    break;
                }
                char c = s[0].charAt(pos[0]);
                int min = Integer.MAX_VALUE, max = 0, l[] = new int[n];
                for (int i = 0; i < n; i++) {
                    l[i] = 0;
                    for (int j = pos[i]; j < s[i].length() && s[i].charAt(j) == c; j++) {
                        l[i]++;
                    }
                    if (l[i] < min) {
                        min = l[i];
                    }
                    if (l[i] > max) {
                        max = l[i];
                    }
                }
                if (min == 0 && max > 0) {
                    res = -1;
                    break;
                } else {
                    for (int i = 0; i < n; i++) {
                        pos[i] += l[i];
                    }
                    int best = Integer.MAX_VALUE;
                    for (int L = min; L <= max; L++) {
                        int cost = 0;
                        for (int i = 0; i < n; i++) {
                            cost += Math.abs(L - l[i]);
                        }
                        if (cost < best) {
                            best = cost;
                        }
                    }
                    res += best;
                }
            }
            if (res >= 0) {
                out.println(String.format("Case #%d: %d", t, res));
            } else {
                out.println(String.format("Case #%d: Fegla Won", t));
            }
        }
    }

}
