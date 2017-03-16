import java.io.*;
import java.math.BigInteger;
import java.util.*;


public class B {

    class Barber implements Comparable<Barber>{
        int time;

        @Override
        public int compareTo(Barber o) {
            if(time!=o.time)
            return time-o.time;
            return index-o.index;
        }

        int index;

        public Barber(int time, int index) {
            this.time = time;
            this.index = index;
        }
    }

    void solve() throws IOException {
        int t=nextInt();
        for(int testCase=0;testCase<t;testCase++){
            int b=nextInt();
            int n=nextInt();
            int[] a=new int[b];
            for(int i=0;i<b;i++)a[i]=nextInt();
            int ans;
            if(n<b){
                ans=n;
            }
            else{
                long l=0;
                long r=n*1l*a[0];
                while(l<r){
                    long m=l+(r-l)/2;
                    long count=0;
                    for(int i=0;i<b;i++){
//                        count+=m/a[i];
//                        if(m%a[i]==0)count++;
                        count+=m/a[i]+1;
                    }
                    if(count<n)
                        l=m+1;
                    else
                        r=m;
                }
                ans=-1;
                int count=0;
                for(int i=0;i<b;i++)count+=r/a[i]+1;
                if(count>=n){
                    for(int i=0;i<b;i++)if(r%a[i]==0)count--;
                }
                for(int i=0;i<b;i++)if(r%a[i]==0){
                    count++;
                    if(count==n) {
                        ans = i + 1;
                        break;
                    }
                }
            }
            out.printf("Case #%d: %d\n",testCase+1,ans);
        }
    }

    public static void main(String[] args) throws IOException {
        new B().run();
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
