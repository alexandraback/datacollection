import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
public class A {
	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter pw;

	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new FileReader("a.in"));
		pw = new PrintWriter(new BufferedWriter(new FileWriter("a.out")));
		final int MAX_CASES = readInt();
		for(int casenum = 1; casenum <= MAX_CASES; casenum++)	{
			pw.printf("Case #%d: ", casenum);
			int firstRow = readInt();
			int[][] grid1 = new int[4][4];
			for(int i = 0; i < 4; i++) {
				for(int j = 0; j < 4; j++) {
					grid1[i][j] = readInt();
				}
			}
			int secondRow = readInt();
			int[][] grid2 = new int[4][4];
			for(int i = 0; i < 4; i++) {
				for(int j = 0; j < 4; j++) {
					grid2[i][j] = readInt();
				}
			}
			Set<Integer> set1 = new HashSet<Integer>();
			for(int out: grid1[firstRow-1]) {
				set1.add(out);
			}
			Set<Integer> set2 = new HashSet<Integer>();
			for(int out: grid2[secondRow-1]) {
				set2.add(out);
			}
			Set<Integer> ret = new HashSet<Integer>();
			for(int out: set1) {
				if(set2.contains(out)) {
					ret.add(out);
				}
			}
			if(ret.size() == 0) {
				pw.println("Volunteer cheated!");
			}
			else if(ret.size() > 1) {
				pw.println("Bad magician!");
			}
			else {
				for(int out: ret) {
					pw.println(out);
				}
			}
		}
		pw.close();
	}

	public static int readInt() throws IOException	{
		return Integer.parseInt(nextToken());
	}

	public static long readLong() throws IOException	{
		return Long.parseLong(nextToken());
	}

	public static double readDouble() throws IOException	{
		return Double.parseDouble(nextToken());
	}

	public static String nextToken() throws IOException {
		while(st == null || !st.hasMoreTokens())	{
			if(!br.ready())	{
				pw.close();
				System.exit(0);
			}
			st = new StringTokenizer(br.readLine());
		}
		return st.nextToken();
	}

	public static String readLine() throws IOException	{
		st = null;
		return br.readLine();
	}

}
