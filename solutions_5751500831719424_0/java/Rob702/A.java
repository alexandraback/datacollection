import java.util.*;

public class A {
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		int numCases = in.nextInt();
		for(int caseNum = 1; caseNum <= numCases; caseNum++) {
            boolean possible = true;
            int maxLen = 0;
            int minLen = 0;
			int numWords = in.nextInt();
			String[] words = new String[ numWords ];
            String[] deduped = new String[ numWords ];
            for(int i = 0; i < numWords; i++) {
                words[i] = in.next();
                if ( words[i].length() > maxLen )
                    maxLen = words[i].length();
                deduped[i] = dedup(words[ i ]);
            }
            String lastWord = null;
            for(int i = 0; i < numWords; i++) {
                if ( lastWord == null )
                    lastWord = deduped[i];
                else if ( !lastWord.equals(deduped[i])) {
                    possible = false;
                    break;
                }
            }
            int minTotalMoves = 0;
            if ( possible && numWords > 0 ) {
                while (words[0].length() > 0 ) {
                    int minCount = -1;
                    int maxCount = -1;
                    int counts[] = new int[numWords];
                    char curChar = words[0].charAt(0);
                    for ( int j = 0; j < numWords; j++ ) {
                        int index = 0;
                        counts[j] = 0;
                        while ( words[j].length() > 0 && words[j].charAt(index) == curChar ) {
                            counts[j]++;
                            words[j] = words[j].substring( 1 );
                        }
                        if ( minCount == -1 || counts[j] < minCount )
                            minCount = counts[j];
                        if ( maxCount == -1 || counts[j] > maxCount )
                            maxCount = counts[j];
                    }
                    int leastMoves = -1;
                    for ( int i = minCount; i<= maxCount; i++ ) {
                        int numMoves = 0;
                        for ( int j = 0; j < numWords; j++ ) {
                            numMoves += Math.abs( i - counts[j] );
                        }
                        if (leastMoves == -1 || numMoves < leastMoves )
                            leastMoves = numMoves;
                    }
                    minTotalMoves += leastMoves;

                }
            }

            if ( !possible  )
                System.out.format("Case #%d: Fegla Won\n", caseNum );
            else
                System.out.format("Case #%d: %d\n", caseNum, minTotalMoves );
		}
	}

    private static String dedup(String word) {
        if ( word.length() <= 1 )
            return word;
        char lastChar = word.charAt(0);
        String output = "" + lastChar;
        for (int i = 1; i < word.length(); i++ ) {
            if ( word.charAt(i) != lastChar ) {
                lastChar = word.charAt(i);
                output += lastChar;
            }
        }
        return output;
    }
}
