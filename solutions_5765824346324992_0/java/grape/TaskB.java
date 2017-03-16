package round1a15.b;

import static util.io.SuperPrinter.*;

import java.util.PriorityQueue;

import util.io.InputParser;
import util.io.OutputGenerator;

public class TaskB {
	
	static final String inputFilename = "B-small-attempt1.in"; // "b-sample.in";// "B-small-attempt0.in";  // "B-large.in";  // 
	
	
	static final OutputGenerator og = new OutputGenerator("src/round1a15/out/" + inputFilename.substring(0, inputFilename.length()-3) + ".out");
	static final InputParser ip = new InputParser("src/round1a15/in/" + inputFilename, og);

	
	public static void main(String[] args) {
		final int noCases = ip.i();
		
		while(true) {
			int[] tmp = ip.ia();
			int B = tmp[0];
			int N = tmp[1];
			
			int[] times = ip.ia();
			assert(times.length == B);
			
			
			double totalThroughput = 0;   // customers served per minute
			int timeOfSlowest = max(times);
			
			
			for(int t: times) {
				totalThroughput += 1d / t;
			}
			
			int startingTimeOfCalculation = (int)(N / totalThroughput) - timeOfSlowest;
			
			
			PriorityQueue<Barber> queue = new PriorityQueue<>();
			int k=1;
			int processedCustomers = 0;
			for(int time: times) {
				Barber b = new Barber(k++, time);
				int willFinishAt = (int)(Math.ceil(startingTimeOfCalculation / (double)b.timeForHaircut) * b.timeForHaircut);
				b.availableAt = willFinishAt;
				queue.add(b);
				processedCustomers += Math.ceil(startingTimeOfCalculation / (double)b.timeForHaircut);
			}
			
				
			Barber nxtFreeBarber = null;
			for(; processedCustomers<=N-1; processedCustomers++) {
				nxtFreeBarber = queue.poll();
				nxtFreeBarber.availableAt += nxtFreeBarber.timeForHaircut;
				queue.add(nxtFreeBarber);
			}
			System.out.println(nxtFreeBarber.id);
			og.oCase(nxtFreeBarber.id);
		}
	}
	
	
	
	public static final int max(int[] arr) {
		int max = -Integer.MAX_VALUE;
		for (int i = 0; i < arr.length; i++) {
			if(arr[i] > max)
				max = arr[i];
		}
		return max;
	}
}

class Barber implements Comparable<Barber> {
	final int timeForHaircut;
	final int id;
	
	public Barber(int id, int time) {
		this.id = id;
		timeForHaircut = time;
	}
	
	int availableAt = 0;

	@Override
	public int compareTo(Barber o) {
		if(this.availableAt == o.availableAt)
			return this.id - o.id;
		else
			return this.availableAt - o.availableAt;
	}
	
	
}