import java.util.*;

class B {
	public static void main (String [] args) {
		Scanner sc = new Scanner(System.in);
		int numTests = sc.nextInt();
		for (int test = 1; test <= numTests; test++) {
			int numBarbers = sc.nextInt();
			long myPlaceInLine = sc.nextLong();
			int[] barberSessionLengths = new int[numBarbers];
			for (int i = 0; i < numBarbers; i++) {
				barberSessionLengths[i] = sc.nextInt();
			}
			long lo = 0;
			long hi = Long.MAX_VALUE/ 10000;
			long myBarber = -1;
			ALG:
			while (lo != hi +1) {
				long t = ((hi - lo) / 2) + lo;
				// System.out.println("t " + t + "lo " + lo + "hi " + hi);
				long numCustomersBeforeMe = numBarbers; // because they go instantly
				int numCustomersAtTimeT = 0;

				for (int i = 0; i < numBarbers; i++) {
					numCustomersBeforeMe += (t-1) / barberSessionLengths[i];
					if (t % barberSessionLengths[i] == 0) {
						numCustomersAtTimeT++;
					}
				}
				if (numCustomersBeforeMe < 0) {
					throw new IllegalArgumentException();
				}
				if (t == 0)
					numCustomersBeforeMe = 0;
				// System.out.println("Time " + t + "numCustomersBeforeMe" + numCustomersBeforeMe + "numCustomersAtTimeT" + numCustomersAtTimeT);
				if (t != 0 && myPlaceInLine <= numCustomersBeforeMe) {
					hi = t - 1;
				} else if (myPlaceInLine > numCustomersBeforeMe + numCustomersAtTimeT) {
					lo = t + 1;
				} else {
					long nthGuy = myPlaceInLine - numCustomersBeforeMe;
					for (int i = 0; i < numBarbers; i++) {
						if (t % barberSessionLengths[i] == 0) {
							--nthGuy;
							if (nthGuy == 0) {
								myBarber = i+1; // 1 -indexing
								break ALG;
							}
						}
					}
				}

			}
			System.out.printf("Case #%d: %d\n", test, myBarber);
		}
	}
}