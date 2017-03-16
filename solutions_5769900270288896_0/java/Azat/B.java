import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class B {

	static StringTokenizer st;
	static BufferedReader br;
	static PrintWriter pw;
	
	public static void main(String[] args) throws IOException{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		int tests = nextInt();
		for (int test = 1; test <= tests; test++) {
			pw.print("Case #"+test+": ");
			int n = nextInt();
			int m = nextInt();
			int t = nextInt();
			int ans = 1000000000;
			int[][]a = new int[n][m];
			for (int mask = 0; mask < (1 << n*m); mask++) {
				if (Integer.bitCount(mask)==t) {
					for (int i = 0; i < n; i++) {
						for (int j = 0; j < m; j++) {
							int q = i*m+j;
							if ((mask & (1 << q)) != 0)
								a[i][j] = 1;
							else
								a[i][j] = 0;
						}
					}
					int cur = 0;
					for (int i = 0; i < n; i++) {
						for (int j = 0; j < m; j++) {
							if (i < n-1 && a[i][j]==1 && a[i+1][j]==1)
								cur++;
							if (j < m-1 && a[i][j]==1 && a[i][j+1]==1)
								cur++;
						}
					}
					ans = Math.min(ans, cur);
				}
			}
			pw.println(ans);
		}
		pw.close();
	}

	private static int nextInt() throws IOException {
		return Integer.parseInt(next());
	}
	private static long nextLong() throws IOException {
		return Long.parseLong(next());
	}
	private static double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}

	private static String next() throws IOException{
		while (st==null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine());
		return st.nextToken();
	}

}
