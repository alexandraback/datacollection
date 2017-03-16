import java.io.BufferedInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Repeater {
	private static final boolean DEBUG = false;
	private static final String FILENAME = "repeater";

	public static void main(String[] args) throws IOException {
		long startTime = System.nanoTime();

		if(DEBUG) {
			System.setIn(new BufferedInputStream(new FileInputStream(FILENAME + "_example.in")));
		} else {
			System.setIn(new BufferedInputStream(new FileInputStream(FILENAME + ".in")));
			System.setOut(new PrintStream(FILENAME + ".out"));
		}

		Scanner sc = new Scanner(System.in);

		int numTestCases = sc.nextInt();
		for(int caseNum = 1; caseNum <= numTestCases; caseNum++) {
			int numStrings = sc.nextInt();
			String[] words = new String[numStrings];
			for(int i = 0; i < words.length; i++) {
				words[i] = sc.next();
			}
			
			List<String> wordCopies = new ArrayList<String>();
			for(int i = 0; i < words.length; i++) {
				wordCopies.add(words[i]);
			}
			
			for(int i = 0; i < wordCopies.size(); i++) {
				String word = wordCopies.get(i);
				String newWord = "" + word.charAt(0);
				for(int j = 1; j < word.length(); j++) {
					if(word.charAt(j) != word.charAt(j - 1)) {
						newWord += word.charAt(j);
					}
				}
				wordCopies.set(i, newWord);
			}
			
			boolean feglaWon = false;
			for(int i = 1; i < wordCopies.size(); i++) {
				if(!wordCopies.get(i).equals(wordCopies.get(i - 1))) {
					feglaWon = true;
				}
			}
			
			if(feglaWon) {
				System.out.println("Case #" + caseNum + ": Fegla Won");
			} else {
				List<List<Integer>> wordsCharCounts = new ArrayList<List<Integer>>();

				for(int i = 0; i < words.length; i++) {
					List<Integer> consecutiveCharCounts = new ArrayList<Integer>();

					String word = words[i];
					int consecutiveCount = 1;
					for(int j = 1; j < word.length(); j++) {
						if(word.charAt(j) == word.charAt(j - 1)) {
							consecutiveCount++;
						} else {
							consecutiveCharCounts.add(consecutiveCount);
							consecutiveCount = 1;
						}
					}
					consecutiveCharCounts.add(consecutiveCount);

					wordsCharCounts.add(consecutiveCharCounts);
				}

				int totalCount = 0;
				for(int charIndex = 0; charIndex < wordsCharCounts.get(0).size(); charIndex++) {
					List<Integer> allWordsNthCharCount = new ArrayList<Integer>();
					for(int wordIndex = 0; wordIndex < wordsCharCounts.size(); wordIndex++) {
						allWordsNthCharCount.add(wordsCharCounts.get(wordIndex).get(charIndex));
					}

					int minNumChanges = Integer.MAX_VALUE;
					for(int i = 0; i < allWordsNthCharCount.size(); i++) {
						int numChangesNeeded = 0;
						for(int j = 0; j < allWordsNthCharCount.size(); j++) {
							if(i != j) {
								numChangesNeeded += Math.abs(allWordsNthCharCount.get(i) - allWordsNthCharCount.get(j));
							}
						}

						if(numChangesNeeded < minNumChanges) {
							minNumChanges = numChangesNeeded;
						}
					}

					totalCount += minNumChanges;
				}

				System.out.println("Case #" + caseNum + ": " + totalCount);
			}
		}

		if(DEBUG) System.out.println("Total time: " + ((System.nanoTime() - startTime) / 1000.0 / 1000.0 / 1000.0) + "s");
	}
}