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
import java.security.acl.LastOwnerException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.BitSet;
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

public class Jam2016_1C {
	//10^4 <  Short.MAX_VALUE (2^15)   < 10^5
	//10^9 <  Integer.MAX_VALUE (2^31) < 10^10
	//10^18 < Long.MAX_VALUE (2^63)    < 10^20

	//static String size = "sample";
	//static String size = "small";
	//static String size = "large"=
	// path: C:\Users\Lucas\workspace_tc\CodeJam\src\gcj\Jam2016_1C.java
	static String filename = "C:\\Users\\Lucas\\Downloads\\A-small-attempt0";

	static String outputfile = filename + ".out";
	static MyScanner scan;
	static PrintStream out;

	public static void main(String[] args) throws NumberFormatException, IOException {
		scan = new MyScanner(new FileInputStream(filename+".in"));
		out = new PrintStream(new BufferedOutputStream(new FileOutputStream(outputfile)));
		System.out.println(Calendar.getInstance().getTime()+" - Started writing to: "+outputfile);
		
		SenateEvacuation();

		System.out.println(Calendar.getInstance().getTime()+" - Finished writing to: "+outputfile);
		scan.close();
		out.close();
	}
	
	public static void testSenateEvacuation() {
		Random rand = new Random();
		for (int i = 0; i < 1000; i++) {
			for (int parties = 3; parties <= 26; parties++) {
				for (int total = 3; total <= 100; total++) {
					
				}
			}
		}
	}
	
	public static String SenateEvacuation(int n, int[] a) {
		int total = 0;
		for (int i = 0; i < a.length; i++) {
			total += a[i];
		}
		String out = "";
		
		while (total > 0) {
			int numP = 0;
			ArrayList<Integer> num = new ArrayList<>();
			for (int i = 0; i < a.length; i++) {
				if (a[i] > 0) {
					numP++;
					num.add(a[i]);
				}
			}
			boolean eq = true;
			for (int i = 1; i < num.size(); i++) {
				if (!num.get(0).equals(num.get(i))) {
					eq = false;
					break;
				}
			}
			
			if (numP == 2 && eq) {
				for (int i = 0; i < a.length; i++) {
					if (a[i] > 0) {
						out += (char)('A' + i);
						total--;
					}
				}
			} else {
				int max = 0;
				int maxN = 0;
				for (int i = 0; i < a.length; i++) {
					if (a[i] > max) {
						max = a[i];
						maxN = i;
					}
				}
				a[maxN]--;
				max--;
				total--;
				out += (char)('A' + maxN);
				
				if (max > total - max) {
					System.out.println("majority violation");
				}
			}
			out += " ";
		}
		return out;
	}

	public static void SenateEvacuation() {
		int tests = scan.nextInt();

		for (int test = 0; test < tests; test++) {
			int n = scan.nextInt();
			int[] a = scan.nextIntArray(n);
			out.println("Case #" +(test + 1) + ": " + SenateEvacuation(n, a));
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