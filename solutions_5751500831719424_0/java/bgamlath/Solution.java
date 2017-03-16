
import java.util.*;
import java.io.*;
import java.math.*;

public class Solution {

    static BufferedReader in;
    static StringTokenizer stk;
    static int T, N, M, K;
    static PrintWriter out;

    public static void main(String[] args) throws Exception {

        backupPreviousOutputs("out.txt");

        out = new PrintWriter("out.txt");
        in = new BufferedReader(new FileReader("src/in.txt"));

        // Start of User Code

        T = ni();

        for (int i = 0; i < T; i++) {
            printf("Case #%d: %s\n", i + 1, proc());
        }

        // End of User Code
        out.flush();
        out.close();
        in.close();
    }

    static String proc() throws Exception {
        N = ni();
        String[] temp = new String[N];
        for (int i = 0; i < N; i++) {
            temp[i] = ns();
        }

        String id = getID(temp[0]);
        
        for (int i = 1; i < N; i++) {
            if (!id.equals(getID(temp[i]))) {
                return "Fegla Won";
            }
        }

        long res = 0;

        int[][] x = getCounts(temp);
        
//        for(int i = 0; i< N; i++){
//            for(int j = 0; j<id.length(); j++){
//                System.out.printf("%d ", x[j][i]);
//            }
//            System.out.println("");
//        }
        for (int i = 0; i < id.length(); i++) {
            res += findMinDistanceSum(x[i]);
        }
        return res + "";
        //throw new Exception("NOT IMPLEMENTED YET");

    }

    static String getID(String s) {
        StringBuilder sb = new StringBuilder(s.length());
        char c = 0;
        for (int i = 0; i < s.length(); i++) {
            if (c != s.charAt(i)) {
                c = s.charAt(i);
                sb.append(c);
            }
        }
        //System.out.println(sb.toString());
        return sb.toString();
    }

    static int[][] getCounts(String[] s) {
        int[][] res = new int[getID(s[0]).length()][N];
        for (int j = 0; j < s.length; j++) {
            char c = 0;
            int ind = -1;
            for (int i = 0; i < s[j].length(); i++) {
                if (c != s[j].charAt(i)) {
                    ind++;
                    res[ind][j] = 1;
                    c = s[j].charAt(i);
                } else {
                    res[ind][j]++;
                }
            }
        }
        return res;
    }

    static long findMinDistanceSum(int[] k) {
        Arrays.sort(k);
        int midIndex = (k.length - 1) / 2;
        long sum = 0;
        for (int d : k) {
            sum += Math.abs(d - k[midIndex]);
        }
        return sum;
    }

    static long modPow(long n, long pow, long mod) {
        return BigInteger.valueOf(n).modPow(BigInteger.valueOf(pow), BigInteger.valueOf(mod)).longValue();
    }

    static long modInv(long n, long mod, boolean isPrimeModuli) {
        if (isPrimeModuli) {
            return modPow(n, mod - 2, mod);
        }
        return BigInteger.valueOf(n).modInverse(BigInteger.valueOf(mod)).longValue();
    }
    // calc factorials
    static long[] fact;

    static void calcFactorials(int n) {
        fact = new long[n + 1];
        fact[0] = 1;
        for (int i = 1; i <= n; i++) {
            fact[i] = fact[i - 1] * i;
        }
    }

    static void calcFactorialsModM(int n, long M) {
        fact = new long[n + 1];
        fact[0] = 1;
        for (int i = 1; i <= n; i++) {
            fact[i] = fact[i - 1] * i;
            fact[i] %= M;
        }
    }

    static long ncr(int n, int r) {
        return fact[n] / (fact[n - r] * fact[r]);
    }

    static long ncrModM(int n, int r, long MOD, boolean isPrimeModuli) {
        return fact[n] * modInv(fact[n - r], MOD, isPrimeModuli) * modInv(fact[r], MOD, isPrimeModuli);
    }

    static long toL(String s) {
        return Long.parseLong(s);
    }

    static long toL(BigInteger n) {
        return n.longValue();
    }

    static int toI(String s) {
        return Integer.parseInt(s);
    }

    static double toD(String s) {
        return Double.parseDouble(s);
    }

    static void printf(String format, Object... args) {
        out.printf(format, args);
        System.out.printf(format, args);
    }

    static void println(String str) {
        out.println(str);
        System.out.println(str);
    }

    static int ni() throws Exception {
        while (stk == null || !stk.hasMoreTokens()) {
            stk = new StringTokenizer(in.readLine());
        }
        return Integer.parseInt(stk.nextToken());
    }

    static long nl() throws Exception {
        while (stk == null || !stk.hasMoreTokens()) {
            stk = new StringTokenizer(in.readLine());
        }
        return Long.parseLong(stk.nextToken());
    }

    static double nd() throws Exception {
        while (stk == null || !stk.hasMoreTokens()) {
            stk = new StringTokenizer(in.readLine());
        }
        return Double.parseDouble(stk.nextToken());
    }

    static String ns() throws Exception {
        while (stk == null || !stk.hasMoreTokens()) {
            stk = new StringTokenizer(in.readLine());
        }
        return stk.nextToken();
    }

    static int min(int a, int b) {
        return a < b ? a : b;
    }

    static int max(int a, int b) {
        return a > b ? a : b;
    }

    static long min(long a, long b) {
        return a < b ? a : b;
    }

    static long max(long a, long b) {
        return a > b ? a : b;
    }

    static int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    static long gcd(long a, long b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    public static void backupPreviousOutputs(String name) throws Exception {
        File f = new File(name);
        if (f.exists()) {
            f.renameTo(new File("out [" + new Date(f.lastModified()).toLocaleString() + "].txt"));
        }
    }
}
