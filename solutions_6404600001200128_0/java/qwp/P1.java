package First;

import java.io.*;
import java.util.*;

public class P1 {
	public static final String filename = "A-small-attempt0";
	public static Scanner in;
	public static PrintStream out;

	public static void main(String[] args) throws Exception {
		in = new Scanner(new File(filename + ".in"));
		out = new PrintStream(new FileOutputStream(filename + ".out"));
		
		int num = Integer.parseInt(in.nextLine());
		for (int i = 1; i <= num; i++) {
			String line = in.nextLine();
			int n = Integer.parseInt(line);
			int[] arr = new int[n];
			String[] ss = in.nextLine().split(" ");
			for (int j = 0; j < n; j++) {
				arr[j] = Integer.parseInt(ss[j]);
			}
			int res1 = solve1(arr);
			int res2 = solve2(arr);
			print("Case #" + i + ": " + res1 + " " + res2);
		}
		in.close();
		out.close();
	}
	
	public static int solve1(int[] a) {
		int sum = 0;
		for (int i = 0; i < a.length - 1; i++) {
			if (a[i] > a[i + 1])
				sum += a[i] - a[i + 1];
		}
		return sum;
	}
	
	public static int solve2(int[] a) {
		int sum = 0;
		int rate = 0;
		for (int i = 0; i < a.length - 1; i++) {
			if (a[i] - a[i + 1] > rate)
				rate = a[i] - a[i + 1];
		}
		
		for (int i = 0; i < a.length - 1; i++) {
			if (a[i] >= rate) {
				sum += rate;
				a[i] -= rate;
			} else { // a[i] < rate
				sum += a[i];
				a[i] = 0;
			}
		}
		return sum;
	}
	
	public static void print(String s) {
		System.out.println(s);
		out.println(s);
	}
}
