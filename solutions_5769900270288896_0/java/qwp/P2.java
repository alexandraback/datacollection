package firstB;

import java.io.*;
import java.util.*;

public class P2 {
	public static final String filename = "B-small-attempt2";
	public static Scanner in;
	public static PrintStream out;

	public static void main(String[] args) throws Exception {
		in = new Scanner(new File(filename + ".in"));
		out = new PrintStream(new FileOutputStream(filename + ".out"));
		
		int num = Integer.parseInt(in.nextLine());
		for (int i = 1; i <= num; i++) {
			String[] input = in.nextLine().split(" ");
			int r = Integer.parseInt(input[0]);
			int c = Integer.parseInt(input[1]);
			int n = Integer.parseInt(input[2]);
			int res = solve(r, c, n);
			print("Case #" + i + ": " + res);
		}
		in.close();
		out.close();
	}
	
	public static int solve(int r, int c, int n) {
		boolean[][] apt = new boolean[r][c];  // initialize to false
		boolean flag = true;
		if (r * c < 2 * n) {
			for (int i = 0; i < r; i++) {
				for(int j = 0; j < c; j++) {
					apt[i][j] = true;
				}
			}
			n = r * c - n;
			flag = false;
		}
		
		return recur(n, 0, flag, apt, r * c);
	}
	
	public static int recur(int num, int offset, boolean flag, boolean[][] arr, int size) {
		if ((offset + num) > size)
			return 1000;
		if (num == 0)
			return score(arr);
//		if ((size - offset) == num) {
//			for (int i = offset; i < size; i++) {
//				arr[i / arr.length][i % arr.length] = flag;
//			}
//			int s = score(arr);
//			for (int i = offset; i < size; i++) {
//				arr[i / arr.length][i % arr.length] = !flag;
//			}
//			return s;
//		}
		
		int r1 = recur(num, offset + 1, flag, arr, size);
		arr[offset / arr[0].length][offset % arr[0].length] = flag;
		int r2 = recur(num - 1, offset + 1, flag, arr, size);
		arr[offset / arr[0].length][offset % arr[0].length] = !flag;
		return Math.min(r1,  r2);
	}
	
	public static int score(boolean[][] arr) {
		int score = 0;
		int r = arr.length;
		int c = arr[0].length;
		for (int i = 0; i < r; i++) {
			for(int j = 0; j < c; j++) {
				if (arr[i][j]) {
					if (i + 1 < r && arr[i+1][j])
						score++;
					if (j + 1 < c && arr[i][j+1])
						score++;
				}
			}
		}
		return score;
	}
	
	public static void print(String s) {
		System.out.println(s);
		out.println(s);
	}
}
