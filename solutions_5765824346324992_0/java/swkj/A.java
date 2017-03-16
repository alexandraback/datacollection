package codejam.y2014.qualification.copy;
import java.util.*;
import java.io.*;

public class A {

	public static int solve(int you, int[] bTime)
	{
		// check if you < bTime. 
		if (you <= bTime.length ) {
			return you;
		}
		
		// prepare the first round of customers
		int[] arr = bTime.clone();
		int period = bTime[0];
		int counter = bTime.length + 1;
		for(int i : bTime) period = GCD(period, i);
		
		// lets take out extra un-needed full cycles. THIS IS WRONG
		int sum = 0;
		for(int i : bTime) sum += i / period;
		//you = you % sum;
		
//		while(you > sum) {
//			you -= sum;
//		}
//		System.out.println("you left with " + you);
		
		// try again.
		
		int[] spare = bTime.clone();
		Arrays.sort(spare);
		int maxVal = spare[spare.length - 1];
		int cycleLen = 1;
		if (period != maxVal) {
			sum = 0;
			cycleLen = 1;
			for(int i : bTime) cycleLen *= i;
			for(int i : bTime) sum += cycleLen / i;
		}
		// every time we can take out sum people for the queue to reach its original state. 
		//System.out.println("taking out sum: " + sum + " arr : " + Arrays.toString(bTime));
		while(you > sum) {
			you -= sum;
		}
//		System.out.println("taking out sum: " + sum + " arr : " + Arrays.toString(bTime));
//		System.out.println("you left with " + you);
//		
		
		if (you <= bTime.length ) {
			return you;
		}
		
		//after first round of customers, lets start. counter represents the counter-th person waiting
		while (counter <= you) {
			for(int barber = 0; barber < arr.length; barber++)
			{
				arr[barber] = arr[barber] - period;
				if(arr[barber] == 0) 
				{
					if (counter == you) {
						return barber + 1; // off set zero array vs real life
					}
					arr[barber] += bTime[barber];
					counter++;
				}
			}
		}
		return -1;
	}
	
	public static int GCD(int a, int b) {
	    if (b == 0) return a;
	    else return (GCD (b, a % b));
	}
	
	public static void main(String[] args) throws IOException {
		solve();
	}

	public static void solve() throws IOException {
		String inFile = "//Users//user//Documents//workspace//Runnables//src//codejam//y2014//qualification//copy//B-small-attempt5.in";
		//String outFile = "//Runnables//src//codejam//y2014//qualification//A_output";

		Scanner in = new Scanner(new FileReader(inFile));
//		FileWriter out = new FileWriter(outFile);
		int totalRounds = in.nextInt();
		for (int round = 1; round <= totalRounds; round++) {
			// FORMATTING HERE
			int B = in.nextInt();
			int you = in.nextInt();
			int[] arr = new int[B];
			for (int i = 0; i < B; i++) {
				arr[i] = in.nextInt();
			}
			System.out.format("Case #%d: ", round);
			System.out.println(solve(you, arr));
		}
		in.close();
//		out.close();
	}
}
