package haircut;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class Haircut {

	public static void main(String[] args) throws NumberFormatException,
			IOException {
		
		BufferedReader br = new BufferedReader(new FileReader(args[0]));

		int numCases = Integer.parseInt(br.readLine());

		for (int i = 0; i < numCases; i++) {
			solve(br, i + 1);
		}

	}

	private static void solve(BufferedReader br, int i) throws IOException {
		
		String[] BN = br.readLine().split(" ");
		
		String B = BN[0], N = BN[1];
		
		String[] bt = br.readLine().split(" ");
		
		int[] times = new int[Integer.parseInt(B)];
		
		for (int j = 0; j < Integer.parseInt(B); j++ ) {
			times[j] = Integer.parseInt(bt[j]);
		}
		
		int in = Integer.parseInt(N);
		
		int sum = 0;
		int lcm = LCM(times);
		for (int j = 0; j < times.length; j++) {
			sum += lcm / times[j]; 
		}
		
		in = in % sum;
		
		if (in == 0) in = sum;
		
		int lastBarber = -1;
		
		int[] barbers = new int[times.length];
		
		while (in > 0) {
			int currentShortest = 1000000000;
			for (int j = 0; j < Integer.parseInt(B); j++ ) {
				if (barbers[j] == 0) {
					in--;
					barbers[j] = times[j];
					lastBarber = j;
				}
				
				if (in == 0) break;
				
				currentShortest = currentShortest > barbers[j] ? barbers[j] : currentShortest;
				
			}
			if (in == 0) break;

			for (int k = 0; k < Integer.parseInt(B); k++) {
				barbers[k] -= currentShortest;
			}
		}
		
		System.out.println("Case #" + i + ": " + (lastBarber + 1));

		return;
	}
	
	public static int GCD(int a, int b) {
		return b == 0 ? a : GCD(b, a%b);
	}
	
	public static int GCD(int[] in) {
		return GCD(in, in.length);
	}
	
	public static int GCD(int[] in, int len) {
		if (len == 2) {
			return GCD(in[0], in[1]);
		} else {
			return GCD(in[len - 1], GCD(in, len - 1));
		}
	}
	
	public static int LCM(int a, int b) {
		return (a * b) / GCD(a, b);
	}
	
	public static int LCM(int[] in) {
		return LCM(in, in.length);
	}
	
	public static int LCM(int[] in, int len) {
		
		if (len == 2) {
			return LCM(in[0], in[1]);
		} else {
			return LCM(in[len - 1], LCM(in, len - 1));
		}
	}
}
