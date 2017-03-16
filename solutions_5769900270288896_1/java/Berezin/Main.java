package codeJam2A;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.LinkedList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
	public static int valid(int i, int j, int r, int c) {
		int a = 0;
		if (i > 0) a++;
		if (j > 0) a++;
		if (i < r - 1) a++;
		if (j < c - 1) a++;
		return a;
	}
	public static void main(String[] args) throws FileNotFoundException {
		 InputReader in = new InputReader(new FileInputStream(new File("src/input.txt")));
		 PrintWriter out = new PrintWriter(new File("src/output.txt"));
		 int t = in.nextInt();
		 for (int tt = 0; tt < t; tt++) {
			 int r = in.nextInt();
			 int c = in.nextInt();
			 int n = in.nextInt();
			 int n1 = n; int n2 = n;
			 int a1[][] = new int[r][c];
			 int a2[][] = new int[r][c];
			 int f1[] = new int[5];
			 int f2[] = new int[5];
			 
			 for (int i = 0; i < r; i++) {
				 for (int j = 0; j < c; j++) {
					 if ((i + j) % 2 == 0) {
						 a1[i][j] = 1;
					 } else {
						 a2[i][j] = 1;
					 }
				 }
			 }
			 
			 for (int i = 0; i < r; i++) {
				 for (int j = 0; j < c; j++) {
					 if (a1[i][j] == 0) {
						 f1[valid(i,j,r,c)]++;
					 } else {
						 f1[0]++;
					 }
					 if (a2[i][j] == 0) {
						 f2[valid(i,j,r,c)]++;
					 } else {
						 f2[0]++;
					 }
				 }
			 }
			 
			 int ans1 = 0;
			 for (int q = 0; q < 5; q++) {
				 int x = Math.min(n1, f1[q]);
				 ans1 = ans1 + x * q;
				 n1 = n1 - x;
			 }
			 
			 int ans2 = 0;
			 for (int q = 0; q < 5; q++) {
				 int x = Math.min(n2, f2[q]);
				 ans2 = ans2 + x * q;
				 n2 = n2 - x;
			 }
			 int answer = Math.min(ans1, ans2);
			 
			 out.println("Case #" + (tt + 1) + ": " + answer);			 
		 }
		 out.close();
	}	
}

class InputReader {
	public BufferedReader reader;
	public StringTokenizer tokenizer;

	public InputReader(InputStream stream) {
		reader = new BufferedReader(new InputStreamReader(stream));
		tokenizer = null;
	}
	public String nextLine() throws IOException {
		return reader.readLine();
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
	
	public double nextDouble() {
		return Double.parseDouble(next());
	}
	
	public long nextLong() {
		return Long.parseLong(next());
	}

	public int nextInt() {
		return Integer.parseInt(next());
	}
}