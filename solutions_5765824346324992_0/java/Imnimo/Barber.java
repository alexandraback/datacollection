import java.io.File;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Scanner;


public class Barber {
	public static void main(String[] args) throws Exception {
		Scanner s = new Scanner(new File("B-small-attempt1.in"));
		int numCases = Integer.parseInt(s.nextLine());
		for(int currentCase = 1;currentCase<=numCases;currentCase++) {
			String bandn = s.nextLine();
			String[] bandnArr = bandn.split("\\s+");
			int b = Integer.parseInt(bandnArr[0]);
			long n = Long.parseLong(bandnArr[1]);
			String barbers = s.nextLine();
			String[] barbersArr = barbers.split("\\s+");
			int[] m = new int[b];
			for(int i = 0;i<b;i++) {
				m[i] = Integer.parseInt(barbersArr[i]);
			}
			System.out.println("Case #" + currentCase + ": " + (findBarber(m,n)+1));
		}
		
	}
	public static int findBarber(int[] m, long n) {
		n--;
		
		//System.out.println("Starting n: " + n);
		
		long lcm = getLCM(m);
		
		
		long numServicedInRound = 0;
		for(int x : m) {
			numServicedInRound += lcm/x;
		}
		
		n%=numServicedInRound;
		
		
		
		///System.out.println(Arrays.toString(m) + " LCM: " + lcm + " NUMSERVICED: " + numServicedInRound);
		//System.out.println("N is now " + n);
		
		
		PriorityQueue<HairCut> queue = new PriorityQueue<HairCut>();
		for(int i = 0;i<m.length;i++) {
			HairCut hc = new HairCut(i,0);
			queue.add(hc);
		}
		int currentCustomer = 0;
		while(true) {
			//System.out.println(currentCustomer + " " + queue);
			HairCut finished = queue.remove();
			if(currentCustomer == n) {
				return finished.barberID;
			} else {
				HairCut hc = new HairCut(finished.barberID,finished.endTime + m[finished.barberID]);
				queue.add(hc);
			}
			currentCustomer++;
		}
	}
	
	public static long getLCM(int[] m) {
		long lcm = 1;
		for(int x : m) {
			lcm = lcm(lcm,x);
		}
		return lcm;
	}
	public static long lcm(long a, long b) {
		return (a * b)/gcd(a,b);
	}
	public static long gcd(long a, long b) {
		if(b==0) return a;
		return gcd(b, a % b);
	}
	
}
class HairCut implements Comparable<HairCut> {
	int barberID;
	int endTime;
	public HairCut(int b, int t) {
		barberID = b;
		endTime = t;
	}
	@Override
	public int compareTo(HairCut arg0) {
		
		if(endTime==arg0.endTime) {
			return Integer.valueOf(barberID).compareTo(arg0.barberID);
		}
		
		return Integer.valueOf(endTime).compareTo(arg0.endTime);
	}
	
}


 