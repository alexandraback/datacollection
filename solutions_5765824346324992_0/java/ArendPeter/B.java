import java.util.Scanner;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.util.Arrays;

public class B{
	public static void main(String args[]){
		String inputFileName = "B-small-attempt4.in";
		String outputFileName = "B-small-attempt4.out";
		try{
			Scanner scan = new Scanner(new FileInputStream(inputFileName));
			PrintWriter printer = new PrintWriter(new FileOutputStream(outputFileName));
			int T = scan.nextInt();
			scan.nextLine();
			for(int t = 0; t < T; t++){
				int B = scan.nextInt();
				long N = scan.nextLong();
				int[] times = new int[B];
				for(int i = 0; i < B; i++)
					times[i] = scan.nextInt();
				
				long curTime = 0;
				long nextTime = 0;
				long numCut = 0;
				int ans = 0;
				//simulate first bit
				int lcm = times[0];
				for(int i = 1; i < B; i++){
					int left = lcm;
					int right = times[i];
					while(right != 0){
						int temp = right;
						right = left % right;
						left = temp;
					}
					lcm = (lcm * times[i]) / left; //prod / gcd
				}
				long prod = 1;
				for(int i = 0; i < B; i++)
					prod*=times[i];
				long unitPeriod = lcm;
				long unitCuts = 0;
				for(int i = 0; i <B; i++)
					unitCuts += unitPeriod / times[i];
				long numUnits = N / unitCuts;
				N -= unitCuts * numUnits;
				if(N == 0){
					int minTime = times[0];
					int minIndex = 0;
					for(int i = 1; i < B; i++){
						if(times[i] <= minTime){
							minTime = times[i];
							minIndex = i;
						}
					}
					ans = minIndex+1;
				}
				//run for final section
				long[] endTimes = new long[B];
				while(numCut < N){
					curTime = nextTime;
					for(int i = 0; i < times.length; i++){
						if(endTimes[i] == curTime){
							numCut++;
							endTimes[i] = curTime + times[i];
							if(numCut == N){
								ans = i+1;
							}
						}
						if(endTimes[i] < nextTime || nextTime == curTime)
							nextTime = endTimes[i];
					}
				}
				printer.println("Case #"+(t+1)+": "+ans);
			}
			printer.close();
		}catch(Exception e){
			e.printStackTrace();
		}
	}
}