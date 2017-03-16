import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class A {
    static BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st = new StringTokenizer("");

    static class P implements Comparable<P>{
        public int x;
        public char y;
        public P(int x, char y) {
            this.x = x;
            this.y = y;
        }
        @Override
        public String toString() {
            return "{"+x+","+y+"}";
        }

        @Override
        public int compareTo(P p) {
            return p.x-x;
        }
    }

    public static void main(String[] args) throws Exception {
        int T = readInt();
        int caseN = 1;

        while (T-- > 0) {
            int N = readInt();
            System.out.print("Case #"+(caseN++)+":");

            PriorityQueue<P> pq = new PriorityQueue<P>();
            long sum = 0;
            //int[] people = new int[N];
            for(int n = 0; n < N; n++) {
                int x = readInt();
                sum += x;
                if(x > 0) pq.add(new P(x, (char)('A'+n)));
            }
            if(sum % 2 == 1) {
                P top = pq.poll();
                top.x--;
                if(top.x != 0) pq.add(top);
                System.out.print(" " + top.y);
            }
            while(!pq.isEmpty()) {
                P top = pq.poll();
                P sTop = pq.poll();
                if(Math.abs(top.x - sTop.x) <= 1) {
                    top.x--;
                    sTop.x--;
                    if(top.x != 0) pq.add(top);
                    if(sTop.x != 0) pq.add(sTop);
                    System.out.print(" " + top.y + sTop.y);
                } else {
                    top.x -= 2;
                    if(top.x != 0) pq.add(top);
                    if(sTop.x != 0) pq.add(sTop);
                    System.out.print(" " + top.y + top.y);
                }
            }
            System.out.println();
        }
    }

    // Read next input-token as string.
    static String readString() throws Exception {
        while (!st.hasMoreTokens()) {
            st = new StringTokenizer(stdin.readLine());
        }
        return st.nextToken();
    }

    // Read next input-token as integer.
    static int readInt() throws Exception {
        return Integer.parseInt(readString());
    }
    
    // Read next input-token as long.
    static long readLong() throws Exception {
        return Long.parseLong(readString());
    }

    // Read next input-token as double.
    static double readDouble() throws Exception {
        return Double.parseDouble(readString());
    }
}

