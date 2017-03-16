import java.io.File;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


public class TheRepeater {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception {
		Scanner s = new Scanner(new File("A-large.in"));

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

		// size check
		int size = strings2[0].size();
		for (int i=0; i<strings2.length; ++i) {
			if (strings2[i].size() != size) {
				return "Fegla Won";
			}
		}

		// count actions
		int[][] actions = new int[size/2][strings.length];

		for (int i=0;i<size; i+=2) {
			for (int j=0; j<strings.length; ++j) {
				Object c = strings2[j].get(i);
				int n = (Integer) strings2[j].get(i+1);
				for (int k=0; k<strings.length; ++k) {
					if (c == strings2[k].get(i)) {
						actions[i/2][j] += Math.abs(n - (Integer)(strings2[k].get(i+1)));
					} else {
						return "Fegla Won";
					}
				}
			}
		}

		int sum = 0;
		for (int i=0; i<size/2; ++i) {
			int min = Integer.MAX_VALUE;
			for (int j=0; j<strings.length; ++j) {
				if (min > actions[i][j]) {
					min = actions[i][j];
				}
			}
			sum += min;
		}

		return String.valueOf(sum);
	}

}
