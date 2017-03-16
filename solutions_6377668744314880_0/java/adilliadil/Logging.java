import java.util.Scanner;

public class Logging {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for (int t = 0; t < T; t++) {
			int N = in.nextInt();
			Point[] p = new Point[N];
			for (int i = 0; i < N; i++) {
				p[i] = new Point(in.nextInt(), in.nextInt());
			}
			// position = sign( (Bx-Ax)*(Y-Ay) - (By-Ay)*(X-Ax) )
			// p[j]->Bxy & p[i]->Axy & p[k]->XY
			System.out.println("Case #" + (t + 1) + ":");
			for (int i = 0; i < N; i++) {
				int min = N != 1 ? Integer.MAX_VALUE : 0;
				for (int j = 0; j < N; j++) {
					int right = 0;
					int left = 0;
					if (i != j) {
						for (int k = 0; k < N; k++) {
							int sign = (int) Math.signum((p[j].X - p[i].X)
									* (p[k].Y - p[i].Y) - (p[j].Y - p[i].Y)
									* (p[k].X - p[i].X));
							if (sign == 1)
								right++;
							else if (sign == -1)
								left++;
						}
						// System.out.println("l:" + left + " r:" + right);
						if (min > Math.min(right, left))
							min = Math.min(right, left);
					}

				}
				System.out.println(min);
			}

		}

	}

	public static class Point {
		long X;
		long Y;

		public Point(long x, long y) {
			this.X = x;
			this.Y = y;

		}
	}

}
