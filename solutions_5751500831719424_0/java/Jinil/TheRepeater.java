import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class TheRepeater {

	private static boolean isFinished(final ArrayList<String> words, final ArrayList<Integer> wordsPos) {
		for(int i=0; i<words.size(); i++) {
			int wordPos = wordsPos.get(i);
			if(wordPos != words.get(i).length()) {
				return false;
			}	
		}
		return true;
	}
	
	private static boolean isValidWords(final ArrayList<String> words, final ArrayList<Integer> wordsPos) {
		for(int i=0; i<words.size(); i++) {
			int wordPos = wordsPos.get(i);
			if(wordPos >= words.get(i).length()) {
				return false;
			}
		}
		return true;
	}
	
	private static int calculate(final ArrayList<String> words) {
		int result = 0;
		
		ArrayList<Integer> wordsPos = new ArrayList<Integer>();
		for(int i=0; i<words.size(); i++) { wordsPos.add(0); }
		
		while(true) {
			
			if (isFinished(words, wordsPos)) {
				break;
			} else if (!isValidWords(words, wordsPos)) { 
				return -1;
			}
			
			ArrayList<Integer> charSizes = new ArrayList<Integer>();
			char curChar = words.get(0).charAt(wordsPos.get(0));
			
			for(int i=0; i<words.size(); i++) {
				int charSize = 0;
				while(wordsPos.get(i) < words.get(i).length() 
						&& words.get(i).charAt(wordsPos.get(i)) == curChar) {
					
					charSize++;
					wordsPos.set(i, wordsPos.get(i) + 1);
				}
				charSizes.add(charSize);				
			}
			
			System.out.println(charSizes.toString());
			
			// check there are no 0
			for(int j=0; j<charSizes.size(); j++) {
				if(charSizes.get(j) == 0)
					return -1;
			}
			
			// compute
			int bestCount = Integer.MAX_VALUE;
			for(int j=0; j<charSizes.size(); j++) {
				int baseSize = charSizes.get(j);
				int curCount = 0;
				
				for(int k=0; k<charSizes.size(); k++) {
					int count = baseSize - charSizes.get(k);
					curCount += (count > 0 ? count : count * -1);
				}
				
				if(curCount < bestCount)
					bestCount = curCount;
				System.out.println("curCount: " + curCount + ", bestCount: " + bestCount + ", result: " + result);
			}
			result += bestCount;
		}
		
		return result;
	}
	
	public static void main(String args[]) throws IOException {
		if(args.length == 0) {
			System.out.println("No file. Exit this program");
			System.exit(1);
		}
		
		final BufferedReader br = new BufferedReader(new FileReader(args[0]));
		final BufferedWriter bw = new BufferedWriter(new FileWriter(args[0] + "_output.txt"));
		
		final int gamesCount = Integer.parseInt(br.readLine());
		
		for(int i=1; i<=gamesCount; i++) {
			final int N = Integer.parseInt(br.readLine());
			
			// get strings
			ArrayList<String> words = new ArrayList<String>();
			for(int j=0; j<N; j++) {
				words.add(br.readLine());
			}
			
			int result = calculate(words);
			
			String resultStr;
			if(result == -1) {
				resultStr = String.format("Case #%d: Fegla Won", i);
			} else {
				resultStr = String.format("Case #%d: %d", i, result);
			}
			bw.write(resultStr);
			bw.newLine();			
		}
		
		bw.close();
	}
}
