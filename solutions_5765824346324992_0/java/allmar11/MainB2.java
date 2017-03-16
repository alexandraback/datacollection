package gcj2015.round1A.problemB;

import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;

public abstract class MainB2 {

	public static void main(String[] args) throws Exception {
		// Open input and output files. (stdin and stdout are not used because
		// of the lack of support for using a file as stdin in Eclipse.)
		InputStream inStream = new FileInputStream(
			"input/B-small-attempt0.in");
		OutputStream outStream = new FileOutputStream(
			"output/B-small-attempt0-out.txt");
		
		Scanner in = new Scanner(new BufferedInputStream(inStream));
		PrintWriter out = new PrintWriter(new BufferedOutputStream(outStream));
		
		int numCases = in.nextInt();
		for (int caseIdx = 1; caseIdx <= numCases; caseIdx++) {
			
			int numBarbers = in.nextInt();
			int numCustomers = in.nextInt();
			int[] barbTimes = new int[numBarbers];
			for (int i = 0; i < numBarbers; i++) {
				barbTimes[i] = in.nextInt();
			}
			
			// Solve this test case;
			int result = solve(barbTimes, numCustomers);
			
			// Print the result.
			String resultStr = "" + result;
			String fullResultStr = String.format("Case #%s: %s", caseIdx,
				resultStr);
			out.println(fullResultStr);
			System.out.println(fullResultStr);
		}
		
		in.close();
		out.close();
	}
	
	private static int solve(int[] barbTimes, int numCustomers) {
		int numBarbers = barbTimes.length;
		
		if (numCustomers <= numBarbers) {
			return numCustomers;
		}
		
		// Estimate the time until the number of customers is less than the
		// number of barbers.
		double custRate = 0.0;
		for (int barbTime : barbTimes) {
			custRate += 1.0 / barbTime;
		}
		double estTime = (numCustomers - numBarbers) / custRate;
		
		// Start the simulation some time before the above estimate. (The above
		// estimate is never an overestimate, so this should result in the
		// simulation starting at a point in time where every barber has a
		// customer.)
		int currentTime = (int) (Math.floor(estTime) - 1);
		int[] numBarbed = new int[numBarbers];
		int[] timeUntilNextCust = new int[numBarbers];
		int numCustomersLeft = numCustomers;
		for (int i = 0; i < numBarbers; i++) {
			numBarbed[i] = ((currentTime) / barbTimes[i]) + 1;
			timeUntilNextCust[i] = (currentTime % barbTimes[i] == 0) ?
				barbTimes[i] : barbTimes[i] - (currentTime % barbTimes[i]);
			numCustomersLeft -= numBarbed[i];
		}
		assert(numCustomersLeft > 0);
		
		// Run the simulation from this current point in time.
		PriorityQueue<Event> eventQueue = new PriorityQueue<Event>(
			new Comparator<Event>() {
				@Override
				public int compare(Event ev0, Event ev1) {
					int timeCompare = ev0.time - ev1.time;
					return (timeCompare == 0) ?
						(ev0.barber - ev1.barber) : timeCompare;
				}
		});
		
		int mostRecentBarber = -1;
		
		for (int i = 0; i < barbTimes.length; i++) {
			Event event = new Event();
			event.time = currentTime + timeUntilNextCust[i];
			event.barber = i;
			eventQueue.add(event);
		}
		
		while (numCustomersLeft > 0) {
			
			// Current event: A barber becomes able to accept a new customer.
//			Event currEvent = eventQueue.remove();
//			numCustomersLeft--;
//			Event nextEvent = new Event();
//			nextEvent.time = currEvent.time + barbTimes[currEvent.barber];
//			nextEvent.barber = currEvent.barber;
//			eventQueue.add(nextEvent);
			Event currEvent = eventQueue.remove();
			numCustomersLeft--;
			mostRecentBarber = currEvent.barber;
			currEvent.time += barbTimes[currEvent.barber];
			eventQueue.add(currEvent);
		}
		
		return mostRecentBarber + 1;
	}
	
	private static class Event {
		int time;
		int barber;
	}
}
