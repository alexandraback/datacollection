import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.PriorityQueue;

class Haircut {

	private static final class Barber implements Comparable<Barber> {
		int id;
		int time = 0;

		public Barber(int id) {
			this.id = id;
		}

		public int compareTo(Barber x) {
			return 1000*(this.time - x.time) + (this.id - x.id);
		}
	}

	public static final int gcd(int a, int b) {
		if (b == 0) return a;
		return gcd(b, a%b);
	}

	public static final int lcm(int a, int b) {
		return a*b / gcd(a, b);
	}

	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new FileReader(args[0]));
		PrintWriter out = new PrintWriter(args[1]);

		int numberOfCases = Integer.parseInt(in.readLine());
		for (int caseNumber = 1; caseNumber <= numberOfCases; caseNumber++) {
			String[] params = in.readLine().split(" ");
			int numBarbers = Integer.parseInt(params[0]);
			int myPosition = Integer.parseInt(params[1]);
			
			String[] params2 = in.readLine().split(" ");
			int[] barbers = new int[numBarbers];
			for (int i = 0; i < numBarbers; i++) {
				barbers[i] = Integer.parseInt(params2[i]);
			}

			int totalLcm = 1;
			for (int i = 0; i < numBarbers; i++) {
				totalLcm = lcm(totalLcm, barbers[i]);
			}

			int block = 0;
			for (int i = 0; i < numBarbers; i++) {
				block += totalLcm / barbers[i];
			}

			myPosition = (myPosition - 1) % block + 1;

			PriorityQueue<Barber> barberQueue = new PriorityQueue();
			for (int i = 0; i < numBarbers; i++) {
				barberQueue.add(new Barber(i));
			}

			for (int i = 1; i < myPosition; i++) {
				Barber nextBarber = barberQueue.poll();
				nextBarber.time += barbers[nextBarber.id];
				barberQueue.add(nextBarber);
			}

			int myBarber = barberQueue.poll().id + 1;

			out.println(String.format("Case #%d: %d", caseNumber, myBarber));
		}

		in.close();
		out.close();
	}
}