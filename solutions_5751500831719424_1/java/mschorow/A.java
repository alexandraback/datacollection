import java.util.*;
import java.io.*;

public class A {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int t = s.nextInt();
		outer: for (int testCase = 1; testCase <= t; testCase++) {
			int result = 0;
			int n = s.nextInt();
			ArrayList<String> strings = new ArrayList<String>();
			for (int i = 0; i < n; i++) {
				strings.add(s.next());
			}
			ArrayList<ArrayList<LetterEncoding>> encodedStrings = new ArrayList<ArrayList<LetterEncoding>>();
			for (String str : strings) {
				encodedStrings.add(encode(str));
			}
			int testSize = encodedStrings.get(0).size();
			for (ArrayList<LetterEncoding> encodedString : encodedStrings) {
				if (encodedString.size() != testSize) {
					System.out
							.println("Case #" + testCase + ": " + "Fegla Won");
					continue outer;
				}
			}
			for (int i = 0; i < encodedStrings.get(0).size(); i++) {
				char c = encodedStrings.get(0).get(i).letter;
				int sum = 0;
				int count = 0;
				for (ArrayList<LetterEncoding> encodedString : encodedStrings) {
					char tempC = encodedString.get(i).letter;
					if (c != tempC) {
						System.out.println("Case #" + testCase + ": "
								+ "Fegla Won");
						continue outer;
					}
					sum += encodedString.get(i).length;
					count++;
				}
				int lengthToUse = (int) Math.round((sum + 0.0) / count);
				for (ArrayList<LetterEncoding> encodedString : encodedStrings) {
					result += Math.abs(encodedString.get(i).length
							- lengthToUse);
				}

			}
			System.out.println("Case #" + testCase + ": " + result);
		}
	}

	private static ArrayList<LetterEncoding> encode(String s) {
		ArrayList<LetterEncoding> result = new ArrayList<LetterEncoding>();
		if (s.length() == 0) {
			return result;
		}
		char curChar = s.charAt(0);
		LetterEncoding currentEncoding = new LetterEncoding();
		currentEncoding.length = 1;
		currentEncoding.letter = curChar;
		for (int i = 1; i < s.length(); i++) {
			char tempC = s.charAt(i);
			if (tempC == curChar) {
				currentEncoding.length++;
				continue;
			} else {
				result.add(currentEncoding);
				currentEncoding = new LetterEncoding();
				curChar = tempC;
				currentEncoding.length = 1;
				currentEncoding.letter = curChar;
			}
		}
		result.add(currentEncoding);
		return result;
	}

	static class LetterEncoding {
		char letter;
		int length;
	}

}
