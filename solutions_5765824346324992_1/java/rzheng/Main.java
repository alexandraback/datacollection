import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {
	private static int B[], N;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int i = 1; i <= T; i++) {
			B = new int[sc.nextInt()];
			N = sc.nextInt();
			int min = Integer.MAX_VALUE;
			for (int j = 0; j < B.length; j++) {
				B[j] = sc.nextInt();
				min = Math.min(min, B[j]);
			}
			System.out.println("Case #" + i + ": " + binarySearch(0, (long) min * N));
		}
		sc.close();
	}

	private static int binarySearch(long left, long right) {
		long mid = (left + right) / 2;
		long count = 0;
		for (int M : B) {
			count += mid / M + (mid % M == 0 ? 0 : 1);
		}
		if (count >= N) {
			return binarySearch(left, mid - 1);
		} else if (count < N - B.length) {
			return binarySearch(mid + 1, right);
		} else {
			long max = 0;
			int sum = 0;
			PriorityQueue<Barber> pq = new PriorityQueue<Barber>();
			for (int j = 0; j < B.length; j++) {
				pq.add(new Barber(j, B[j], mid / B[j] * B[j]));
				max = Math.max(max, mid / B[j] * B[j]);
			}
			for (int j = 0; j < B.length; j++) {
				sum += max / B[j];
			}
			for (int j = sum; j < N - 1; j++) {
				Barber barber = pq.remove();
				barber.time += barber.M;
				pq.add(barber);
			}
			if (sum == N) {
				return B.length;
			}
			return 1 + pq.remove().B;
		}
	}

	private static class Barber implements Comparable<Barber> {
		private int B;
		private int M;
		private long time;

		private Barber(int B, int M, long time) {
			this.B = B;
			this.M = M;
			this.time = time;
		}

		public int compareTo(Barber o) {
			if (time < o.time) {
				return -1;
			} else if (time > o.time) {
				return 1;
			} else {
				return B - o.B;
			}
		}
	}
}