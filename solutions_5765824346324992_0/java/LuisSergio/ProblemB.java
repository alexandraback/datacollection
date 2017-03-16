import java.io.BufferedWriter;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Scanner;

import com.google.common.math.IntMath;

public class ProblemB {

	private static BufferedWriter writer;
	private static Scanner scanner;

	static class Barber {
		int id;
		int time;
		int currentTime;
		boolean busy;

		int getTime() {
			return time;
		}
		@Override
		public String toString() {
			return String.valueOf(time);
		}
	}

	private static int b;
	private static int n;
	private static Barber barbers[];
	private static int times[];

	private static int barber;

	private static void processCase(int i) throws IOException {
		readInput();
		solve();
		outputResults(i);
	}

	private static void outputResults(int testCase) throws IOException {
		String out = String.format("Case #%d: %d", testCase + 1, barber);
		System.err.println(out);
		writer.write(out);
		writer.newLine();
	}

	static int free;
	static int minimumTime;

	private static void solve() {

		int lcm = lcmofarray(times, 0, times.length);
		int customersPerCycle = 0;
		for(int t : times) {
			customersPerCycle += lcm/t;
		}

		int position = n % customersPerCycle; 
		if (position == 0) {
			position = customersPerCycle;
		}
		n = position;
		if (barbers.length== 1) {
			barber = 1;
			return;
		}
		

		if (position <= barbers.length) {
			barber = barbers[n - 1].id;
			return;
		}

		while (position > 0) {			
			minimumTime = 0;
			// ocupy as many barbers as needed
			for (int i = 0; i < barbers.length; i++) {
				if (!barbers[i].busy) {
					barbers[i].busy = true;
					barbers[i].currentTime = barbers[i].time;
					--position;
					if (position == 0) {
						barber = barbers[i].id;
						return;
					}
				}
			}
			// find min time
			int minimumTime = barbers[0].currentTime;
			for (Barber b : barbers) {
				if (b.currentTime < minimumTime && b.busy){
					minimumTime = b.currentTime;
				}
			}
			
			// decrease min time of all barbers
			for(Barber b: barbers) {
				b.currentTime -= minimumTime;
				if (b.currentTime == 0){
					b.busy = false;
				}
			}
		}
	}

	private static void readInput() {
		b = scanner.nextInt();
		n = scanner.nextInt();
		barbers = new Barber[b];
		times = new int[b];
		for (int i = 0; i < b; i++) {
			barbers[i] = new Barber();
			barbers[i].id = i + 1;
			barbers[i].time = barbers[i].currentTime = times[i] = scanner
					.nextInt();
		}
	}

	public static void main(String[] args) throws IOException {
		Path input = Paths.get("input.txt");
		Path output = Paths.get("output.txt");
		scanner = new Scanner(input);
		writer = Files.newBufferedWriter(output);
		int testCases = scanner.nextInt();
		for (int i = 0; i < testCases; i++) {
			processCase(i);
		}
		writer.close();

	}

	public static int gcd(int a, int b) {
		if (a < b)
			return gcd(b, a);
		if (a % b == 0)
			return b;
		else
			return gcd(b, a % b);
	}

	public static int lcm(int a, int b) {
		return ((a * b) / gcd(a, b));

	}

	public static int lcmofarray(int[] arr, int start, int end) {
		if ((end - start) == 1)
			return lcm(arr[start], arr[end - 1]);
		else
			return (lcm(arr[start], lcmofarray(arr, start + 1, end)));
	}

}
