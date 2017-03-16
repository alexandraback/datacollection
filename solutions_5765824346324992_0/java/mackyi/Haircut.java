import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.PriorityQueue;


public class Haircut {
	public static void main(String[] args) throws NumberFormatException, IOException {
//		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		 BufferedReader br = new BufferedReader(new FileReader("B-small-attempt0.in"));
		int cases = Integer.parseInt(br.readLine());
		for(int i =0; i<cases; i++){
			String[] nums = br.readLine().split(" ");
			int B = Integer.parseInt(nums[0]);
			long N = Integer.parseInt(nums[1]);
			String[] barbers = br.readLine().split(" ");
			long[] times = new long[B];
			
			PriorityQueue<Barber> barbTimes = new PriorityQueue<>();
			for(int j = 0; j < B; j++) {
				times[j] = Integer.parseInt(barbers[j]);
				barbTimes.add(new Barber(j, times[j]));
			}
			long lcm = lcm(times);
			long modPeople = 0;
			for(int j = 0; j < B; j++) {
				modPeople+= lcm/times[j];
			}
//			System.out.println(modPeople);
			N = N % modPeople;
			if(N == 0) N = modPeople;
			
			for(int j = 0; j < N-1; j++) {
				Barber curr = barbTimes.remove();
//				System.out.println(curr.num);
				curr.currTime += curr.time;
				barbTimes.add(curr);
			}
			int myBarb = barbTimes.remove().num + 1;
			
			
//			int maxDecrease = 0;
//			int case1shrooms = 0;
//			int case2shrooms = 0;
//			for(int j = 1; j < numTimes; j++) {
//				int diff = shrooms[j-1]-shrooms[j];
////				System.out.println(diff);
//				if(diff > 0) {
//					case1shrooms += diff;
//				}
//				if(diff > maxDecrease) {
//					maxDecrease = diff;
//				}
//			}
////			System.out.println(maxDecrease);
//			for(int j = 0; j < numTimes-1; j++) {
//				if(shrooms[j] < maxDecrease) {
//					case2shrooms += shrooms[j];
//				} else {
//					case2shrooms += maxDecrease;
//				}
//			}
			System.out.println("Case #" + (i+1) +  ": " + myBarb);
		}
	}
	
	public static class Barber implements Comparable<Barber>{
		public long time;
		public int num;
		public long currTime;
		
		public Barber(int num, long time) {
			this.time = time;
			this.num = num;
			this.currTime = 0;
		}

		@Override
		public int compareTo(Barber arg0) {
			if(currTime != arg0.currTime) {
				return (int) (currTime - arg0.currTime);
			} else {
				return num - arg0.num;
			}
		}
	}
	
	public static long gcd(long a, long b)
	{
	    while (b > 0)
	    {
	        long temp = b;
	        b = a % b; // % is remainder
	        a = temp;
	    }
	    return a;
	}
	
	public static long gcd(long[] input)
	{
	    long result = input[0];
	    for(int i = 1; i < input.length; i++) result = gcd(result, input[i]);
	    return result;
	}
	
	public static long lcm(long a, long b)
	{
	    return a * (b / gcd(a, b));
	}

	public static long lcm(long[] input)
	{
	    long result = input[0];
	    for(int i = 1; i < input.length; i++) result = lcm(result, input[i]);
	    return result;
	}
	
}
