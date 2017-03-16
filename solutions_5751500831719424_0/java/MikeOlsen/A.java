import java.io.*;
import java.util.Scanner;

public class A{
	static int[][] charCounts;
    public static void main(String[] args) throws FileNotFoundException, IOException {
		//File paths:
		String inputfile = "inputfile.in";
		String outputfile = "outputfile.out";
		
		//Set up input and output:
        Scanner scanner = new Scanner(new File(inputfile));
        BufferedWriter writer = new BufferedWriter(new FileWriter(outputfile));
		
		//Case loop:
        int caseNum = scanner.nextInt();
        for(int x = 1; x <= caseNum; x++) {
        	
        	int numStrings = scanner.nextInt();
        	String curString = scanner.next();
        	String prevString = minimizeString(curString);
        	int stringLength = prevString.length();
        	charCounts = new int[numStrings][stringLength];
        	countCharacters(curString, 0);
        	
        	
        	boolean FeglaWon = false;
        	
        	for(int y = 1; y < numStrings; y++){
        		curString = scanner.next();
        		countCharacters(curString, y);
        		curString = minimizeString(curString);
        		if(! curString.equals(prevString)) FeglaWon = true;
        		prevString = curString;
        	}
        	
        	if(FeglaWon){
        		writer.write("Case #" + x + ": Fegla Won");
                writer.newLine();
                continue;
        	}
        	
        	int score = 0;
        	
        	for(int i = 0; i < stringLength; i++){
        		int min = charCounts[0][i];
        		for(int j = 0; j < numStrings; j++){
        			if(charCounts[j][i] < min) min = charCounts[j][i];
        		}
        		
        		int prevSubTotal = getScore(min, i);
        		min++;
        		int curSubTotal = getScore(min, i);
        		min++;
        		while(curSubTotal < prevSubTotal){
        			prevSubTotal = curSubTotal;
        			curSubTotal = getScore(min, i);
        			min++;
        		}
        		score += prevSubTotal;
        	}
        	
        	
         
            writer.write("Case #" + x + ": " + score);
			
            writer.newLine();
        }
		
		//Cleanup:
        scanner.close();
        writer.close();
    }
    
    public static String minimizeString(String in){
    	StringBuilder out = new StringBuilder();
    	char lastChar = in.charAt(0);
    	out.append(lastChar);
    	for(int i = 1; i < in.length(); i++){
    		if(in.charAt(i) == lastChar) continue;
    		lastChar = in.charAt(i);
    		out.append(in.charAt(i));
    	}
    	return out.toString();
    }
    
    public static void countCharacters(String in, int stringIndex){
    	char lastChar = in.charAt(0);
    	charCounts[stringIndex][0] = 1;
    	int charIndex = 0;
    	for(int i = 1; i < in.length(); i++){
    		if(lastChar != in.charAt(i)){
    			lastChar = in.charAt(i);
    			charIndex++;
    			if(charIndex >= charCounts[0].length) break;
    		}
			charCounts[stringIndex][charIndex]++;
    	}
    }
    
    public static int getScore(int targetNum, int charIndex){
    	int ret = 0;
    	for(int i = 0; i < charCounts.length; i++){
    		ret += Math.abs(charCounts[i][charIndex] - targetNum);
    	}
    	return ret;
    }
}