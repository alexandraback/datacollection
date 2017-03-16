package R1B;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Locale;
import java.util.Scanner;

//
public class B {

	private static Scanner sc;
	private static PrintStream out;

	private static int sol(int a, int b, int N) {
		if ( N < 2 )
			return 0;

		if ( b == 1 ) {
			if ( N <= a / 2 )
				return 0;
			if ( N == a )
				return N - 1;
			return sol(a - 2, b, N - 1);
		}

		if ( b == 2 ) {
			if ( N <= a )
				return 0;
			if ( N == a + 1 )
				return 2;
			if ( N == a + 2 )
				return 4;
			int k = a + 2;
			return (N - k) * 3 + 4;
		}

		if ( b == 3 ) {
			if ( a == 3 ) {
				if ( N <= 5 )
					return 0;
				if ( N == 8 )
					return 8;
				return (N - 5) * 3;
			}
			if ( a == 4 ) {
				if ( N <= 6 )
					return 0;
				if ( N <= 8 )
					return 2 * (N - 6);
				if ( N <= 11 ) {
					return 3 * (N - 8) + 4;
				}
				return 17;
			}
			if ( a == 5 ) {
				if ( N <= 8 )
					return 0;
				if ( N == 12 )
					return 11;

				if ( N == 13 )
					return 14;
				if ( N <= 14 )
					return 3 * (N - 8);
				return 22;
			}

		}
		if ( a != 4 || b != 4 )
			System.out.println("fail");
		if ( N <= 8 )
			return 0;
		if ( N <= 10 )
			return 2 * (N - 8);
		if ( N <= 14 ) {
			return 3 * (N - 10) + 4;
		}
		return N == 15 ? 20 : 24;
	}

	private static void solve(int TC) {
		int R = ni();
		int C = ni();
		int N = ni();

		int a = Math.max(R, C);
		int b = Math.min(R, C);

		long ret = sol(a, b, N);
		out.println(String.format("Case #%d: %d", TC, ret));
	}

	public static void main(String[] args) throws FileNotFoundException {
		Locale.setDefault(Locale.ROOT);

		String file = "src/R1B/B.sm1";
		sc = new Scanner(new FileInputStream(file + ".in"));
		out = new PrintStream(file + ".out");

		int TC = ni();
		for (int i = 1; i <= TC; i++)
			solve(i);
	}

	private static int ni() {
		return sc.nextInt();
	}
}
