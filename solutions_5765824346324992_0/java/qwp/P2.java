package First;

import java.io.*;
import java.util.*;

public class P2 {
	public static final String filename = "B-small-attempt1";
	public static Scanner in;
	public static PrintStream out;

	public static void main(String[] args) throws Exception {
		in = new Scanner(new File(filename + ".in"));
		out = new PrintStream(new FileOutputStream(filename + ".out"));
		
		int num = Integer.parseInt(in.nextLine());
		for (int i = 1; i <= num; i++) {
			String line = in.nextLine();
			int m = Integer.parseInt(line.substring(0, line.indexOf(" ")));
			int n = Integer.parseInt(line.substring(line.indexOf(" ") + 1));
			String[] ss = in.nextLine().split(" ");
			int[] arr = new int[m];
			for (int j = 0; j < m; j++)
				arr[j] = Integer.parseInt(ss[j]);
			
			int res = solve(n, arr);
			print("Case #" + i + ": " + res);
		}
		in.close();
		out.close();
	}
	
	public static int solve(int n, int[] arr) {
		int count = n - arr.length;
		if (count < 0)
			return n;
		int[] a = new int[arr.length];
		int cm = 1; // common multiple
		for (int i = 0; i < arr.length; i++) {
			a[i] = arr[i];
			if (cm % a[i] != 0)
				cm *= a[i];
		}
		
		int x = 0;
		for (int i = 0; i < arr.length; i++)
			x += cm / a[i];
		
		count -= x * (count / x);
		if (count == 0)
			return arr.length;
		
		while (true) {
			int min = a[0];
			for (int i = 1; i < a.length; i++) {
				if (a[i] < min)
					min = a[i];
			}
			for (int i = 0; i < a.length; i++) {
				a[i] -= min;
				if (a[i] == 0) {
					a[i] = arr[i];
					count--;
					if (count == 0)
						return i + 1;
				}
			}
		}
	}
	
	public static void print(String s) {
		System.out.println(s);
		out.println(s);
	}
}
