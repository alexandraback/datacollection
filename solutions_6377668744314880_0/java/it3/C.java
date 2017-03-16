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
public class C {
//    private static final String IMPOSSIBLE = "IMPOSSIBLE";
    private static final String NO = "IMPOSSIBLE";
    public static final long MAX = Long.MAX_VALUE;
    public static final int INF = 1000000000;
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
        int N = INT();

        int[] x = new int[N];
        int[] y = new int[N];
        for (int i = 0; i < y.length; i++) {
            x[i] = INT();
            y[i] = INT();
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
        
//        int ret = 0;
        int[] ret = bf(x,y);
//        String ret = "";
        
        out.printf("Case #%d:\n", caseNumber);
        for (int i = 0; i < ret.length; i++) {
            out.println(ret[i]);
        }
    }

    // msk=33
    //  pt[9]=[(0, 0), (0, 5), (0, 10), (5, 0), (5, 5), (5, 10), (10, 0), (10, 5), (10, 10)]    
    private int[] bf(int[] x, int[] y) {
        int n = y.length;
        List<XY> ls = new ArrayList<>();
        XY[] a = new XY[n];
        for (int i = 0; i < a.length; i++) {
            a[i]=new XY(x[i],y[i]);
            ls.add(new XY(x[i],y[i]));
        }
        int[] ret = new int[n];
        if (n<=3) {
            return ret;
        }
        
        fill(ret,INF);
        for (int msk = 0; msk < (1<<n)-1; msk++) {
            int v=bitCount(msk);
            int[] nx = new int[n-v];
            int[] ny = new int[n-v];
            int idx=0;
            for (int i = 0; i < x.length; i++) {
                if (has(msk,i)) continue; 
                
                nx[idx] = x[i]; 
                ny[idx] = y[i];
                idx++;
            }
            XY[] poly = convex(nx, ny);
            for (idx = 0; idx < n; idx++) {
                if (has(msk,idx)) continue;
                
                for (int j = 1; j < poly.length; j++) {
                    if (onSegment(x[idx], y[idx], poly[j-1].x, poly[j-1].y, poly[j].x, poly[j].y)) {
                        if (ret[idx] > v) {
                            ret[idx] = v;
//                            if (v==2) {
//                                System.out.println("  msk=" + msk);;
//                            }
                        }
                    }
                }
//                for (XY xy : poly) {
//                    if (idx>=0) {
//                    }
//                }
            }
        }
        return ret;
    }
    
    
    // keep only the lowest bit
    static int lowest(int mask) {
        return (mask & -mask);
    }

    // i-th bit is set
    static boolean has(int mask, int i) {
        return (mask & (1 << i)) != 0;
    }

    // set i-th bit to v
    static int set(int mask, int i, boolean v) {
        return v ? set(mask, i) : unset(mask, i);
    }

    // set i-th bit
    static int set(int mask, int i) {
        return mask | (1 << i);
    }

    // unset i-th bit
    static int unset(int mask, int i) {
        return mask & ~(1 << i);
    }

    // mask set contains subset
    static boolean contain(int set, int subset) {
        return (set & subset) == subset;
    }

    boolean onSegment(int x, int y, int x1, int y1, int x2, int y2) {
        return colinear(x1, y1, x2, y2, x, y) 
                && between(x,y,x1,y1,x2,y2);
    }
    boolean colinear(int x1, int y1, int x2, int y2, int x3, int y3) {
        int A1=y2-y1;
        int B1=-(x2-x1);
        int A2=y3-y2;
        int B2=-(x3-x2);
        int det = A1*B2 - A2*B1;        
        return det==0;
    }
 // return true if (x,y) is between (x0,y0), (x1,y1), assume all pointa on the same line
    static boolean between(int x, int y, int x0, int y0, int x1, int y1) {
        return Math.min(x0,x1)<=x && x<=Math.max(x0,x1) && Math.min(y0,y1)<=y && y<=Math.max(y0,y1);
    }
    
    // OA cross OB, >0 means OA=>OB clockwise rotate  
    static double cross(XY o, XY a, XY b) {
        return 1.0 * (a.x - o.x) * (b.y - o.y) - 1.0 * (a.y - o.y) * (b.x - o.x);
    }

//    static int[] convexIdx(int[] x, int[] y) {
//        XY[] pt = new XY[x.length];
//        for (int i = 0; i < pt.length; i++) {
//            pt[i] = new XY(x[i], y[i]);
//        }
//        Arrays.sort(pt);
//
//        int[] temp = new int[pt.length + 1];
//        int m = 0; // m: convex hull size  
//        // wrap lower half  
//        for (int i = 0; i < pt.length; ++i) {
//            while (m >= 2 && cross(pt[temp[m - 2]], pt[temp[m - 1]], pt[i]) <= 0) {
//                m--;
//            }
//            temp[m++] = i;
//        }
//
//        // wrap upper half, ignore final point, will wrap 1st point again  
//        for (int i = pt.length - 2, t = m + 1; i >= 0; --i) {
//            while (m >= t && cross(pt[temp[m - 2]], pt[temp[m - 1]], pt[i]) <= 0) {
//                m--;
//            }
//            temp[m++] = pt[i];
//        }
//
//        XY[] poly = new XY[m];
//        for (int i = 0; i < m; i++) {
//            poly[i] = temp[i];
//        }
//        return poly;        
//    }
    
    // Andrew's Monotone Chain : O(nlogn)
    // return convex poly, 1st & last element are the same point
    static XY[] convex(int[] x, int[] y) {
        XY[] pt = new XY[x.length];
        for (int i = 0; i < pt.length; i++) {
            pt[i] = new XY(x[i], y[i]);
        }
        Arrays.sort(pt);
//        System.out.println("  pt[" + pt.length + "]=" + Arrays.toString(pt));

        XY[] temp = new XY[pt.length + 1];

        int m = 0; // m: convex hull size  

        // wrap lower half  
        for (int i = 0; i < pt.length; ++i) {
            while (m >= 2 && cross(temp[m - 2], temp[m - 1], pt[i]) <= 0) {
                m--;
            }
            temp[m++] = pt[i];
        }

        // wrap upper half, ignore final point, will wrap 1st point again  
        for (int i = pt.length - 2, t = m + 1; i >= 0; --i) {
            while (m >= t && cross(temp[m - 2], temp[m - 1], pt[i]) <= 0) {
                m--;
            }
            temp[m++] = pt[i];
        }

        XY[] poly = new XY[m];
        for (int i = 0; i < m; i++) {
            poly[i] = temp[i];
        }
        return poly;
    }
    
    private static final double EPS = 1e-10;

    // return grid points inside or on convex
    static List<XY> convexPoints(XY[] convex, int miny, int maxy) {
        List<XY> pt = new ArrayList<XY>();

        // scan line find all points inside or on convex poly
        for (int py = miny; py <= maxy; ++py) {
            double left = INF, right = -INF;
            for (int i = 0; i < convex.length - 1; ++i) {
                int x1 = convex[i].x;
                int y1 = convex[i].y;
                int x2 = convex[i + 1].x;
                int y2 = convex[i + 1].y;

                // no intersection in py coordinate
                if ((y1 < py && y2 < py) || (y1 > py && y2 > py)) {
                    continue;
                }

                // same as py coordinate, update left & right boundary
                if (y1 == py && y2 == py) {
                    left = Math.min(left, x1);
                    left = Math.min(left, x2);
                    right = Math.max(right, x1);
                    right = Math.max(right, x2);
                    continue;
                }

                // find intersection at py
                double px = x1 + (x2 - x1 + 0.0) * (py - y1) / (y2 - y1 + 0.0);
                left = Math.min(left, px);
                right = Math.max(right, px);
            }

            if (left > right) {
                continue;
            }

            int xl = (int) Math.ceil(left - EPS);
            int xr = (int) Math.floor(right + EPS);
            for (int px = xl; px <= xr; ++px) {
                pt.add(new XY(px, py));
            }
        }

        return pt;
    }

    static class XY implements Comparable<XY> {
        int x;
        int y;

        public XY(int x, int y) {
            this.x = x;
            this.y = y;
        }

        public String toString() {
            return "(" + x + ", " + y + ")";
        }

        public int hashCode() {
            final int M = 31;
            int r = M * M + M * x + y;
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
    
    static boolean printInput=false;
//    static boolean printInput=true; // print input case

    static boolean printDoubleCheck=true;
//    static boolean printDoubleCheck=false;

    static boolean redirectStdoutToFile=false;
//    static boolean redirectStdoutToFile=true; // redirect all STDOUT to "output.txt"

    
    static boolean writeToFile=true; // output result to file
//    static boolean writeToFile=false;

    static String[] testFilenames = new String[] {
        "C-test.in",
        "C-small-attempt0.in",
//        "C-small-attempt1.in",
//        "C-small.in",
//        "C-small-practice.in",
//        "C-large.in",
//        "C-large-practice.in",
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
                new C().run(i);
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
//        int num=-1000;
        int num=1000;
        for (int i = 1; i <= num; ++i) {
//            System.out.println(i+" : "+new C().small(Rn.i(0,50)));
//            for (int j = 1; j <= i; ++j) {
//                System.out.println(i+","+j+" : "+i);
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
