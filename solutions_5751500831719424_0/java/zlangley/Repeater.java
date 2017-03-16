import java.util.*;

public class Repeater {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		int T = scan.nextInt();
		for (int cse = 1; cse <= T; cse++) {
			int N = scan.nextInt();
			String[] strs = new String[N];
			for (int i = 0; i < N; i++) {
				strs[i] = scan.next();
			}

			boolean possible = true;
			List<Character> charSet = stringToCharSet(strs[0]);
			for (int i = 1; i < N; i++) {
				List<Character> currentCharSet = stringToCharSet(strs[i]);
				if (!currentCharSet.equals(charSet)) {
					System.out.printf("Case #%d: Fegla won\n", cse);
					possible = false;
					break;
				}
			}
			if (!possible) {
				continue;
			}

			int cost = 0;
			int[] currentIndex = new int[N];
			for (Character c : charSet) {
				List<Integer> counts = new ArrayList<Integer>();
				for (int i = 0; i < N; i++) {
					String s = strs[i];
					int idx = currentIndex[i];

					int count = 1;
					for (int j = idx; j < s.length() - 1; j++) {
						if (s.charAt(idx) == s.charAt(idx + 1)) {
							count++;
							idx++;
						}
					}
					idx++;

					counts.add(count);

					currentIndex[i] = idx;
				}

				Collections.sort(counts);
				int mdn = counts.get(counts.size() / 2);

				for (int cnt : counts) {
					cost += Math.abs(cnt - mdn);
				}
			}

			System.out.printf("Case #%d: %d\n", cse, cost);
		}
	}

	public static List<Character> stringToCharSet(String s) {
		List<Character> l = new ArrayList<Character>();
		char last = '\0';
		for (char c : s.toCharArray()) {
			if (c != last) {
				l.add(c);
				last = c;
			}
		}
		return l;
	}
}
