import java.util.Arrays;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

public class TheRepeater {
	public int getMin(List<String> words) {
		Set<String> s = new HashSet<>();
		for (String word : words) {
			String w = "";
			for (char c : word.toCharArray()) {
				if (w.length() == 0 || w.charAt(w.length() - 1) != c) w += c;
			}
			s.add(w);
		}
		if (s.size() > 1) return -1;
		List<List<Integer>> cts = new LinkedList<>();
		for (String word : words) cts.add(getMap(word));
		int l = cts.get(0).size();
		int min = 0;
		for (int i = 0; i < l; i++) {
			int[] c = new int[cts.size()];
			int j = 0;
			for (List<Integer> ct : cts) c[j++] = ct.get(i);
			Arrays.sort(c);
			int ct = c[cts.size() / 2];
			for (int cc : c) min += Math.abs(cc - ct);
		}
		return min;
	}
	private static List<Integer> getMap(String s) {
		List<Integer> l = new LinkedList<>();
		char p = s.charAt(0);
		int ct = 1;
		for (int i = 1; i < s.length(); i++) {
			if (s.charAt(i) == p) ct++;
			else {
				l.add(ct);
				ct = 1;
				p = s.charAt(i);
			}
		}
		l.add(ct);
		return l;
	}
	public static void main(String[] args) {
		try (final Scanner in = new Scanner(System.in)) {
			final int t = Integer.parseInt(in.nextLine());
			for (int i = 1; i <= t; i++) {
				int n = Integer.parseInt(in.nextLine());
				List<String> words = new LinkedList<>();
				for (int j = 0; j < n; j++) {
					words.add(in.nextLine());
				}
				int ret = new TheRepeater().getMin(words);
				System.out.printf("Case #%s: %s%n", i, ret >= 0 ? ret : "Fegla Won");
			}
		}
	}
}
