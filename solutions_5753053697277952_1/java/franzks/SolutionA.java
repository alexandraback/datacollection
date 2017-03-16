package round1c_2016;

import java.io.*;
import java.util.Map;
import java.util.StringTokenizer;

public class SolutionA {

    private final static String FILENAME = "A-large.in";
    private final static String PATH = System.getProperty("user.home") + "/codejam/" + FILENAME;

    public static void main(String[] args) throws IOException {
        new SolutionA()
                .initInputReader()
                .solveAllTestCases()
                .cleanup();
    }

    private SolutionA solveAllTestCases() throws IOException {
        int testCases = nextInt();

        for (int testCase = 0; testCase < testCases; testCase++) {
            StringBuilder sb = new StringBuilder();
            sb.append("Case #")
               .append(testCase + 1)
               .append(": ");

            solveTestCase(sb);

            sb.append("\n");
            System.out.print(sb.toString());
            out.write(sb.toString());
        }

        return this;
    }

    private void solveTestCase(StringBuilder sb) throws IOException {
        int n = nextInt();
        int[] arr = new int[n];
        int tot = 0;
        for (int i = 0; i < n; i++) {
            arr[i] = nextInt();
            tot += arr[i];
        }

        if (tot % 2 == 1) {
            int mx = 0;
            int idx = -1;
            for (int i = 0; i < n; i++) {
                if (arr[i] > mx) {
                    mx = arr[i];
                    idx = i;
                }
            }
            sb.append((char) ('A' + idx));
            sb.append(" ");
            arr[idx]--;
            tot--;
        }

        for (;;) {
            int mx1 = 0;
            int idx1 = -1;
            int mx2 = 0;
            int idx2 = -1;

            for (int i = 0; i < n; i++) {
                if (arr[i] >= mx1) {
                    mx2 = mx1;
                    idx2 = idx1;
                    mx1 = arr[i];
                    idx1 = i;
                } else if (arr[i] >= mx2) {
                    mx2 = arr[i];
                    idx2 = i;
                }
            }

            char c1 = (char) ('A' + idx1);
            char c2 = (char) ('A' + idx2);

            if (mx1 - mx2 >= 2) {
                sb.append(c1);
                sb.append(c1);
                sb.append(' ');
                arr[idx1] -= 2;
            } else {
                sb.append(c1);
                sb.append(c2);
                sb.append(' ');
                arr[idx1]--;
                arr[idx2]--;
            }

            tot -= 2;
            if (tot == 0)
                break;

//            sb.append((char) ('A' + idx));
//            sb.append(' ');
//            arr[idx]--;
//            tot--;
        }
    }

    private final static int MOD = 1000000007;

    /*
     * Methods for reading input
     */

    private BufferedReader br;
    private StringTokenizer st;
    private FileWriter out;

    private SolutionA initInputReader() throws IOException {
        br = new BufferedReader(new FileReader(
                new File(PATH)));
        out = new FileWriter(PATH + ".solution");
        st = new StringTokenizer(br.readLine());
        return this;
    }

    private void cleanup() throws IOException {
        br.close();
        out.flush();
        out.close();
    }

    private int nextInt() throws IOException {
        checkEmptyTokenizer();
        return Integer.parseInt(st.nextToken());
    }

    private long nextLong() throws IOException {
        checkEmptyTokenizer();
        return Long.parseLong(st.nextToken());
    }

    private double nextDouble() throws IOException {
        checkEmptyTokenizer();
        return Double.parseDouble(st.nextToken());
    }

    private String nextString() throws IOException {
        checkEmptyTokenizer();
        return st.nextToken();
    }

    private void checkEmptyTokenizer() throws IOException {
        if (!st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
    }

    /*
     * Convenience methods
     */

    // Provides a default value if map doesn't have the key
    private <K, V> V getFromMap(Map<K, V> map, K key, V def) {
        if (map.containsKey(key)) {
            return map.get(key);
        } else {
            map.put(key, def);
        }
        return def;
    }

    private void print(String line, Object... args) {
        System.out.println(String.format(line, args));
    }
}
