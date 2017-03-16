import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

public class A {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt(); in.nextLine();
		for (int i = 0; i < T; i++) {
			int N = in.nextInt(); in.nextLine();
			List<String> strings = new LinkedList<String>();
			for (int j = 0; j < N; j++) {
				strings.add(in.nextLine());
			}
			System.out.println("Case #" + (i + 1) + ": " + solve(strings));
		}
		in.close();
	}

	private static String solve(List<String> strings) {
		if (impossible(strings))
			return "Fegla Won";
		
		int result = 0;
		
		while (strings.get(0).length() > 0) {
			List<Integer> prefixLengths = new LinkedList<Integer>();
			List<String> newStrings = new LinkedList<String>();
			for (String s : strings) {
				int ps = prefixLength(s);
				prefixLengths.add(ps);
				newStrings.add(s.substring(ps));
			}
			result += movesToEqualisePrefixes(prefixLengths);
			strings = newStrings;
		}
		
		return "" + result;
	}

	private static int movesToEqualisePrefixes(List<Integer> prefixLengths) {
		Collections.sort(prefixLengths);
		int min = Integer.MAX_VALUE;
		for (int i = prefixLengths.get(0); i <= prefixLengths.get(prefixLengths.size() - 1); i++) {
			int partial = 0;
			for (int pl : prefixLengths) {
				partial += Math.abs(i - pl);
			}
			if (partial < min) {
				min = partial;
			}
		}
		return min;
	}

	private static int prefixLength(String s) {
		char c = s.charAt(0);
		int result = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) == c) {
				result++;
			} else {
				break;
			}
		}
		return result;
	}

	private static boolean impossible(List<String> strings) {
		String trimmed = trim(strings.get(0));		
		for (int i = 1; i < strings.size(); i++) {
			String s = strings.get(i);
			if (!trimmed.equals(trim(s))) {
				return true;
			}
		}
		return false;
	}

	private static String trim(String s) {
		String result = "" + s.charAt(0);
		char lastChar = s.charAt(0);
		for (int i = 1; i < s.length(); i++) {
			char c = s.charAt(i);
			if (c != lastChar) {
				lastChar = c;
				result += c;
			}
		}
		return result;
	}

}
