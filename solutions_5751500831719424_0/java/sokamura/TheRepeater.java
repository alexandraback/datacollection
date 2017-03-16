import java.io.File;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


public class TheRepeater {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception {
		Scanner s = new Scanner(new File("A-small.in"));

		int caseNum = s.nextInt();
		for (int t = 1; t <= caseNum; ++t) {
			int n = s.nextInt();
			s.nextLine();
			String[] strings = new String[n];
			for (int i=0; i<n; ++i) {
				strings[i] = s.nextLine();
			}

			System.out.println("Case #" + t + ": " + TheRepeater.solve(strings));
		}
	}

	public static String solve(String[] strings) {
		List[] strings2 = new ArrayList[strings.length];
		for (int i=0; i<strings.length; ++i) {
			strings2[i] = new ArrayList();
			char c = strings[i].charAt(0);
			int n = 1;
			for (int j=1; j<strings[i].length(); ++j) {
				if (c == strings[i].charAt(j)) {
					++n;
				} else {
					strings2[i].add(c);
					strings2[i].add(n);
					c = strings[i].charAt(j);
					n = 1;
				}
			}
			strings2[i].add(c);
			strings2[i].add(n);
		}

		int[][] actions = new int[strings.length][strings.length];

		for (int i=0;i<strings.length; ++i) {

			for (int j=i+1; j<strings.length; ++j) {
				if (strings2[i].size() != strings2[j].size()) {
					return "Fegla Won";
				}
				int num = 0;
				int k = 0;
				while (k < strings2[i].size()) {
					if (strings2[i].get(k) == strings2[j].get(k)) {
						k++;
						num += Math.abs(((Integer)(strings2[i].get(k)) - (Integer)(strings2[j].get(k))));
						k++;
					} else {
						return "Fegla Won";
					}
				}
				actions[i][j] = num;
			}
		}

		int min = Integer.MAX_VALUE;
		for (int i=0; i<strings.length; ++i) {
			int sum = 0;
			for (int j=0; j<strings.length; ++j) {
				if (i <= j) {
					sum += actions[i][j];
				} else {
					sum += actions[j][i];
				}
			}
			if (min > sum) {
				min =sum;
			}
		}

		return String.valueOf(min);
	}

}
