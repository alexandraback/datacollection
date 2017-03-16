import java.io.File;
import java.io.PrintStream;
import java.util.PriorityQueue;
import java.util.Scanner;

public class B {
	static final Boolean SAMPLE = false;
	static final String PROBLEM = "B";
	static final String INPUT = "small";
	static final String ID = "0";
	static final String PATH = "/Users/wangkai/Documents/codejam-commandline-1.2-beta1/source/";

	public static void main(String[] args) throws Throwable {
		Scanner in = SAMPLE ? new Scanner(System.in) : new Scanner(new File(
				PATH + PROBLEM + "-" + INPUT + "-" + ID + ".in"));
		PrintStream out = SAMPLE ? System.out : new PrintStream(PATH + PROBLEM
				+ "-" + INPUT + "-" + ID + ".out");

		int test = in.nextInt();
		for (int t = 1; t <= test; t++) {
			out.print("Case #" + t + ": ");

			int B = in.nextInt();
			int N = in.nextInt();
			int[] minutes = new int[B];
			for (int i = 0; i < minutes.length; i++) {
				minutes[i] = in.nextInt();
			}

			int commonMinute = lcm(minutes);
			int commonPeople = 0;
			for (int minute : minutes) {
				commonPeople += commonMinute / minute;
			}
			int person = (N - 1) % commonPeople;

			Barber[] barbers = new Barber[B];
			for (int i = 0; i < barbers.length; i++) {
				barbers[i] = new Barber(i, 0);
			}

			PriorityQueue<Barber> pq = new PriorityQueue<Barber>();
			for (Barber barber : barbers) {
				pq.offer(barber);
			}

			for (int i = 0; i < person; i++) {
				Barber head = pq.poll();

				for (Barber barber : pq) {
					barber.timeLeft -= head.timeLeft;
				}

				pq.offer(new Barber(head.index, minutes[head.index]));
			}

			out.println(pq.peek().index + 1);
		}

		out.close();
		in.close();

		System.out.println("finish!");
	}

	static int lcm(int[] numbers) {
		int common = gcd(numbers);
		int result = common;
		for (int number : numbers) {
			result *= number / common;
		}
		return result;
	}

	static int gcd(int[] numbers) {
		int common = numbers[0];
		for (int i = 1; i < numbers.length; i++) {
			common = gcd(common, numbers[i]);
		}
		return common;
	}

	static int gcd(int a, int b) {
		while (b != 0) {
			int c = a % b;
			a = b;
			b = c;
		}
		return a;
	}
}

class Barber implements Comparable<Barber> {
	int index;
	int timeLeft;

	Barber(int index, int timeLeft) {
		this.index = index;
		this.timeLeft = timeLeft;
	}

	@Override
	public int compareTo(Barber other) {
		if (timeLeft != other.timeLeft) {
			return timeLeft - other.timeLeft;
		}
		return index - other.index;
	}
}