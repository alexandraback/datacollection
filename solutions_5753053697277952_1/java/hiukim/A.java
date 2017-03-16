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
        int sum = 0;
        int[] count = new int[N];
        for (int i = 0; i < N; i++) {
            count[i] = nextInt();
            sum += count[i];
        }

        while (sum > 0) {
            int maxIndex = 0;
            for (int i = 1; i < N; i++) {
                if (count[i] > count[maxIndex]) {
                    maxIndex = i;
                }
            }
            int countMax = 0;
            for (int i = 0; i < N; i++) {
                if (count[i] == count[maxIndex]) {
                    countMax++;
                }
            }

            if (countMax == 2) {
                int leave1 = maxIndex;
                int leave2 = -1;
                for (int i = 0; i < N; i++) {
                    if (count[i] == count[maxIndex] && i != leave1) {
                        leave2 = i;
                    }
                }

                count[leave1]--;
                count[leave2]--;
                sum-=2;

                out.print( (char)('A' + leave1));
                out.print( (char)('A' + leave2));
                out.print(" ");
            } else {
                count[maxIndex]--;
                sum--;

                out.print((char) ('A' + maxIndex));
                out.print(" ");
            }
        }

        /*
        while (sum > 1) {
            int maxIndex = 0;
            for (int i = 1; i < N; i++) {
                if (count[i] > count[maxIndex]) {
                    maxIndex = i;
                }
            }
            int leave1 = maxIndex;
            int leave2 = -1;
            for (int i = 0; i < N; i++) {
                if (i != maxIndex && count[i] > 0) {
                    leave2 = i;
                    break;
                }
            }

            count[leave1]--;
            count[leave2]--;
            sum -= 2;

            out.print( (char)('A' + leave1));
            out.print( (char)('A' + leave2));
            out.print(" ");
        }
        if (sum == 1) {
            for (int i = 0; i < N; i++) {
                if (count[i] > 0) {
                    out.print( (char)('A' + i) );
                    break;
                }
            }
        }
        */
        out.println();


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
