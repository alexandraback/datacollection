package gcj2014.round1B;

import java.io.BufferedReader;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class A {
	public static void main(String[] args) throws Exception {
		A main = new A("A_sample.txt");
		main.solve();
	}

	private final BufferedReader in;

	public A(String input) throws Exception {
		in = new BufferedReader(new FileReader(this.getClass().getResource(input).getFile()));
	}

	private void solve() throws Exception {
		int T = getInt();
		for (int c = 1; c <= T; c++) {
			int n = getInt();
			String[] s = new String[n];
			for (int i = 0; i < n; i++) {
				s[i] = in.readLine();
			}
			String ans = solveOne(s);
			System.out.println("Case #" + c + ": " + ans);
		}
	}

	private String solveOne(String[] str) {
		Set<String> splits = new HashSet<String>();
		List<List<Integer>> patterns = new ArrayList<List<Integer>>();
		for (String string : str) {
			String split = "";
			List<Integer> pattern = new ArrayList<Integer>();

			for (String chr : string.split("")) {
				if (split.equals("")) {
					split = chr;
					pattern.add(1);
				} else if (!chr.equals(split.substring(split.length() - 1))) {
					split = split + chr;
					pattern.add(1);
				} else {
					int loc = pattern.size() - 1;
					pattern.set(loc, pattern.get(loc) + 1);
				}
			}
			splits.add(split);
			patterns.add(pattern);
		}

		if (splits.size() != 1) {
			return "Fegla Won";
		}

		int sum = 0;
		int numpatt = patterns.size();

		for (int i = 0; i < patterns.get(0).size(); i++) {
			int min = Integer.MAX_VALUE;
			for (int j = 0; j < numpatt; j++) {
				int tmpSum = 0;
				for (int k = 0; k < numpatt; k++) {
					tmpSum += Math.abs(patterns.get(k).get(i) - patterns.get(j).get(i));
				}
				if (tmpSum < min) {
					min = tmpSum;
				}
			}
			sum += min;
		}

		return "" + sum;
	}

	/*
	 * File processing
	 */
	private int getInt() throws Exception {
		return Integer.valueOf(in.readLine()).intValue();
	}

}
