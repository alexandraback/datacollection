package codejam.com.round1a;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.Scanner;

public class Haircut {
	
	public int num(int B, int N, int[] M) {
		// sanity check
		if (N <= B) {
			return N;
		}
		
		int time = 1;
		for (int i = 0; i < B; i++) {
			time *= M[i];
		}
		
		// how many people get cut?
		int cut = 0;
		for (int i = 0; i < B; i++) {
			cut += (time/M[i]);
		}
//		System.out.println(cut);
		
		N -= B;
		N %= cut;
		
		int[] M_left = new int[B];
		int minInd = 0;
		// first feed
		for (int i = 0; i < B; i++) {
			M_left[i] = M[i];
			if (M_left[i] < M_left[minInd]) {
				minInd = i;
			}
		}
		
		int target = M_left[minInd];
		int rst = B - 1;
		while (N > 0) {
			minInd = 0;
			for (int i = 0; i < B; i++) {
				M_left[i] -= target;
				if (M_left[i] == 0) {
					N--;
					M_left[i] = M[i];
					rst = i;
					if (N == 0) {
						return rst + 1;
					}
				}
				if (M_left[i] < M_left[minInd]) {
					minInd = i;
				}
			}
			target = M_left[minInd];
		}
		
		return rst + 1;
	}

	public static void main(String[] args) throws FileNotFoundException, UnsupportedEncodingException {
		Scanner in = new Scanner(new File("B-small-attempt1.in"));
		PrintWriter out = new PrintWriter(new File("B-small-attempt1.out"));
		int T = in.nextInt(); // number of test cases
		
		for (int i = 0; i < T; i++) {
			int B = in.nextInt();
			int N = in.nextInt();
			int[] M = new int[B];
			for (int j = 0; j < B; j++) {
				M[j] = in.nextInt();
			}
			Haircut sol = new Haircut();
			out.println("Case #" + (i+1) + ": " + sol.num(B, N, M));
		}
		
		in.close();
		out.close();
	}


}
