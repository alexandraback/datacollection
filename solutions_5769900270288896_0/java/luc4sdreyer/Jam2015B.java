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

public class Jam2015B {
	//10^4 <  Short.MAX_VALUE (2^15)   < 10^5
	//10^9 <  Integer.MAX_VALUE (2^31) < 10^10
	//10^18 < Long.MAX_VALUE (2^63)    < 10^20

	//static String size = "sample";
	//static String size = "small-attempt0";
	//static String size = "large"=
	//static String filename = "D:\\gcj\\2015\\B\\B-sample";
	static String filename = "D:\\gcj\\2015\\B\\B-small-attempt0";
	//static String filename = "D:\\gcj\\2015\\B\\A-small-attempt1";
	//static String filename = "D:\\gcj\\2015\\B\\A-large";

	static String outputfile = filename + ".out";
	static MyScanner scan;
	static PrintStream out;

	public static void main(String[] args) throws NumberFormatException, IOException {
		scan = new MyScanner(new FileInputStream(filename+".in"));
		out = new PrintStream(new BufferedOutputStream(new FileOutputStream(outputfile)));
		System.out.println(Calendar.getInstance().getTime()+" - Started writing to: "+outputfile);
		
		//counterCulture();
		noisyNeighbors();

		System.out.println(Calendar.getInstance().getTime()+" - Finished writing to: "+outputfile);
		scan.close();
		out.close();
	}

	public static void noisyNeighbors() {
		int tests = scan.nextInt();
		for (int test = 0; test < tests; test++) {
			int r = scan.nextInt();
			int c = scan.nextInt();
			int m = scan.nextInt();
			

			int N = 1 << (r*c);
			int min = Integer.MAX_VALUE;
			for (int n = 0; n < N; n++) {
				boolean[] active = new boolean[r*c];
				int num = 0;
				for (int i = 0; i < r*c; i++) {
					if (((1 << i) & n) != 0) {
						active[i] = true;
						num++;
					}
				}
				
				if (num == m) {
					boolean[][] map = new boolean[c][r];
					int temp = 0;
					for (int y = 0; y < c; y++) {
						for (int x = 0; x < r; x++) {
							if (active[temp++]) {
								map[y][x] = true;
							}
						}
					}

					int unhap = 0;
					for (int y = 0; y < c; y++) {
						for (int x = 0; x < r; x++) {
							if (y > 0 && map[y][x] && map[y-1][x]) {
								unhap++;
							}
							if (x > 0 && map[y][x] && map[y][x-1]) {
								unhap++;
							}
						}
					}
					
					min = Math.min(min, unhap);
				}
			}
			out.println("Case #" + (test+1) + ": " + min);
		}
	}

	public static void counterCulture() {
		int tests = scan.nextInt();
		for (int test = 0; test < tests; test++) {
			int n = scan.nextInt();
			
			int[] a = new int[n+1];
			Arrays.fill(a, Integer.MAX_VALUE);
			a[0] = 0;
			for (int i = 0; i < a.length-1; i++) {
				a[i+1] = Math.min(a[i] + 1, a[i+1]);
				String s = Integer.toString(i);
				String rev = "";
				for (int j = 0; j < s.length(); j++) {
					rev += s.charAt(s.length() - j - 1);
				}
				int r = Integer.parseInt(rev);
				if (r < a.length) {
					a[r] = Math.min(a[r], a[i] + 1);
				}
			}
			out.println("Case #" + (test+1) + ": " + a[a.length-1]);
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