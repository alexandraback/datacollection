package round1C;

import java.util.*;
import java.util.Map.Entry;
import java.io.*;
import java.math.*;

public class A {

	private static Scanner sc;
	

	public static void main(final String[] args) {
		setStreams("/Users/yariv/Downloads/A-small-attempt0");
//		setStreams("/Users/yariv/Downloads/A-large");
//		setStreams("/Users/yariv/Downloads/test");
		sc = new Scanner(System.in);
		final int numCases = sc.nextInt();
		handleCases(numCases);
	}

	private static void setStreams(final String baseFileName) {
		try {
			System.setIn(new FileInputStream(baseFileName + ".in"));
			System.setOut(new PrintStream(baseFileName + ".out"));
		} catch (final FileNotFoundException e) {
			e.printStackTrace();
		}
	}

	private static void handleCases(final long numCases) {
		for (int i = 1; i <= numCases; i++) {
			handleCase(i);
		}
	}

	private static void handleCase(final int caseNumber) {
		long N = sc.nextLong();
		Map<Character, Integer> sMap = new HashMap<>();
		int total = 0;
		for(int i = 0 ; i < N ; i++) {
			int val = sc.nextInt();
			sMap.put((char)('A' + i), val);
			total += val;
		}
		
		System.out.print("Case #" + caseNumber + ": ");
		
		while(total > 0) {
			Character largest1 = ' ';
			int max = -1;
			for(Entry<Character, Integer> entry : sMap.entrySet()) {
				if(entry.getValue() > max) {
					largest1 = entry.getKey();
					max = entry.getValue();
				}
			}
			
			total--;
			sMap.put(largest1, sMap.get(largest1) - 1);
			
			boolean remove2 = false;
			Character largest2 = ' ';
			if(total > 0) {
				remove2 = true;
				max = -1;
				for(Entry<Character, Integer> entry : sMap.entrySet()) {
					if(entry.getValue() > max) {
						largest2 = entry.getKey();
						max = entry.getValue();
					}
				}
				
				for(Entry<Character, Integer> entry : sMap.entrySet()) {
					if(entry.getValue() > ((double)(total - 1) / 2) && entry.getKey() != largest2) {
						remove2 = false;
					}
				}
				
				if(remove2) {
					total--;
					sMap.put(largest2, sMap.get(largest2) - 1);
				}
			}
			
			System.out.print(largest1);
			if(remove2) {
				System.out.print(largest2);
			}
			System.out.print(' ');
		}
		
		System.out.println("");
	}
	
	private static void log(final String message) {
//		System.out.println(message);
	}
}
