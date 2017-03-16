package codejam2015.round1a;

import java.io.FileInputStream;
import java.io.PrintStream;
import java.util.Scanner;

public class Mushroom {
	Scanner cin;
	
	public void solveAll() {
		cin = new Scanner(System.in);
		int t = cin.nextInt();
		for (int i = 1; i <= t; ++i) {
			System.out.printf("Case #%d: %s\n", i, solve());
		}
	}
	
	private String solve() {
		int n = cin.nextInt();
		int[] m = new int[n];
		
		for (int i = 0;i < n; ++i) {
			m[i] = cin.nextInt();
		}
		
		int a = 0;		
		int max = 0;
		for (int i = 1; i < n; ++i) {
			int d = m[i - 1] - m[i];
			if (d > 0) {
				a += d;				
			}
			if (d > max) {
				max = d;
			}
		}
		
		int b = 0;
		for (int i = 0; i < n - 1; ++i) {
			b += Math.min(m[i], max);
		}
				
		return String.format("%d %d", a, b);
	}

	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream("A-large.in"));
		System.setOut(new PrintStream("A-large.out"));
		new Mushroom().solveAll();
	}
}
