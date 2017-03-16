import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Scanner;


public class Haircut {

	public static void main(String[] args) {
		InputData input = new InputData(2);
		List<String> inputLines = input.getLines();
		List<String> outputCases = new ArrayList<String>();
		Iterator<String> iterator = inputLines.iterator();
		while (iterator.hasNext()) {
			String topline = iterator.next();
			Scanner topScanner = new Scanner(topline);
			int b = Integer.parseInt(topScanner.next()); //number of barbers.
			int n = Integer.parseInt(topScanner.next()); //my place in line.
			topScanner.close();
			String barberDurations = iterator.next();
			PriorityQueue<Barber> barbers = new PriorityQueue<Barber>(b);
			Barber[] barbersArray = new Barber[b]; //for temporary storage of Barbers.
			int[] durationsArray = new int[b];
			Scanner barberScanner = new Scanner(barberDurations);
			for (int i = 0; i < b; i++) {
				durationsArray[i] = Integer.parseInt(barberScanner.next());
				barbersArray[i] = new Barber(i + 1, durationsArray[i]);
				barbers.add(barbersArray[i]);
			}
			barberScanner.close();
			/*
			 * Reducing the problem...:
			 */
			int lcm = lcm(durationsArray);
			int cycleLength = 0; //number of customers before all barbers are free again simultaneously.
			for (int duration : durationsArray) {
				cycleLength += lcm/duration;
			}
			n = n % cycleLength; //ignore as many customers as possible irrelevant to the problem.
			if (n == 0) n = cycleLength; //needs to be at least 1.
			/*
			 * Invariants:
			 * i is the number of the current customer being seated;
			 * There is at least one barber free;
			 * No barber has been waiting for a customer for any time, since the start, at all;
			 * All customers have been seated per the policy (first available barber);
			 */
			for (int i = 1; i < n; i++) {
				Barber nextBarber = barbers.poll(); //get first free barber.
				nextBarber.assign(); //assign customer i to this barber.
				barbers.add(nextBarber); //put back in queue.
				//Now rebuild the queue after waiting for a barber to finish.
				int timeToWait = barbers.peek().getTimeLeft(); //smallest amount of time left.
				if (timeToWait != 0) {
					barbers.clear();
					for (Barber barber : barbersArray) {
						barber.elapseTime(timeToWait);
						barbers.add(barber);
					}
				}
			}
			//now it is me (n) being assigned a barber.
			int myBarber = barbers.poll().getIndex(); //index of first available barber.
			outputCases.add(myBarber + "");
		}
		
		
		for (int i = 0; i < outputCases.size(); i++) {
			System.out.println("Case #" + (i+1) + ": " + outputCases.get(i));
		}
	}
	
	
	
	private static int gcd(int a, int b) {
		while (b > 0) {
			int temp = b;
			b = a % b;
			a = temp;
		}
		return a;
	}
	
	private static int lcm(int a, int b) {
		if (a == b) return a;
		else return a * (b / gcd(a, b));
	}

	/**
	 * Least common multiple of an array of integers
	 * @param input array of ints to find lcm of.
	 * @return LCM(input).
	 */
	private static int lcm(int[] input) {
		int result = input[0];
		for (int i = 1; i < input.length; i++)
			result = lcm(result, input[i]);
		return result;
	}

}
