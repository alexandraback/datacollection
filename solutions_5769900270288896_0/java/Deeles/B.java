package A;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;


public class B {
	
	private int[] f;
	private int[][] m;
	private int N;
	private int min = Integer.MAX_VALUE;
	
	private int solve(int R, int C, int N) {
		this.N = N;
		f = new int[R*C];
		m = new int[R][C];
		min = Integer.MAX_VALUE;
		generuj(0);
		return min;
	}


	private void generuj(int index) {
		if (index == f.length) {
			get();
			return;
		}
		for (int i = 0; i < 2; i++) {
			f[index] = i;
			generuj(index + 1);
		}
		
	}


	private void get() {
		int c = 0;
		int x = 0;
		for (int i = 0; i < f.length; i++) {
			m[i / m[0].length][i % m[0].length] = f[i];
			if (f[i] == 1) {
				x++;
			}
		}
		if (x != N) {
			return;
		}
		for (int i = 0; i < m.length - 1; i++) {
			for (int j = 0; j < m[0].length - 1; j++) {
				if (m[i][j] == 1 && m[i+1][j] == 1) {
					c++;
				}
				if (m[i][j] == 1 && m[i][j+1] == 1) {
					c++;
				}
			}
		}
		for (int i = 0; i < m.length - 1; i++) {
			if (m[i][m[0].length - 1] == 1 && m[i+1][m[0].length - 1] == 1) {
				c++;
			}
		}
		for (int i = 0; i < m[0].length - 1; i++) {
			if (m[m.length - 1][i] == 1 && m[m.length - 1][i + 1] == 1) {
				c++;
			}
		}
		if (c < min) {
			min = c;
		}
	}


	public static void main(String[] args) throws FileNotFoundException {
		B b = new B();
		Scanner s = new Scanner(new File("inB.in"));
		PrintWriter pw = new PrintWriter(new File("outB.out"));
		int c = s.nextInt();
		for (int i = 0; i < c; i++) {
			pw.println("Case #" + (i + 1) + ": " + b.solve(s.nextInt(), s.nextInt(), s.nextInt()));
		}
		pw.close();
	}

}
