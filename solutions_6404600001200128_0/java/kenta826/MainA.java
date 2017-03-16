package gcj.y2015.r1a;

import java.io.File;
import java.util.Scanner;

public class MainA {

	static int t;
	static int count;

	static int[][] map;

	public static void main(String[] args) throws Exception {
		// 問題の読み込み
		Scanner sc = new Scanner(new File("src/in.txt"));

		int T = sc.nextInt();

		for (t=1; t<=T; t++) {

			int N = sc.nextInt();

			int[] m = new int[N];
			for (int i=0; i<N; i++) {
				m[i] = sc.nextInt();
			}

			solve(N, m);
		}
	}

	static void solve(int N, int[] m) {
		long ans1 = 0;
		long ans2 = 0;

		int[] d = new int[N-1];

		for (int i=0; i<N-1; i++) {
			d[i] = m[i+1]-m[i];
		}

		int min = 0;
		for (int i=0; i<N-1; i++) {
			// ans1の計算
			if (d[i] < 0) {
				ans1 -= d[i];
			}

			// ans2の計算
			if (d[i] < min) {
				min = d[i];
			}
		}

		min = -min;
		for (int i=0; i<N-1; i++) {
			// ans2の計算
			if (m[i] >= min) {
				ans2 += min;
			} else {
				ans2 += m[i];
			}
		}

		output(t, ans1, ans2);

	}

	static void output(int i, Object ans1, Object ans2) {
		System.out.println("Case #" + i + ": " + ans1 + " " + ans2);
	}
}