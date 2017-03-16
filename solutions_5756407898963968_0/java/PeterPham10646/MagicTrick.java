package Task1;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
 
public class MagicTrick {
	
	public static String explainResult(int result, int matchCard){
		if(result == 0){
			return "Volunteer cheated!";
		}else if (result == 1){
			return "" + matchCard ;
		}else if(result > 1){
			return "Bad magician!";
		}
		
		return "Something is Wrong";
	}
 
	public static void main(String[] args) {
		
		int numTestCase, chosenRow, matchCount, matchCard;
		int[] chosen1 = new int[4];
		int[] chosen2 = new int[4];
		String dir = "/Users/tnpha6/Documents/workspace/CodeJam Preparation/files/MagicTrick/";
		String result = "";
		String[] splited = null;
		BufferedReader br = null;
		PrintWriter writer = null;
		try {
 
			String sCurrentLine;
 
			br = new BufferedReader(new FileReader(dir + "A-small-attempt0.in"));
			writer = new PrintWriter(dir + "output", "UTF-8");
			
			// Getting the number of test case
			numTestCase = Integer.parseInt(br.readLine());
			
			// Loop through every test cases
			for(int i = 0; i < numTestCase; i++){
				
				matchCount = 0;
				matchCard = -1;
				// Getting the number of chosen row
				chosenRow = Integer.parseInt(br.readLine());
				
				//Read arrangement
				for(int row = 1; row < 5; row++){
					splited = br.readLine().split(" ");
					if(row != chosenRow) continue;
					
					for(int column = 0; column < 4; column++){
						chosen1[column] = Integer.parseInt(splited[column]); 
					}
				}
				
				// Getting the number of chosen row
				chosenRow = Integer.parseInt(br.readLine());
				
				//Read second arrangment
				for(int row = 1; row < 5; row++){
					
					splited = br.readLine().split(" ");
					if(row != chosenRow) continue;
					
					// Search
					for(int column = 0; column < 4; column++){
						for(int column2 = 0; column2 < 4; column2++){
						
							if (chosen1[column2] == Integer.parseInt(splited[column])){ 
								matchCount++;
								matchCard = chosen1[column2];
								break;
							}
						}
					}
				}
				// Print out test case number
				writer.println("Case #" + (i+1) + ": " + explainResult(matchCount, matchCard));
				System.out.println("Case #" + (i+1) + ": " + explainResult(matchCount, matchCard));
			}
			
			writer.close();
 
		
		
		
		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			try {
				if (br != null)br.close();
			} catch (IOException ex) {
				ex.printStackTrace();
			}
		}
 
	}
}


