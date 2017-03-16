import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class A {	
	BufferedReader reader;
    StringTokenizer tokenizer;
    PrintWriter out;
    
    public void task() throws IOException {
        int N = nextInt();
        int[] A = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = nextInt();
        }

        int ans1 = 0;
        for (int i = 1; i < N; i++) {
            if (A[i] < A[i-1]) {
                ans1 += (A[i-1] - A[i]);
            }
        }

        double rate = 0;
        for (int i = 1; i < N; i++) {
            if (A[i] < A[i-1]) {
                rate = Math.max(rate, (A[i-1] - A[i]) * 1.0 / 10);
            }
        }
//        out.println("rate: " + rate);
        int ans2 = 0;
        for (int i = 0; i < N-1; i++) {
            ans2 += Math.min(A[i], rate * 10);
        }

        out.println(ans1 + " " + ans2);

    }
        
	public void solve() throws IOException {
		int T = nextInt();
		for(int t = 1; t <= T; t++){
			out.print("Case #" + (t) + ": ");
			task();
		}
	}
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		new A().run();
	}
	
	public void run() {
        try {
            reader = new BufferedReader(new InputStreamReader(System.in));
            tokenizer = null;
            out = new PrintWriter(System.out);
            solve();
            reader.close();
            out.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

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
