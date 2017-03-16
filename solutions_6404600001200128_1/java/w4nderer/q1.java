
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
public class q1 {
	public static void main(String[] args) throws Exception {

		String inputLine;
		try{
			// open input stream test.txt for reading purpose.
			BufferedReader br = new BufferedReader(new FileReader("C:/Users/vincent/Desktop/A-large.txt"));
			FileWriter fw = new FileWriter("C:/Users/vincent/Desktop/output.txt");
			inputLine = br.readLine();

			int testCaseNumber = 0;

			int[] inputData;

			while ((inputLine = br.readLine()) != null) {
				double maxDiff = 0;
				int currentInPlate = 0;
				int timesWeCheck = 0;

				testCaseNumber++;

				timesWeCheck = Integer.parseInt(inputLine);
				inputData = new int[timesWeCheck];

				inputLine = br.readLine();
				String[] inputParts = inputLine.split(" ");
				currentInPlate = Integer.parseInt(inputParts[0]);
				inputData[0] = currentInPlate;

				for (int i = 1; i < timesWeCheck; i++) {
					int newInPlate = Integer.parseInt(inputParts[i]);
					int currentDiff = currentInPlate - newInPlate;
					if (currentDiff >= 0 && currentDiff > maxDiff) {
						maxDiff = currentDiff;
					}
					currentInPlate = newInPlate;
					inputData[i] = newInPlate;
				}

				int answer = processInput(inputData);
				int answer2 = processInput2(inputData, maxDiff/10);
				String output = "Case #" + testCaseNumber + ": " + answer + " " + answer2 + "\n";
				fw.write(output);
			}
			fw.close();
			br.close();
		}catch(Exception e){
			e.printStackTrace();
		}
	}

	private static int processInput(int[] inputData) {
		int answer = 0;

		for (int i = 0; i < inputData.length-1; i++) {
			int currentOnPlate = inputData[i];
			int nextOnPlate = inputData[i+1];
			int diff = currentOnPlate - nextOnPlate;
			if (diff > 0) {
				answer += diff;
			}
		}

		return answer;
	}

	static int processInput2(int[] inputData, double rate) {
		int answer = 0;

		for (int i = 0; i < inputData.length-1; i++) {
			int currentOnPlate = inputData[i];
			if (currentOnPlate - inputData[i+1] >= 0) {
				if (currentOnPlate >= rate*10) {
					answer += rate*10;
				} else {
					answer += currentOnPlate;
				}
			} else {
				if (currentOnPlate < rate*10) {
					answer += currentOnPlate;
				} else {
					answer += rate*10;
				}
			}
		}

		return answer;
	}
}