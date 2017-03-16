package codeJam2;

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
	
	public static int getRev(int x) {
		String t = String.valueOf(x);
		StringBuilder y = new StringBuilder("");
		for (int i = t.length() - 1; i >= 0; i--) {
			y.append(t.charAt(i));
		}
		return Integer.valueOf(y.toString());
	}
	
	public static int check(int a[][], int r, int c) {
		int sum = 0; int i1 = 0; int j1 = 0;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				i1 = i + 1; j1 = j;
				if (i1 < r && a[i][j] + a[i1][j1] == 2) sum++;
				i1 = i; j1 = j + 1;
				if (j1 < c && a[i][j] + a[i1][j1] == 2) sum++;
			}
		}
		return sum;
	}
	
	public static int find(int i, int j, int n, int a[][], int r, int c) {
		if (n == 0) {
			return check(a, r, c);
		}
		if (j == c) {
			return find(i + 1, 0, n, a, r, c);
		}
		if (i == r) {
			return Integer.MAX_VALUE / 2;
		}
		// no
		int answer = find(i, j + 1, n, a, r, c);
		a[i][j] = 1; n--;
		answer = Math.min(answer, find(i, j + 1, n, a, r, c));
		a[i][j] = 0; n++;
		return answer;
	}
	
	public static void main(String[] args) throws FileNotFoundException {
		 InputReader in = new InputReader(new FileInputStream(new File("src/input.txt")));
		 PrintWriter out = new PrintWriter(new File("src/output.txt"));
		 int t = in.nextInt();
		 for (int j = 0; j < t; j++) {
			 int r = in.nextInt();
			 int c = in.nextInt();
			 int n = in.nextInt();
			 int a[][] = new int[r][c];
			 int answer = find(0, 0, n, a, r, c);
			 out.println("Case #" + (j + 1) + ": " + answer);			 
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