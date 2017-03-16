import java.io.*;
import java.util.*;

import static java.lang.Math.min;

public class Main {
    /**
     * author geshpaniec
     * 23.10.2014
     */

    StringTokenizer in;
    BufferedReader inb;
    PrintWriter out;
    static boolean local;
    final String problemname = "success";
    final static String _localArg="geshpaniec1";
    final static byte IO=3;
        /* IO:
         * 1 - standard I/O
         * 2 - input.txt/output.txt
         * 3 - problemname.in/problemname.out
         */

    int[] barbers;
    int[] barbersOld;
    int B;
    long N=0;
    boolean nowN=false;
    int ans=0;

    long resTime(long time){
        long res = B,now = 0;
        for (int i = 0; i < B; i++) {
            res+=time/barbers[i];
            if (time%barbers[i]==0)
                now++;
        }
        if (res-now<N&&res>=N) {
            nowN = true;
            long A = res-now;
            for (int i = 0; i < B ; i++) {
                if (time%barbersOld[i]==0) {
                    A++;
                    if (A==N)
                        ans = i;
                }
            }
        }
        return res;
    }

    public void solve() throws Exception {
        int T = nextInt();
        A:for (int q = 0; q < T; q++) {
            long R = 100000000000000L, L = 0;
            B = nextInt();
            N = nextInt();
            barbers = nextArray(B);
            barbersOld = barbers.clone();
            Arrays.sort(barbers);
            while (L <= R) {
                long mid = (L + R) >>> 1;
                long midVal = resTime(mid);

                if (midVal < N)
                    L = mid + 1;
                else if (midVal >= N) {
                    if (nowN) {
                        nowN = false;
                        out.println("Case #"+(q+1)+": "+(ans + 1));
                        continue A;
                    } else
                        R = mid - 1;
                }
            }
        }
    }

    public static void main(String[] args) throws Exception {
        local = false;
        if (args.length == 1 && args[0].equals(_localArg))
            local = true;
        new Main().run();
    }

    public void run() throws Exception {
        if (local) {
            inb = new BufferedReader(new FileReader("input.txt"));
            out = new PrintWriter(new OutputStreamWriter(System.out));
        } else {
            switch (IO){
                case 1:
                    inb = new BufferedReader(new InputStreamReader(System.in));
                    out = new PrintWriter(new OutputStreamWriter(System.out));
                    break;
                case 2:
                    inb = new BufferedReader(new FileReader("input.txt"));
                    out = new PrintWriter(new FileWriter("output.txt"));
                    break;
                case 3:
                    inb = new BufferedReader(new FileReader(problemname+".in"));
                    out = new PrintWriter(new FileWriter(problemname+".out"));
                    break;
            }
        }
        in = new StringTokenizer("");
        double Time=System.nanoTime();
        solve();
        if (local){
            Time=System.nanoTime()-Time;
            out.println();
            out.println(" Time work: "+Time/(1e9)+" seconds");
        }
        out.flush();
    }

    int nextInt() throws Exception {
        return Integer.parseInt(next());
    }

    long nextLong() throws Exception{
        return Long.parseLong(next());
    }

    double nextDouble() throws Exception {
        return Double.parseDouble(next());
    }

    String next() throws Exception {
        if (!in.hasMoreTokens())
            in=new StringTokenizer(inb.readLine());
        return in.nextToken();
    }

    int[] nextArray(int n) throws Exception{
        int[] a=new int[n];
        for (int i=0;i<n;i++)
            a[i]=nextInt();
        return a;
    }

    long[] nextLArray(int n) throws Exception{
        long[] a=new long[n];
        for (int i=0;i<n;i++)
            a[i]=nextLong();
        return a;
    }

    double[] nextDArray(int n) throws Exception{
        double[] a=new double[n];
        for (int i=0;i<n;i++)
            a[i]=nextDouble();
        return a;
    }

    String[] nextSArray(int n) throws Exception{
        String[] a=new String[n];
        for (int i=0;i<n;i++)
            a[i]=next();
        return a;
    }


}