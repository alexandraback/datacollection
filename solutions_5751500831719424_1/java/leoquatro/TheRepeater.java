import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class TheRepeater {

	private final Scanner scanner;
	private final String OUTPUT = "Case #%d: %s"; 
	
	public TheRepeater() {
		this.scanner = new Scanner(System.in);
	}
	
	public String solve() {
		int n = scanner.nextInt();
		List<Word> words = new ArrayList<>(n);
				
		for (int i = 0; i < n; i++) {
			String word = scanner.next();
			words.add(new Word(word));
		}
		
		if (!compareChars(words)) return "Fegla Won";
		
		int sum = 0;
		for (int i = 0; i < words.get(0).frequency.length; i++) {
			int[] frequencies = getFrequenciesOfChar(words, i);
			sum = sum + countChanges(frequencies);
		}
		
		return Integer.toString(sum);
	}
	
	private int countChanges(int[] frequencies) {
		int middle = frequencies.length / 2;
		int value = frequencies[middle];
		int sum = 0;
		for (int f : frequencies) {
			sum = sum + Math.abs(f - value);
		}
		return sum;		
	}
	
	private int[] getFrequenciesOfChar(List<Word> words, int pos) {
		int[] frequencies = new int[words.size()];
		int i = 0;
		
		for (Word w : words) {
			frequencies[i] = w.frequency[pos];
			i++;
		}
		
		Arrays.sort(frequencies);
		return frequencies;
	}
 	
	private boolean compareChars(List<Word> words) {
		if (words.isEmpty()) return false;
		
		char[] chars = words.get(0).chars;
		
		for (Word w : words) {
			if (!Arrays.equals(chars, w.chars)) {
				return false;
			}
		}
		
		return true;
	}
	
	public void run() {
		int instances = scanner.nextInt();
		scanner.nextLine();
		
		for (int i = 0; i < instances; i++) {
			String solution = this.solve();
			System.out.println(String.format(OUTPUT, i+1, solution));
		}
	}
	
	public static void main(String[] args) {
		(new TheRepeater()).run();
	}
	
	public static class Word {
		
		private final char[] chars;
		private final int[] frequency;
		
		public Word(String word) {
			this.chars = removeDuplicates(word);
			this.frequency = countFrequency(word, this.chars);
		}
		
		private static char[] removeDuplicates(String word) {
			char[] nonDup = new char[word.length()];
			char last = '*';
			int j = 0;
			
			for (int i = 0; i < word.length(); i++) {
				char current = word.charAt(i);
				
				if (current != last) {
					nonDup[j] = current;
					j++;
				}
				last = current;
			}
			
			return Arrays.copyOf(nonDup, j);
		}
		
		private static int[] countFrequency(String word, char[] chars) {
			if (word.length() == 0) return new int[0];
			
			int j = 0;
			int sum = 0;
			int[] count = new int[chars.length];
			
			for (int i = 0; i < word.length(); i++) {
				if (chars[j] == word.charAt(i)) continue;
				
				count[j] = i - sum;
				sum = i;
				j++;
			}
			
			count[count.length - 1] = word.length() - sum;
			return count;
		}
		
	}
	
}
