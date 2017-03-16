package gcj;

import java.awt.Point;
import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Calendar;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedHashMap;
import java.util.LinkedHashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Random;
import java.util.Scanner;
import java.util.Set;
import java.util.Stack;
import java.util.StringTokenizer;
import java.util.TreeSet;
import java.util.Iterator;

public class Jam2015A {
	//10^4 <  Short.MAX_VALUE (2^15)   < 10^5
	//10^9 <  Integer.MAX_VALUE (2^31) < 10^10
	//10^18 < Long.MAX_VALUE (2^63)    < 10^20

	//static String size = "sample";
	//static String size = "small-attempt0";
	//static String size = "large"=
	static String filename = "D:\\gcj\\2015\\A\\B-large";

	static String outputfile = filename + ".out";
	static MyScanner scan;
	static PrintStream out;

	public static void main(String[] args) throws NumberFormatException, IOException {
		scan = new MyScanner(new FileInputStream(filename+".in"));
		out = new PrintStream(new BufferedOutputStream(new FileOutputStream(outputfile)));
		System.out.println(Calendar.getInstance().getTime()+" - Started writing to: "+outputfile);
		
		haircut();

		System.out.println(Calendar.getInstance().getTime()+" - Finished writing to: "+outputfile);
		scan.close();
		out.close();
	}

	public static void haircut3() {
		int tests = scan.nextInt();
		for (int test = 0; test < tests; test++) {
			int b = scan.nextInt();
			int n = scan.nextInt();
			int[] minutes = scan.nextIntArray(b);
			int maxMinutes = 0;
			for (int i = 0; i < minutes.length; i++) {
				maxMinutes = Math.max(maxMinutes, minutes[i]);
			}
			
			HashMap<Integer, Integer> lookup = new HashMap<>();
			
			int c = 1;
			int time = 0;
			int ans = 0;
			while (ans == 0) {
				for (int i = 0; i < minutes.length; i++) {
					if (time % minutes[i] == 0 || time == 0) {
						if (c == n) {
							ans = i+1;
							break;
						}
						c++;
					}
				}
				time++;
			}
			
			out.println("Case #" + (test+1) + ": " + ans);
		}
	}


	public static void haircut() {
		int tests = scan.nextInt();
		for (int test = 0; test < tests; test++) {
			int b = scan.nextInt();
			int n = scan.nextInt();
			int[] minutes = scan.nextIntArray(b);
			int maxMinutes = 0;
			for (int i = 0; i < minutes.length; i++) {
				maxMinutes = Math.max(maxMinutes, minutes[i]);
			}
			
			long ans = 0;
			long high = 100000L * 1000000000L;
			long low = 0;
			long mid = (high + low) / 2;
			while (high >= low) {
				mid = (high + low) / 2;
				long prev = getCount(minutes, mid-1);
				for (int i = 0; i < minutes.length; i++) {
					if (mid % minutes[i] == 0 || mid == 0) {
						prev++;
						if (prev == n) {
							ans = i+1;
							break;
						}
					}
				}
				if (prev < n) {
					low = mid+1;
				} else {
					high = mid-1;
				}
			}
			
			out.println("Case #" + (test+1) + ": " + ans);
		}
	}


	public static long getCount(int[] minutes, long t) {
		long total = 0;
		if (t >= 0) {
			total += minutes.length;
			for (int i = 0; i < minutes.length; i++) {
				total += t / minutes[i];
			}
		}
		return total;
	}

	public static void haircut4() {
		int tests = scan.nextInt();
		for (int test = 0; test < tests; test++) {
			int b = scan.nextInt();
			int n = scan.nextInt();
			int[] minutes = scan.nextIntArray(b);
			int maxMinutes = 0;
			for (int i = 0; i < minutes.length; i++) {
				maxMinutes = Math.max(maxMinutes, minutes[i]);
			}
			
			HashMap<Integer, Integer> lookup = new HashMap<>();
			
			int c = 1;
			for (int time = 0; time < maxMinutes; time++) {
				for (int i = 0; i < minutes.length; i++) {
					if (time % minutes[i] == 0 || time == 0) {
						lookup.put(c, (i+1));
						c++;
					}
				}
			}
			
			c--;
			int a = n % c;
			if (a == 0) {
				a = c;
			}
			
			out.println("Case #" + (test+1) + ": " + lookup.get(a));
		}
	}

	public static void haircut2() {
		int tests = scan.nextInt();
		for (int test = 0; test < tests; test++) {
			int b = scan.nextInt();
			int n = scan.nextInt();
			int[] minutes = scan.nextIntArray(b);
			
			int c = b+1;
			int[] repeat = new int[b];
			int togo = b;
			int time = 1;
			while (togo > 0) {
				for (int i = 0; i < minutes.length; i++) {
					if (time % minutes[i] == 0) {
						if (repeat[i] == 0) {
							repeat[i] = c - (i + 1);
							togo--;
						}
						c++;
					}
				}
				time++;
			}
			
			for (int i = 0; i < repeat.length; i++) {
				//if ((n - (i+1)) % repeat[i])
			}
			
			out.println("Case #" + (test+1) + ": " + "");
		}
	}

	public static void mushroomMonster() {
		int tests = scan.nextInt();
		for (int test = 0; test < tests; test++) {
			int n = scan.nextInt();
			int[] m = scan.nextIntArray(n);
			
			long a1 = 0;
			for (int i = 1; i < m.length; i++) {
				if (m[i-1] > m[i]) {
					a1 += m[i-1] - m[i];
				}
			}
			
			long a2 = 0;
			double grad = 0;
			for (int i = 1; i < m.length; i++) {
				if (m[i-1] > m[i]) {
					grad = Math.max(grad, (m[i-1] - m[i]));
				}
			}
			for (int i = 0; i < m.length-1; i++) {
				a2 += Math.min(grad, m[i]);
			}
			out.println("Case #" + (test+1) + ": " + a1 + " " + a2);
		}
	}

	public static class MyScanner {
		BufferedReader br;
		StringTokenizer st;

		public MyScanner(InputStream in) {
			this.br = new BufferedReader(new InputStreamReader(in));
		}

		public void close() {
			try {
				this.br.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
		}

		String next() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		long[] nextLongArray(int n) {
			long[] a = new long[n];
			for (int i = 0; i < a.length; i++) {
				a[i] = this.nextLong();
			}
			return a;
		}

		int[] nextIntArray(int n) {
			int[] a = new int[n];
			for (int i = 0; i < a.length; i++) {
				a[i] = this.nextInt();
			}
			return a;
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}

		String nextLine(){
			String str = "";
			try {
				str = br.readLine();
			} catch (IOException e) {
				e.printStackTrace();
			}
			return str;
		}
	}

}