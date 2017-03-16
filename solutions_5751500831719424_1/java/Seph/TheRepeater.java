import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


public class TheRepeater {
	
	public static int numRuns = 0;
	
	public static void main(String[] args) throws IOException {
		System.out.println(args[0]);
		System.out.println(args[1]);
		
		Scanner s = new Scanner(new File(args[0]));
		File out = new File(args[1]);
		if(!out.exists()) {
			out.createNewFile();
		} else {
			out.delete();
			out.createNewFile();
		}
		FileWriter fw = new FileWriter(out);
		
		int numCases = s.nextInt();
		for(int i=1; i<=numCases; i++) {
			int n = s.nextInt();
			List<String> strings = new ArrayList<String>();
			for(int j=0; j<n; j++) {
				strings.add(s.next());
			}
			
			int[][] counts = countAndVerifyRunTypes(strings);
			
			if(counts == null) {
				fw.write("Case #"+i+": Fegla Won\n");
			} else {
				int minMoves = getMinMoves(counts, n,  numRuns);
				fw.write("Case #"+i+": " + minMoves+"\n");
			}
			/*
			int minMoves = Integer.MAX_VALUE;
			for(int j=0; j<n; j++) {
				String target = strings.get(j);
				
				int totalMovesForThisTarget = 0;
				for(int k=0; k<n; k++) {
					if(j != k) {
						int thisStringsMoves = getNumMoves(strings.get(k), target);
						if(thisStringsMoves == -1) {
							totalMovesForThisTarget = -1;
							break;
						} else {
							totalMovesForThisTarget += thisStringsMoves;
						}
					}
				}
				
				if(totalMovesForThisTarget == -1) {
					minMoves = -1;
					break;
				} else {
					if(totalMovesForThisTarget < minMoves) {
						minMoves = totalMovesForThisTarget;
					}
				}
	
			}
			
			if(minMoves == -1) {
				fw.write("Case #"+i+": Felga Won\n");
			} else {
				fw.write("Case #"+i+": " + minMoves+"\n");
			}*/
		}
		fw.close();
		
		
		
	}
	
	
	public static int getNumMoves(String start, String dest) {
		int startIndex = 0;
		int destIndex = 0;
		
		int moves = 0;
		while(true) {
			boolean startFinished = false;
			boolean destFinished = false;
			char currentStartChar = '1';
			char currentDestChar = '2';
			
			if(startIndex < start.length()) {
				currentStartChar = start.charAt(startIndex);
			} else {
				startFinished = true;
			}
			
			if(destIndex < dest.length()) {
				currentDestChar = dest.charAt(destIndex);
			} else {
				destFinished = true;
			}
			
			if (startFinished && destFinished) {
				return moves;
			}
			
			if(currentStartChar!=currentDestChar) {
				return -1;
			}
			
			int startRunLength = getRunLength(start, currentStartChar, startIndex);
			int destRunLength = getRunLength(dest, currentDestChar, destIndex);
			
			moves += Math.abs(startRunLength-destRunLength);
			
			startIndex += startRunLength;
			destIndex += destRunLength;
		}
		
	}
	
	public static int getMinMoves(int[][] count, int counts, int runs) {
		int totalMoves = 0;
		for(int run=0; run<runs; run++) {
			int minMoves = Integer.MAX_VALUE;
			for(int countIndex1 = 0; countIndex1< counts; countIndex1++) {
				int target = count[countIndex1][run];
				int thisMoves = 0;
				for(int countIndex2 = 0; countIndex2< counts; countIndex2++) {
					if(countIndex1 != countIndex2) {
						thisMoves+= Math.abs(target - count[countIndex2][run]);
					}
				}
				if(thisMoves<minMoves) {
					minMoves = thisMoves;
				}
			}
			totalMoves+=minMoves;
		}
		return totalMoves;
	}
	
	public static int[][] countAndVerifyRunTypes(List<String> strings) {
		List<Character> runType = new ArrayList<Character>();
		
		String first = strings.get(0);
		int firstIndex = 0;
		numRuns = 0;
		while(firstIndex < first.length()) {
			char runChar = first.charAt(firstIndex);
			runType.add(runChar);
			int stringRunLength = getRunLength(first, runChar, firstIndex);
			firstIndex += stringRunLength;
			numRuns++;
		}
		
		int[][] counts = new int[strings.size()][numRuns];
		int countIndex = 0;
		for(String thisString : strings) {
			int stringIndex = 0;
			int runIndex = 0;
			while(stringIndex < thisString.length()) {
				char runChar = thisString.charAt(stringIndex);
				if(runIndex >= runType.size() || runType.get(runIndex) != runChar) {
					return null;
				}
				int stringRunLength = getRunLength(thisString, runChar, stringIndex);
				stringIndex += stringRunLength;
				counts[countIndex][runIndex] = stringRunLength;
				runIndex++;
			}
			
			if(runIndex!=runType.size()) {
				return null;
			}
			
			countIndex++;
		}
		return counts;
		
		
	}
	
	
	
	public static int getRunLength(String thisString, char runTarget, int startIndex) {
		int runCount = 0;
		while(startIndex < thisString.length() && thisString.charAt(startIndex) == runTarget) {
			runCount++;
			startIndex++;
		}
		return runCount;
	}
		
		
	
	
}
