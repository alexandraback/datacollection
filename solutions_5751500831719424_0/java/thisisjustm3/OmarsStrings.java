import java.io.*;
import java.util.HashSet;
import java.util.Set;

/**
 * @author arshsab
 * @since 05 2014
 */

public class OmarsStrings {
    public static void main(String... args) throws IOException {
        final String FILE_NAME = "omar";

        BufferedReader br = new BufferedReader(new FileReader(FILE_NAME + ".in"));

        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(FILE_NAME + ".out")));

        final int T = Integer.parseInt(br.readLine());

        for (int t = 1; t <= T; t++) {
            final int N = Integer.parseInt(br.readLine());

            String[] strings = new String[N];

            for (int i = 0; i < strings.length; i++) {
                strings[i] = br.readLine();
            }

            int sol = solve(strings);

            if (sol != -1)
                out.printf("Case #%d: %d\n", t, sol);
            else
                out.printf("Case #%d: Fegla Won\n", t);
        }

        out.flush();
        out.close();
    }

    public static int solve(String[] strings) {
        Set<String> dupChecker = new HashSet<>();

        for (String s : strings) {
            String act = s.charAt(0) + "";
            char curr = s.charAt(0);

            for (char c : s.toCharArray()) {
                if (c != curr) {
                    curr = c;
                    act += c;
                }
            }

            dupChecker.add(act);
        }

        if (dupChecker.size() != 1) {
            return -1;
        }

        String stripped = dupChecker.iterator().next();

        int[][] arr = new int[strings.length][stripped.length()];

        for (int i = 0; i < strings.length; i++) {

            int pos = 0;

            for (int j = 0; j < arr[i].length; j++) {
                int orig = pos;

                char c = strings[i].charAt(pos);
                while (pos < strings[i].length() && strings[i].charAt(pos) == c) {
                    pos++;
                }

                arr[i][j] = pos - orig;
            }
        }

        int totMin = 0;

        for (int i = 0; i < stripped.length(); i++) {
            int letMin = Integer.MAX_VALUE;

            for (int k = 0; ; k++) {
                int greater = 0;
                int less = 0;

                for (int j = 0; j < strings.length; j++) {
                    if (arr[j][i] > k) {
                        greater += arr[j][i] - k;
                    } else {
                        less += k - arr[j][i];
                    }
                }

                letMin = Math.min(letMin, greater + less);

                if (greater == 0) {
                    break;
                }
            }

            totMin += letMin;
        }

        return totMin;
    }

}
