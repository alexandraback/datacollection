package round1b;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Locale;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

/*
 * Google Code Jam 2014
 * Round 1B
 * raguenets@gmail.com
 * Usage : java MagicTrick inputFileName outputFileName
 */
public class TheRepeater {
	public static final String FEGLA_WON = "Fegla Won";

	public static void main(String[] args) {
		int T = 0;
		int N = 0;
		String[] strings;

		if (args.length == 2) {
			String inputFilename = args[0];
			File finput = new File(inputFilename);
			String outputFilename = args[1];
			File foutput = new File(outputFilename);
			Scanner scanner = null;
			BufferedWriter bw = null;
			try {
				bw = new BufferedWriter(new FileWriter(foutput));
			} catch (IOException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}
			if (finput.exists()) {
				try {
					scanner = new Scanner(finput);
					scanner.useLocale(Locale.US);
					// Reads first line : number of Tests
					if (scanner.hasNextInt()) {
						T = scanner.nextInt();
					}
					for (int i = 0; i < T; i++) {
						// Read number of flies
						N = scanner.nextInt();
						strings = new String[N];
						for (int k = 0; k < N; k++) {
							strings[k] = scanner.next();
						}
						// Read fly positions
						bw.write("Case #" + (i + 1) + ": "
								+ theRepeater(N, strings) + "\n");
					}
				} catch (FileNotFoundException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				} finally {
					try {
						bw.close();
						if (scanner != null) {
							scanner.close();
						}
					} catch (IOException e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
					}
				}
			}
		}
	}

	public static String theRepeater(int N, String[] values) {
		// Impossible if character are not the same
		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				for (int k = 0; k < values[i].length(); k++) {
					if (values[j].indexOf(values[i].charAt(k)) == -1) {
						return FEGLA_WON;
					}
				}
			}
		}
		// If characters are possible, check strings are differents (if not
		// return 0)
		boolean differenceFound = false;
		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				if (!values[i].equals(values[j])) {
					differenceFound = true;
				}
			}
		}
		if (!differenceFound)
			return Integer.toString(0);
		// check order of characters without
		// cost function = number of movements
		// trying to minimise |a - ai| for every letters

		List<Character> lettresStrings[] = new ArrayList[N];
		List<Integer> frequencesStrings[] = new ArrayList[N];
		for (int k = 0; k < N; k++) {
			lettresStrings[k] = new ArrayList<Character>();
			frequencesStrings[k] = new ArrayList<Integer>();
			char[] a = values[k].toCharArray();
			char c = values[k].charAt(0);
			int freq = 1;
			for (int i = 1; i < a.length; i++) {
				if (values[k].charAt(i) == c) {
					freq++;
				} else {
//					System.err.println(Character.toString(c) + ' ' + freq);
					lettresStrings[k].add(c);
					frequencesStrings[k].add(freq);
					c = values[k].charAt(i);
					freq = 1;
				}
			}
			if (c == values[k].charAt(values[k].length() - 1)) {
//				System.err.println(Character.toString(c) + ' ' + freq);
				lettresStrings[k].add(c);
				frequencesStrings[k].add(freq);
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				if (!lettresStrings[i].equals(lettresStrings[j])) {
					return FEGLA_WON;
				}
			}
		}
		int sum = 0;
		for (int i=0; i < frequencesStrings[0].size(); i++) {
			int freq[] = new int[N];
			for (int j=0; j < N; j++) {
				freq[j] = frequencesStrings[j].get(i);
			}
			sum += findMinimumMove(freq);
		}
		
		return Integer.toString(sum);
	}

	public static int findMinimumMove(int[] freq) {
		int min = Integer.MAX_VALUE;
		int max = 0;
		for (int f:freq) {
			if (f < min) {
				min = f;
			}
			if (f > max) {
				max = f;
			}
		}
		int bestSum = Integer.MAX_VALUE;
		int bestIndex = 0;
		for (int i=min; i <= max ; i++) {
			int sum = 0;
			for (int f: freq) {
				sum += Math.abs(f-i);
			}
			if (sum < bestSum) {
				bestSum = sum;
				bestIndex = i;
			}
		}
		return bestSum;
	}
}
