// gengkev
// This is the brute-force solution.
// Useful for checking answers with other program, probably.

import java.io.*;
import java.util.*;

public class haircut {
	private static final boolean useStandardInput = false;
	private static final String filename = "round1A/B-small-attempt1";
	private static final boolean log = true;

	private static void run() throws IOException {
		final int T = readLineInt();

		for (int i = 1; i <= T; i++) {
			int[] input = readLineIntArray();
			final int B = input[0];
			final int N = input[1];

			int[] minutes = readLineIntArray();
			int result = calculate(N, minutes);
			output(i, String.valueOf(result));
		}
	}

	private static int calculate(final int N, final int[] minutes) {
		final int B = minutes.length; // barbers

		PriorityQueue<Event> events = new PriorityQueue<Event>();

		// people at each position
//		int[] patrons = new int[B];
//		for (int i = 0; i < B; i++) {
//			patrons[i] = -1;
//		}

		// positions that are open
		ArrayList<Integer> openPositions = new ArrayList<Integer>(B);

		int t = 0; // time
		int n = 0; // patron



		// ** BEGIN FIRST RUN **
		// add as many patrons as possible
		for (int pos = 0; pos < B; pos++) {
			// if we're at ending patron, return barber/pos
			if (n+1 == N) {
				return pos+1;
			}
			events.add(new Event(t + minutes[pos], pos));
			n++;
		}
		t++;
		// ** END FIRST RUN **



		while (true) {
			openPositions.clear();
			Event peek = events.peek();

			if (peek == null) {
				throw new IllegalStateException();
			}

			if (peek.time > t) {
				t = peek.time;
			}

			// remove all events that occur at this time
			while (peek != null && peek.time <= t) {
				events.remove();
				openPositions.add(peek.pos);
				peek = events.peek();
			}

			// all positions are open, just as at start
			// this happens after every t, then
			if (openPositions.size() == B) {
				//log("openPositions.size() = " + openPositions.size() + ", B = " + B);
				//log("reducing N = " + N + " to " + (((N-1) % n) + 1) + " with n = " + n);
				return calculate(((N-1) % n) + 1, minutes);
			}

			// add as many patrons as possible
			for (int pos : openPositions) {
				// if we're at ending patron, return barber/pos
				if (n+1 == N) {
					return pos+1;
				}
				events.add(new Event(t + minutes[pos], pos));
				n++;
			}
			t++;
		}
	}

	static class Event implements Comparable<Event> {
		public Event(int t, int p) {
			this.time = t;
			this.pos = p;
		}

		public int time; // time at which person is free
		public int pos; // position at which person is free

		public int compareTo(Event e) {
			int cmp = time - e.time;
			if (cmp != 0) return cmp;
			return pos - e.pos;
		}
	}

	// ----------------------------------------------------------------------------------------------------------------
	// competition helper methods

	private static BufferedReader reader;
	private static BufferedWriter writer;

	public static void main(String[] args) throws IOException {
		if (useStandardInput) {
			reader = new BufferedReader(new InputStreamReader(System.in));
			writer = new BufferedWriter(new StringWriter());
		} else {
			reader = new BufferedReader(new FileReader(filename + ".in"));
			writer = new BufferedWriter(new FileWriter(filename + ".out"));
		}
		run();
		reader.close();
		writer.close();
		if (!useStandardInput)
			System.out.println("FINISHED for file " + filename);
		System.exit(0);
	}

	private static String readLine() throws IOException {
		return reader.readLine();
	}
	private static int readLineInt() throws IOException {
		return Integer.parseInt(readLine());
	}
	private static int[] readLineIntArray() throws IOException {
		String[] strings = readLine().split("\\s");
		int L = strings.length;
		int[] ints = new int[L];
		for (int i = 0; i < L; i++) {
			ints[i] = Integer.parseInt(strings[i]);
		}
		return ints;
	}

	private static void output(int caseNo, String str) throws IOException {
		String output = "Case #" + caseNo + ": " + str + "\n";
		System.out.print("OUT: " + output);
		if (!useStandardInput) {
			writer.write(output);
		}
	}

	private static void log(String s) {
		if (log) System.out.println(s);
	}
	private static void log(String s, boolean newline) {
		if (log) System.out.print(s + (newline ? "\n" : ""));
	}
}
