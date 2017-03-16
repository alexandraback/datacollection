import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class ProblemBLarge {
    BufferedReader rd;

    private ProblemBLarge() throws IOException {
        rd = new BufferedReader(new InputStreamReader(System.in));
        compute();
    }

    private void compute() throws IOException {
        int n = pint();
        for(int i=0;i<n;i++) {
            out("Case #" + (i + 1) + ": " + solve());
        }
    }

    private String solve() throws IOException {
        int[] a = intarr();
        long[] m = longarr();
        int b = a[0];
        long n = a[1]-1;
        if(b == 1) {
            return "1";
        } else {
            if(n < b) {
                return Long.toString(n+1);
            }
            long g = m[0];
            for(long k: m) {
                g = gcd(g, k);
            }
            long t1 = 0;
            long t2 = 1000000000000000L;
            while(t2 - t1 > 1) {
                long t = (t1+t2)/2;
                long sum = 0;
                for(long k: m) {
                    sum += t/k+(t%k!=0?1:0);
                }
                if(sum < n) {
                    t1 = t;
                } else {
                    t2 = t-1;
                }
            }
            long off = -3;
            while(true) {
                for(long base: new long[] { t1-g, t1, t1+g }) {
                    long t = base + off;
                    long sum = 0;
                    for(long k: m) {
                        sum += t/k+(t%k!=0?1:0);
                    }
                    for(int k=0;k<m.length;k++) {
                        if(t%m[k]==0) {
                            if(sum == n) {
                                return Long.toString(k+1);
                            }
                            sum++;
                        }
                    }
                }
                off++;
            }
        }
    }

    public static long gcd(long a, long b) {
        while (b > 0) {
            long c = a % b;
            a = b;
            b = c;
        }
        return a;
    }

    private int pint() throws IOException {
        return pint(rd.readLine());
    }

    private int pint(String s) {
        return Integer.parseInt(s);
    }

    private int[] intarr() throws IOException {
        return intarr(rd.readLine());
    }

    private int[] intarr(String s) {
        String[] q = split(s);
        int n = q.length;
        int[] a = new int[n];
        for(int i=0;i<n;i++) {
            a[i] = Integer.parseInt(q[i]);
        }
        return a;
    }

    private long[] longarr() throws IOException {
        return longarr(rd.readLine());
    }

    private long[] longarr(String s) {
        String[] q = split(s);
        int n = q.length;
        long[] a = new long[n];
        for(int i=0;i<n;i++) {
            a[i] = Long.parseLong(q[i]);
        }
        return a;
    }

    private String[] split(String s) {
        int n = s.length();
        int sp = 0;
        for(int i=0;i<n;i++) {
            if(s.charAt(i)==' ') {
                sp++;
            }
        }
        String[] res = new String[sp+1];
        int last = 0;
        int x = 0;
        for(int i=0;i<n;i++) {
            char c = s.charAt(i);
            if(c == ' ') {
                res[x++] = s.substring(last,i);
                last = i+1;
            }
        }
        res[x] = s.substring(last,n);
        return res;
    }

    private static void out(Object x) {
        System.out.println(x);
    }

    public static void main(String[] args) throws IOException {
        new ProblemBLarge();
    }
}
