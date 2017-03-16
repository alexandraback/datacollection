package round1B;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class TheRepeater {
	private static BufferedWriter writer;
	private static BufferedReader reader;

	public static void main(String[] args) throws IOException {
		File file = new File("round1B/A-small-attempt0.in");
		reader = new BufferedReader(new FileReader(file));
		
		File outputFile = new File("round1B/output-repeater.txt");
		writer = new BufferedWriter(new FileWriter(outputFile));
		
		int numberOfGames = Integer.parseInt(reader.readLine());
		for (int game = 1; game <= numberOfGames; game++) {
			int numberOfStrings = Integer.parseInt(reader.readLine());
			List<String> stringList = new ArrayList<>();
			
			for (int string = 0; string < numberOfStrings; string++) {
				stringList.add(reader.readLine());
			}
			List<Character> charList = makeCharList(stringList.get(0));
			boolean possible = true;
			for (int string = 0; string < numberOfStrings; string++) {
				if (!charList.equals(makeCharList(stringList.get(string)))) {
					possible = false;
				}
				
			}
			if (!possible) {
				generateOutput("Case #" + game + ": Fegla Won");
			}
			else {
				int repeats[][] = new int[charList.size()][stringList.size()];
				for (int string = 0; string < numberOfStrings; string++) {
					fillRepeats(repeats, string, stringList.get(string));
				}
				int moves = 0;
				for (int ch = 0; ch < charList.size(); ch++) {
					moves += countMovesForCharacter(repeats[ch]);
				}
				
				generateOutput("Case #" + game + ": " + moves);
			}
		}
		reader.close();
		writer.close();
	}

	private static void fillRepeats(int[][] repeats, int stringNumber, String string) {
		char[] charArray = string.toCharArray();
		int ch = 0;
		
		for (int c = 0; c < charArray.length; c++) {
			int repeatsOfChar = 0;
			while (c+1 < charArray.length && charArray[c+1] == charArray[c]) {
				repeatsOfChar++;
				c++;
			}
			repeats[ch][stringNumber] = repeatsOfChar;
			ch++;
		}
	}

	private static int countMovesForCharacter(int[] repeatsForChar) {
		int median = determineMedian(repeatsForChar);
		int moves = 0;
		for (int string = 0; string < repeatsForChar.length; string++) {
			moves += Math.abs(repeatsForChar[string] - median);
		}
		return moves;
	}

	private static int determineMedian(int[] repeatsForChar) {
		List<Integer> intList = new ArrayList<Integer>();
		for (int index = 0; index < repeatsForChar.length; index++) {
			intList.add(repeatsForChar[index]);
		}
		
		Collections.sort(intList);
		return intList.get(intList.size()/2);
	}

	private static List<Character> makeCharList(String string) {
		char[] charArray = string.toCharArray();
		List<Character> list = new ArrayList<>();
		for (int c = 0; c < charArray.length; c++) {
			list.add(charArray[c]);
			while (c+1 < charArray.length && charArray[c+1] == charArray[c]) {
				c++;
			}
		}
		return list;
	}

	private static void generateOutput(String line) throws IOException {
		System.out.println(line);
		writer.write(line + "\n");
	}
}
