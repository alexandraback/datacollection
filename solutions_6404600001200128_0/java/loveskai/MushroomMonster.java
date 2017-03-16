package codejam.com.round1a;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.Scanner;

public class MushroomMonster {

	public int[] num(int N, int[] M) {
		
		int sum1 = 0;
		int max = 0;
		for (int i = 1; i < N; i++) {
			if (M[i] < M[i-1]) {
				sum1 += (M[i-1] - M[i]);
				if (M[i-1] - M[i] > max) {
					max = M[i-1] - M[i];
				}
			}
		}
		
		int sum2 = 0;
		for (int i = 0; i < N - 1; i++) {
			if (M[i] > max) {
				sum2 += max;
			} else {
				sum2 += M[i];
			}
		}
		
		return new int[]{sum1, sum2};
	}
	
	public static void main(String[] args) throws FileNotFoundException, UnsupportedEncodingException {
		Scanner in = new Scanner(new File("A-small-attempt0.in"));
		PrintWriter out = new PrintWriter(new File("A-small-attempt0.out"));
		int T = in.nextInt(); // number of test cases
		
		for (int i = 0; i < T; i++) {
			int N = in.nextInt();
			int[] M = new int[N];
			for (int j = 0; j < N; j++) {
				M[j] = in.nextInt();
			}
			MushroomMonster sol = new MushroomMonster();
			out.println("Case #" + (i+1) + ": " + sol.num(N, M)[0] + " "  + sol.num(N,M)[1]);
		}
		
		in.close();
		out.close();
	}

}
