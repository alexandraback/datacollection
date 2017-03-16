import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Problem1B{
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

    public class Node {
        int index;
        int time;
        public Node(int t_index, int t_time) {
            index = t_index;
            time = t_time;
        }
    }
    
    int gcd(int a, int b)
    {
      while(a != 0 && b != 0) // until either one of them is 0
      {
         int c = b;
         b = a % b;
         a = c;
      }
      return a + b; // either one is 0, so return the non-zero value
    }
    
    int compute(int[] list) {
        int tempGcd = list[0];
        for (int i = 1; i < list.length; i++) {
            tempGcd = gcd(tempGcd, list[i]);
        }
        int result = 1;
        for (int i = 0; i < list.length; i++) {
            result *= list[i];
        }
        return result / tempGcd;
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
            int B = scan.nextInt();
            int N = scan.nextInt();
            int[] values = new int[B];
            for (int j = 0; j < B; j++) {
                values[j] = scan.nextInt();
            }
            int tempResult = compute(values);
            int tempCount = 0;
            for (int j = 0; j < B; j++) {
                tempCount += (tempResult / values[j]);
            }
            N = (N - 1) % tempCount + 1;
            PriorityQueue<Node> q = new PriorityQueue<Node>(B,
                    new Comparator<Node>(){
                        public int compare(Node a, Node b) {
                        if (a.time > b.time)
                            return 1;
                        else if(a.time == b.time) {
                            return a.index - b.index;
                        }
                        else 
                            return -1;
                    }
                });
            for (int j = 0; j < B; j++) {
                q.add(new Node(j, 0));
            }
            for (int j = 1; j < N; j++) {
                Node tempNode = q.poll();
                tempNode.time += values[tempNode.index];
                q.add(tempNode);
            }
            out.println("Case #" + (i + 1) + ": " + (q.peek().index + 1));
        }
        out.close();
    }

    public static void main(String[] args){ 
        Problem1B tool = new Problem1B();
        tool.init();
    }
}