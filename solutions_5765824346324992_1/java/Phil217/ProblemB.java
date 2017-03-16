package Round1A;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Locale;
import java.util.Scanner;

public class ProblemB {

	public static void solve(Scanner sc) {
		int B = sc.nextInt();
		int N = sc.nextInt() - 1;
		int[] M = new int[B];
		int sum = 0;
		for (int i = 0; i < M.length; i++) {
			M[i] = sc.nextInt();
			sum += M[i];
		}
		if (N < B) {
			System.out.println(N + 1);
			return;
		}
		double strangeSum = 0;
		for (int i = 0; i < M.length; i++) {
			strangeSum += sum * 1.0 / M[i];
		}
		int[] tmp = new int[B];
		int tmpSum = 0;
		long[] endtimes = new long[B];
		long[] starttimes = new long[B];
		for (int i = 0; i < tmp.length; i++) {
			tmp[i] = (int) (1L * N * sum / M[i] / strangeSum);
			tmpSum += tmp[i];
			endtimes[i] = 1L * tmp[i] * M[i];
			starttimes[i] = endtimes[i] - M[i];
		}
		while (tmpSum < N) {
			int min = 0;
			for (int i = 1; i < endtimes.length; i++) {
				if (endtimes[i] < endtimes[min]) {
					min = i;
				}
			}
			endtimes[min] += M[min];
			starttimes[min] += M[min];
			tmp[min]++;
			tmpSum++;
		}
		// shift bad stuff
		boolean good = false;
		while (!good) {
			good = true;
			int latestStarted = 0;
			long latestTime = Math.max(starttimes[0],0);
			int earliestFinished = 0;
			for (int i = 1; i < endtimes.length; i++) {
				if (endtimes[i] < endtimes[earliestFinished]) {
					earliestFinished = i;
				}
				if (tmp[i] > 0 && starttimes[i] >= latestTime) {
					latestStarted = i;
					latestTime = starttimes[i];
				}
			}
			if (latestTime > endtimes[earliestFinished] || (latestTime == endtimes[earliestFinished] && latestStarted > earliestFinished)) {
				good = false;
				endtimes[latestStarted] -= M[latestStarted];
				starttimes[latestStarted] -= M[latestStarted];
				tmp[latestStarted]--;
				endtimes[earliestFinished] += M[earliestFinished];
				starttimes[earliestFinished] += M[earliestFinished];
				tmp[earliestFinished]++;
			}
		}

		int min = 0;
		for (int i = 1; i < endtimes.length; i++) {
			if (endtimes[i] < endtimes[min]) {
				min = i;
			}
		}
		System.out.println(min + 1);
	}

	public static void main(String[] args) throws FileNotFoundException {
		// Scanner sc = new Scanner(new File("B-practice.in"));
//		Scanner sc = new Scanner(new File("B-small-attempt4.in"));
		 Scanner sc = new Scanner(new File("B-large.in"));
		sc.useLocale(Locale.US);
		int cases = sc.nextInt();

		for (int i = 1; i <= cases; i++) {
			System.out.format(Locale.US, "Case #%d: ", i);
			solve(sc);
		}
		sc.close();
	}
}
