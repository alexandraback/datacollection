package r1;

import java.util.Scanner;

public class Q2 {
	public static void main(String... args) {
		@SuppressWarnings("resource")
		Scanner in = new Scanner(System.in);
		int caseCount = in.nextInt();
		int[] M = new int[1001]; // Minutes to process 1.
		for (int caseValue = 1; caseValue <= caseCount; caseValue++) {
			int result = 0;
			int B = in.nextInt(); // 1-1000
			int N = in.nextInt(); // 1-1e9
			double spdTotal = 0;
			int maxMinutes = 0;
			for (int i = 0; i < B; i++) {
				M[i] = in.nextInt();
				spdTotal += ((double) 1) / M[i];
				if (maxMinutes < M[i]) {
					maxMinutes = M[i];
				}
			}
			double minutesToTake = (N - 1) / spdTotal;
			// WAIT_MAX=(N-1)*100000 > INT_MAX
			long minuteGuess = Math.max(0, ((long) minutesToTake) - 1L - maxMinutes);
			long processed = 0;
			for (int i = 0; i < B; i++) {
				processed += minuteGuess / M[i] + 1;
				if (processed == N) {
					result = (i + 1);
					break;
				}
			}
			if (0 == result) {
				GotResult:
				for (long minute = minuteGuess + 1;; minute++) {
					for (int i = 0; i < B; i++) {
						if (minute % M[i] == 0) {
							processed++;
							if (processed == N) {
								result = (i + 1);
								break GotResult;
							}
						}
					}
				}
			}
			System.out.println("Case #" + caseValue + ": " + result);
		}
	}
}
