import java.awt.Point;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;

public class b {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int cases = in.nextInt();

		int cn = 0;

		while (cn++ < cases) {
			int barbers = in.nextInt();
			int pos = in.nextInt() - 1;

			int lcm = 1;
			int[] speeds = new int[barbers];
			for (int i = 0; i < speeds.length; i++) {
				speeds[i] = in.nextInt();
				int gcd = gcd(lcm, speeds[i]);
				lcm /= gcd;
				lcm *= speeds[i];
			}

			int used = 0;
			for (int i = 0; i < speeds.length; i++) {
				used += (lcm / speeds[i]);
			}

			pos %= used;

			PriorityQueue<Point> pq = new PriorityQueue<Point>(barbers,
					new Comparator<Point>() {
						@Override
						public int compare(Point o1, Point o2) {
							if (o1.x == o2.x)
								return Integer.compare(o1.y, o2.y);
							else
								return Integer.compare(o1.x, o2.x);
						}
					});

			for (int i = 0; i < barbers; i++) {
				pq.add(new Point(0, i));
			}

			while (pos > 0) {
				Point here = pq.poll();
				here.x += speeds[here.y];
				pq.add(here);
				pos--;
			}

			System.out.printf("Case #%d: %d\n", cn, pq.poll().y + 1);

		}
	}

	private static int gcd(int a, int b) {

		while (b > 0) {
			int t = a % b;
			a = b;
			b = t;
		}
		return a;
	}
}
