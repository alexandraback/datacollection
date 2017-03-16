
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
public class q2 {
	public static void main(String[] args) throws Exception {

		String inputLine;
		try{
			// open input stream test.txt for reading purpose.
			BufferedReader br = new BufferedReader(new FileReader("C:/Users/vincent/Desktop/B-small-attempt3.txt"));
			FileWriter fw = new FileWriter("C:/Users/vincent/Desktop/output.txt");
			inputLine = br.readLine();

			int testCaseNumber = 0;

			int[] inputData;
			int[] barberTime;

			while ((inputLine = br.readLine()) != null) {
				int numberOfBarber = 0;
				int numberInQueue = 0;

				testCaseNumber++;

				String[] inputParts = inputLine.split(" ");
				numberOfBarber = Integer.parseInt(inputParts[0]);
				numberInQueue = Integer.parseInt(inputParts[1]);
				inputData = new int[numberOfBarber];
				barberTime = new int[numberOfBarber];
				
				inputLine = br.readLine();
				inputParts = inputLine.split(" ");

				for (int i = 0; i < numberOfBarber; i++) {
					int timeTaken = Integer.parseInt(inputParts[i]);
					inputData[i] = timeTaken;
					barberTime[i] = 0;
				}

				int answer = processInput(inputData, barberTime, numberInQueue);
				String output = "Case #" + testCaseNumber + ": " + answer + "\n";
				fw.write(output);
			}
			fw.close();
			br.close();
		}catch(Exception e){
			e.printStackTrace();
		}
	}

	private static int processInput(int[] inputData, int[] barberTime, int numberInQueue) {
		int answer = 0;
		int cycleTime = lcm(inputData);
		int cycle = 0;
		for (int i = 0; i < inputData.length; i++) {
			cycle += cycleTime/inputData[i];
		}
		
		numberInQueue = numberInQueue%cycle;
		
		if (numberInQueue == 0) {
			numberInQueue = cycle;
		}
		
		while (numberInQueue > 0) {
			answer = findNextBarber(barberTime);
			barberTime[answer] = inputData[answer];
			numberInQueue--;
		}

		return answer+1;
	}

private static int findNextBarber(int[] barberTime) {
	int index = 0;
	int fastest = barberTime[0];
	
	for (int i = 1; i < barberTime.length; i++) {
		if (barberTime[i] < fastest) {
			fastest = barberTime[i];
			index = i;
		}
	}
	

	for (int i = 0; i < barberTime.length; i++) {
		barberTime[i] -= fastest;
	}
	
	return index;
}

private static int gcd(int a, int b)
{
    while (b > 0)
    {
    	int temp = b;
        b = a % b; // % is remainder
        a = temp;
    }
    return a;
}

private static int lcm(int a, int b)
{
    return a * (b / gcd(a, b));
}

private static int lcm(int[] inputData)
{
	int result = inputData[0];
    for(int i = 1; i < inputData.length; i++) {
    	result = lcm(result, inputData[i]);
    }
    return result;
}

}