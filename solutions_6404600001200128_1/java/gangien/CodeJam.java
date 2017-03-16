import java.io.*;
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
        a();
//        b();
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
        String questionName = "B-test";
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
}
