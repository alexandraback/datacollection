package com.google.codejam.ka.first;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class First {

	public static void main(String args[]) throws FileNotFoundException {
		parseInput(args[0]);
	}

	private static void parseInput(String arg) throws FileNotFoundException {
		Scanner scanner = new Scanner(new File(arg));
		int testCases = scanner.nextInt();
		for (int i = 0; i < testCases; i++) {
			int count = scanner.nextInt();
			int[] arr = new int[count];
			int a = scanner.nextInt();
			arr[0] = a;
			int first_method = 0;
			int max_diff = 0;
			for (int j = 1; j < count; j++) {
				int b = scanner.nextInt();
				arr[j] = b;
				if (b < a) {
					first_method += a-b;
				}
				if (a - b > max_diff) {
					max_diff = a - b;
				}
				a = b;
			}
			int second_method = count_second_method(arr, max_diff);
			printOutput(i + 1, first_method + " " + second_method);
		}
	}

	private static int count_second_method(int[] arr, int max_diff) {
		int sum = 0;
		for (int i1 = 0; i1 < arr.length-1; i1++) {
			int i = arr[i1];
				sum += Integer.min(i, max_diff);
		}
		return sum;
	}


	private static void printOutput(int i, String s) {
		System.out.println(String.format("Case #%d: %s", i, s));
	}
}
