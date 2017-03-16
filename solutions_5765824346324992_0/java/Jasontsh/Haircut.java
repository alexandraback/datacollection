import java.util.Scanner;


public class Haircut {

	public static void main(String[] args) {
		Scanner reader = new Scanner(System.in);
		int testCases = reader.nextInt();
		for(int t = 0; t < testCases; t++){
			int size = reader.nextInt();
			long pos = reader.nextLong();
			int[] time = new int[size];
			long lcm = 1;
			int diff = Integer.MAX_VALUE;
			int[] bufftime = new int[size];
			if(size > pos){
				System.out.println("Case #" + (t+1) + ": " + pos);
				continue;
			}
			pos -= size;
			for(int i = 0; i < size; i++){
				time[i] = reader.nextInt();
				lcm = lcm(lcm, time[i]);
				if(diff > time[i]){
					diff = time[i];
				}
				bufftime[i] = time[i];
			}
			long sum = 0;
			for(int i = 0; i < size; i++){
				sum += lcm / time[i];
			}
			long actualpos = pos % sum;
			if(actualpos == 0){
				actualpos += sum;
			}
			boolean gotit = false;
			int buffdif = diff;
			while(actualpos >= 0){
				for(int i = 0; i < size; i++){
					bufftime[i] -= diff;
					if(bufftime[i] <= 0){
						bufftime[i] += time[i];
						actualpos--;
					}
					if(actualpos == 0){
						System.out.println("Case #" + (t+1) + ": " + (i+1));
						gotit = true;
						break;
					}
					if(buffdif > bufftime[i]){
						buffdif = bufftime[i];
					}
					
				}
				if(gotit){
					break;
				}
				diff = buffdif;
			}
		}
		
		reader.close();
	}
	
	private static long gcd(long a, long b)
	{
	    while (b > 0)
	    {
	        long temp = b;
	        b = a % b; 
	        a = temp;
	    }
	    return a;
	}
	private static long lcm(long a, long b)
	{
	    return a * (b / gcd(a, b));
	}
}
