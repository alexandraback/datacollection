import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;


public class GoogleCodeJam2015Round1AProblemB {
	public static void main(String[] args) throws IOException{
		//Scanner input = new Scanner(System.in);
		Scanner input = new Scanner(new File("B-small-attempt2.in"));
		int t = input.nextInt();
		String[] answer = new String[t];
		for(int i = 0; i < t; i++){
			int b = input.nextInt(); //number of barbers.
			int n = input.nextInt(); //you are nth person
			int[] time = new int[b];
			for(int j = 0; j < time.length; j++){
				time[j] = input.nextInt();
			}
			
			answer[i] = "" + findBarber(n, time);
		}
		
		PrintWriter out = new PrintWriter(new FileWriter("Round1AProblemBSmall2.out"));
		for(int i = 0; i < answer.length; i++){
			out.println("Case #" + (i + 1) + ": " + answer[i]); 
		}
		out.close();
		System.out.println(Arrays.toString(answer));
		System.exit(0);
/*		System.out.println(lcm(new int[]{25,25, 5, 1, 16,}));
		System.out.println(numOfCustomerPerRound(new int[]{25,25, 5, 1, 16,}));
		System.out.println(110843770 % numOfCustomerPerRound(new int[]{25,25, 5, 1, 16,}));*/
	}
	
	public static int findBarber(int n, int[] time){
		int[] originalTime = time.clone();
		int numOfCustomerPerRound = numOfCustomerPerRound(time); 
		if (n > numOfCustomerPerRound){
			n = n % numOfCustomerPerRound + + numOfCustomerPerRound;
		}
		if(n <= time.length){
			//System.out.println("less than");
			return n;
		}
		else{
			n = n - time.length;
			while(n >= 0){
				int min = findMin(time);
				for(int i = 0; i < time.length; i++){
					time[i] -= min;
				}
				System.out.println("this time: " + Arrays.toString(time));
				int numOfZero = numOfZero(time);
				if(n > numOfZero){
					System.out.println("number of barbers ready: " + numOfZero);
					n -= numOfZero;
					System.out.println("people before me: " + n);
				}
				else{
					return nthZero(time, n) + 1;
				}
				for (int i = 0; i < time.length; i++){
					if(time[i] == 0){
						//System.out.println("origianl: " + originalTime[i]);
						time[i] = originalTime[i];
					}
				}
				//System.out.println("restored time: " + Arrays.toString(time));
			}
		}
		return -1;
	}
	
	
	
	public static int findMin(int[] a){
		int min = -1;
		for(int i = 0; i < a.length; i++){
			if(min == -1 || a[i] < min){
				min = a[i];
			}
		}
		return min;
	}
	
	public static int numOfZero(int[] a){
		int sum = 0;
		for(int i = 0; i < a.length; i++){
			if(a[i] == 0) sum++;
		}
		return sum;
	}
	
	public static int nthZero(int[] a, int n){
		int count = 0;
		for(int i = 0; i < a.length; i++){
			if (a[i] == 0){
				count ++;
			}
			if (count == n){
				return i;
			}
		}
		return -1;
	}
	
	public static int lcm(int[] a){
		int result = a[0];
	    for(int i = 1; i < a.length; i++) {
	    	result = lcm(result, a[i]);
	    }
	    return result;
	}
	
	public static int lcm(int a, int b){
		return a * (b / gcf(a, b));
	}
	
	public static int gcf(int a, int b){
		while (b > 0)
	    {
	        int temp = b;
	        b = a % b; // % is remainder
	        a = temp;
	    }
	    return a;
	}
	
	public static int numOfCustomerPerRound(int[] a){
		int lcm = lcm(a);
		System.out.println("lcm: " + lcm);
		int sum = 0;
		for(int i = 0; i < a.length; i++){
			sum += lcm / a[i];
		}
		return sum;
	}
}
