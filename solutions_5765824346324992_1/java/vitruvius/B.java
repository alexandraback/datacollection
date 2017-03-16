import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class B {

	public static void main(String[] args) throws Exception {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(bf.readLine());
		for (int tc = 1; tc <= T; tc++) {
			StringTokenizer st = new StringTokenizer(bf.readLine());
			int b = Integer.parseInt(st.nextToken());
			long n = Long.parseLong(st.nextToken());
			long[] m = new long[b];
			st = new StringTokenizer(bf.readLine());
			long min = -1;
			for (int i = 0; i < b; i++) {
				m[i] = Integer.parseInt(st.nextToken());
				if (min == -1 || m[i] < min) {
					min = m[i];
				}
			}

			// at best, we could be served at t=0
			// at worst, there might only be one barber, so we'd be served at t=n*m[0]
			int barber = binSearch(m, n, 0, n * min);

			System.out.println("Case #" + tc + ": " + barber);
		}
	}

	private static int binSearch(long[] m, long n, long lo, long hi) {
		// we're looking for the point at which numServed(t) >= n, but numServed(t-1) < n
		// System.out.println("searching in range t=[" + lo + ", " + hi + "]");
		long mid = (lo + hi) / 2L;
		long numPrev = numServed(m, mid - 1);
		long numCur = numServed(m, mid);

		if (numCur >= n && numPrev < n) {
			// return the barber number

			// System.out.println("Found the barber at t=" + mid);
			// System.out.println("numPrev: " + numPrev);
			// System.out.println("numCur: " + numCur);
			long indexInQueue = n - numPrev;
			for (int i = 0; i < m.length; i++) {
				if (mid % m[i] == 0) {
					if (indexInQueue == 1) {
						return (i + 1);
					}
					indexInQueue--;
				}
			}
		} else {
			if (numPrev >= n) {
				// too high
				return binSearch(m, n, lo, mid);
			} else {
				// too low
				return binSearch(m, n, mid, hi);
			}
		}

		return -1;
	}

	private static long numServed(long[] m, long t) {
		long total = 0;
		for (int i = 0; i < m.length; i++) {
			total += 1L + t / m[i];
		}
		return total;
	}
}
