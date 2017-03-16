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
            String[] ss = new String[N];
            for (int i = 0; i < N; i++) ss[i] = in.next();
            int res = calcs(ss);
            System.out.printf("Case #%d: ", _i+1);
            System.out.println(res<0 ? "Fegla Won" : res);
        }
    }

    static int calcc(List<Integer> li) {
        int res = Integer.MAX_VALUE;
        for (int i = 0; i < li.size(); i++) {
            int r = 0;
            for (int j = 0; j < li.size(); j++) {
                r += Math.abs(li.get(i) - li.get(j));
            }
            res = Math.min(res, r);
        }
        return res;
    }

    private static int calcs(String[] ss) {
        List<Pair<Character, Integer>> r1 = calc(ss[0]);
        List<Integer> counts[] = new List[r1.size()];
        for (int i = 0; i < r1.size(); i++) {
            counts[i] = new ArrayList<>();
            counts[i].add(r1.get(i).t2);
        }
        for (int i=1; i<ss.length; i++) {
            String s = ss[i];
            List<Pair<Character, Integer>> r = calc(s);
            if (r.size() != r1.size()) return -1;
            for (int j = 0; j < r.size(); j++) {
                if (r.get(j).t1 != r1.get(j).t1)
                    return -1;
                counts[j].add(r.get(j).t2);
            }
        }
        int res = 0;
        for (int i = 0; i < counts.length; i++) {
            res += calcc(counts[i]);
        }
        return res;
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