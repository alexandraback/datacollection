package assigment;

import java.util.ArrayList;
import java.util.List;

import codejam.war.TestCase;

public class ConcreteTestCase implements TestCase {
	List<String> words;
	List<String> bases;
	int[][] nums = new int[100][100];
	int nOfWords;
	
	public ConcreteTestCase(List<String> words, int nOfWords) {
		this.words = words;
		bases = new ArrayList<>();
		this.nOfWords = nOfWords;
	}

	@Override
	public String solve(int testCaseNo) {
		System.out.println("Case: " + testCaseNo);
		createBases();
		if (feglaWon()) {
			return String.format("Case #%s: Fegla Won", testCaseNo);
		} else {
			return String.format("Case #%s: %s", testCaseNo, solveThat());
		}
	}

	private int solveThat() {
		int i = 0;
		int nOfChains = 0;
		for (String word : words) {
			nOfChains = count(word, i++);
		}
		nOfChains++;
		int howMuch = 0;
		for(int chain = 0; chain < nOfChains; chain++) {
			howMuch += solveSingleShit(chain);
		}
		
		
		return howMuch;
	}

	private int solveSingleShit(int chain) {
		List<Integer> options = new ArrayList<>();
		for(int i = 0; i < nOfWords; i++) {
			int sum = 0;
			for(int j = 0; j < nOfWords; j++) {
				if(i != j) {
					sum += Math.abs(nums[i][chain] - nums[j][chain]);
				}
			}
			options.add(sum);
		}
		return findMin(options);
	}

	private int findMin(List<Integer> options) {
		int min = options.get(0);
		for(Integer i : options) {
			if(min > i) {
				min = i;
			}
		}
		return min;
	}

	private int count(String word, int i) {
		int nOfChars = 1;
		int k = 0;
		for (int j = 0; j < word.length() - 1; j++) {
			if (word.charAt(j) == word.charAt(j + 1)) {
				nOfChars++;
			} else {
				nums[i][k] = nOfChars;
				nOfChars = 1;
				k++;
			}
		}

		nums[i][k] = nOfChars;

		return k;
	}

	private boolean feglaWon() {
		String base = bases.get(0);
		for (String str : bases) {
			if (!str.equals(base)) {
				return true;
			}
		}
		return false;
	}

	private void createBases() {
		for (String word : words) {
			bases.add(createBase(word));
		}
	}

	private String createBase(String word) {
		Character letter = ' ';
		int n = word.length();
		for (int i = 0; i < n; i++) {
			if (word.charAt(i) == letter) {
				word = word.substring(0, i - 1) + word.substring(i, n);
				i--;
				n = word.length();
			}
			letter = word.charAt(i);
		}
		return word;
	}
}
