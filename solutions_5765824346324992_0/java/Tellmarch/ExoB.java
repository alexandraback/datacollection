package gcj2015.r1a;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

public class ExoB {
	private static int bs[];
	private static int N;

	public static void main(final String[] args) {

		final String base = "/home/jean/gcj2015/1a/ExoB/";
		final String input = base + "s5.in";
		final String output = base + "s5.out";

		try {
			final Scanner sc = new Scanner(new FileReader(input));
			final PrintWriter pw = new PrintWriter(output);

			final int n = sc.nextInt();
			sc.nextLine();
			for (int c = 0; c < n; c++) {
				System.out.println("Test case " + (c + 1) + "...");
				pw.print("Case #" + (c + 1) + ": ");
				test(sc, pw);
				pw.println();
			}
			pw.println();
			pw.flush();
			pw.close();
			sc.close();
		} catch (final FileNotFoundException ex) {
			Logger.getLogger(ExoB.class.getName()).log(Level.SEVERE, null, ex);
		}

	}

	private static void test(final Scanner sc, final PrintWriter pw) {
		final int B = sc.nextInt();
		N = sc.nextInt();
		bs = new int[B];
		for (int i = 0; i < bs.length; i++) {
			bs[i] = sc.nextInt();
		}
		long max = ((long) 100000) * ((long) N);
		if (sth(max) == -2) {
			System.out.println("uh " + max);
			sth(max);
			return;
		}
		pw.print(bs(0, max) + 1);

	}

	private static int bs(final long l, final long h) {
		// System.out.println(l + " " + h);
		if (l > h) {
			System.out.println(sth(l) + " " + sth(h));
		}
		long mid = l + (h - l) / 2;
		int a = sth(mid);
		if (a == -2) {
			return bs(mid + 1, h);
		} else if (a == -1) {
			return bs(l, mid);
		} else {
			return a;
		}
	}

	private static int sth(final long n) {
		long t = 0;
		if (n > 0) {
			for (int i = 0; i < bs.length; i++) {
				t += ((n - 1) / bs[i]) + 1;
			}
		}
		if (t >= N) {
			return -1;
		}
		for (int i = 0; i < bs.length; i++) {
			if (n % bs[i] == 0) {
				t++;
				if (t == N) {
					return i;
				}
			}
		}
		// System.out.println("***" + t + " " + N);
		return -2;
	}
}
