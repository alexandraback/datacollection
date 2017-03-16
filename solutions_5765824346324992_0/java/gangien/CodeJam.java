import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;

/**
 * Created with IntelliJ IDEA.
 * User: gangien
 * Date: 4/10/15
 * Time: 7:26 PM
 * To change this template use File | Settings | File Templates.
 */
public class CodeJam {
    public static void main(String [] args) throws Exception {
        long start = System.currentTimeMillis();
//        a();
        b();
//        c();
//        d();

        long end = System.currentTimeMillis();

        System.out.printf("Took: %d(ms)\n", (end - start));
    }


    public static void a() throws Exception {
        String questionName = "A-large";
        BufferedReader r = getBufferedReader(questionName + ".in");
        PrintStream out = System.out;
        out = getPrintStream(questionName + ".out");
        int count = readNumber(r);

        for(int x = 0; x < count; x++) {
            String answer = "";
            int N = readNumber(r);
            int [] m = readNumbers(r);
            int maxRate = 0;
            int m2 = 0;
            int m1 = 0;
            for(int y = 0; y < m.length; y++) {
                if(y != 0) {
                    maxRate = Math.max(maxRate, m[y-1] - m[y]);
                }
            }

            for(int y = 0; y < m.length; y++) {
                if(y != 0) {
                    int diff = m[y-1] - m[y];
                    if(m[y-1] > 0) {
                        if(m[y-1] >= maxRate) {
                            m2 += maxRate;
                        } else if(m[y-1] < maxRate) {
                            m2 += m[y-1];
                        }
                    }

                    if(diff >= 0) {
                        m1 += diff;
                    }
                }
            }

            answer = "" + m1 + " " + m2;

            out.printf("Case #%d: ", x + 1);
            out.print(answer);
            out.println();
        }
    }

    public static void b() throws Exception {
        String questionName = "B-small-attempt1";
        BufferedReader r = getBufferedReader(questionName + ".in");
        PrintStream out = System.out;
        out = getPrintStream(questionName + ".out");
        int count = readNumber(r);

        for(int x = 0; x < count; x++) {
            String answer = "";
            long [] t= readLongs(r);
            long B = t[0];
            long N = t[1];
            long [] M = readLongs(r);
            long low = 0;
            long high = Long.MAX_VALUE;
            Fraction rate = new Fraction(0, 1);
            for(int b = 0; b < M.length; b++) {
                rate = rate.add(new Fraction(1, M[b])).reduce();
            }
            Fraction res = new Fraction(N, 1).divide(rate).reduce();
            high = res.left.longValue() / res.right.longValue() + res.right.longValue();


            while(true) {
                long average = (high - low) / 2 + low;
                long total = 0;
                long subtotal = 0;
                for(int a = 0; a < M.length; a++) {
                    total += average / M[a] + 1;
                    if(average % M[a] != 0) {
                        subtotal += average/M[a];
                    }
                }
                if(total < N) {
                    low = average + 1;
                } else {
                    high = average;
                }

                if(low == high) {
                    total = 0;
                    for(int a = 0; a < M.length; a++) {
                        total += low / M[a] +1;
                    }
                    long diff = total - N;
                    for(int a = M.length - 1; a >= 0; a--) {
                        if(low % M[a] == 0) {
                            if(diff == 0) {
                                answer = "" + (a+1);
                                break;
                            }
                            diff --;
                        }
                    }
                    break;
                }
            }
            out.printf("Case #%d: ", x + 1);
            out.print(answer);
            out.println();
        }
    }

    public static void c() throws Exception {
        String questionName = "C-test";
        BufferedReader r = getBufferedReader(questionName + ".in");
        PrintStream out = System.out;
//        out = getPrintStream(questionName + ".out");
        int count = readNumber(r);
        for(int x = 0; x < count; x++) {
            String answer = "";


            out.printf("Case #%d: ", x + 1);
            out.print(answer);
            out.println();
        }
    }



    public static void d() throws Exception {
        String questionName = "D-test";
        BufferedReader r = getBufferedReader(questionName + ".in");
        PrintStream out = System.out;
//        out = getPrintStream(questionName + ".out");
        int count = readNumber(r);

        for(int x = 0; x < count; x++) {
            String answer = "";



            out.printf("Case #%d: ", x + 1);
            out.print(answer);
            out.println();
        }
    }


    public static void fill(boolean [][] a, boolean v) {
        for(boolean [] i : a) {
            Arrays.fill(i, v);
        }
    }

    public static List<Integer> toList(int [] a) {
        final List<Integer> ret = new ArrayList<Integer>();
        for(int i : a) {
            ret.add(i);
        }
        return ret;
    }

    public static BufferedReader getBufferedReader(String file) throws Exception {
        return new BufferedReader(new FileReader(file));
    }
    public static int readNumber(BufferedReader reader) throws Exception {
        return Integer.parseInt(reader.readLine());
    }

    public static long readLong(BufferedReader reader) throws Exception {
        return Long.parseLong(reader.readLine());
    }



    public static int [] readNumbers(BufferedReader reader) throws Exception {
        String [] nums = reader.readLine().split(" ");
        int [] ret = new int[nums.length];
        for(int x = 0; x < nums.length; x++) {
            ret[x] = Integer.parseInt(nums[x]);
        }
        return ret;
    }

    public static long [] readLongs(BufferedReader reader) throws Exception {
        String [] nums = reader.readLine().split(" ");
        long [] ret = new long[nums.length];
        for(int x = 0; x < nums.length; x++) {
            ret[x] = Long.parseLong(nums[x]);
        }
        return ret;
    }
    public static double [] readDoubles(BufferedReader reader) throws Exception {
        String line = reader.readLine();
        String [] nums = line.split(" ");
        double [] ret = new double[nums.length];
        for(int x = 0; x < nums.length; x++) {
            ret[x] = Double.parseDouble(nums[x]);
        }
        return ret;
    }

    public static String [] readStrings(BufferedReader reader) throws Exception {
        String line = reader.readLine();
        String [] nums = line.split(" ");
        return nums;
    }

    public static long [] readBinaryLongs(BufferedReader reader) throws Exception {
        String [] line = readStrings(reader);
        long [] nums = new long[line.length];
        for(int x = 0; x < line.length; x++) {
            nums[x] = Long.parseLong(line[x], 2);
        }
        return nums;
    }


    public static PrintStream getPrintStream(String file) throws Exception {
        if(new File(file).exists()) {
            throw new RuntimeException(new File(file).getAbsolutePath() + " Already exists");
        }

        FileOutputStream fos = new FileOutputStream(new File(file), true);
        PrintStream printStream = new PrintStream(fos);
        return printStream;
    }

    public static class Fraction extends Pair<BigInteger, BigInteger> {
        final public static Fraction ONE = new Fraction(BigInteger.ONE,BigInteger.ONE);
        final public static Fraction TEN = new Fraction(BigInteger.TEN,BigInteger.ONE);
        final public static Fraction ZERO = new Fraction(BigInteger.ZERO, BigInteger.ONE);

        public Fraction(long numerator, long denominator) {
            super(BigInteger.valueOf(numerator), BigInteger.valueOf(denominator));
        }
        public Fraction(BigInteger numerator, BigInteger denominator) {
            super(numerator,denominator);
        }

        public Fraction reduce() {
            BigInteger gcd = left.gcd(right);
            Fraction d = new Fraction(left.divide(gcd), right.divide(gcd));
            if(d.right.compareTo(BigInteger.ZERO) < 0) {
                d.right = d.right.negate();
                d.left = d.left.negate();
            }
            return d;
        }

        public String toString() {
            return left.toString() + "/" + right.toString();
        }

        public Fraction add(final long o) {
            return add(BigInteger.valueOf(o));
        }
        public Fraction add(final BigInteger o) {
            return add(new Fraction(o, BigInteger.ONE));

        }
        public Fraction add(final Fraction o) {
            BigInteger num = left.multiply(o.right).add(right.multiply(o.left));
            BigInteger den = right.multiply(o.right);
            return new Fraction(num, den).reduce();
        }
        public Fraction multiply(final Fraction o) {
            return new Fraction(left.multiply(o.left), right.multiply(o.right)).reduce();
        }
        public Fraction divide(final Fraction o) {
            return this.multiply(new Fraction(o.right, o.left));
        }
        public Fraction subtract(final Fraction o) {
            return this.add(new Fraction(o.left.negate(), o.right));
        }
        public BigInteger floor() {
            return left.divide(right);
        }

        @Override
        public boolean equals(Object o) {
            Fraction f = (Fraction)o;
            f = f.reduce();
            Fraction t = this.reduce();
            if(f.left.equals(t.left) && f.right.equals(t.right)) {
                return true;
            }
            return false;
        }

        public boolean greaterThan(Fraction o) {
            return new BigDecimal(left).divide(new BigDecimal(right), 100, BigDecimal.ROUND_HALF_UP).compareTo(new BigDecimal(o.left).divide(new BigDecimal(o.right), 100, BigDecimal.ROUND_HALF_UP)) > 0;
        }

        public boolean lessThan(Fraction o) {
            return new BigDecimal(left).divide(new BigDecimal(right), 100, BigDecimal.ROUND_HALF_UP).compareTo(new BigDecimal(o.left).divide(new BigDecimal(o.right), 100, BigDecimal.ROUND_HALF_UP)) < 0;
        }
    }
    public static class Pair<L extends Comparable, R extends Comparable> implements Comparable<Pair<L, R>> {
        public L left;
        public R right;

        public Pair(L l, R r) {
            left = l;
            right = r;
        }

        public L getLeft() {
            return left;
        }
        public R getRight() {
            return right;
        }

        public int compareTo(Pair<L, R> o) {
            if(this == o) {
                return 0;
            }
            int res = left.compareTo(o.getLeft());
            if(res == 0) {
                res = right.compareTo(o.getRight());
            }
            return res;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (!(o instanceof Pair)) return false;

            Pair pair = (Pair) o;

            if (left != null ? !left.equals(pair.left) : pair.left != null) return false;
            if (right != null ? !right.equals(pair.right) : pair.right != null) return false;

            return true;
        }

        @Override
        public int hashCode() {
            int result = left != null ? left.hashCode() : 0;
            result = 31 * result + (right != null ? right.hashCode() : 0);
            return result;
        }

        @Override
        public String toString() {
            return "[" + left + ", " + right + "]";
        }
    }
}
