package com.google.gcj;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class A1 {

	public static void main(String[] args) throws FileNotFoundException {

		Scanner sc = new Scanner(new File("A1-input.txt"));

		int T = sc.nextInt();

		for (int i = 1; i <= T; i++) {

			int N = sc.nextInt();
			int[] m = new int[N];
			for (int j = 0; j < N; j++) {
				m[j] = sc.nextInt();
			}

			int res1 = solve1(m);
			int res2 = solve2(m);
			System.out.println("Case #" + i + ": " + res1 + " " + res2);
		}

		sc.close();
	}

	private static int solve1(int[] m) {

		int res = 0;
		for (int i = 1; i < m.length; i++) {
			res += Math.max(m[i - 1] - m[i], 0);
		}

		return res;
	}

	private static int solve2(int[] m) {

		int speed = 0;

		for (int i = 1; i < m.length; i++) {
			speed = Math.max(speed, m[i - 1] - m[i]);
		}

		int res = 0;

		for (int i = 0; i < m.length - 1; i++) {
			int eat = Math.min(m[i], speed);
			res += eat;
		}

		return res;
	}

}
