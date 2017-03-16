package gcj_1B_A;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Repeater {
	
	static class WordSchema {
		
		public List<Character> letters;
		public List<Integer> numbers;
		
		public WordSchema() {
			letters = new ArrayList<Character>();
			numbers = new ArrayList<Integer>();
		}
		
		public WordSchema(String word) { 
			letters = new ArrayList<Character>();
			numbers = new ArrayList<Integer>();
			
			if (word.length() == 0) {
				return;
			}
			
			char lastChar = word.charAt(0);
			int num = 1;
			
			for (int i=1; i<word.length(); ++i) {
				if (word.charAt(i) == lastChar) {
					++num;
				} else {
					numbers.add(num);
					letters.add(lastChar);
					lastChar = word.charAt(i);
					num = 0;
				}
			}
			
			numbers.add(num);
			letters.add(lastChar);
		}
		
		boolean match(WordSchema w) {
			if (letters.size() != w.letters.size()) {
				return false;
			}
			for (int i=0; i<letters.size(); ++i) {
				if (letters.get(i) != w.letters.get(i)) {
					return false;
				}
			}
			return true;
		}
		
		
	}
	
	static int medianDistSum(List<WordSchema> m) {
		
		int L = m.get(0).letters.size();
		int M = m.size();
		int result = 0;
		
		for (int i=0; i<L; ++i) {
			int[] letterNums = new int[M];
			for (int j=0; j<M; ++j) {
				letterNums[j] = m.get(j).numbers.get(i);
			}
			result += medianDist(letterNums);
		}
		
		return result;
	}
	
	static int medianDist(int[] nums) {
		
		Arrays.sort(nums);
		int median = nums[nums.length/2];
		int result = 0;
		for (int n : nums){
			if (median > n) {
				result += median - n;
			} else {
				result += n - median;
			}
		}
		
		return result;
	}

	public static void main(String[] args) {
		
		Scanner scanner = null;
		
		try {
			scanner = new Scanner(new FileReader(args[0]));
		} catch (FileNotFoundException e) {
			System.err.println("file not found:" + args[0]);
		}
		
		int T = scanner.nextInt();
		
		for (int i=0; i<T; ++i) {
			int N = scanner.nextInt();
			List<WordSchema> wordSchemas = new ArrayList<WordSchema>();
			for (int j=0; j<N; ++j) {
				wordSchemas.add(new WordSchema(scanner.next()));
			}
			boolean winnable = true;
			for (int j=1; j<N; ++j) {
				if (!wordSchemas.get(0).match(wordSchemas.get(j))) {
					winnable = false;
				}
			}
			if (winnable) {
				int result = medianDistSum(wordSchemas);
				System.out.println("Case #" + (i+1) + ": " + result);
			} else {
				System.out.println("Case #" + (i+1) + ": Fegla Won");
			}
		}
	}

}
