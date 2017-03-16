package Round1A2015;
import java.io.*;
import java.util.Arrays;
import java.util.Locale;
import java.util.Random;
import java.util.StringTokenizer;
import java.util.concurrent.Callable;
import java.util.concurrent.Future;
import java.util.concurrent.ScheduledThreadPoolExecutor;

public class A implements Runnable {

    private PrintWriter out;
    
    final String file = "/Users/sayghosh/code/GCJ/src/Round1A2015/A-large";
    Random rnd = new Random(42);

    static class InputData {

        int N;
        int[] M;
        int Y=0;
        int rate=0;
        int Z=0;
        
        InputData(FastReader in) throws IOException {
            N = in.nextInt();
            M = new int[N];
            for(int i=0;i<N;i++) {
                M[i] = in.nextInt();
                if(i>0 && M[i-1]>M[i]) {
                    Y=Y-M[i]+M[i-1];
                    if((M[i-1]-M[i])>rate)
                        rate = M[i-1]-M[i];
                }
            }
        }
        
        void solve(PrintWriter out) {
            System.out.println(rate);
            for(int i=0;i<N-1;i++) {
                Z+=M[i]>=rate?rate:M[i];
            }
            out.println(Y+" "+Z);
            
        }
        
    }
    
    static class Solver implements Callable<String> {

        InputData data;
        
        Solver(InputData data) {
            this.data = data;
        }

        @Override
        public String call() throws Exception {
            StringWriter out = new StringWriter();
            data.solve(new PrintWriter(out));
            return out.toString();
        }
        
    }

    public void run() {
        try {
            FastReader in = new FastReader(new BufferedReader(new FileReader(file + ".in")));
            out = new PrintWriter(file + ".out");
            
            ScheduledThreadPoolExecutor service = new ScheduledThreadPoolExecutor(7);
            
            int tests = in.nextInt();
            Future<String>[] ts = new Future[tests];
            System.out.println(tests);
            for (int test = 0; test < tests; ++test) {
                ts[test] = service.submit(new Solver(new InputData(in)));
            }
            for (int test = 0; test < tests; ++test) {
                while (!ts[test].isDone()) {
                    Thread.sleep(500);
                }
                System.err.println("Test " + test);
                out.print("Case #" + (test + 1) + ": ");
                out.print(ts[test].get());
            }
            service.shutdown();
            
            out.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    
    static class FastReader {
        public FastReader(BufferedReader in) {
            this.in = in;
            eat("");
        }
        
        private StringTokenizer st;
        private BufferedReader in;
        
        void eat(String s) {
            st = new StringTokenizer(s);
        }
        
        String next() throws IOException {
            while (!st.hasMoreTokens()) {
                String line = in.readLine();
                if (line == null) {
                    return null;
                }
                eat(line);
            }
            return st.nextToken();
        }
        
        int nextInt() throws IOException {
            return Integer.parseInt(next());
        }
        
        long nextLong() throws IOException {
            return Long.parseLong(next());
        }
        
        double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }
    }
    
    public static void main(String[] args) {
        Locale.setDefault(Locale.US);
        new A().run();
    }
    
}
