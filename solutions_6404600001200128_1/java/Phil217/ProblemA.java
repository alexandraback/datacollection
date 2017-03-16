package Round1A;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Locale;
import java.util.Scanner;

public class ProblemA {

	public static void solve(Scanner sc) {
		int N = sc.nextInt();
		int[] m = new int[N];
		int maxDiff = 0;
		int eaten1 = 0;
		for (int i = 0; i < m.length; i++) {
			m[i] = sc.nextInt();
			if (i > 0) {
				maxDiff = Math.max(maxDiff, m[i - 1] - m[i]);
				if (m[i - 1] - m[i] > 0) {
					eaten1 += m[i - 1] - m[i];
				}
			}
		}
		int eaten2 = 0;
		for (int i = 0; i < m.length - 1; i++) {
			eaten2 += Math.min(maxDiff, m[i]);
		}
		System.out.println(eaten1 + " " + eaten2);
	}

	public static void main(String[] args) throws FileNotFoundException {
//		Scanner sc = new Scanner(new File("A-practice.in"));
//		 Scanner sc = new Scanner(new File("A-small-attempt0.in"));
		 Scanner sc = new Scanner(new File("A-large.in"));
		sc.useLocale(Locale.US);
		int cases = sc.nextInt();

		for (int i = 1; i <= cases; i++) {
			System.out.format(Locale.US, "Case #%d: ", i);
			solve(sc);
		}
		sc.close();
	}
}
