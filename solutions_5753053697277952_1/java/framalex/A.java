package gcj.c2016.r1c;


import java.util.*;
import java.io.*;
import java.lang.*;
import java.math.*;

public class A implements Runnable {

	public void run() {
		int tests = nextInt();
		for (int iter = 1; iter <= tests; ++iter) {
			int n = nextInt();
			String[] p = new String[2000];
			for (int i = 0; i < 2000; ++i) {
				p[i] = "";
			}
			for (int i = 0; i < n; ++i) {
				int num = nextInt();
				p[num] = p[num] + (char)(i + 'A');
			}

			String ans = "";
			for (int cnt = 1999; cnt > 0; --cnt) {
				while (p[cnt].length() > 0) {
					if (p[cnt].length() == 2) {
						ans += " " + p[cnt];
						p[cnt - 1] += p[cnt];
						p[cnt] = "";
					} else {
						ans += " " + p[cnt].charAt(0);
						p[cnt - 1] += p[cnt].charAt(0);
						p[cnt] = p[cnt].substring(1);
					}
				}
			}
			out.println("Case #"+iter + ":" +ans);
		}
		out.flush();
	}

	private static BufferedReader br = null;
	private static PrintWriter out = null;
	private static StringTokenizer stk = null;
	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new FileReader(new File("A.txt")));
		out = new PrintWriter("AA.txt");
		(new A()).run();
	}

	private void loadLine() {
		try {
			stk = new StringTokenizer(br.readLine());
		}
		catch (IOException e) {
			e.printStackTrace();
		}
	}

	private String nextLine() {
		try {
			return (br.readLine());
		}
		catch (IOException e) {
			e.printStackTrace();
		}
		return null;
	}

	private int nextInt() {
		while (stk == null || !stk.hasMoreElements()) loadLine();
		return Integer.parseInt(stk.nextToken());
	}

	private long nextLong() {
		while (stk == null || !stk.hasMoreElements()) loadLine();
		return Long.parseLong(stk.nextToken());
	}

	private double nextDouble() {
		while (stk == null || !stk.hasMoreElements()) loadLine();
		return Double.parseDouble(stk.nextToken());
	}

	private String nextWord() {
		while (stk == null || !stk.hasMoreElements()) loadLine();
		return (stk.nextToken());
	}
}
