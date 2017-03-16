import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.List;
import java.util.Vector;

public class Repeater {
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Repeater test = new Repeater();
		test.repInit("A-large.in", "Repeater-large.txt");
		//test.ropeInit("Rope-small.in", "Rope-small.txt");
	}
	
	public void repInit(String inputFile, String outputFile){
		
		BufferedReader input;
		List<Integer> result = new Vector<Integer>();
		
		try {
		
			input = new BufferedReader(new FileReader(inputFile));
			
			int cases = Integer.parseInt(input.readLine());
			
			for (int i = 0; i < cases; i++){
				
				result.add(caseSolver(input));
			}
			
			printResult(result, outputFile);
			
		} catch (FileNotFoundException fnte) {
			
			System.out.println("File " + inputFile + " not found");
			
		} catch (IOException ioe) {
			
			System.out.println("Error reading file");
		}
	}
	
	public int caseSolver(BufferedReader input) throws IOException{
		
		String line = input.readLine();
		int numStrings = Integer.parseInt(line);
		int result = 0;
		
		String[] strings = new String[numStrings];
		
		for (int i = 0; i < numStrings; i++){
			
			strings[i] = input.readLine();
		}
		
		Vector<Character> sequence = new Vector<Character>();
				
		for (int i = 0; i < strings[0].toCharArray().length; i++){
			
			if (sequence.size() == 0){
			
				sequence.add(strings[0].toCharArray()[i]);
				
			} else if (strings[0].toCharArray()[i] != sequence.get(sequence.size() - 1)){
				
				sequence.add(strings[0].toCharArray()[i]);
			}
		}
		
		Vector<Vector<Integer>> numChars = new Vector<Vector<Integer>>();
		
		for (int i = 0; i < sequence.size(); i++){
			
			numChars.add(new Vector<Integer>());
		}
		
		for (int i = 0; i < numStrings; i++){
			
			int characterNum = 0;
			int counter = 0;
			
			for (int j = 0; j < strings[i].toCharArray().length; j++){
				
				if (strings[i].toCharArray()[j] == sequence.get(characterNum)) {
					
					counter++;
					
				} else if (j > 0 && characterNum < (sequence.size() - 1) && strings[i].toCharArray()[j] == sequence.get(characterNum + 1)){
					
					if (numChars.get(characterNum).size() == 0){
						
						numChars.get(characterNum).add(counter);
						
					} else {
						
						boolean lower = false;
						
						for (int k = 0; k < numChars.get(characterNum).size(); k++){
							
							if (numChars.get(characterNum).get(k) >= counter){
								
								numChars.get(characterNum).add(k, counter);
								lower = true;
								break;
							}
						}
						
						if (!lower){
							
							numChars.get(characterNum).add(counter);
						}
					}
					
					characterNum++;
					counter = 1;
					
				} else {
					
					return -1;
				}
			}
			
			if (characterNum < (sequence.size() - 1)){
				
				return -1;
			}
			
			if (numChars.get(characterNum).size() == 0){
				
				numChars.get(characterNum).add(counter);
				
			} else {
				
				boolean lower = false;
				
				for (int k = 0; k < numChars.get(characterNum).size(); k++){
					
					if (numChars.get(characterNum).get(k) >= counter){
						
						numChars.get(characterNum).add(k, counter);
						lower = true;
						break;
					}
				}
				
				if (!lower){
					
					numChars.get(characterNum).add(counter);
				}
			}
		}
		
		for (int i = 0; i < numChars.size(); i++){
			
			Vector<Integer> current = numChars.get(i);
			
			int ideal = current.get(current.size() / 2);
			
			for (int j = 0; j < current.size(); j++){
				
				int difference = ideal - current.get(j);
				
				if (difference < 0){
					
					difference = difference * -1;
				}
				
				result = result + difference;
			}
		}
		
		return result;
	}
	
	
	public void printResult(List<Integer> results, String outputFile) throws IOException{
		PrintWriter printer = new PrintWriter(new File(outputFile));
		
		for (int i = 0; i < results.size(); i++){
			
			int state = results.get(i);
			
			if (state != -1){
			
				printer.println("Case #" + (i + 1) + ": " + state);
				printer.flush();
				
			} else {
				
				printer.println("Case #" + (i + 1) + ": Fegla Won");
				printer.flush();
			}
		}
	}
}
