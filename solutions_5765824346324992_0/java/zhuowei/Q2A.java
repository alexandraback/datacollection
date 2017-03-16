import java.util.*;

public class Q2A {

	public static List<Integer> primes = sieve(100000);

	public static List<Integer> sieve(int max) {
		boolean[] s = new boolean[max + 1];
		List<Integer> out = new ArrayList<>();
		int theMax = ((int) Math.sqrt(max)) + 1;
		for (int i = 2; i <= max; i++) {
			if (s[i]) continue;
			out.add(i);
			if (i > theMax) continue;
			for (int j = i*i; j <= max; j += i) {
				s[j] = true;
			}
		}
		return out;
	}

	public static List<Integer> factor(int a) {
		List<Integer> factors = new ArrayList<>();
		for (Integer primeObj: primes) {
			int prime = primeObj;
			while(a % prime == 0) {
				factors.add(primeObj);
				a /= prime;
			}
		}
		return factors;
	}

	public static int lcm(List<Integer>[] l) {
		Map<Integer, Integer> m = new HashMap<>();
		for (List<Integer> factors: l) {
			Map<Integer, Integer> m2 = new HashMap<>();
			for (int f: factors) {
				Integer curCount = m2.get(f);
				if (curCount == null) {
					m2.put(f, 1);
				} else {
					m2.put(f, curCount + 1);
				}
			}
			for (Map.Entry<Integer, Integer> entry: m2.entrySet()) {
				Integer curCount = m.get(entry.getKey());
				if (curCount == null || curCount < entry.getValue()) {
					m.put(entry.getKey(), entry.getValue());
				}
			}
		}
		//System.out.println(m);
		int a = 1;
		for (Map.Entry<Integer, Integer> entry: m.entrySet()) {
			for (int i = 0; i < entry.getValue(); i++) {
				a *= entry.getKey();
			}
		}
		return a;
	}

	public static int solve(int[] times, int mynum) {
		List<Integer>[] factors = new List[times.length];
		for (int i = 0; i < factors.length; i++) {
			factors[i] = factor(times[i]);
		}
		int allMultiplied = lcm(factors);
		//System.out.println(Arrays.toString(times) + ":" + factors + ":" + allMultiplied);
		int serves = 0;
		for (int i: times) {
			serves += allMultiplied / i;
		}
		int newmynum = ((mynum - 1) % serves) + 1;
		return solve_newer(times, newmynum);
	}
 
	public static int solve_newer(int[] times, int mynum) {
		long[] barberRemaining = new long[times.length];
		int minIndex = 0;
		for (int i = 1; i <= mynum;) {
			// put in free barber
			long minTime = barberRemaining[0];
			minIndex = 0;
			int numberServed = 1;
			for (int b = 1; b < barberRemaining.length; b++) {
				// find the minimum timed one
				if (barberRemaining[b] < minTime) {
					minTime = barberRemaining[b];
					minIndex = b;
					numberServed = 1;
				} else if (barberRemaining[b] == minTime) {
					numberServed++;
				}
			}
			int newi = i;
			// next free barber at minTime
			for (int b = 0; b < barberRemaining.length; b++) {
				if (barberRemaining[b] == minTime) {
					barberRemaining[b] = times[b];
					//System.out.println("Serving " + newi + " with " + (b+1));
					if (newi == mynum) {
						return b;
					}
					newi++;
				} else if (barberRemaining[b] > 0) {
					barberRemaining[b] = Math.max(0, barberRemaining[b] - minTime);
				}
			}
			i += numberServed;
		}
		return minIndex;
	}

	public static int solveold(int[] times, int mynum) {
		long[] barberRemaining = new long[times.length];
		int minIndex = 0;
		for (int i = 1; i <= mynum; i++) {
			// put in free barber
			long minTime = barberRemaining[0];
			minIndex = 0;
			for (int b = 1; b < barberRemaining.length; b++) {
				// find the minimum timed one
				if (barberRemaining[b] < minTime) {
					minTime = barberRemaining[b];
					minIndex = b;
				}
			}
			// next free barber at minTime
			for (int b = 0; b < barberRemaining.length; b++) {
				if (barberRemaining[b] > 0) barberRemaining[b] = Math.max(0, barberRemaining[b] - minTime);
			}
			barberRemaining[minIndex] = times[minIndex];
		}
		return minIndex;
	}

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int cases = scan.nextInt();
		for (int casen = 0; casen < cases; casen++) {
			int barbers = scan.nextInt();
			int place = scan.nextInt();
			int[] barberTimes = new int[barbers];
			for (int i = 0; i < barberTimes.length; i++) {
				barberTimes[i] = scan.nextInt();
			}
			int barberCut = solve(barberTimes, place);
			System.out.println("Case #" + (casen + 1) + ": " + (barberCut + 1));
		}
	}
}