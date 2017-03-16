import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;


public class TheRepeater {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner s = new Scanner(new File("/home/piyushk/codejam/A-large.in"));
        PrintWriter pw = new PrintWriter("/home/piyushk/codejam/A-large.out");
        
        int T = s.nextInt();
        
        
        for(int i = 0; i < T; i++) {
            char charOrder[] = new char[100];
            int[][] charFreq = new int[100][100];
            int[] minCharCount = new int[100];
            int[] maxCharCount = new int[100];
            int maxDistinctChar = -1;
            int N = s.nextInt();
            String firstString = s.next();
            char[] strCh = firstString.toCharArray();
            char prevChar = ' ';
            for(int k = 0; k < strCh.length; k++) {
                
                if(strCh[k] == prevChar) {
                    charFreq[0][maxDistinctChar]++;
                    maxCharCount[maxDistinctChar]++;
                    minCharCount[maxDistinctChar]++;
                } else {
                    maxDistinctChar++;
                    prevChar = strCh[k];
                    charOrder[maxDistinctChar] = prevChar;
                    charFreq[0][maxDistinctChar] = 1;
                    minCharCount[maxDistinctChar] = 1;
                    maxCharCount[maxDistinctChar] = 1;
                }
            }
            boolean mismatch = false;
            for(int j = 1; j < N; j++) {
                strCh = s.next().toCharArray();
                int distinctChar = -1;
                prevChar = ' ';
                int prevCharCount = 0;
                for(int k = 0; k < strCh.length; k++) {
                    if(strCh[k] == prevChar) {
                        charFreq[j][distinctChar]++;
                        prevCharCount++;
                    } else {
                        if(prevCharCount > 0) {
                            if(minCharCount[distinctChar] > prevCharCount) {
                                minCharCount[distinctChar] = prevCharCount;
                            }
                            
                            if(maxCharCount[distinctChar] < prevCharCount) {
                                maxCharCount[distinctChar] = prevCharCount;
                            }
                        }
                        distinctChar++;
                        prevChar = strCh[k];
                        charFreq[j][distinctChar] = 1;
                        prevCharCount = 1;
                        if(charOrder[distinctChar] != prevChar) {
                            mismatch = true;
                            break;
                        }
                        
                    }
                }
                if(distinctChar != maxDistinctChar)
                    mismatch = true;
                
                
                if(prevCharCount > 0) {
                    if(minCharCount[distinctChar] > prevCharCount) {
                        minCharCount[distinctChar] = prevCharCount;
                    }
                    
                    if(maxCharCount[distinctChar] < prevCharCount) {
                        maxCharCount[distinctChar] = prevCharCount;
                    }
                }
            }
            
            int min = 0;
            if(!mismatch) {
                for(int l = 0; l <= maxDistinctChar; l++) {
                    int best = 100*100;
                    
                    for(int mm = minCharCount[l]; mm <= maxCharCount[l]; mm++) {
                        int currentBest = 0;
                        for(int h = 0; h < N; h++) {
                            currentBest += Math.abs(mm - charFreq[h][l]);
                        }
                        if(best > currentBest) {
                            best = currentBest;
                        }
                    }
                    
                    min += best;
                }
            }
            pw.println(String.format("Case #%s: %s", i + 1, mismatch ? "Fegla Won" : min));
        }
        pw.close();
        s.close();
        System.out.println("Done");
    }
}