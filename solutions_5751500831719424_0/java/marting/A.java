import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class A {
    static List<Pair<Character, Integer>> calc(String s) {
        List<Pair<Character, Integer>> res = new ArrayList<>();
        int i0 = 0;
        for (int i=1; i<s.length(); i++) {
            if (s.charAt(i)!=s.charAt(i-1)) {
                res.add(new Pair(s.charAt(i-1), i-i0));
                i0 = i;
            }
        }
        res.add(new Pair(s.charAt(s.length()-1), s.length()-i0));
        return res;
    }
    static int cmp(List<Pair<Character, Integer>> r1, List<Pair<Character, Integer>> r2) {
        int res = 0;
        if (r1.size() == r2.size()) {
            for (int i = 0; i < r1.size(); i++) {
                if (r1.get(i).t1 == r2.get(i).t1)
                    res += Math.abs(r1.get(i).t2 - r2.get(i).t2);
                else
                    return -1;
            }
        } else
            return -1;
        return res;
    }
    public static void main(String[] args) {
        FastScanner in = new FastScanner();
        int T = in.nextInt();
        for (int _i=0; _i<T; _i++) {
            int N = in.nextInt();
            String s1 = in.next();
            String s2 = in.next();
            int i1 = 0, i2 = 0;
            System.out.printf("Case #%d: ", _i + 1);
            List<Pair<Character, Integer>> r1 = calc(s1);
            List<Pair<Character, Integer>> r2 = calc(s2);
            int res = cmp(r1, r2);
            System.out.println(res<0 ? "Fegla Won" : res);
        }
    }
    public static class FastScanner {
        final BufferedReader br;
        StringTokenizer st = new StringTokenizer("");
        FastScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }
        FastScanner(String file) throws FileNotFoundException {
            br = new BufferedReader(new FileReader(file));
        }
        String next() {
            while (!st.hasMoreTokens())
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            return st.nextToken();
        }
        int nextInt() {
            return Integer.parseInt(next());
        }
        double nextDouble() {
            return Double.parseDouble(next());
        }
        long nextLong() {
            return Long.valueOf(next());
        }
        long[] readArr(int n) {
            long[] r = new long[n];
            for (int i = 0; i < n; i++) {
                r[i] = nextLong();
            }
            return r;
        }
    }
    public static class Pair<T1 extends Comparable<T1>, T2 extends Comparable<T2>> implements Comparable<Pair<T1, T2>> {
        public final T1 t1;
        public final T2 t2;
        public Pair(T1 t1, T2 t2) {
            this.t1 = t1;
            this.t2 = t2;
        }
        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            Pair pair = (Pair) o;
            if (!t1.equals(pair.t1)) return false;
            if (!t2.equals(pair.t2)) return false;
            return true;
        }
        @Override
        public int hashCode() {
            int result = t1.hashCode();
            result = 31 * result + t2.hashCode();
            return result;
        }
        @Override
        public int compareTo(Pair<T1, T2> o) {
            int r = t1.compareTo(o.t1);
            if (r!=0) return r;
            return t2.compareTo(t2);
        }
    }
}