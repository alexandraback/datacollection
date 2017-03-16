import java.io.*;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {

        new Main().solve();
    }

    //ArrayList<Integer>[] g;

    int mod = 1000000007;

    PrintWriter out;

    int n;

    ArrayList<Integer>[] g;

    void solve() throws IOException {

        Reader in = new Reader("A-large.in");
        out = new PrintWriter( new BufferedWriter(new FileWriter("A-large.out")) );

        //Reader in = new Reader();
        //out = new PrintWriter( new BufferedWriter(new OutputStreamWriter(System.out)) );

        //BufferedReader br = new BufferedReader( new FileReader("in.txt") );
        //BufferedReader br = new BufferedReader( new InputStreamReader( System.in ) );

        int t = in.nextInt();
        int cs = 1;

        while (t > 0) {

            out.print("Case #" + cs + ": ");

            int n = in.nextInt();

            int[] a = new int[n];
            int cnt = n;

            for (int i = 0; i < n; i++)
                a[i] = in.nextInt();

            while (cnt > 0) {

                int max1 = 0;
                int max2 = 0;

                int i1 = -1;
                int i2 = -1;

                for (int i = 0; i < n; i++) {

                    if (a[i] == 0)
                        continue;

                    if (a[i] >= max1) {

                        max2 = max1;
                        i2 = i1;
                        max1 = a[i];
                        i1 = i;
                    }
                    else
                    if (a[i] > max2) {

                        max2 = a[i];
                        i2 = i;
                    }
                }

                //System.err.println(max1+" "+max2+" "+cnt+" "+i1+" "+i2);

                if (max2 > 1 || (max2 == 1 && cnt > 3)) {

                    out.print((char)('A'+i1)+""+((char)('A'+i2))+" ");
                    a[i1]--;
                    a[i2]--;

                    if (a[i2] == 0)
                        cnt--;

                    if (a[i1] == 0)
                        cnt--;
                }
                else
                if (max2 == 1) {

                    if (max1 != 1 || cnt == 3) {

                        out.print((char)('A'+i1)+" ");
                        a[i1]--;

                        if (a[i1] == 0)
                            cnt--;

                    }
                    else {

                        out.print((char)('A'+i1)+""+(char)('A'+i2)+" ");
                        a[i1]--;
                        a[i2]--;
                        cnt = 0;
                    }
                }


            }

            out.println();

            t--;
            cs++;
        }

        out.flush();
        out.close();
    }


    class Pair implements Comparable<Pair>{

        int a;
        int b;


        Pair(int a, int b) {

            this.a = a;
            this.b = b;
        }

        public int compareTo(Pair p) {

            if (a < p.a)
                return -1;

            if (a > p.a)
                return 1;

            if  (b < p.b)
                return -1;

            if (b > p.b)
                return 1;

            return 0;
        }
    }

    class Item {

        int a;
        int b;
        int c;

        Item(int a, int b, int c) {
            this.a = a;
            this.b = b;
            this.c = c;
        }

    }

    class Reader {

        BufferedReader  br;
        StringTokenizer tok;

        Reader(String file) throws IOException {
            br = new BufferedReader( new FileReader(file) );
        }

        Reader() throws IOException {
            br = new BufferedReader( new InputStreamReader(System.in) );
        }

        String next() throws IOException {

            while (tok == null || !tok.hasMoreElements())
                tok = new StringTokenizer(br.readLine());
            return tok.nextToken();
        }

        int nextInt() throws NumberFormatException, IOException {
            return Integer.valueOf(next());
        }

        long nextLong() throws NumberFormatException, IOException {
            return Long.valueOf(next());
        }

        double nextDouble() throws NumberFormatException, IOException {
            return Double.valueOf(next());
        }

        String nextLine() throws IOException {
            return br.readLine();
        }

    }

}