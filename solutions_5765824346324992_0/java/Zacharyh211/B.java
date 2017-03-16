import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.PriorityQueue;
import java.util.Scanner;

public class B {
	public static void main(String[] args) throws IOException {
		Scanner input = new Scanner(System.in);
		// PrintWriter write = new PrintWriter("B-small-attempt1.out");
		int cases = input.nextInt();
		for (int cs = 1; cs <= cases; cs++) {
			int barbers = input.nextInt();
			int spot = input.nextInt();
			int lcm = 1;
			int people = 0;
			PriorityQueue<Barber> pq = new PriorityQueue<Barber>();
			for (int i = 1; i <= barbers; i++) {
				int temp = input.nextInt();
				int temp2 = LCM(temp, lcm);
				people = temp2 / lcm * people + temp2 / temp;
				lcm = temp2;
				pq.offer(new Barber(temp, i));
			}
			spot = spot % people;
			if (spot == 0) {
				int smallest = pq.peek().incr;
				Barber x = pq.poll();
				while(!pq.isEmpty() && pq.peek().incr == smallest)
					x = pq.poll();
				System.out.printf("Case #%d: %d%n", cs, x.id);
			}
			else
				for (int i = 1; i <= spot; i++) {
					Barber temp = pq.poll();
					temp.update();
					pq.offer(temp);
					if (i == spot) {
						System.out.printf("Case #%d: %d%n", cs, temp.id);
					}
				}
		}
	}

	public static int LCM(int a, int b) {
		return a / gcd(a, b) * b;
	}

	public static int gcd(int a, int b) {
		while (b != 0) {
			int t = b;
			b = a % b;
			a = t;
		}
		return a;
	}
}

class Barber implements Comparable<Barber> {
	int incr;
	int time;
	int id;

	public Barber(int i, int t) {
		incr = i;
		time = 0;
		id = t;
	}

	public int compareTo(Barber other) {
		int temp = Integer.compare(this.time, other.time);
		if (temp == 0)
			return Integer.compare(this.id, other.id);
		else
			return temp;
	}

	public void update() {
		time += incr;
	}
	
	public String toString() {
		return id + ":" + incr;
	}
}