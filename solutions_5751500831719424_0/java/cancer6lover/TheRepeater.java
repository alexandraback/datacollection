import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/**
 * User: aartika
 * Date: 5/3/14
 */
public class TheRepeater {

    public static void main(String[] args) {

        MyScanner sc = new MyScanner();
        int T = sc.nextInt();
        for (int i = 1; i <= T; i++) {
            boolean possible = true;
            int ans = 0;
            int N = sc.nextInt();
            String[] strings = new String[N];
            for (int j = 0; j < N; j++) {
                strings[j] = sc.nextLine();
            }
            int[][] count = new int[N][100];
            String str = "";
            for (int j = 0; j < N; j++) {
                int index = 0;
                char curr = strings[j].charAt(0);
                String chars = curr + "";
                count[j][0] = 1;
                for (int k = 1; k < strings[j].length(); k++) {
                    if (strings[j].charAt(k) == curr) {
                        count[j][index]++;
                    } else {
                        curr = strings[j].charAt(k);
                        index++;
                        count[j][index]++;
                        chars+= curr;
                    }
                }
                if (str.equals(""))
                    str = chars;
                if (!chars.equals(str)) {
                    possible = false;
                    break;
                }
            }

            if (possible) {
                for (int j = 0; j < str.length(); j++) {
                    int sol = Integer.MAX_VALUE;
                    for (int k = 0; k < strings.length; k++) {
                        int tmp = 0;
                        for (int l = 0; l < strings.length; l++) {
                           tmp += Math.abs(count[k][j] - count[l][j]);
                        }
                        if (tmp < sol)
                            sol = tmp;
                    }
                    ans += sol;
                }
            }

            if (possible)
                System.out.println("Case #" + i + ": " + ans);
            else
                System.out.println("Case #" + i + ": Fegla won");
        }

    }

    public static class MyScanner {
        BufferedReader br;
        StringTokenizer st;

        public MyScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine(){
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }

    }

}
