package codes;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashSet;
import java.util.Set;

public class MagicTrick {
	
	int [][] configuration1 = new int[4][4];
	int [][] configuration2 = new int[4][4];
	
	int row1;
	int row2;
	
	int record;
	int totalCases;
	
	String[] result;
	
	public String[] readFile(String fileName)  {
		File file = new File(fileName);
		FileReader fileReader;
		try {
			fileReader = new FileReader(file);
			BufferedReader bufferedReader= new BufferedReader(fileReader);
			

			
			String line = bufferedReader.readLine();
			totalCases = Integer.valueOf(line.trim());
			
			
			result = new String[totalCases];
			
			for(int caseI = 0; caseI < totalCases; ++caseI) {
				line = bufferedReader.readLine();
				row1 = Integer.valueOf(line.trim());
				for (int j = 0; j < 4; ++j) {
					line = bufferedReader.readLine();
					String[] nums = line.split("\\s+");
					for (int k = 0; k < 4; ++k) {
						configuration1[j][k] = Integer.valueOf(nums[k]);
					}
				}
			
				line = bufferedReader.readLine();
				row2 = Integer.valueOf(line.trim());
				
				for (int j = 0; j < 4; ++j) {
					line = bufferedReader.readLine();
					String[] nums = line.split("\\s+");
					for (int k = 0; k < 4; ++k) {
						configuration2[j][k] = Integer.valueOf(nums[k]);
					}
				}
			
				int evaluationResult = evaluate();
				
				
				switch(evaluationResult) {
				case 1:
					result[caseI] = Integer.toString(record);
					break;
				case 2:
					result[caseI] = "Bad magician!";
					break;
				case 3:
					result[caseI] = "Volunteer cheated!";
					break;
				}
			
			}	
			
			
			
			bufferedReader.close();
			fileReader.close();
			
			return result;
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		return null;
	}
	
	
	// evaluation
	//  1: give number
	//  2: bad magician (multiple)
	//  3: cheated
	private int evaluate() {
		
		
		int evaluation = 0;
		
		Set<Integer> config1RowSet = new HashSet<Integer>();
		
		for (int i = 0; i < 4; ++i) {
			config1RowSet.add(configuration1[row1-1][i]);
		}
		
		int count = 0;
		
		for (int i = 0; i < 4; ++i) {
			if (config1RowSet.contains(configuration2[row2-1][i])) {
				count++;
				record = configuration2[row2-1][i];
			}
		}
		
		if (count == 0) {
			return 3;
		} else if (count == 1) {
			return 1;
		} else {
			return 2;
		}
	}

	public String[]  printResult(String fileName) {
		return readFile(fileName);		
	}
	
	public void writeData (String fileName) { 
		File file = new File(fileName);
		try {
			if (!file.exists()) {
				file.createNewFile();
			}
			
			FileWriter fileWriter = new FileWriter(file);
			BufferedWriter bufferedWriter = new BufferedWriter(fileWriter);
			
			String str = "Case #";
			for (int i = 0; i < totalCases; ++i) {
				bufferedWriter.write(str+ Integer.toString(i+1) + ": " + result[i] + "\n");
			}
			
			bufferedWriter.flush();
			
			bufferedWriter.close();
			fileWriter.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}
	
	public static void main(String[] args) {
		MagicTrick instance = new MagicTrick();
		
		String fileName1 = "./data/MagicianTrick/A-small-attempt0.in";
		String fileName2 = "./data/MagicianTrick/A-small-attempt0.out";
		
		instance.readFile(fileName1);
		instance.writeData(fileName2);
	}
}
