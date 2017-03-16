import java.io.*;
import java.math.BigInteger;
import java.util.*;


public class A {

    void solve() throws IOException {
        int t=nextInt();
        for(int testCase=0;testCase<t;testCase++){
            int a=nextInt();
            HashSet<Integer> x=new HashSet<Integer>();
            HashSet<Integer> y=new HashSet<Integer>();
            for(int i=1;i<a;i++)for(int j=0;j<4;j++)nextInt();
            for(int i=0;i<4;i++)x.add(nextInt());
            for(int i=a;i<4;i++)for(int j=0;j<4;j++)nextInt();
            a=nextInt();
            for(int i=1;i<a;i++)for(int j=0;j<4;j++)nextInt();
            for(int i=0;i<4;i++)y.add(nextInt());
            for(int i=a;i<4;i++)for(int j=0;j<4;j++)nextInt();
            ArrayList<Integer> z=new ArrayList<Integer>();
            for(Integer q:x)
                if(y.contains(q))
                    z.add(q);
            out.printf("Case #%d: ",testCase+1);
            if(z.size()==1)
                out.println(z.get(0));
            if(z.size()==0)
                out.println("Volunteer cheated!");
            if(z.size()>1)
                out.println("Bad magician!");

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