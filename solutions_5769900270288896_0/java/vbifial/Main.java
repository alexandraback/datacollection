import static java.lang.Math.*;
import static java.lang.System.currentTimeMillis;
import static java.lang.System.exit;
import static java.lang.System.arraycopy;
import static java.util.Arrays.sort;
import static java.util.Arrays.binarySearch;
import static java.util.Arrays.fill;

import java.util.*;
import java.io.*;

@SuppressWarnings("unused")
public class Main {
	public static void main(String[] args) throws IOException {
		new Main().run();		
	}

	BufferedReader in;
	PrintWriter out;
	StringTokenizer st = new StringTokenizer("");

	private void run() throws IOException {
//		if (new File("input.txt").exists())
//			in = new BufferedReader(new FileReader("input.txt"));
//		else
			in = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
//		out = new PrintWriter("output.txt");
		solve();
		in.close();
		out.close();
	}
	

	private void solve() throws IOException {
		
		
		int T = nextInt();
		
		
		for (int t = 0; t < T; t++) {
			
			int r = nextInt();
			int c = nextInt();
			int n = nextInt();
			
			int m = (1 << (r * c)); 
			
			int ans = r * c * 2;
			for (int mask = 0; mask < m; mask++) {
				if (Integer.bitCount(mask) == n) {
					int cans = 0;
					for (int i = 0; i < r; i++)
						for (int j = 0; j < c; j++) {
							if (((1 << (i * c + j)) & mask) != 0) {
								if (i < r - 1)
									if (((1 << ((i + 1) * c + j)) & mask) != 0)
										cans++;
								if (j < c - 1)
									if (((1 << ((i) * c + j + 1)) & mask) != 0)
										cans++;
							}
						}
					if (cans < ans)
						ans = cans;
				}
			}
			
			
			
			out.println("Case #" + (t + 1) + ": " + ans);
		}
		
		
	}
	
	void chk(boolean b) {
		if (b)
			return;
		System.out.println(new Error().getStackTrace()[1]);
		exit(999);
	}
	void deb(String fmt, Object... args) {
		System.out.printf(Locale.US, fmt + "%n", args);
	}
	String nextToken() throws IOException {
		while (!st.hasMoreTokens())
			st = new StringTokenizer(in.readLine());
		return st.nextToken();
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
	String nextLine() throws IOException {
		st = new StringTokenizer("");
		return in.readLine();
	}
	boolean EOF() throws IOException {
		while (!st.hasMoreTokens()) {
			String s = in.readLine();
			if (s == null)
				return true;
			st = new StringTokenizer(s);
		}
		return false;
	}
}
