import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Problem1A{
    //-----------PrintWriter for faster output---------------------------------
    public static PrintWriter out;

    //-----------MyScanner class for faster input----------
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

    public void init(){
        MyScanner scan = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));

        // Start writing your solution here. -------------------------------------

        /*
        int n      = sc.nextInt();        // read input as integer
        long k     = sc.nextLong();       // read input as long
        double d   = sc.nextDouble();     // read input as double
        String str = sc.next();           // read input as String
        String s   = sc.nextLine();       // read whole line as String

        int result = 3*n;
        out.println(result);                    // print via PrintWriter
         */

        // Stop writing your solution here. -------------------------------------
        int caseCount = scan.nextInt();
        for (int i = 0; i < caseCount; i++) {
            int n = scan.nextInt();
            int[] input = new int[n];
            for (int j = 0; j < n; j++) {
                input[j] = scan.nextInt();
            }
            // compute method1
            int result1 = 0;
            for (int j = 1; j < n; j++) {
                if (input[j] < input[j - 1]) {
                    result1 += input[j - 1] - input[j];
                }
            }

            //compute method2
            int maxRate = 0;
            for (int j = 1; j < n; j++) {
                if (input[j] < input[j - 1]) {
                    maxRate = Math.max(maxRate, input[j - 1] - input[j]);
                }
            }
            int result2 =  maxRate * (input.length - 1);
            for (int j = 0; j < n - 1; j++) {
                if (input[j] < maxRate ) {
                    result2 -= maxRate - input[j];
                }
            }
            out.println("Case #" + (i + 1) + ": " + result1 + " " + result2);
        }
        out.close();
    }

    public static void main(String[] args){ 
        Problem1A tool = new Problem1A();
        tool.init();
    }
}