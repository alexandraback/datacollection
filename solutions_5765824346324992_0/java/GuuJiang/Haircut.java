package codejam2015.round1a;

import java.io.FileInputStream;
import java.io.PrintStream;
import java.util.PriorityQueue;
import java.util.Scanner;
import static org.apache.commons.math3.util.ArithmeticUtils.*;

public class Haircut {
	Scanner cin;
	
	public void solveAll() {
		cin = new Scanner(System.in);
		int t = cin.nextInt();
		for (int i = 1; i <= t; ++i) {
			System.out.printf("Case #%d: %d\n", i, solve());
		}
	}
	
	private int solve() {
		int b = cin.nextInt();
		int n = cin.nextInt();
		
		PriorityQueue<Barber> q = new PriorityQueue<Barber>();
		
		int[] m = new int[b];
		int l = 1;
		for (int i = 0; i < b; ++i) {
			m[i] = cin.nextInt();
			Barber barber = new Barber();
			barber.number = i + 1;
			barber.interval = m[i];
			q.add(barber);
			l = lcm(l, m[i]);
		}
		
		int run = 0;
		for (int i = 0; i < b; ++i) {
			run += l / m[i];
		}
		
		for (int i = 0; i < (n - 1) % run; ++i) {
			Barber barber = q.poll();
			barber.nexttime += barber.interval;
			q.add(barber);
		}
		
		return q.poll().number;
	}

	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream("B-small-attempt1.in"));
		System.setOut(new PrintStream("B-small.out"));
		new Haircut().solveAll();
	}
}

class Barber implements Comparable<Barber> {
	int number;
	int interval;
	int nexttime;
	
	@Override
	public int compareTo(Barber o) {
		if (nexttime != o.nexttime) {
			return nexttime - o.nexttime;
		} else {
			return number - o.number;
		}
	}
}