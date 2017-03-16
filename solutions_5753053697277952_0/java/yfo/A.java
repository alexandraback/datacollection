package y2016r1C;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.StringTokenizer;

public class A {
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer buffer;
	
	public static void solve() throws Exception {
		int T = ni();
		for (int t=0;t<T;t++) {
			int n = ni();
			int[]a = ni(n);
			
			List<String>res = new ArrayList<>();
			int left = 0;
			for (Integer x: a) left+=x;
			
			while (left>0) {
				int max = a[0], pos = 0;
				for (int i=0;i<n;i++) {
					if (a[i]>max) {
						max = a[i];
						pos = i;
					}
				}
				
				int pos2 = -1;
				for (int i=0;i<n;i++) {
					if (a[i] == max && i!=pos) {
						pos2 = i;
						break;
					}
				}
				
				String out = "";
				a[pos]--;
				left--;
				out += (char)('A'+pos);
				
				if (pos2!=-1 && left!=2) {
					a[pos2]--;
					left--;
					out+=(char)('A'+pos2);
				}
				res.add(out);
			}

			out.print("Case #" + (t+1) + ": ");
			for (String s: res) out.print(s + " ");
			out.println();
		}
	}

	public static void main(String[] args) throws IOException, Exception {
		in = new BufferedReader(new FileReader(new File("/tmp/a1.in")));
		out = new PrintWriter(new FileWriter(new File("/tmp/a1_out.in")));
		solve();
		out.close();
	}

	static String next() {
		while (buffer == null || !buffer.hasMoreElements()) {
			try {
				buffer = new StringTokenizer(in.readLine());
			} catch (IOException e) {
			}
		}
		return buffer.nextToken();
	}

	static int ni() {
		return Integer.parseInt(next());
	}

	static long nl() {
		return Long.parseLong(next());
	}

	static double nd() {
		return Double.parseDouble(next());
	}

	static String ns() {
		return next();
	}

	static int[] ni(int n) {
		int[] res = new int[n];
		for (int i = 0; i < n; i++)
			res[i] = Integer.parseInt(next());
		return res;
	}

	static long[] nl(int n) {
		long[] res = new long[n];
		for (int i = 0; i < n; i++)
			res[i] = Long.parseLong(next());
		return res;
	}

	static double[] nd(int n) {
		double[] res = new double[n];
		for (int i = 0; i < n; i++)
			res[i] = Double.parseDouble(next());
		return res;
	}

	static String[] ns(int n) {
		String[] res = new String[n];
		for (int i = 0; i < n; i++)
			res[i] = next();
		return res;
	}
}
