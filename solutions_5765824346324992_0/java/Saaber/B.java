import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;






public class B {

	public static void main(String[] args) throws IOException{
		
		String filePath = "C:/codeJam/secondRound/2/";
		BufferedReader buffer = new BufferedReader(new FileReader(filePath+"attempt.in"));
		
		String line = buffer.readLine();
		
		int numOfCase = 1;
		StringBuilder sb = new StringBuilder();
		while (line != null) {
			line = buffer.readLine();
			if(line == null)
				break;
			String numOfBarbers = line.split(" ")[0];
			String spot = line.split(" ")[1];
			if(spot.equals("695191631"))
				System.out.println();
			line = buffer.readLine();
			String[] cabs = line.split(" ");
			int res = schedule(cabs, Integer.parseInt(numOfBarbers), Integer.parseInt(spot));
			
			sb.append("Case #"+numOfCase+": "+res);
			sb.append(System.lineSeparator());
			numOfCase++;
			
		}
		File file = new File(filePath+"res.out");
        BufferedWriter output = new BufferedWriter(new FileWriter(file));
        output.write(sb.toString());
        output.close();
	}

	private static int schedule(String[] barbersRate, int numOfBarbers,  int spot) {
		long lcm = lcm(barbersRate);
		int serverInLCM = sumOfServedInLCM(barbersRate, lcm);
		spot = spot % serverInLCM;
		if(spot == 0)
			spot = serverInLCM;
		int finBarber = 1;
		int[] barbersLine = new int[barbersRate.length];
		int i = 1;
		while(i <= spot){
			for(int b = 0 ; b < numOfBarbers ; b++){
				if(barbersLine[b]* Integer.parseInt(barbersRate[b]) <= minTime(barbersLine,barbersRate)){
					barbersLine[b] ++;
					if(i == spot){
						finBarber = b;
						i++;
						break;
					}
					i++;
				}
			}
					
		}
		return finBarber+1;
	}

	private static int sumOfServedInLCM(String[] barbersRates, long lcm) {
		int served = 0;
		for(int b = 0 ; b < barbersRates.length ; b++){
			served += lcm/Integer.parseInt(barbersRates[b]);
		}
		return served;
	}

	private static int minTime(int[] barbersLine, String[] barbersRate) {
		int min = barbersLine[0] * Integer.parseInt(barbersRate[0]);
		for(int b = 0 ; b < barbersLine.length ; b++){
			if(barbersLine[b] * Integer.parseInt(barbersRate[b]) < min)
				min = barbersLine[b] * Integer.parseInt(barbersRate[b]);
		}
		return min;
	}
	
	private static long lcm(long a, long b)
	{
	    return a * (b / gcd(a, b));
	}

	private static long gcd(long a, long b)
	{
	    while (b > 0)
	    {
	        long temp = b;
	        b = a % b; // % is remainder
	        a = temp;
	    }
	    return a;
	}

	
	private static long gcd(long[] input)
	{
	    long result = input[0];
	    for(int i = 1; i < input.length; i++) result = gcd(result, input[i]);
	    return result;
	}
	
	private static long lcm(String[] input)
	{
	    long result = Integer.parseInt(input[0]);
	    for(int i = 1; i < input.length; i++) result = lcm(result, Integer.parseInt(input[i]));
	    return result;
	}

}
