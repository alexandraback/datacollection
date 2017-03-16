import java.io.File;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Haircut {

	static PrintWriter writer;

	public static void main(String[] args) throws Exception {
		writer = new PrintWriter("out.txt", "UTF-8");
		Scanner sc = new Scanner(new File("in.txt"));
		int T = sc.nextInt();
		for (int t = 0; t < T; t++) {
			// -------------------------------------------------------------------------------------
			int B = sc.nextInt();
			int N = sc.nextInt();
			long[] M = new long[B];

			for (int b = 0; b < B; b++) {
				M[b] = sc.nextInt();
			}
			
			//how many customers does it take to repeat?
			long lcm = lcm(M);
			int tot = 0;
			for (int i = 0; i < B; i++) {
				tot += lcm / M[i];
			}

			//int start at repeat
			long start = (N / tot) * tot+1;
			System.out.println(tot + "\t" + lcm + "\t" + start);
start=Math.max(1,start-tot);
			
//			System.out.println(tot + "\t" + lcm + "\t" + start);
			PriorityQueue<BB> q = new PriorityQueue<>();
			for (int b = 0; b < B; b++) {
				q.add(new BB(b + 1, 0, M[b]));
			}
			BB bb = null;
				for (long i = start; i < N + 1; i++) {
					bb = q.poll();
					//System.out.println(i + "\t" + bb);
					bb.time += bb.add;
					q.add(bb);
				}

				
//				System.out.println("_________");
//				q.clear();
//				for (int b = 0; b < B; b++) {
//					q.add(new BB(b + 1, 0, M[b]));
//				}
//				for (int i = 1; i < N+1; i++) {
//					bb = q.poll();
//					//System.out.println(i + "\t" + bb);
//					bb.time += bb.add;
//					q.add(bb);
//				}
				
				
				out(t, (bb.barber) + "");
				System.out.println("____________________________");

			// -------------------------------------------------------------------------------------
		}
		writer.flush();
		writer.close();
		sc.close();
	}

	private static long gcd(long a, long b) {
		while (b > 0) {
			long temp = b;
			b = a % b;
			a = temp;
		}
		return a;
	}

	private static long lcm(long[] input) {
		long result = input[0];
		for (int i = 1; i < input.length; i++)
			result = lcm(result, input[i]);
		return result;
	}

	private static long lcm(long a, long b) {
		return a * (b / gcd(a, b));
	}

	public static void out(int t, String out) {
		String s = "Case #" + (t + 1) + ": " + out;
		System.out.println(s);
		writer.println(s);
	}

}

class BB implements Comparable<BB> {
	int barber = 0;
	long time;
	long add = 0;

	public BB(int barber, long lcm, long m) {
		super();
		this.barber = barber;
		this.time = lcm;
		this.add = m;
	}

	@Override
	public String toString() {
		return "BB [barber=" + barber + ", time=" + time + "]";
	}

	@Override
	public int compareTo(BB o) {
		if (time == o.time)
			return Integer.compare(barber, o.barber);
		else
			return Long.compare(time, o.time);
	}

}