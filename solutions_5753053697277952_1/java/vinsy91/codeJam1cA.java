import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * Created by vinaysaini on 5/7/16.
 */
class codeJam1cA {

    public static void main(String[] args) {
        PrintWriter out = null;
        try {
            out = new PrintWriter("/Users/vinaysaini/bitbucket/javaprog/src/output_large.txt");
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        int T = in.nextInt();
        for (int t = 0; t < T; t++) {
            int n = in.nextInt();
            int[] ar = new int[n];
            for (int i = 0; i < n; i++) {
                ar[i] = in.nextInt();
            }
            StringBuilder ans = new StringBuilder();
            while (getCount(ar) > 0) {
                int total = getCount(ar);
                int people = 2;
                if (total % 2 != 0) people = 1;
                int majority = (total - people) / 2;
                StringBuilder sb = new StringBuilder();
                for (int i = 0; i < n && people > 0; i++) {
                    while (ar[i] > majority) {
                        people--;
                        ar[i]--;
                        sb.append((char)(i + 'A'));
                    }
                }
                if (people > 0) {
                    for (int i = 0; i < n&& people > 0; i++) {
                        if (ar[i] > 0) {
                            ar[i]--;
                            sb.append((char)(i + 'A'));
                            people--;
                        }
                    }
                }
                if (people > 0) {
                    for (int i = 0; i < n && people > 0; i++) {
                        if (ar[i] > 0) {
                            ar[i]--;
                            sb.append((char)(i + 'A'));
                            people--;
                        }
                    }
                }
                ans.append(sb);
                ans.append(" ");
            }
            out.println("Case #"+(t+1)+": "+ans.toString().trim());

        }
        out.close();
    }
    static int getCount(int [] ar) {
        int total = 0;
        for (int i = 0; i < ar.length; i++) {
            total += ar[i];
        }
        return total;
    }



    public static FastScanner in = new FastScanner();

    public static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner() {
           // br = new BufferedReader(new InputStreamReader(System.in));
            try {
                br = new BufferedReader(new FileReader("/Users/vinaysaini/bitbucket/javaprog/src/A-large.in"));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
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

        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }

    static class Pair implements Comparable<Pair>{
        int x, y;
        Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
        @Override
        public int compareTo(Pair o) {
            return  this.x - o.x;
        }
        public String toString() {
            return "{"+this.x+","+this.y+"}";
        }
    }
}
