import java.util.Scanner;


public class Barber {
	public static void main(String ... orange) throws Exception
    {
        Scanner input = new Scanner(System.in);
        int numCases = input.nextInt();
        for (int n = 0; n < numCases; n++)
        {
        	int B = input.nextInt();
            int N = input.nextInt();
            
            int[] ps = new int[B]; int minTime = 999999;
            int[] load = new int[B];
            
            for (int i = 0; i < B; i++){
            	ps[i] = input.nextInt();
            	if(ps[i] < minTime) minTime=ps[i];
            }
            
            int lcm = Barber.lcm(ps);int sum = 0;
            //System.out.println("LCM = " + lcm);
            for (int i = 0; i < B; i++){
            	sum += lcm/ps[i];
            }
            N = N % sum;
            if(N == 0) N = sum;
            //System.out.println("New N = " + N);
            
            int currCustomer = 0;
            int output = -1;
            while(currCustomer < N){
            	
            	for(int i =0; i < B; i++){
            		if(load[i] == 0) {
            			currCustomer++;
            			if(currCustomer == N) {
            				output = i+1;
            				break;
            			}
            			load[i] = ps[i];
            		}
            		load[i] = load[i] -1;
            		//System.out.print(load[i] + " ");
            	}
            	//System.out.println();
            }
            
            System.out.printf("Case #%d: %d\n", n + 1, output);
        }
    }
	
	private static int gcd(int a, int b)
	{
	    while (b > 0)
	    {
	        int temp = b;
	        b = a % b; // % is remainder
	        a = temp;
	    }
	    return a;
	}

	private static int gcd(int[] input)
	{
	    int result = input[0];
	    for(int i = 1; i < input.length; i++) result = gcd(result, input[i]);
	    return result;
	}
	
	private static int lcm(int a, int b)
	{
	    return a * (b / gcd(a, b));
	}

	private static int lcm(int[] input)
	{
	    int result = input[0];
	    for(int i = 1; i < input.length; i++) result = lcm(result, input[i]);
	    return result;
	}

}
