package round1b;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.List;

public class Repeater {
	private BufferedReader cin;

	public Repeater() {
		cin = new BufferedReader(new InputStreamReader(System.in));
	}

	public void solve() throws Exception {
		int t = Integer.parseInt(cin.readLine());
		for (int i = 1; i <= t; ++i) {
			System.out.printf("Case #%d: %s\n", i, solveCase());
		}
	}

	private String solveCase() throws Exception {
		int n = Integer.parseInt(cin.readLine());
		List<List<Pair>> pairs = new ArrayList<>(n);
		for (int i = 0; i < n; ++i) {
			pairs.add(convert(cin.readLine()));
		}
		Collections.sort(pairs, new Comparator<List<Pair>>() {
			@Override
			public int compare(List<Pair> o1, List<Pair> o2) {
				return o2.size() - o1.size();
			}
		});
		List<Pair> first = pairs.get(0);
		int count = 0;
		for (int i = 0; i < first.size(); ++i) {
			int[] counts = new int[n];
			for (int j = 0; j < n; ++j) {
				List<Pair> l = pairs.get(j);
				if (l.size() <= i) {
					return "Fegla Won";
				}
				if (l.get(i).character != first.get(i).character) {
					return "Fegla Won";
				}
				counts[j] = l.get(i).count;
			}
			count += minOp(counts);
		}
		return String.valueOf(count);
	}

	private int minOp(int[] arr) {
		int min = Integer.MAX_VALUE;
		for (int i = 0; i < arr.length; ++i) {
			int count = 0;
			for (int j = 0; j < arr.length; ++j) {
				count += Math.abs(arr[j] - arr[i]);
			}
			min = Math.min(min, count);
		}
		return min;
	}

	private List<Pair> convert(String s) {
		List<Pair> result = new LinkedList<>();
		char prev = 0;
		char curr = 0;
		int count = 0;
		for (int i = 0; i < s.length(); ++i) {
			curr = s.charAt(i);
			if (curr != prev) {
				result.add(new Pair(prev, count));
				prev = curr;
				count = 1;
			} else {
				++count;
			}
		}
		result.add(new Pair(curr, count));
		return result;
	}

	/**
	 * @param args
	 * @throws Exception
	 */
	public static void main(String[] args) throws Exception {
		new Repeater().solve();
	}
}

class Pair {
	public Pair(char character, int count) {
		this.character = character;
		this.count = count;
	}

	public char character;
	public int count;
}
