import java.io.*;
import java.util.*;
import java.lang.reflect.*;


public class Main {

	static long CURRENT_TIME_NANO = System.nanoTime();

	public static void main(String[] args) throws Exception {

		int tests = next();


		for (int test = 1; test <= tests; test++) {
			int n = next();

			char[][] s = new char[n][];
			int[] start = new int[n];
			Arrays.fill(start, 0);

			for (int i = 0; i < n; i++) s[i] = nextline().toCharArray();

			int inf = 1000000000;
			int answ = 0;
			while (true) {
				int count = 0;
				for (int i = 0; i < n; i++) if (start[i] == s[i].length) count++;
				if (count > 0) {
					if (count != n) answ = inf;
					break;
				}

				char c = s[0][start[0]];
				count = 0;
				for (int i = 0; i < n; i++) if (c == s[i][start[i]]) count++;
				if (count != n) {
					answ = inf;
					break;
				}

				int[] kol = new int[n];
				for (int i = 0; i < n; i++) {
					while (start[i] < s[i].length && s[i][start[i]] == c) {
						kol[i]++;
						start[i]++;
					}
				}
				Arrays.sort(kol);

				int sum = 0;
				for (int i = 0; i < n; i++) sum += Math.abs(kol[i] - kol[n/2]);

				answ += sum;
			}
			
			if (answ< inf) out.println("Case #" + test + ": " + answ);
			else out.println("Case #" + test + ": " + "Fegla Won");
		}

		out.close();
	}
	
	static void printtime() {System.out.println((System.nanoTime() - CURRENT_TIME_NANO)*1e-9);}
	static void nexttime() {printtime(); CURRENT_TIME_NANO = System.nanoTime();}
	static PrintWriter out = new PrintWriter(System.out);
	
	static BufferedReader bufferedreader = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer in = new StringTokenizer("");

	static String nextToken() throws Exception {
		if (!in.hasMoreTokens()) in = new StringTokenizer(bufferedreader.readLine());
		return in.nextToken();
	}

	static int next()  throws Exception {return Integer.parseInt(nextToken());};
	static int[] next(int n) throws Exception {
		int[] x = new int[n];
		for (int i = 0; i < n; i++) x[i] = next();
		return x;
	}
	static int[][] next(int n, int m) throws Exception {
		int[][] x = new int[n][];
		for (int i = 0; i < n; i++) x[i] = next(m);
		return x;
	}

	static long nextl() throws Exception {return Long.parseLong(nextToken());};
	static long[] nextl(int n) throws Exception {
		long[] x = new long[n];
		for (int i = 0; i < n; i++) x[i] = nextl();
		return x;
	}
	static long[][] nextl(int n, int m) throws Exception {
		long[][] x = new long[n][];
		for (int i = 0; i < n; i++) x[i] = nextl(m);
		return x;
	}

	static double nextd() throws Exception {return Double.parseDouble(nextToken());};
	static double[] nextd(int n) throws Exception {
		double[] x = new double[n];
		for (int i = 0; i < n; i++) x[i] = nextd();
		return x;
	}
	static double[][] nextd(int n, int m) throws Exception {
		double[][] x = new double[n][];
		for (int i = 0; i < n; i++) x[i] = nextd(m);
		return x;
	}

	static String nextline() throws Exception {
		in = new StringTokenizer("");
		return bufferedreader.readLine();
	}

	static void sout(long x) {System.out.println(x);}
	static void sout(String s) {System.out.println(s);}
	static void sout(int[] x) {for (int xx : x) System.out.print(xx + " "); System.out.println();}
	static void sout(long[] x) {for (long xx : x) System.out.print(xx + " "); System.out.println();}
	static void sout(int[][] x) {for (int[] xx : x) sout(xx); System.out.println();}
	static void sout(long[][] x) {for (long[] xx : x) sout(xx); System.out.println();}


}