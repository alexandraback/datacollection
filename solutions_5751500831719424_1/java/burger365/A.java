import java.io.*;
import java.util.*;

/**
 * Created by burger on 5/4/14.
 */
public class A {
    public String solve(int N, String[] S) {
        List<Character> l = new LinkedList<Character>();
        char c = '_';
        for (int i = 0; i < S[0].length(); i++) {
            if (S[0].charAt(i) != c) {
                c = S[0].charAt(i);
                l.add(c);
            }
        }

        for (int i = 1; i < N; i++) {
            List<Character> cmp = new LinkedList<Character>();
            c = '_';
            for (int j = 0; j < S[i].length(); j++) {
                if (S[i].charAt(j) != c) {
                    c = S[i].charAt(j);
                    cmp.add(c);
                }
            }
            if (cmp.size() != l.size()) return "Fegla Won";
            for (int j = 0; j < l.size(); j++)
                if (!l.get(j).equals(cmp.get(j)))
                    return "Fegla Won";
        }

        int[][] numChars = new int[N][l.size()];
        for (int i = 0; i < N; i++) {
            c = '_';
            for (int j = 0, k = -1; j < S[i].length(); j++) {
                if (S[i].charAt(j) != c) {
                    c = S[i].charAt(j);
                    k++;
                }
                numChars[i][k]++;
            }
        }

        int res = 0;
        for (int i = 0; i < l.size(); i++) {
            HashSet<Integer> set = new HashSet<Integer>();
            for (int j = 0; j < N; j++) {
                set.add(numChars[j][i]);
            }

            int minOps = Integer.MAX_VALUE;
            for (int j : set) {
                int ops = 0;
                for (int k = 0; k < N; k++) {
                    ops += Math.abs(numChars[k][i] - j);
                }
                minOps = Math.min(minOps, ops);
            }
            res += minOps;
        }

        return String.valueOf(res);
    }

    public static void main(String[] args) {
        InputStream inputStream;
        try {
            inputStream = new FileInputStream("large.in");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        OutputStream outputStream;
        try {
            outputStream = new FileOutputStream("answer.out");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);

        int T = in.nextInt();
        for (int t = 1; t <= T; t++) {
            int N = in.nextInt();
            in.nextLine();
            String[] S = new String[N];
            for (int i = 0; i < N; i++)
                S[i] = in.nextLine();

            out.write("Case #" + t + ": " + new A().solve(N, S) + "\n");
        }

        out.close();
    }
}
