package com.google.codejam.ka.second;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.SortedSet;
import java.util.TreeSet;

public class Second {

	public static void main(String args[]) throws FileNotFoundException {
		parseInput(args[0]);
	}

	private static class Barber implements Comparable<Barber> {
		int m;
		int idx;
		int time = 0;

		public Barber(int m, int idx) {
			this.m = m;
			this.idx = idx;
		}

		public void inc() {
			time += m;
		}

		@Override
		public int compareTo(Barber o) {
			if (time == o.time) {
				return idx - o.idx;
			} else {
				return time - o.time;
			}
		}

		@Override
		public String toString() {
			return "Barber{" +
					"m=" + m +
					", idx=" + idx +
					", time=" + time +
					'}';
		}
	}

	private static void parseInput(String arg) throws FileNotFoundException {
		Scanner scanner = new Scanner(new File(arg));
		int testCases = scanner.nextInt();
		for (int i = 0; i < testCases; i++) {
			int barbers = scanner.nextInt();
			long pos = scanner.nextInt();
			SortedSet<Barber> b = new TreeSet<Barber>();
			long[] l = new long[barbers];
			long max = 0;
			for (int j = 0; j < barbers; j++) {
				int m = scanner.nextInt();
				b.add(new Barber(m, j));
				l[j] = m;
				if (m > max) {
					max = m;
				}
			}
			long lcm = lcm(l);
			int sum_per_round = 0;
			for (int j = 0; j < barbers; j++) {
				sum_per_round += lcm/l[j];
			}
			pos = pos % sum_per_round + sum_per_round;
			if (pos != 0) {
				for (int j = 0; j < pos-1; j++) {
					Barber bar = b.first();
					b.remove(bar);
					bar.inc();
					b.add(bar);
				}
				int res = b.first().idx;
				printOutput(i+1, Integer.toString(res+1));
			} else {
				printOutput(i+1, Integer.toString(barbers));
			}
		}
	}

	private static long lcm(long a, long b)
	{
		return a * (b / gcd(a, b));
	}

	private static long lcm(long[] input)
	{
		long result = input[0];
		for(int i = 1; i < input.length; i++) result = lcm(result, input[i]);
		return result;
	}

	private static long gcd(long a, long b)
	{
		while (b > 0)
		{
			long temp = b;
			b = a % b; // % is remainder
			a = temp;
		}
		return a;
	}

	private static void printOutput(int i, String s) {
		System.out.println(String.format("Case #%d: %s", i, s));
	}
}
