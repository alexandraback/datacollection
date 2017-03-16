import java.util.Scanner;


public class Barbers {
    public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int t = sc.nextInt();
    for (int i = 0; i < t; i++) {
    	
        int n = sc.nextInt();
        int place = sc.nextInt();
        int[] ar = new int[n];
        for(int j=0; j<n; j++){
        	ar[j] = sc.nextInt();
        }
        int res = b(ar,place);
        
        System.out.println("Case #"+(i+1)+": "+res);

    }
    }


	private static int b(int[] ar, int place) {
		long lc = lcm(ar);
		long ll=0;
		for(int i=0; i<ar.length;i++){
			ll += lc/ar[i];
		}
		
		if(place > ll){
			place = place % (int)ll;
			if(place == 0){
				place = (int)ll;
			}
		}
		
		if(place <= ar.length){
			return place;
		}
		
		long[] curTimes = new long[ar.length];
		for(int i=0;i<ar.length;i++){
			curTimes[i] = ar[i];
		}
		int minBarb = 0;
		for(int cur = ar.length; cur<place; cur++ ){
			minBarb = getMinBarb(curTimes);
			curTimes[minBarb]+=ar[minBarb];
		}
		return minBarb+1;
	}

	private static int getMinBarb(long[] curTimes) {
		long min = Long.MAX_VALUE	;
		int minIndex = -1;
		for(int i=0; i<curTimes.length; i++){
			if(curTimes[i]<min){
				min = curTimes[i];
				minIndex = i;
			}
		}
		return minIndex;
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

	private static long lcm(int[] ar)
	{
	    long result = ar[0];
	    for(int i = 1; i < ar.length; i++) result = lcm(result, ar[i]);
	    return result;
	}
}
