import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;



public class Main {

	public static void main(String args[]) throws NumberFormatException, IOException{
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int numTestCases = Integer.parseInt(br.readLine());
		for( int testCase = 1; testCase <= numTestCases; testCase++){
			int numStrings = Integer.parseInt(br.readLine());
			String[] strings = new String[numStrings];
			for(int i = 0; i < numStrings; i++){
				strings[i] = br.readLine();
			}
			
			final String nonRepeatingString = getNonRepeatingCharacterString(strings[0]);
			boolean Feglawin = false;
			//check if Fegla won
			for(String string : strings){
				if( !getNonRepeatingCharacterString( string).equals(nonRepeatingString)){
					System.out.println("Case #"+testCase+": Fegla Won");
					Feglawin = true;
				}
			}
			
			
			if(!Feglawin){
				int numMoves = 0;
				for(int charIndex = 0; charIndex < nonRepeatingString.length(); charIndex++){
					List<Integer> sorted = new ArrayList<Integer>();
					for(String string:strings){
						sorted.add(getCharacterCounts(string).get(charIndex));
					}
					Collections.sort(sorted);
					int median = sorted.get(new Double(numStrings/2).intValue());
					for(String string:strings){
						numMoves+=Math.abs(getCharacterCounts(string).get(charIndex)-median);
					}
				}
				System.out.println("Case #" + testCase+": "+numMoves);
			}
		}
	}
	
	private static List<Integer> getCharacterCounts(String input){
		List<Integer> output= new ArrayList<Integer>();
		char lastChar = input.charAt(0);
		int count = 1;
		for(int i = 1; i <= input.length()-1; i++){
			if (input.charAt(i) != lastChar){
				lastChar=input.charAt(i);
				output.add(count);
				count=1;
			}else count++;
		}
		output.add(count);
		return output;
	}
	
	private static String getNonRepeatingCharacterString(String input){
		
		String output = ""+input.charAt(0);
		char lastChar = input.charAt(0);
		for(int i = 1; i <= input.length()-1; i++){
			if (input.charAt(i) != lastChar){
				output+= input.charAt(i);
				lastChar = input.charAt(i);
			}
		}
		
		return output;
	}

}
