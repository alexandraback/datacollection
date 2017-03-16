package Round1B;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class ProblemA {

	public static void main(String[] args) throws IOException {
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

		int T = Integer.parseInt(reader.readLine());
		for (int t=1; t <= T; t++) {
			int N = Integer.parseInt(reader.readLine());
			String[] strings = new String[N];
			for (int i=0; i < N; i++) {
				strings[i] = reader.readLine();
			}

			int c = strings[0].charAt(0), newC = c;
			int moves = 0;

			boolean allEqual = true;
			for (int i=0; i < N; i++) {
				if (strings[i].charAt(0) != c) {
					allEqual = false;
					break;
				}
			}
			if (allEqual) {
				int[] indexes = new int[N];
				int[] lengths = new int[N];
				for (int i=0; i < N; i++) {
					indexes[i] = 1;
					lengths[i] = strings[i].length();
				}
				boolean finished = false;
				while (!finished) {
					allEqual = true;
					int duplicate = 0;
					int different = 0;
					int diffC = -1;
					for (int j=0; j < N; j++) {
						int x = indexes[j] < lengths[j] ? strings[j].charAt(indexes[j]) : -1;
						if (x == c) {
							duplicate++;
						} else {
							if (different == 0) {
								diffC = x;
							} else {
								if (diffC != x) {
									allEqual = false;
									break;
								}
							}
							different++;
						}
					}
					if (!allEqual) {
						break;
					}
					if (different == 0 || duplicate == 0) {
						newC = indexes[0] < lengths[0] ? strings[0].charAt(indexes[0]) : -1;
						for (int j=0; j < N; j++) {
							indexes[j]++;
						}
					} else if (duplicate > different) {
						for (int j=0; j < N; j++) {
							int x = indexes[j] < lengths[j] ? strings[j].charAt(indexes[j]) : -1;
							if (x != c) {
								moves++;
							} else {
								indexes[j]++;
							}
						}
					} else {
						for (int j=0; j < N; j++) {
							int x = indexes[j] < lengths[j] ? strings[j].charAt(indexes[j]) : -1;
							if (x == c) {
								moves++;
								indexes[j]++;
							}
						}
					}
					c = newC;
					finished = true;
					for (int i=0; i < N; i++) {
						if (indexes[i] < lengths[i]) {
							finished = false;
							break;
						}
					}
				}
			}
			if (!allEqual) {
				System.out.println("Case #" + t + ": Fegla Won");
			} else {
				System.out.println("Case #" + t + ": " + moves);
			}
		}
	}
}
