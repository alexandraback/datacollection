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
    	HashSet<Integer> possible1 = new HashSet<Integer>();
    	HashSet<Integer> possible2 = new HashSet<Integer>();
    	int C1 = nextInt();
    	for (int i = 0; i < 4; i++) {
    		for (int j = 0; j < 4; j++) {
    			int N = nextInt();
    			if (i == C1 - 1) possible1.add(N);
    		}
    	}
    	int C2 = nextInt();
    	for (int i = 0; i < 4; i++) {
    		for (int j = 0; j < 4; j++) {
    			int N = nextInt();
    			if (i == C2 - 1) possible2.add(N);
    		}
    	}
    	possible1.retainAll(possible2);
    	if (possible1.size() == 1) {
    		for (int N: possible1) {
    			out.println(N);
    		}
    	} else if(possible1.size() == 0) {
    		out.println("Volunteer cheated!");
    	} else {
    		out.println("Bad magician!");
    	}
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
