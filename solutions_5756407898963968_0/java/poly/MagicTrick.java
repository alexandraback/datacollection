import java.io.File;
import java.io.FileInputStream;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class MagicTrick {
    private static String file = "data/A-small-attempt0.in";
    private static final String MULTI = "Bad magician!";
    private static final String CHEAT = "Volunteer cheated!";

    public static void main(String[] args) throws Exception {
        FileInputStream is = new FileInputStream(new File(file));
        Scanner scanner = new Scanner(is);
        scanner.useDelimiter("[;\r\n]+");
        int T = scanner.nextInt();
        for (int t = 0; t < T; t++) {
            Set<Integer> first = new HashSet<Integer>();
            int ans1 = scanner.nextInt();
            for (int i = 0; i < 4; i++) {
                String s = scanner.next();
                if (i == ans1 - 1) {
                    String[] strings = s.split(" ");
                    for (String ss : strings) {
                        int k = Integer.parseInt(ss);
                        first.add(k);
                    }
                }
            }

            int match = 0;
            int ans = -1;
            int ans2 = scanner.nextInt();
            for (int i = 0; i < 4; i++) {
                String s = scanner.next();
                if (i == ans2 - 1) {
                    String[] strings = s.split(" ");
                    for (String ss : strings) {
                        int k = Integer.parseInt(ss);
                        if (first.contains(k)) {
                            match++;
                            ans = k;
                        }
                    }
                }
            }

            if (match > 1) {
                out(t, MULTI);
            } else if (match == 1) {
                out(t, ans);
            } else {
                out(t, CHEAT);
            }
        }
    }

    static void out(int t, Object ans) {
        System.out.println("Case #" + (t + 1) + ": " + ans);
    }
}
