package com.google.gcj;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class A2 {

	public static void main(String[] args) throws FileNotFoundException {

		Scanner sc = new Scanner(new File("A2-input.txt"));

		int T = sc.nextInt();

		for (int i = 1; i <= T; i++) {

			int B = sc.nextInt();
			long N = sc.nextLong();
			int[] m = new int[B];
			for (int j = 0; j < B; j++) {
				m[j] = sc.nextInt();
			}

			int res = solve(m, B, N);
			System.out.println("Case #" + i + ": " + res);

		}

		sc.close();
	}

	private static int solve(int[] m, int B, long N) {

		int max = 1;
		for (int i = 0; i < m.length; i++) {
			max *= m[i];
		}
		int sum = 0;
		for (int i = 0; i < m.length; i++) {
			sum += max / m[i];
		}

		int[] arr = new int[sum];
		int index = 0;
		for (int i = 0; i <= max && index < sum; i++) {
			for (int j = 0; j < m.length; j++) {
				if (i % m[j] == 0) {
					arr[index++] = j + 1;
					if (index >= sum)
						break;
				}
			}
		}

		int resIndex = (int) ((N - 1) % sum);

		return arr[resIndex];
	}

}
