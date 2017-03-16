import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Barber {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner in = new Scanner (new File("s.in"));
		//Scanner in = new Scanner (System.in);
		int cases = in.nextInt();
		for (int caseNo = 1; caseNo <= cases; caseNo++)
		{
			int res1 = 0;
			int barbers = in.nextInt();
			int psn = in.nextInt();
			int time = 0;
			
			int []times = new int [barbers];
			for (int i = 0; i < barbers; i++)
				times[i] = in.nextInt();
			
			int lcm = getLCM (times);
			//System.out.println(lcm);
			int period = 0;
			for (int i = 0; i < times.length; i++)
				period += (lcm/times[i]);
			//System.err.println(period);
			psn = psn % period;
			if (psn == 0)
				psn = period;
			
			int [] nextFree = new int[barbers];
			int served = 0;
			while (psn > served)
			{
				int freeBarber = getFree (nextFree);
				time = nextFree[freeBarber];
				served++;
				nextFree[freeBarber] += times[freeBarber];
				res1 = freeBarber + 1;
			}
			//if (res1 == 0)
			//	res1 = barbers;
			
			
			
			System.out.println("Case #" + caseNo + ": " + res1 );
		}
	}
	
	

	private static int getLCM(int[] times) {
	    int lcm = times[0];
	    for (int i = 1; i < times.length; i++)
	    {
	    	int gcd = getGCD (lcm, times[i]);
	    	lcm *= (times[i]/gcd);
	    }
		return lcm;
	}

	private static int getGCD(int x, int y) {
		int rem = x % y;
		if (rem == 0)
			return y;
		return getGCD(y, rem);
	}



	private static int getFree(int[] nextFree) {
		int result = 0;
		
		for (int i = 1; i < nextFree.length; i++)
		{
			if (nextFree[i] < nextFree[result])
				result = i;
		}
		
		return result;
	}
}
