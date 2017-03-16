import java.util.PriorityQueue;
import java.util.Scanner;

public class Round1A15B {
	final static double EPSILON = 1e-11;
	
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int nCases = scanner.nextInt();
		for(int z = 0; z < nCases; z++)
		{
			int nBarbers = scanner.nextInt(), nCustomers = scanner.nextInt();
			int[] times = new int[nBarbers];
			double totalRate = 0;
			for(int i = 0; i < nBarbers; i++)
			{
				int time = scanner.nextInt();
				times[i] = time;
				totalRate += 1d / time;
			}
			
			//compute the progress made by each barber, about nBarbes+1 people before our turn
			//we will then trace exactly who gets which barber
			double totalTime = Math.max(nCustomers - 1 - nBarbers, 0) / totalRate;
			//count how many will be finished when the in-progress ones are completed
			int start = 0;
			PriorityQueue<Barber> barbers = new PriorityQueue<Barber>();
			for(int i = 0; i < nBarbers; i++)
			{
				start += Math.ceil(totalTime / times[i] - EPSILON);
				double minutesLeft = -(totalTime % times[i]);
				if(minutesLeft < -EPSILON)
					minutesLeft += times[i];
				barbers.add(new Barber(i + 1, times[i], minutesLeft));
			}
			
			int bound = nCustomers - 1 - start;
			for(int i = 0; i < bound; i++)
			{
				Barber b = barbers.poll();
				b.availableTime += b.time;
				barbers.add(b);
			}
			
			System.out.println("Case #" + (z+1) + ": " + barbers.peek().number);
		}
		scanner.close();
	}
}
class Barber implements Comparable<Barber>
{
	int number, time;
	double availableTime;
	Barber(int n, int t, double a)
	{
		number = n;
		time = t;
		availableTime = a;
	}
	
	@Override
	public int compareTo(Barber b) {
		if(Math.abs(availableTime - b.availableTime) < Round1A15B.EPSILON)
			return number - b.number;
		return (int) Math.signum(availableTime - b.availableTime);
	}
}