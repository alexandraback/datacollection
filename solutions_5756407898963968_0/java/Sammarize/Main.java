import java.io.*;
import java.util.*;
import java.lang.reflect.*;


public class Main {

	static long CURRENT_TIME_NANO = System.nanoTime();

	public static void main(String[] args) throws Exception {

		int tests = next();

		for (int test = 1; test <= tests; test++) {
			int[] can = new int[16];
			for (int i = 0; i < 2; i++) {
				int x = next() - 1;
				for (int a = 0; a < 4; a++)
					for (int b = 0; b < 4; b++)
						if (a == x) can[next() - 1]++; else next();
			}
			int count = 0;
			int last = -1;
			for (int i = 0; i < 16; i++)
				if (can[i] == 2) {last = i + 1; count++;}

		   	if (count == 0) out.println("Case #" + test + ": Volunteer cheated!");
		   	else if (count == 1) out.println("Case #" + test + ": " + last);
		   	else out.println("Case #" + test + ": Bad magician!");
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