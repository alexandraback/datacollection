import java.util.PriorityQueue;
import java.util.Scanner;

public class Round1A15B {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int nCases = scanner.nextInt();
		for(int z = 0; z < nCases; z++)
		{
			int nBarbers = scanner.nextInt(), nCustomers = scanner.nextInt();
			PriorityQueue<Barber> barbers = new PriorityQueue<Barber>();
			int[] times = new int[nBarbers];
			long lcm = 1;
			int gcf = 0;
			for(int i = 0; i < nBarbers; i++)
			{
				int time = scanner.nextInt();
				barbers.add(new Barber(i + 1, time));
				times[i] = time;
				lcm *= time;
				gcf = gcf(time, gcf);
			}
			for(int i = 0; i < nBarbers - 1; i++)
				lcm /= gcf;
			int cycle = 0;
			for(int i = 0; i < nBarbers; i++)
				cycle += lcm / times[i];
			
			int bound = (nCustomers - 1) % cycle;
			for(int i = 0; i < bound; i++)
			{
				Barber b = barbers.poll();
				b.timeAvailable += b.time;
				barbers.add(b);
			}
			System.out.println("Case #" + (z+1) + ": " + barbers.peek().number);
		}
		scanner.close();
	}

	static int gcf(int x, int y)
	{
		if(y == 0)
			return x;
		if(x == 1 || y == 1)
			return 1;
		if(y == 0)
			System.out.println();
		return gcf(y, x % y);
	}
}
class Barber implements Comparable<Barber>
{
	int number, time;
	long timeAvailable;
	Barber(int n, int t)
	{
		number = n;
		time = t;
		timeAvailable = 0;
	}
	
	@Override
	public int compareTo(Barber b) {
		if(timeAvailable == b.timeAvailable)
			return number - b.number;
		return Long.signum(timeAvailable - b.timeAvailable);
	}
}