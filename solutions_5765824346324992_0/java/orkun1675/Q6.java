import java.util.ArrayList;
import java.util.Scanner;

public class Q6 {

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int numberOfTestCases = Integer.parseInt(s.nextLine());
		ArrayList<BarberShop> trials = new ArrayList<>();
		for (int i = 0; i < numberOfTestCases; i++) {
			BarberShop b = new BarberShop();
			String l1 = s.nextLine();
			int numOfBarbers = Integer.parseInt(l1.substring(0, l1.indexOf(" ")));
			b.placeInLine = Long.parseLong(l1.substring(l1.indexOf(" ") + 1));
			String l2 = s.nextLine();
			for (int j = 1; j < numOfBarbers; j++) {
				b.barberTimes.add(Integer.parseInt(l2.substring(0, l2.indexOf(" "))));
				l2 = l2.substring(l2.indexOf(" ") + 1);
			}
			b.barberTimes.add(Integer.parseInt(l2));
			trials.add(b);
		}
		s.close();
		
		int counter = 1;
		for (BarberShop b : trials) {
			long leastCommonMultiple = lcm(getLongArray(b.barberTimes));
			int lcmProcesses = 0;
			for (Integer i : b.barberTimes) {
				lcmProcesses += leastCommonMultiple / i;
			}
			b.placeInLine = b.placeInLine % lcmProcesses + lcmProcesses;
			if (b.placeInLine <= b.barberTimes.size()) {
				System.out.println("Case #" + counter + ": " + b.placeInLine);
				counter++;
				continue;
			}
			int[] endTimes = new int[b.barberTimes.size()];
			for (int i = 0; i < b.barberTimes.size(); i++) {
				endTimes[i] = b.barberTimes.get(i);
			}
			long customersDone = b.barberTimes.size();
			int nextSeat = getSmallestIndex(endTimes);
			while (customersDone < (b.placeInLine - 1)) {
				subtractAll(endTimes, endTimes[nextSeat]);
				endTimes[nextSeat] = b.barberTimes.get(nextSeat);
				nextSeat = getSmallestIndex(endTimes);
				customersDone++;
			}
			
			System.out.println("Case #" + counter + ": " + (nextSeat + 1));
			counter++;
		}
	}

	public static int getSmallestIndex(int[] array) {
		int smallestIndex = 0;
		for (int i = 1; i < array.length; i++) {
			if (array[i] < array[smallestIndex]) {
				smallestIndex = i;
			}
		}
		return smallestIndex;
	}
	
	public static void subtractAll(int[] array, int val) {
		for (int i = 0; i < array.length; i++) {
			array[i] = array[i] - val;
		}
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
	
	private static long lcm(long a, long b)
	{
	    return a * (b / gcd(a, b));
	}

	private static long lcm(long[] input)
	{
	    long result = input[0];
	    for(int i = 1; i < input.length; i++) result = lcm(result, input[i]);
	    return result;
	}
	
	private static long[] getLongArray (ArrayList<Integer> l) {
		long[] a = new long[l.size()];
		for (int i = 0; i < l.size(); i++) {
			a[i] = l.get(i);
		}
		return a;
	}
}
