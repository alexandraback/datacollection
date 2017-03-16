import java.io.*;
import java.math.BigInteger;
import java.util.*;


public class A {

    void solve() throws IOException {
        int t=nextInt();
        for(int testCase=0;testCase<t;testCase++){
            int n=nextInt();
            int[] a=new int[n];
            for(int i=0;i<n;i++)a[i]=nextInt();
            int maxDif=0;
            for(int i=1;i<n;i++)if(a[i-1]>a[i])maxDif=Math.max(maxDif,Math.abs(a[i]-a[i-1]));
            int y=0;
            int z=0;
            for(int i=1;i<n;i++){
                if(a[i]<a[i-1])y+=a[i-1]-a[i];
                z+=Math.min(maxDif,a[i-1]);
            }
            out.printf("Case #%d: %d %d\n",testCase+1,y,z);
        }
    }

    public static void main(String[] args) throws IOException {
        new A().run();
    }

    void run() throws IOException {
        reader = new BufferedReader(new InputStreamReader(System.in));
		reader = new BufferedReader(new FileReader("input.txt"));
        tokenizer = null;
        out = new PrintWriter(new OutputStreamWriter(System.out));
		out = new PrintWriter(new FileWriter("output.txt"));
        solve();
        reader.close();
        out.flush();

    }

    BufferedReader reader;
    StringTokenizer tokenizer;
    PrintWriter out;

    int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    String nextToken() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }
}
