package gcj2015;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Haircut {
	static String PATH = "data/gcj2015/1a/", PROBLEM = "B", SIZE = "small",
			ATTEMPT = "1";

	/**
	 * Find the lowest index which have lowest time
	 * 
	 * @param currentMax
	 * @return
	 */
	static int findLowest(long[] currentMax) {
		long lowest = -1;
		int lowestB = -1;
		int b = 0;
		while (b < currentMax.length) {
			if (lowest == -1 || currentMax[b] < lowest) {
				lowest = currentMax[b];
				lowestB = b;
			}
			b++;
		}
		return lowestB;
	}

	static long commonDivisor(long n, long m) {
		while (n % m != 0) {
			long temp = n % m;
			n = m;
			m = temp;
		}
		return m;
	}

	static long commonMultiple(long n, long m) {
		return n * m / commonDivisor(n, m);
	}

	public static void main(String[] args) throws NumberFormatException,
			IOException {
		String filename = PATH + PROBLEM + "-" + SIZE;
		if (SIZE.equals("small"))
			filename += "-attempt" + ATTEMPT;
		Scanner sc = new Scanner(new File(filename + ".in"));
		BufferedWriter bw = new BufferedWriter(new FileWriter(PATH + PROBLEM
				+ "-" + SIZE + "-attempt" + ATTEMPT + ".out"));
		int T = sc.nextInt();
		sc.nextLine();
		for (int t = 0; t < T; t++) {
			System.out.println(t);
			int B = sc.nextInt();
			int N = sc.nextInt();
			int[] m = new int[B];
			long[] currentMax = new long[B];
			for (int b = 0; b < B; b++) {
				m[b] = sc.nextInt();
				currentMax[b] = 0;
			}

			int result = -1;
			// Check if common multiple helps
			if (B == 1) {
				result = 1;
			} else {
				long cm = commonMultiple(m[0], m[1]);
				for (int b = 2; b < B; b++) {
					cm = commonMultiple(cm, m[b]);
				}
				long cmpeople = 0;
				for (int b = 0; b < B; b++) {
					cmpeople += cm / m[b];
				}
				int p = 0;
				while (p + cmpeople < N - 1) {
					p += cmpeople;
				}
				while (p < N - 1) {
					// Find the current lowest available
					int l = findLowest(currentMax);
					currentMax[l] += m[l];
					p++;
				}
				result = findLowest(currentMax);
			}
			bw.write("Case #" + (t + 1) + ": " + (result + 1));
			bw.newLine();
		}
		sc.close();
		bw.close();
	}
}
