import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class B {	
	BufferedReader reader;
    StringTokenizer tokenizer;
    PrintWriter out;
    
    public void task() throws IOException {
        int B = nextInt();
        int N = nextInt();
        long[] M = new long[B];
        for (int i = 0; i < B; i++) {
            M[i] = nextLong();
        }

        long l = 0;
        long r = 100000L * N;

        while (l < r) {
            long mid = (l + r) / 2;
            if (compute(M, mid) >= N) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

//        out.println("l: " + l + ", " + compute(M, l));

        int ans = -1;
        long cnt = compute(M, l);
        for (int i = B - 1; i >= 0; i--) {
            if (l % M[i] == 0) {
                if (cnt == N) {
                    ans = i;
                    break;
                }

                cnt--;
            }
        }

        out.println(ans + 1);
    }

    public long compute (long[] M, long time) {
        long cnt = 0;
        for (int i = 0; i < M.length; i++) {
            cnt += time / M[i] + 1;
        }
        return cnt;
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
		new B().run();
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
