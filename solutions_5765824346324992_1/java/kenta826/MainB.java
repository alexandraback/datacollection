package gcj.y2015.r1a;

import java.io.File;
import java.math.BigDecimal;
import java.util.Scanner;

public class MainB {

	static int t;
	static int count;

	static int[][] map;

	public static void main(String[] args) throws Exception {
		// 問題の読み込み
		Scanner sc = new Scanner(new File("src/in.txt"));

		int T = sc.nextInt();

		for (t=1; t<=T; t++) {

			int B = sc.nextInt();
			long N = sc.nextLong();

			long[] M = new long[B];

			for (int i=0; i<B; i++) {
				M[i] = sc.nextInt();
			}

			solve (N, B, M);
		}
	}

	static void solve (long N, int B, long[] M) {
		BigDecimal s = new BigDecimal(0);
		s = s.divide(new BigDecimal(2),20,BigDecimal.ROUND_HALF_UP);

		for (int i=0; i<B; i++) {
			BigDecimal a = new BigDecimal(1);
			BigDecimal b = new BigDecimal(M[i]);
			s = s.add(a.divide(b,20,BigDecimal.ROUND_HALF_UP));
		}

		BigDecimal n = new BigDecimal(N-B);

		BigDecimal tt = n.divide(s,0,BigDecimal.ROUND_DOWN);
		long time = tt.longValue();

		long NN = N;


		long[] R = new long[B];
		for (int i=0; i<B; i++) {
			NN -= time/M[i];
			R[i] = time%M[i];
			if (R[i] != 0) {
				NN = NN-1;
				R[i] = M[i] - R[i];
			}
		}

//		System.out.println("NN:" + NN);

		while (NN > 0) {
			// 空いているバーバーがいたら割り当てて順番来るか判定
			for (int i=0; i<B; i++) {
				if (R[i] == 0) {
					NN = NN-1;
					R[i] = M[i];
				}

				if (NN == 0) {
					output(t,i+1);
					return;
				}
			}

			// 空いているバーバーがいなくなったら、一番早く終わる人の時間に合わせて時間進める
			long min = R[0];
			for (int i=0; i<B; i++) {
				if (R[i] < min) {
					min = R[i];
				}
			}
			time = time + min;
			for (int i=0; i<B; i++) {
				R[i] = R[i]-min;
			}

		}

	}

	static class Vec {
		public int x;
		public int y;

		Vec(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}

	static void output(int i, Object ans) {
		System.out.println("Case #" + i + ": " + ans);
	}
}