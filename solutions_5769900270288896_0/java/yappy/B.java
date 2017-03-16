import java.util.Scanner;

public class B {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for (int no = 1; no <= T; no++) {
			int R = in.nextInt();
			int C = in.nextInt();
			int N = in.nextInt();

			int ans = 0xffffff;
			int rc = R * C;
			for (int b = 0; b < (1 << rc); b++) {
				if (Integer.bitCount(b) != N)
					continue;
				int val = 0;
				for (int y = 0; y < R; y++) {
					for (int x = 0; x < C - 1; x++) {
						int x1 = x;
						int y1 = y;
						int x2 = x + 1;
						int y2 = y;
						boolean b1 = (b & (1 << y1 * C + x1)) != 0;
						boolean b2 = (b & (1 << y2 * C + x2)) != 0;
						if (b1 && b2)
							val++;
					}
				}
				for (int x = 0; x < C; x++) {
					for (int y = 0; y < R - 1; y++) {
						int x1 = x;
						int y1 = y;
						int x2 = x;
						int y2 = y + 1;
						boolean b1 = (b & (1 << y1 * C + x1)) != 0;
						boolean b2 = (b & (1 << y2 * C + x2)) != 0;
						if (b1 && b2)
							val++;
					}
				}
				ans = Math.min(ans, val);
			}

			System.out.printf("Case #%d: %d%n", no, ans);
		}
	}
}
