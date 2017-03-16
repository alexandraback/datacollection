import static java.lang.Math.*;
import static java.util.Arrays.*;
import static java.util.Collections.reverse;
import static java.lang.Integer.*;
import static java.lang.Long.parseLong;
import java.util.*;
import java.util.concurrent.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.awt.geom.*;
import java.io.*;

//// Apache Jakarta Common Lang : http://commons.apache.org/lang/
//import org.apache.commons.lang.builder.*;

// java -Xmx1024m -Xss5m
@SuppressWarnings("unchecked")
public class B {
//    private static final String IMPOSSIBLE = "IMPOSSIBLE";
    private static final String NO = "IMPOSSIBLE";
    public static final long MAX = Long.MAX_VALUE;
    public static final long INF = 1000000000000000000L;
    public static final int MOD = 9901; 
    public static final int UNDEF = -3;

    /*
     * problem
     * 
     * 
     */
    /*
     * solution
     * 
     * 
     */
    private void run(int caseNumber) throws Exception {
        int B = INT();
        int N = INT();
        long[] m = new long[B];
        for (int i = 0; i < m.length; i++) {
            m[i] = INT();
        }
        
        
        /// reading input done
        if(debugTestCases.length>0 && Arrays.binarySearch(debugTestCases, caseNumber)<0) {
            if(writeToFile) {
                out.printf("Case #%d: skip\n", caseNumber);
            }
//            System.out.println("----- skip case "+caseNumber+" -----");
            return;
        }

        
        /// start solving problem
//        int ret = small(N, m);
        int ret = big(N, m);
        
        out.printf("Case #%d: %s\n", caseNumber, ret);
    }
    
    // ceil(a/b) , for a>=0, b>0
    static long ceil(long a, long b) {
        return (a + b - 1) / b;
    }
/*
  a[579]=[60, 8, 58, 60, 1, 36, 31, 71, 58, 84, 62, 17, 69, 3, 47, 93, 86, 32, 24, 63, 65, 57, 42, 45, 29, 79, 80, 5, 28, 68, 80, 15, 81, 83, 29, 69, 33, 82, 54, 15, 34, 28, 59, 24, 63, 63, 98, 41, 54, 35, 16, 99, 16, 97, 58, 39, 49, 66, 4, 9, 54, 8, 84, 32, 80, 55, 50, 23, 90, 68, 87, 96, 57, 27, 52, 18, 91, 91, 70, 89, 28, 30, 2, 28, 92, 93, 52, 56, 11, 100, 57, 100, 97, 98, 50, 58, 26, 94, 45, 44, 54, 10, 17, 40, 80, 97, 32, 50, 88, 47, 25, 52, 25, 14, 70, 85, 100, 45, 14, 72, 55, 55, 96, 24, 92, 68, 13, 59, 28, 16, 56, 93, 2, 64, 87, 16, 74, 66, 40, 98, 19, 55, 69, 19, 8, 92, 27, 44, 73, 62, 46, 78, 90, 20, 57, 2, 32, 81, 45, 12, 84, 34, 56, 58, 81, 45, 88, 58, 83, 45, 78, 60, 34, 74, 87, 53, 97, 44, 15, 15, 1, 66, 17, 7, 31, 14, 68, 5, 36, 1, 81, 10, 14, 46, 6, 15, 9, 44, 88, 79, 19, 59, 49, 57, 7, 41, 91, 16, 5, 71, 54, 25, 64, 75, 51, 13, 8, 62, 14, 53, 29, 82, 64, 56, 99, 59, 42, 75, 43, 19, 50, 35, 68, 96, 33, 55, 36, 2, 73, 28, 75, 71, 22, 7, 13, 53, 46, 78, 63, 61, 16, 98, 99, 60, 73, 92, 48, 32, 30, 87, 71, 94, 60, 100, 16, 77, 82, 18, 94, 74, 94, 16, 3, 42, 35, 53, 78, 2, 44, 14, 31, 90, 68, 3, 56, 73, 51, 48, 7, 61, 23, 15, 45, 62, 44, 68, 93, 36, 86, 100, 74, 85, 85, 4, 17, 2, 21, 95, 54, 60, 49, 31, 10, 83, 88, 21, 15, 15, 23, 12, 98, 30, 78, 96, 34, 40, 45, 75, 4, 63, 69, 77, 68, 39, 56, 27, 45, 3, 17, 20, 37, 20, 37, 59, 56, 15, 91, 7, 65, 85, 32, 79, 24, 98, 35, 61, 61, 54, 46, 33, 45, 43, 47, 61, 3, 21, 86, 26, 24, 37, 43, 21, 79, 40, 55, 84, 47, 7, 37, 70, 42, 87, 70, 98, 60, 100, 12, 24, 46, 52, 25, 35, 16, 83, 7, 5, 25, 30, 34, 61, 49, 51, 62, 48, 60, 43, 27, 75, 91, 3, 58, 79, 38, 12, 81, 65, 50, 86, 60, 63, 73, 43, 4, 37, 16, 27, 77, 45, 2, 24, 59, 2, 32, 61, 98, 71, 24, 9, 20, 79, 56, 23, 28, 13, 94, 33, 36, 72, 88, 100, 36, 62, 7, 26, 20, 64, 18, 55, 49, 12, 25, 41, 94, 40, 88, 63, 79, 11, 27, 28, 63, 58, 27, 8, 87, 92, 96, 60, 84, 2, 1, 25, 52, 46, 11, 13, 2, 32, 34, 82, 26, 83, 67, 57, 84, 62, 41, 62, 15, 88, 84, 34, 8, 8, 42, 16, 7, 55, 69, 91, 71, 32, 74, 90, 70, 60, 81, 82, 84, 41, 38, 49, 69, 74, 27, 10, 65, 52, 71, 5, 68, 71, 27, 79, 59, 98, 36, 21, 93, 46, 40, 59, 55, 94, 17, 7, 81, 96, 25, 64, 70, 45, 99, 6, 92, 29, 17, 18, 20, 50, 38, 90, 6, 47, 59, 7, 8, 35, 68, 63, 41, 77, 5, 15, 49, 27, 78, 86, 76]
  ans=12
  res=530
  
  a[765]=[15, 89, 75, 6, 95, 10, 86, 98, 89, 55, 1, 26, 11, 38, 11, 88, 24, 32, 90, 36, 23, 87, 87, 34, 50, 60, 22, 37, 43, 31, 72, 100, 80, 45, 44, 82, 36, 48, 71, 74, 90, 24, 59, 61, 90, 22, 49, 4, 4, 55, 18, 53, 50, 26, 16, 27, 77, 84, 2, 40, 56, 24, 50, 25, 29, 6, 86, 4, 2, 28, 86, 76, 42, 67, 20, 11, 82, 17, 11, 44, 27, 31, 22, 46, 94, 56, 57, 11, 54, 44, 76, 65, 56, 100, 40, 84, 84, 2, 51, 23, 83, 70, 45, 7, 16, 78, 54, 99, 84, 28, 17, 18, 100, 10, 58, 17, 91, 13, 21, 69, 15, 58, 51, 92, 62, 52, 9, 32, 35, 23, 83, 51, 13, 87, 79, 66, 29, 79, 53, 81, 74, 69, 34, 45, 82, 8, 35, 9, 1, 45, 56, 93, 67, 11, 37, 57, 64, 23, 45, 49, 37, 4, 20, 66, 55, 54, 17, 63, 45, 49, 49, 93, 78, 53, 46, 59, 48, 7, 30, 79, 96, 15, 22, 39, 39, 74, 27, 89, 26, 91, 12, 27, 91, 80, 69, 63, 62, 39, 19, 40, 21, 5, 1, 30, 76, 51, 74, 72, 8, 15, 13, 67, 90, 7, 32, 6, 83, 51, 25, 87, 78, 34, 62, 99, 73, 77, 68, 55, 86, 34, 97, 8, 85, 87, 73, 29, 85, 26, 21, 84, 48, 30, 4, 16, 73, 78, 53, 4, 3, 64, 63, 71, 61, 43, 85, 9, 75, 69, 51, 89, 31, 64, 99, 22, 89, 100, 32, 4, 12, 81, 12, 85, 78, 47, 100, 3, 8, 63, 69, 39, 39, 62, 58, 1, 74, 19, 63, 32, 22, 79, 89, 18, 66, 36, 18, 52, 2, 18, 23, 32, 31, 89, 54, 21, 61, 40, 72, 10, 71, 14, 82, 7, 50, 40, 1, 80, 20, 34, 89, 37, 90, 94, 99, 99, 36, 76, 53, 81, 99, 15, 76, 5, 38, 38, 86, 7, 16, 50, 80, 99, 46, 11, 55, 26, 25, 6, 76, 17, 35, 80, 43, 38, 43, 32, 57, 27, 81, 24, 50, 1, 76, 95, 53, 59, 14, 13, 49, 87, 99, 67, 52, 60, 40, 14, 65, 78, 98, 42, 3, 12, 55, 72, 49, 77, 75, 11, 52, 32, 45, 21, 44, 82, 29, 98, 19, 83, 88, 16, 89, 81, 35, 29, 13, 84, 2, 8, 36, 88, 80, 77, 15, 61, 7, 79, 92, 19, 20, 88, 99, 46, 13, 96, 6, 93, 23, 80, 64, 10, 44, 92, 94, 58, 22, 76, 78, 10, 96, 48, 76, 58, 2, 37, 19, 63, 79, 77, 95, 35, 36, 72, 86, 72, 82, 93, 62, 49, 89, 4, 22, 87, 43, 65, 39, 77, 8, 28, 27, 23, 91, 87, 36, 85, 10, 18, 7, 22, 76, 46, 16, 33, 64, 55, 89, 31, 66, 17, 84, 71, 55, 74, 85, 100, 27, 87, 22, 12, 48, 37, 10, 27, 36, 7, 93, 94, 94, 26, 51, 30, 65, 53, 20, 17, 67, 1, 20, 75, 87, 100, 4, 80, 25, 46, 3, 87, 16, 59, 4, 32, 51, 18, 90, 94, 17, 6, 7, 13, 89, 53, 6, 33, 16, 32, 53, 58, 27, 29, 2, 9, 74, 24, 1, 73, 74, 77, 60, 70, 81, 64, 62, 98, 52, 29, 55, 3, 70, 35, 34, 48, 31, 87, 1, 67, 31, 4, 77, 93, 82, 34, 8, 37, 10, 76, 80, 77, 79, 46, 85, 44, 15, 15, 52, 48, 81, 9, 34, 90, 99, 38, 65, 50, 6, 63, 88, 28, 81, 76, 69, 48, 89, 46, 14, 95, 27, 33, 75, 22, 22, 65, 10, 74, 74, 82, 86, 32, 86, 78, 46, 24, 41, 10, 13, 67, 98, 36, 76, 39, 88, 92, 20, 53, 39, 19, 81, 26, 1, 23, 17, 61, 1, 37, 72, 98, 72, 59, 55, 56, 27, 74, 11, 79, 51, 86, 54, 51, 61, 26, 25, 5, 52, 78, 7, 69, 28, 98, 93, 55, 83, 74, 87, 8, 53, 98, 40, 99, 9, 16, 20, 29, 25, 13, 89, 37, 13, 44, 26, 16, 45, 17, 43, 98, 39, 75, 56, 79, 86, 6, 2, 42, 32, 39, 1, 29, 5, 40, 98, 81, 43, 52, 37, 20, 55, 85, 84, 54, 8, 92, 82, 98, 73, 26, 85, 60, 77, 78, 89, 15, 6, 57, 12, 39, 52, 89, 27, 89, 29, 74, 64, 30, 10, 68, 68, 21, 85, 60, 12, 58, 55, 94, 65, 37, 53, 25, 62, 26, 86]
  ans=128
  res=551
  
 */
    static int big(int N, long[] m) {
        // lo false, hi true
        long lo = -1;
        long hi = INF;
        while (lo < hi) {
            long mid = (long) (lo + ((long) hi - lo) / 2);
            long num = num(mid, m);
            if (num>=N) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        long prev=num(lo-1, m);
        int d=(int) (N-prev);
        Set<Integer> set = new TreeSet<>();
        for (int i = 0; i < m.length; i++) {
            if (lo%m[i]==0) {
                set.add(i);
            }
        }
        int ret=-1;
        int idx=0;
        for (int r : set) {
            idx++;
            if (idx==d) {
                ret=r+1;
                break;
            }
        }
        return ret;
    }

    static long num(long mid, long[] m) {
        long ret=0;
        for (int i = 0; i < m.length; i++) {
//            num += mid/m[i]+1;
            ret+=ceil(mid+1,m[i]);
        }
        return ret;
    }
    
    static int small(int N, long[] m) {
        N--;
        
//        long lcm=lcm(m);
//        long block=0;
//        for (int i = 0; i < m.length; i++) {
//            block+=lcm/m[i];
//        }
//        if (N>block) {
//            N%=block;
//        }
        int ret = bf(N,m);
        return ret;
    }
    
    private static int bf(int n, long[] m) {
        // head is the first element in sort
        PriorityQueue<XY> q = new PriorityQueue<>();
        for (int i = 0; i < m.length; i++) {
            q.add(new XY(0,i));
        }
        int i=0;
        while (true) {
            XY st = q.poll();
            long t=st.x;
            long idx=st.y;
            if (i==n) {
                return (int) idx+1;
            }
            
            q.add(new XY(t+m[(int) idx], idx));
            i++;
        }
    }
    static class XY implements Comparable<XY> {
        long x;
        long y;

        public XY(long x, long y) {
            this.x = x;
            this.y = y;
        }

        public String toString() {
            return "(" + x + ", " + y + ")";
        }

        public int hashCode() {
            final long M = 31;
            long r = M * M + M * x + y;
            return (int) r;
        }

        public boolean equals(Object a) {
            if (a == null || getClass() != a.getClass())
                return false;
            XY o = (XY) a;
            return x == o.x && y == o.y;
        }

        public int compareTo(XY o) {
            // < : -1 smallest 1st
            if (x != o.x)
                return x < o.x ? -1 : 1;
            return y < o.y ? -1 : (y == o.y ? 0 : 1);
        }
    }

    //  assume that a>0, b>0
    public static long lcm(long a, long b) {
        /*
        if (b/gcd(a,b)>Long.MAX_VALUE/a) return -1; // overflow
         */
        return b / gcd(a, b) * a; // better do div first to avoid overflow 
    }

    public static long lcm(long[] a) {
        long ret = 1;
        for (int i = 0; i < a.length; ++i) {
            ret = lcm(a[i], ret);
            // NOTE: ret might overflow
            /*
            if(ret>MAX) {
                return -1;
            }
             */
        }
        return ret;
    }

    // non recursive version for gcd
    public static long gcd(long x, long y) {
        x = Math.abs(x); // take case of negative
        y = Math.abs(y);
        if (x == 0 && y == 0)
            return 1;
        while (y != 0) {
            long c = x % y;
            x = y;
            y = c;
        }
        return x;
    }

    // gcd of array
    public static long gcd(long[] x) {
        long ret = x[0];
        for (int i = 1; i < x.length; ++i) {
            ret = gcd(ret, x[i]);
        }
        return ret;
    }
    
    static boolean printInput=false;
//    static boolean printInput=true; // print input case

    static boolean printDoubleCheck=true;
//    static boolean printDoubleCheck=false;
    
    static boolean redirectStdoutToFile=false;
//    static boolean redirectStdoutToFile=true; // redirect all STDOUT to "output.txt"

    
    static boolean writeToFile=true; // output result to file
//    static boolean writeToFile=false;

    static String[] testFilenames = new String[] {
        "B-test.in",
        "B-small-attempt0.in",
//        "B-small-attempt1.in",
//        "B-small.in",
//        "B-small-practice.in",
        "B-large.in",
//        "B-large-practice.in",
    };

    static int THREAD=1;
//    static int THREAD=3;

    static BufferedReader in;
    static StringTokenizer inTok = new StringTokenizer("");
    static PrintWriter out;

    /// only run given cases, {} runs all
    static int[] debugTestCases = {};
//    static int[] debugTestCases = {};

    public static void main(String[] args) throws Exception {
        // $0 inputFile caseStart caseEnd
        if (args.length>0) {
            testFilenames = args;
        }

        if (debugTestCases.length > 0) {
            System.out.println("NOTE: only run these cases: "+Arrays.toString(debugTestCases)+"\n");            
        }
        // redirect sys out
        if (redirectStdoutToFile) {
            String filename = "output.txt";
            System.out.println("NOTE: redirect stdout to file "+filename);
            FileOutputStream fos = new FileOutputStream(filename);
            PrintStream ps = new PrintStream(fos,true);
            System.setOut(ps);
        }

//        myTest();

        for (int i = 0; i < testFilenames.length; i++) {
            System.out.println((i>0?"\n\n":"") + "##### file["+i+"]: "+testFilenames[i]);
            solveFile(testFilenames[i]);
        }
    }

    static void solveFile(String testFilename) throws Exception {
        String resultFilename=testFilename+"-res.txt";
        long start = System.currentTimeMillis();
//        in = new BufferedReader(new InputStreamReader(System.in));
        in = new BufferedReader(new FileReader(testFilename));
        int NN=INT();
        out = writeToFile ? new PrintWriter(new FileWriter(resultFilename),true)
                          : new PrintWriter(System.out, true);
        if (THREAD>1) {
            parallelSolve(NN);
        } else {
            for (int i = 1; i <= NN; i++) {
                boolean debug=debugTestCases.length>0 && Arrays.binarySearch(debugTestCases, i)>=0;
                if (debug) {
                    printInput = true;
                }
//                out.printf("Case #%d: ", i);
                if (printInput) System.out.println("\n### Case "+i);
                new B().run(i);
                if (debug) {
                    printInput = false;
                }
            }
        }
        in.close();

        if (writeToFile) {
            out.close();
        }

        System.out.println("\nTime taken: "+((System.currentTimeMillis()-start)/1000.0)+" sec");

        if (writeToFile) {
            boolean first = true;
            String[] suffix = new String[] {
                    "", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9",
                    "-bad", "-bad0", "-bad1", "-bad2", "-bad3", "-bad4", "-bad5", "-bad6", "-bad7", "-bad8", "-bad9", };
            for (int i = 0; i < suffix.length; i++) {
                File ans=new File(testFilename+"-ans"+suffix[i]+".txt");
                if(ans.exists()&&ans.length()>0) {
                    boolean same=sameFileContent(ans, new File(resultFilename), first);
                    first = false;
                    if(same) {
                        System.out.println("All pass :)          Answer == "+ans);
                        break;
                    } else {
                        System.out.println("ERROR: Answer != "+ans);
                    }
                }
            }
        }
    }
    static void parallelSolve(int totalCase) throws Exception {
        int th = Math.min(THREAD, Runtime.getRuntime().availableProcessors());
        System.out.println("thread = "+th);
        ExecutorService executor = Executors.newFixedThreadPool(th);
        List<Solver> solvers = new ArrayList<Solver>();
        for (int i = 1; i <= totalCase; i++) {
            if (printInput) System.out.println("\n### Case "+i);

            solvers.add(new Solver());
        }

        List <Future<Object>> results = executor.invokeAll(solvers);

        int caseNumber=1;
        for (Future<Object> result : results) {
            out.printf("Case #%d: %s\n", caseNumber, result.get());
            caseNumber++;
        }
        executor.shutdown();
    }
    static class Solver implements Callable<Object> {
        final int n;

        // Do all input reading here!!
        public Solver() throws IOException {
            n = INT();
            throw new RuntimeException("TODO: do reading/solving in Solver()");
        }

        // Do no reading here! This is run async!
        // Solve the actual problem here
        public Object call() throws Exception {
            return n;
        }
    }

    private static boolean sameFileContent(File ansFile, File resFile, boolean showInfo) throws IOException {
        if (showInfo) {
            System.out.println();
        }

        BufferedReader ans = new BufferedReader(new FileReader(ansFile));
        BufferedReader res = new BufferedReader(new FileReader(resFile));
        boolean ok=true;
        List<Integer> wrong = new ArrayList<Integer>();
        int ln=1;
        while(true) {
            String sAns=ans.readLine();
            String sRes=res.readLine();
            if(sAns==null) {
                if(sRes!=null) {
                    if (showInfo) {
                        System.out.println("### result has more lines than answer");
                        do {
                            System.out.println(sRes);
                        } while ((sRes=res.readLine())!=null);
                        System.out.println();
                    }
                    ok=false;
                }
                break;
            }
            if(sRes==null) {
                if(sAns!=null && !sAns.isEmpty()) {
                    if (showInfo) {
                        System.out.println("### answer has more lines than result");
                        do {
                            System.out.println(sAns);
                        } while ((sAns=ans.readLine())!=null);
                        System.out.println();
                    }
                    ok=false;
                }
                break;
            }
            String tAns = sAns.trim();
            String tRes = sRes.trim();
            if(!tAns.equals(tRes)) {
                if (matchDouble(tAns,tRes, showInfo && printDoubleCheck)) {
                    if (showInfo && printDoubleCheck) {
                        System.out.println("### line "+ln+" pass double check:");
                        System.out.println("ans = "+sAns);
                        System.out.println("res = "+sRes);
                        System.out.println();
                    }
                } else {
                    if (showInfo) {
                        System.out.println("### line "+ln+" not match:");
                        System.out.println("ans = "+sAns);
                        System.out.println("res = "+sRes);
                        System.out.println();
                    }
                    ok=false;
                    wrong.add(ln);
                }
            }
            ln++;
        }
        if(!ok && showInfo) {
            System.out.println("wrong : "+wrong.size()+" lines, lines start from 1: "+wrong);
            System.out.println("total : "+ln+" lines");
        }
        ans.close();
        res.close();
        return ok;
    }
    private static boolean matchDouble(String tAns, String tRes, boolean showInfo) {
        final double tol = 1e-6;

        if (!tAns.matches(".*[0-9]+\\.[0-9]+.*") || !tRes.matches(".*[0-9]+\\.[0-9]+.*")) {
            // no 123.456 pattern
            return false;
        }

        String[] sa= tAns.split(" ");
        String[] sr= tRes.split(" ");
        if (sa.length!=sr.length) {
            return false;
        }
        for (int i = 0; i < sr.length; i++) {
            if (sa[i].equals(sr[i])) continue;

            try {
                double a = Double.parseDouble(sa[i]);
                double r = Double.parseDouble(sr[i]);
                if (abs(a-r)>tol) {
                    if (showInfo) {
                        System.out.println(i+"-th ans!=res: "+sa[i]+" != "+sr[i]);
                    }
                    return false;
                }
            } catch (NumberFormatException e) {
                return false;
            }
        }
        return true;
    }
    
    private static void myTest() throws Exception {
        int num=10000;
        long[] a;
        for (int i = 1; i <= num; ++i) {
//            a = new long[Rn.i(1,1000)];
////            System.out.println(i+" : "+small(Rn.i(1,1000000000), Rn.a(a,1,100000)));
//            System.out.println(i+" : "+big(Rn.i(1,1000000000), Rn.a(a,1,100000)));
//            
//            a = new long[Rn.i(1,1000)];
////            a = new long[Rn.i(1,10)];
////            a = new long[Rn.i(1,5)];
////            a = Rn.a(a,1,100);
//            a = Rn.a(a,1,100000);
////            int N=Rn.i(1,100000000);
////            int N=Rn.i(1,10000000);
//            int N=Rn.i(1,1000000);
////            int N=Rn.i(1,100000);
//            int ans=big(N, a);
//            int res=small(N, a);
//            if (ans!=res) {
//                System.out.println("ERROR");
//                System.out.println("  a[" + a.length + "]=" + Arrays.toString(a));
//                System.out.println("  ans=" + ans);
//                System.out.println("  res=" + res);
//                System.exit(1);
//            }
        }
    }

    static String LINE() throws IOException {
        String s=in.readLine();
        if (printInput) System.out.println(s);
        return s;
    }
    static String STR() throws IOException {
        while (!inTok.hasMoreTokens()) {
            String line = LINE();
            if (line == null) {
                return null;
            }
            inTok = new StringTokenizer(line);
        }
        return inTok.nextToken();
    }

    static int INT() throws IOException { return Integer.parseInt(STR()); }
    static long LONG() throws IOException { return Long.parseLong(STR()); }
    static double DOUBLE() throws IOException { return Double.parseDouble(STR()); }
    
    static int INT(String s) { return Integer.parseInt(s); }
    static double DOUBLE(String s) { return Double.parseDouble(s); }
    static long LONG(String s) { return Long.parseLong(s); }
}
