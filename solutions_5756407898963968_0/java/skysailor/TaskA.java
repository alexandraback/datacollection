import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;


public class TaskA {
	
	private BufferedReader br;
	private StringBuilder sb;
	private BufferedWriter bw;
	
	public static void main(String args[]) throws IOException {
		System.out.println("Task A");
		System.out.println(System.getProperty("user.dir"));
		TaskA taskA = new TaskA("A-small-attempt0.in","out.txt");
		
		
		try {
			
		    int numOfTestCases = taskA.readNumOfTestCases();
		    for (int i = 1; i <= numOfTestCases; i++) {
		    	int firstInput = taskA.readInput();
		    	int[] possibleCards1 = taskA.readPossibleCards(firstInput);
		    	int secondInput = taskA.readInput();
		    	int[] possibleCards2 = taskA.readPossibleCards(secondInput);
		    	String result = taskA.process(possibleCards1, possibleCards2);
		    	taskA.writeALine("Case #" + i+": " + result);
		    }

		     //   while (line != null) {
		     //   }
		}
		finally {
			taskA.closeRead();
		}
		        
	}
	
	public TaskA(String inputFile, String outputFile) throws IOException {
		
		br = new BufferedReader(new FileReader(inputFile));
		bw = new BufferedWriter(new FileWriter(outputFile));
		sb = new StringBuilder();
	}
	
	public void closeRead() throws IOException{
		br.close();
		bw.close();
	}
	
	private int readNumOfTestCases() throws NumberFormatException, IOException{
		return Integer.valueOf(br.readLine());
	}
	
	private int readInput() throws NumberFormatException, IOException{
		return Integer.valueOf(br.readLine());
	}
	
	private int[] readPossibleCards(int input) throws IOException{
		int[] result = new int[4];
		for (int i = 1; i <=4; i++) {
			String line = br.readLine();
			if (i == input) {
				String[] resultStr = line.split("\\s+");
				for (int j = 0; j < 4; j++) {
					result[j] = Integer.valueOf(resultStr[j]);
				}
			}
		}
		return result;
	}
	
	private String process(int[] possibleCards1, int[] possibleCards2){
		int resultCard = 0;
		for (int a: possibleCards1) {
			for (int b : possibleCards2) {
				if (a == b) {
					if (resultCard == 0) {
						resultCard = a;
					}
					else {
						return "Bad magician!";
					}
				}
			}
		}
		if (resultCard == 0) {
			return "Volunteer cheated!";
		}
		else return String.valueOf(resultCard);
	}
	
	private void writeALine(String str) throws IOException {
		bw.write(str);
		bw.newLine();
	}

}
