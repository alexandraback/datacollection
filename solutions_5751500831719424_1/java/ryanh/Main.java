import java.io.BufferedReader;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

import com.google.common.base.Predicate;
import com.google.common.collect.Iterables;
import com.sun.istack.internal.Nullable;

/**
 * Requires Google Guava, available from http://code.google.com/p/guava-libraries/.
 */
public class Main {
	public static void main(String[] args) throws IOException {
		File output = new File("output");
		try (
				PrintWriter writer = new PrintWriter(new FileWriter(output));
				BufferedReader reader = new BufferedReader(
						new InputStreamReader(Main.class.getClassLoader().getResourceAsStream("sample")))) {

			String line = reader.readLine();
			int problems = Integer.parseInt(line);
			for (int problem = 0; problem < problems; problem++) {
				boolean possible = true;
				int numberOfStrings = Integer.parseInt(reader.readLine());
				ArrayList<String> list = new ArrayList<>(numberOfStrings);
				for (int i = 0; i < numberOfStrings; i++) {
					String string = reader.readLine();
					list.add(string);
				}
				int result = solve(list);
				String answer;
				if (result == -1) {
					answer = "Fegla Won";
				} else {
					answer = "" + result;
				}
				String outputLine = String.format("Case #%d: %s", problem + 1, answer);
				System.out.println(outputLine);
				writer.println(outputLine);
			}
		}
	}

	private static int solve(final List<String> list) {
		String string1 = list.get(0);

		Iterable<String> zeroLengthStrings = Iterables.filter(list, new Predicate<String>() {
			@Override
			public boolean apply(@Nullable final String s) {
				return s.length() == 0;
			}
		});
		int numberOfZeroLengthStrings = Iterables.size(zeroLengthStrings);
		if (numberOfZeroLengthStrings == list.size()) {
			return 0;
		} else if (numberOfZeroLengthStrings != 0 && numberOfZeroLengthStrings != list.size()) {
			return -1;
		} else {
			List<String> newStrings = new ArrayList<>();
			List<Integer> lengths = new ArrayList<>();
			char firstChar = string1.charAt(0);
			for (String string : list) {
				int numInString = 0;
				for (int i = 0; i < string.length(); i++) {
					if (string.charAt(i) == firstChar) {
						numInString++;
					} else {
						break;
					}
				}
				newStrings.add(string.substring(numInString));
				if (numInString == 0) {
					return -1;
				}
				lengths.add(numInString);
			}

			int result = solve(newStrings);
			if (result == -1) {
				return -1;
			}
			int minimumMoves = Integer.MAX_VALUE;
			// need to calculate the minimum. will attempt to brute force, hope that's fast enough
			for (int i = 0; i < lengths.size(); i++) {
				int moves = 0;
				for (int j = 0; j < lengths.size(); j++) {
					moves += Math.abs(lengths.get(i) - lengths.get(j));
				}
				minimumMoves = Math.min(minimumMoves, moves);
			}
			return minimumMoves + result;
		}

		//
		// 1, 2, 3 == 2
		// 1, 2, 4 == 3
		// 0, 10, 11 == 11
		// 0, 10, 11, 20 == 21
		// calculate min moves by length of strings

		//return 0;
	}
	private static int solve2(final ArrayList<String> list) {
		String baseline = list.get(0);
		List<Integer> lengths = new ArrayList<>();
		lengths.add(baseline.length());
		Stack<Character> baseLineInOrderCharacters = createStackOfChars(baseline);
		for (int i = 1; i < list.size(); i++) {
			lengths.add(list.get(i).length());
			Stack<Character> candidateInOrderCharacters = createStackOfChars(list.get(i));
			if (!baseLineInOrderCharacters.equals(candidateInOrderCharacters)) {
				return -1;
			}
		}
		return Math.abs(list.get(1).length() - list.get(0).length());
		//int minimumMoves = 0;
		//List<Integer> sortedLengths = Ordering.natural().sortedCopy(lengths);



		//
		// 1, 2, 3 == 2
		// 1, 2, 4 == 3
		// 0, 10, 11 == 11
		// 0, 10, 11, 20 == 21
		// calculate min moves by length of strings

		//return 0;
	}

	private static Stack<Character> createStackOfChars(final String baseline) {
		Stack<Character> inOrderCharacters = new Stack<>();
		for (Character character : baseline.toCharArray()) {
			if (inOrderCharacters.empty() || !inOrderCharacters.peek().equals(character)) {
				inOrderCharacters.push(character);
			}
		}
		return inOrderCharacters;
	}
}
