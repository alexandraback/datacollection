package gcj1;

import java.io.File;
import java.io.FileInputStream;
import java.io.PrintStream;
import java.util.Scanner;

public class A {

	public static void main(String[] args) throws Exception {
		Scanner s = new Scanner(new FileInputStream(new File("input_a.txt")));
		System.setOut(new PrintStream(new File("output_a.txt")));
		int numCases = s.nextInt();
		for (int c = 0; c < numCases; c++) {
			int size = s.nextInt();
			int[] intervals = new int[size];
			for (int i = 0; i < size; i++) {
				intervals[i] = s.nextInt();
			}
			
			System.out.printf("Case #%d: %d %d%n", c+1, compute1(intervals), compute2(intervals));
		}
	}
	
	public static int compute1(int[] intervals) {
		int count = 0;
		for (int i = 1; i < intervals.length; i++) {
			int diff = intervals[i-1] - intervals[i];
			count += Math.max(0, diff);
		}
		return count;
	}
	
	public static int compute2(int[] intervals) {
		
		int rate = Integer.MIN_VALUE;
		for (int i = 1; i < intervals.length; i++) {
			rate = Math.max(intervals[i-1] - intervals[i], rate);
		}
		
		int count = 0;
		for (int i = 0; i < intervals.length - 1; i++) {
			count += Math.min(rate, intervals[i]);
		}
		
		return count;
	}
}
