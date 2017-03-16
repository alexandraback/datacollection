package gcj1;

import java.io.File;
import java.io.FileInputStream;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;

public class B {
	
	public static int completed = 0;
	int b;
	int n;
	int[] barbers;
	int[] sols;
	public B(int b, int n, int[] barbers) {
		this.b = b;
		this.n = n;
		this.barbers = barbers;
		this.sols = new int[125];
	}
	
	public int run() {
		int maxtime = Integer.MIN_VALUE;
		int mintime = Integer.MAX_VALUE;
		for (int i = 0; i < barbers.length; i++) {
			maxtime = Math.max(maxtime, barbers[i]);
			mintime = Math.min(mintime, barbers[i]);
		}
		int interval = lcm(barbers);
//		System.out.println(Arrays.toString(barbers));
//		System.out.println(interval);
		
		int numfinished = 0;

		for (int i = 0; i < barbers.length; i++) {
			numfinished += interval / barbers[i];
		}
		double minperfinish = interval / (double)numfinished;
		double timetofinish = n * minperfinish;
		int numintervals = (int)Math.floor(timetofinish / interval);
//		System.out.println("numfinished: " + numfinished);
		
		n = (n - (numintervals * numfinished));
		if (n == 0) {
			n += numfinished;
		}
		
//		System.out.println(n);
		
		int[] available = new int[b];
		Arrays.fill(available, 1);
		int res = -1;
		int[] todo = new int[b];
		outer: while (true) {
			int m = Integer.MAX_VALUE;
			for (int x : available) {
				m = Math.min(m, x);
			}
			for (int i = 0; i < available.length; i++) {
				available[i] -= m;
			}
			
			int fillcount = 0;
			for (int i = 0; i < available.length; i++) {
				if (available[i] == 0) {
					todo[fillcount] = i;
					fillcount++;
				}
			}
			for (int i = 0; i < fillcount; i++) {
					if (n == 1) {
						res = todo[i] + 1;
						break outer;
					} else {
						available[todo[i]] = barbers[todo[i]];
						n--;
						break;
					}
			}
		}
//		completed++;
//		System.out.println(completed);
//		System.out.println(res);
		return res;
	}
	
	public static int gcd(int... vals) {
		if (vals.length == 1) {
			return vals[0];
		}
		if (vals.length == 2) {
			if (vals[1] == 0) {
				return vals[0];
			} else {
				return gcd(vals[1], vals[0] % vals[1]);
			}
		}
		
		int ret = gcd(vals[0], vals[1]);
		for (int i = 2; i < vals.length; i++) {
			ret = gcd(ret, vals[i]);
		}
		return ret;
	}
	
	public static int lcm(int... vals) {
		if (vals.length == 1) {
			return vals[0];
		}
		if (vals.length == 2) {
			return vals[0] * vals[1] / gcd(vals[0], vals[1]);
		}
		int ret = lcm(vals[0], vals[1]);
		for (int i = 2; i < vals.length; i++) {
			ret = lcm(ret, vals[i]);
		}
		return ret;
	}

	public static void main(String[] args) throws Exception {
		Scanner s = new Scanner(new FileInputStream(new File("input_b.txt")));
		System.setOut(new PrintStream(new File("output_b.txt")));
		int numCases = s.nextInt();
		
		List<B> torun = new ArrayList<>();
		for (int c = 0; c < numCases; c++) {
			int b = s.nextInt();
			int n = s.nextInt();
			int[] barbers = new int[b];
			for (int i = 0; i < b; i++) {
				barbers[i] = s.nextInt();
			}
			
			torun.add(new B(b, n, barbers));
		}
		
		List<Integer> results = torun.stream().map(b -> b.run()).collect(Collectors.toList());
		for (int i = 0; i < results.size(); i++) {
			System.out.printf("Case #%d: %d%n", i+1, results.get(i));
		}
		
	}
}
