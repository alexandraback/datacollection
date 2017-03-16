import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Scanner;

public class ProblemB {
		
	public static void main(String[] args) throws NumberFormatException, IOException {
		FileWriter writer = new FileWriter("C:/Users/Max/Documents/Java Workspaces/Google Code Jam/Round 1A 2015/src/output.txt");		
		try {
			BufferedReader br = new BufferedReader(new FileReader("C:/Users/Max/Documents/Java Workspaces/Google Code Jam/Round 1A 2015/src/input.txt"));
			int numCases = Integer.parseInt(br.readLine());
			for (int caseNum = 1; caseNum <= numCases; caseNum++) {
				String line = br.readLine();
				Scanner sc = new Scanner(line);
				long b = Long.parseLong(sc.next());
				long n = Long.parseLong(sc.next());
				sc = new Scanner(br.readLine());
				ArrayList<Long> times = new ArrayList<Long>();
				while(sc.hasNext()){
					times.add(Long.parseLong(sc.next()));
				}
				long maxTime = 100000000000000L;
				long x = maxTime/2L;
				long minTime = 0L;
				while(true){
					if(minTime == maxTime) break;
					long total = calculateNumberCut(times, x);
					if(total >= n - b - 1){
						maxTime = x;
						x = (maxTime + minTime)/2L;
					} else {
						minTime = x + 1;
						x = (minTime + maxTime)/2L;
					}
				}
				System.out.println(x);
				long finished = calculateNumberCut(times, x);
				long needed = n - finished;		
				if(needed <= b){
					ArrayList<Long> minutesTilAvailable = new ArrayList<Long>();
					long occupiedChairs = 0;
					for(int i = 0; i < b; i++){
						long minutesLeft = times.get(i) - (x - Math.floorDiv(x, times.get(i))*times.get(i));
						if(minutesLeft == times.get(i)){
							minutesTilAvailable.add(0L);
						} else {
							minutesTilAvailable.add(minutesLeft);		
							occupiedChairs++;
						}
					}
					long target = needed - occupiedChairs;
					long emptyChairs = 0;
					for(int i = 0; i < b; i++){
						if(minutesTilAvailable.get(i) == 0L){
							emptyChairs++;
						}
						if(emptyChairs == target){
							printAnswer("" + (i + 1), caseNum, writer);
							break;
						}
					}
				} else {
					ArrayList<Long> minutesTilAvailable = new ArrayList<Long>();
					for(int i = 0; i < b; i++){
						long minutesLeft = times.get(i) - (x - Math.floorDiv(x, times.get(i))*times.get(i));
						minutesTilAvailable.add(minutesLeft);		
					}
					long smallest = Long.MAX_VALUE;
					long smallIndex = 0;
					for(int i = 0; i < b; i++){
						if(minutesTilAvailable.get(i) < smallest){
							smallest = minutesTilAvailable.get(i);
							smallIndex = i;
						}
					}
					printAnswer("" + (smallIndex + 1), caseNum, writer);
				}
				
			}
			br.close();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		writer.close();
	}

	public static long calculateNumberCut(ArrayList<Long> times, long x){
		long total = 0;
		for(int i = 0; i < times.size(); i++){
			total += Math.floorDiv(x,times.get(i));
		}
		return total;
	}
	public static void printAnswer(String answer, int caseNumber, FileWriter writer) throws IOException {
		writer.write("Case #" + caseNumber + ": " + answer + "\n");
	}
}
