import java.awt.Point;
import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Currency;
import java.util.HashSet;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Stack;
import java.util.StringTokenizer;

/**
 * @author Jens Staahl
 */

public class barber_bs {

	// some local config
	// static boolean test = false ;
	private boolean test = System.getProperty("ONLINE_JUDGE") == null;
	static String testDataFile = "B-small-attempt1.in";
//	 static String testDataFile = "testdata.txt";
	private static String ENDL = "\n";
	// Just solves the acutal kattis-problem
	ZKattio io;
		
	int cnt = 0, max = 0;
	private void solve() throws Throwable {
		io = new ZKattio(stream);

		int n = io.getInt();
		for (int i = 0; i < n; i++) {
			solveIt(i+1);
			
		}
		out.flush();
	}

	private void solveIt(int casenr) {
		int ans = 0;
		int B = io.getInt();
		int n = io.getInt();
		int[] M = new int[B];
		for (int i = 0; i < B; i++) {
			M[i] = io.getInt();

		}
		
		long hi = 1000000000005L, lo = 0;
		while(hi - lo > 5 ) {
			long mid = (hi+lo)/2;
			long ret = cnt(M, mid);
			if(ret < n) {
				lo = mid;
			} else {
				hi = mid;
			}
		}
		if(cnt(M, 0) >= n) {
			ans = n;
		} else {
			
		out:for (long i = lo; ; i++) {
			long A = cnt(M,i);
			long C = cnt(M,i+1);
			if(A < n && C >= n) {
				long turn = i+1;
				long prev = cnt(M,i);
				long need = n - prev;
				for (int j = 0; j < B; j++) {
					if(turn % M[j] == 0) {
						need --;
					}
					if(need == 0) {
						ans = j + 1;
						break out;
					}
				}

			}
		}
		}
		
		print("Case #" + casenr + ": " + ans + "");
	}


	private long cnt(int[] M, long mid) {
			long ret = 0;
			for (int i = 0; i < M.length; i++) {
				ret += mid / M[i] + 1;
			}
		return ret;
	}

	private void print(String string) {
		out.println(string);
		System.out.println(string);
	}


	public static void main(String[] args) throws Throwable {
		new barber_bs().solve();
	}

	public barber_bs() throws Throwable {
		if (test) {
			stream = new FileInputStream(testDataFile);
		}
	}

	InputStream stream = System.in;
	PrintWriter out = new PrintWriter(new File(this.getClass().getCanonicalName() + ".out")); 

	public class ZKattio extends PrintWriter {
		public ZKattio(InputStream i) {
			super(new BufferedOutputStream(System.out));
			r = new BufferedReader(new InputStreamReader(i));
		}

		public ZKattio(InputStream i, OutputStream o) {
			super(new BufferedOutputStream(o));
			r = new BufferedReader(new InputStreamReader(i));
		}

		public boolean hasMoreTokens() {
			return peekToken() != null;
		}

		public int getInt() {
			return Integer.parseInt(nextToken());
		}

		public double getDouble() {
			return Double.parseDouble(nextToken());
		}

		public long getLong() {
			return Long.parseLong(nextToken());
		}

		public String getWord() {
			return nextToken();
		}

		private BufferedReader r;
		private String line;
		private StringTokenizer st;
		private String token;

		private String peekToken() {
			if (token == null)
				try {
					while (st == null || !st.hasMoreTokens()) {
						line = r.readLine();
						if (line == null)
							return null;
						st = new StringTokenizer(line);
					}
					token = st.nextToken();
				} catch (IOException e) {
				}
			return token;
		}

		private String nextToken() {
			String ans = peekToken();
			token = null;
			return ans;
		}
	}
	// System.out;

}