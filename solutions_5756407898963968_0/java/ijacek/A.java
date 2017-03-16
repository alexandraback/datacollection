package R0;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Locale;
import java.util.Scanner;

// Magic Trick
public class A {

	private static Scanner sc;
	private static PrintStream out;

	private static void solve(int TC) {
		boolean[] ch = new boolean[17];
		int a = ni();
		for (int i = 1; i <= 4; i++) {
			for (int j = 1; j <= 4; j++) {
				int n = ni();
				if ( i == a )
					ch[n] = true;
			}
		}
		int b = ni();
		int val = 0;
		long ret = 0;
		for (int i = 1; i <= 4; i++) {
			for (int j = 1; j <= 4; j++) {
				int n = ni();
				if ( i == b && ch[n] ) {
					ret++;
					val = n;
				}
			}
		}

		String res = String.valueOf(val);
		if ( ret > 1 )
			res = "Bad magician!";
		else if ( ret == 0 )
			res = "Volunteer cheated!";
		out.println(String.format("Case #%d: %s", TC, res));
	}

	public static void main(String[] args) throws FileNotFoundException {
		Locale.setDefault(Locale.ENGLISH);

		String file = "tst/R0/A.sm";
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
