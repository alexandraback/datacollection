import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.List;


public class Round1BPA {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws NumberFormatException, IOException {
//		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedReader br = new BufferedReader(new FileReader("input.txt"));
		int numberOfTestCases = Integer.valueOf(br.readLine());
		cases: for(int testCase = 1; testCase <= numberOfTestCases; testCase++) {
			System.out.print("Case #" + testCase + ": ");
			int n = Integer.valueOf(br.readLine());
			ArrayList<String> words = new ArrayList<>();
			ArrayList<String> strippedWords = new ArrayList<String>();
			ArrayList<List<Integer>> wordsChars = new ArrayList<>();
			for(int wordNumber = 0; wordNumber < n; wordNumber++) {
				String word = br.readLine();
				words.add(word);
				strippedWords.add(stripWord(word));
				wordsChars.add(countWordsChars(word));
			}
//			System.out.println(wordsChars);
			String firstStripped = strippedWords.get(0);
			for(int wordNumber = 1; wordNumber < n; wordNumber++) {
				if(!strippedWords.get(wordNumber).equals(firstStripped)) {
					System.out.println("Fegla Won");
					continue cases;
				}
			}
//			Collections.sort(words, new Comparator<String>() {
//
//				@Override
//				public int compare(String s1, String s2) {
//					return s2.length() > s1.length() ? 1 : -1;
//				}
//			});
			int totalChanges = 0;
			int maxIndex = strippedWords.get(0).length();
			for(int charIndex = 0; charIndex < maxIndex; charIndex++) {
				int minChanges = Integer.MAX_VALUE;
				for(int baseIndex = 0; baseIndex < n; baseIndex++) {
					int base = wordsChars.get(baseIndex).get(charIndex);
					int totalNumbersChanges = 0;
					for(int wordNumber = 0; wordNumber < n; wordNumber++) {
						if(wordNumber == baseIndex)
							continue;
						int word = wordsChars.get(wordNumber).get(charIndex);
						totalNumbersChanges += Math.abs(word-base);
					}
					if(totalNumbersChanges < minChanges) {
						minChanges = totalNumbersChanges;
					}
	//				System.out.println(words);
				}
				totalChanges+= minChanges;
			}
			System.out.println(totalChanges);
		}

	}

	private static String stripWord(String word) {
		StringBuilder sb = new StringBuilder();
		Character previousChar = null;
		for(char c : word.toCharArray()) {
			if(previousChar == null || previousChar != c) {
				previousChar = c;
				sb.append(c);
			}
		}
		return sb.toString();
	}
	
	private static List<Integer> countWordsChars(String word) {
		StringBuilder sb = new StringBuilder();
		Character previousChar = null;
		int current = 0;
		List<Integer> wordsChars = new LinkedList<>();
		for(char c : word.toCharArray()) {
			if(previousChar == null || previousChar != c) {
				if(previousChar != null)
					wordsChars.add(current);
				previousChar = c;
				current = 1;
			} else {
				current++;
			}
		}
		wordsChars.add(current);
		return wordsChars;
	}

}
