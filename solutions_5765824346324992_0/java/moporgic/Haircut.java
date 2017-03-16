import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;

public class Haircut {
	static {

		try {
			String input = "B-small-attempt2.in";
			String output = input.substring(0, input.lastIndexOf('.')) + ".out";
			System.setIn(new FileInputStream(input));
			System.setOut(new PrintStream(new FileOutputStream(output), true));
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(0);
		}

	}

	public static void main(String[] args) {
		try (Scanner input = new Scanner(System.in)) {
			int T = input.nextInt();
			long M[] = new long[1001];
			long Mx[] = new long[1001];
			for (int t = 1; t <= T; t++) {
				int B = input.nextInt();
				long N = input.nextLong();
				long gcd = M[0] = input.nextInt();
				for (int i = 1; i < B; i++) {
					M[i] = input.nextInt();
					gcd = GCD(gcd, M[i]);
				}
				long lcm = gcd;
				for (int i = 0; i < B; i++)
					lcm *= (M[i] / gcd);
				long skip = 0;
				for (int i = 0; i < B; i++)
					skip += (lcm / M[i]);

				int index = 0;
				N %= skip;
				// System.out.println("skipped = " + skip + ", remain " + N);
				if (N == 0) {
					index = B;
					for (int i = B - 1; i >= 0; i--) {
						if (M[i] == 1) {
							index = i + 1;
							break;
						}
					}
				} else {
					Arrays.fill(Mx, 0);
					long passed = 0;
					while (N > 0) {

						// System.out.print(N+": ");
						// for (int i = 0; i < B; i++) {
						// System.out.print((Mx[i] - passed) + " ");
						// }

						long min = Long.MAX_VALUE;
						for (int i = 0; i < B; i++) {
							Mx[i] -= passed;
							if (Mx[i] == 0 && N > 0) {
								Mx[i] = M[i];
								// System.out.print(" [" + (i + 1) + "]");
								index = i;
								N--;
							}
							assert Mx[i] >= 0;
							min = Math.min(min, Mx[i]);
						}

						// System.out.println();

						passed = min;
					}
					index++;
				}

				System.out.printf("Case #%d: %d", t, index);
				System.out.println();
			}
		}
	}

	public static long GCD(long m, long n) {
		for (long x; (x = m % n) != 0; m = n, n = x)
			;
		return n;
		// return m % n == 0 ? n : gcd(n, m % n);
	}
}
