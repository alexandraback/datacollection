
import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

public class Repeater {

	public static int solveRepeater(ArrayList<String> strings) {
		int moves = 0;
		int numStrings = strings.size();
		ArrayList<ArrayList<Character>> charLists = new ArrayList<ArrayList<Character>>();
		ArrayList<ArrayList<Integer>> countLists = new ArrayList<ArrayList<Integer>>();		
		
		for (int idx =0; idx < numStrings; idx++) {
			String s = strings.get(idx);
			ArrayList<Character> charList = new ArrayList<Character>();
			ArrayList<Integer> countList = new ArrayList<Integer>();
			
			Character prevChar = null;
			int count = 0;
			
			for (int i=0; i<s.length(); i++) {
				char currChar = s.charAt(i);
				if (prevChar != null && prevChar == currChar) {
					count++;
				}
				else {
					if (prevChar != null) {
						charList.add(prevChar);
						countList.add(count);
					}
					prevChar = currChar;
					count = 1;
				}
				
				if (i == s.length() - 1) {
					charList.add(currChar);
					countList.add(count);
				}
			}
			
			
			if (charLists.size() > 0) {
				if (! charList.equals(charLists.get(0))) {
					return -1;
				}
			}
//			System.out.println(charList);
//			System.out.println(countList);
			charLists.add(charList);
			countLists.add(countList);
		}
		
		int numChars = charLists.get(0).size();
		
		for (int i=0; i<numChars; i++) {
			int[] counts = new int[numStrings];
			for (int idx =0 ; idx < numStrings; idx++) {
				counts[idx] = countLists.get(idx).get(i);
			}
			Arrays.sort(counts);
			int median = median(counts);
			
			for (int c : counts) {
				moves += Math.abs(c - median);
			}
		}
		
		
		return moves;
				
	}
	
	private static int median(int[] list) {
		int n = list.length;
		
		if (n % 2 == 0) {
			return (list[n/2] + list[n/2 - 1])/2;
		} 
		else {
			return list[(n-1)/2];
		}
	}
	
	
	public static void main(String args[] ) throws Exception {
		String filename = "A-large.in";
		String outfilename = "A_large_out.txt";
		
    	BufferedReader br = new BufferedReader(new FileReader(filename));
		String line = br.readLine();
		int numTests = Integer.valueOf(line);
		ArrayList<String> results = new ArrayList<String>();

		for (int i=0; i<numTests; i++) {
			line = br.readLine();
			int numStrings = Integer.valueOf(line);
			
			ArrayList<String> inputStrings = new ArrayList<String>();
			
			for (int r=0; r<numStrings; r++) {
				line = br.readLine();
				inputStrings.add(line);
			}
			
			int moves = solveRepeater(inputStrings);
			String output = "Case #" + (i+1) + ": ";
			
			if (moves == -1) {
				output += "Fegla Won";
			}
			else {
				output += moves;
			}

			results.add(output);
			
		}
		
		br.close();
		
		Writer writer = null;
		try {
		    writer = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(outfilename), "utf-8"));
		    for (String str : results) {
		    	writer.write(str+"\n");
		    }
		} catch (IOException ex) {
		  // report
		} finally {
		   try {writer.close();} catch (Exception ex) {}
		}
	}
}
