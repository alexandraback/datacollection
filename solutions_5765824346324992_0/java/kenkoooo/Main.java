import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int t = 0; t < T; t++) {
			int B = sc.nextInt();
			int N = sc.nextInt();
			int[] M = new int[B];
			for (int i = 0; i < M.length; i++) {
				M[i] = sc.nextInt();
			}

			long common = 1;
			for (int i = 0; i < M.length; i++) {
				common *= M[i];
			}

			long incrment = 0;
			for (int i = 0; i < M.length; i++) {
				incrment += common / M[i];
			}
			N %= incrment;
			if (N == 0) {
				N += incrment;
			}

			if (N <= B) {
				System.out.println("Case #" + (t + 1) + ": " + N);
				continue;
			}
			PriorityQueue<Barber> barbers = new PriorityQueue<>();
			for (int i = 0; i < M.length; i++) {
				barbers.add(new Barber(i + 1, M[i]));
			}

			for (int i = B; i < N - 1; i++) {
				Barber poll = barbers.poll();
				barbers.add(new Barber(poll.barber_id, poll.endtime + M[poll.barber_id - 1]));
			}

			System.out.println("Case #" + (t + 1) + ": " + barbers.poll().barber_id);
		}
	}
}

class Barber implements Comparable<Barber> {
	int barber_id;
	long endtime;

	public Barber(int id, long l) {
		this.barber_id = id;
		this.endtime = l;
	}

	@Override
	public int compareTo(Barber o) {
		if (this.endtime > o.endtime) {
			return 1;
		} else if (this.endtime == o.endtime) {
			return this.barber_id - o.barber_id;
		} else {
			return -1;
		}
	}

}