/* Created by Wolfgang Beyer */

import java.io.*;
import java.util.StringTokenizer;
import java.util.Locale;

public class Main {
    static BufferedReader in;
    static StringTokenizer tok;

    static void solve(int caseNumber) throws Exception {
        int n = nextInt();
        int[] p = new int[n];
        int sum = 0;
        for (int i = 0; i < n; i++) {
            p[i] = nextInt();
            sum += p[i];
        }
        //System.out.println("sum: " + sum);

        StringBuilder sol = new StringBuilder();
        if (sum % 2 == 1) {
            //System.out.println("ungerade");
            int j = getMaxIndex(p);
            sol.append(Character.toString((char) (j + 65)) + " ");
            p[j]--;
            sum--;
        }

        while (sum > 0) {
            int j = getMaxIndex(p);
            sol.append(Character.toString((char) (j + 65)));
            p[j]--;
            sum--;
            j = getMaxIndex(p);
            sol.append(Character.toString((char) (j + 65)) + " ");
            p[j]--;
            sum--;
        }

        System.out.println("Case #" + caseNumber + ": " + sol);
    }

    static int getMaxIndex(int[] p) {
        int max = -1;
        int maxIndex = -1;
        for (int i = 0; i < p.length; i++) {
            if (p[i] > max) {
                max = p[i];
                maxIndex = i;
            }
        }
        return maxIndex;
    }

    static int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    static String next() throws IOException {
        while (tok == null || !tok.hasMoreTokens()) {
            tok = new StringTokenizer(in.readLine());
        }
        return tok.nextToken();
    }

    public static void main(String[] args) {
        try {
            Locale.setDefault(Locale.US);
            //in = new BufferedReader(new InputStreamReader (System.in));
            //in = new BufferedReader(new FileReader ("test.in"));
            //in = new BufferedReader(new FileReader ("A-small-attempt0.in"));
            in = new BufferedReader(new FileReader ("A-large.in"));
            int n = nextInt();
            for (int i = 0; i < n; i++) {
                solve(i + 1);
            }
            in.close();
        } catch (Throwable e) {
            e.printStackTrace();
        }
    }

}
