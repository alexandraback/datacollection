import java.util.*;
import java.io.*;
import java.math.*;

public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		try {
			inputStream = new FileInputStream("a.in");
			outputStream = new FileOutputStream("a.out");
		} catch (FileNotFoundException e) {
			System.err.println("File not found");
			return;
		}
		
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		int t = in.nextInt();
		for (int i = 0; i < t; i++) {
			out.format("Case #%d: ", i + 1);
			Solver solver = new Solver();
			solver.solve(in, out);
		}
		
		out.close();
	}
}

class Solver {
	private static final int MAXN = 101;
	private static final int INF = (int)1e9;
	int[][] nm;
	char[][]c ;
	int[] m;
	boolean eq(int i, int j) {
		if (m[i] != m[j])
			return false;
		for (int j2 = 0; j2 < m[i]; j2++) {
			if (c[i][j2] != c[j][j2])
				return false;
		}
		return true;
	}
	public void solve(InputReader in, PrintWriter out) {
		nm = new int[MAXN][MAXN];
		c = new char[MAXN][MAXN];
		m = new int[MAXN];
		int n = in.nextInt();
		
		for (int i = 0; i < n; i++) {
			String s = in.next();
			int cnt = 0;
			for (int j = 0; j < s.length(); j++) {
				if (j == 0 || s.charAt(j) != s.charAt(j - 1)) {
					nm[i][cnt] = 1;
					c[i][cnt] = s.charAt(j);
					cnt++;
				} else {
					nm[i][cnt - 1]++;
				}
			}
			m[i] = cnt;
		}
		
		for (int i = 1; i < n; i++) {
			if (!eq(0, i)) {
				out.println("Fegla Won");
				return;
			}
		}
		/*
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m[i]; j++) {
				System.err.format("%d ", nm[i][j]);
			}
			System.err.println();
		}*/
		int k = m[0];
		//System.err.println(k);
		int ans = 0;
		for (int i = 0; i < k; i++) {
			int best = INF;
			for (int j = 1; j < 101; j++) {
				int cur = 0;
				for (int j2 = 0; j2 < n; j2++) {
					cur += Math.abs(j - nm[j2][i]); 
				}
				//System.err.format("%d %d\n", j, cur);
				if (cur < best)
					best = cur;
			}
			//System.err.println(best);
			ans += best;
		}
		out.println(ans);
		
	}
}

class InputReader {
	private BufferedReader reader;
	private StringTokenizer tokenizer;

	public InputReader(InputStream stream) {
		reader = new BufferedReader(new InputStreamReader(stream));
		tokenizer = null;
	}

	public String next() {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			try {
				tokenizer = new StringTokenizer(reader.readLine());
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}
		return tokenizer.nextToken();
	}

	public long nextLong() {
		return Long.parseLong(next());
	}

	public int nextInt() {
		return Integer.parseInt(next());
	}

	public double nextDouble() {
		return Double.parseDouble(next());
	}
}
