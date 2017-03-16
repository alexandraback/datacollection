import java.util.Locale;
import java.util.Scanner;

public class A {

	void solve(int icase) {
		int n = si();
		String[] ts = new String[n];
		for (int i = 0; i < n; i++) {
			ts[i] = ss();
		}

		int result = 0;
		printf("Case #%d: ", icase);

		while (true) {
			boolean allEmpty = true;
			for (String s : ts) {
				if (!s.isEmpty()) {
					allEmpty = false;
					break;
				}
			}

			if (allEmpty) {
				printf("%d\n", result);
				return;
			}

			if (ts[0].isEmpty()) {
				printf("Fegla Won\n");
				return;
			}

			char c = ts[0].charAt(0);
			int[] reps = new int[n];
			int min = 0;
			int max = 0;

			for (int i = 0; i < n; i++) {
				String s = ts[i];
				for (int k = 0; k < s.length(); k++) {
					if (s.charAt(k) == c) {
						reps[i]++;
					} else {
						break;
					}
				}

				if (reps[i] == 0) {
					printf("Fegla Won\n");
					return;
				}

				ts[i] = ts[i].substring(reps[i]);

				min = Math.min(min, reps[i]);
				max = Math.max(max, reps[i]);
			}

			int best = Integer.MAX_VALUE;
			for (int k = min; k <= max; k++) {
				int sum = 0;
				for (int i : reps) {
					sum += Math.abs(i - k);
				}
				best = Math.min(best, sum);
			}

			result += best;
		}
	}

	public static void main(String[] args) throws Exception {
		Locale.setDefault(Locale.US);
		new A().repSolve();
	}

	void repSolve() throws Exception {
		scanner = new Scanner(System.in);
		// scanner = new Scanner(new java.io.File(""));
		int ncase = si();
		sline();
		for (int icase = 1; icase <= ncase; icase++) {
			solve(icase);
			System.err.println("[[ " + icase + " ]]");
		}
	}

	Scanner scanner;

	int si() {
		return scanner.nextInt();
	}

	long sl() {
		return scanner.nextLong();
	}

	double sd() {
		return scanner.nextDouble();
	}

	String ss() {
		return scanner.next();
	}

	String sline() {
		return scanner.nextLine();
	}

	void printf(String format, Object... args) {
		System.out.printf(format, args);
	}

}
