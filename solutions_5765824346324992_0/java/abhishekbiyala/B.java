import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class B {

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		String fileName = "B-small-attempt1";
		Scanner in = new Scanner(new File(fileName + ".in"));
		PrintWriter out = new PrintWriter(new FileWriter(fileName + ".out"));
		
		int T = in.nextInt();
		
		for(int i=1; i<=T; i++) {
			out.println("Case #" + i + ": " + solve(in));
		}
		
		in.close();
		out.close();
	}

	private static String solve(Scanner in) {
		
		int B = in.nextInt();
		long N = in.nextLong();
		int[] M = new int[B];
		long[] queue = new long[B];
		
		for(int k=0; k<B; k++) {
			M[k] = in.nextInt();
			queue[k] = 0;
		}
		
		int lcm = lcm(M);
		long totDiv = 0;
		for(int k=0; k<B; k++) {
			totDiv += lcm/M[k];
		}
		
//		System.out.println("Orig N=" + N + ", totDiv=" + totDiv);
		N = N % totDiv;
		if(N == 0) {
			N = totDiv;
		}
//		System.out.println("New N=" + N);
				
		int queueIdx = 0;
		for(long i=0; i<N; i++) {
			
			// check which queue is the shortest
			queueIdx = 0;
			long shortest = queue[0];
			for(int j=1; j<B; j++) {
				if(queue[j] < shortest) {
					shortest = queue[j];
					queueIdx = j;
				}
			}
			
//			System.out.println("cust: " + (i+1) + ", barber: " + (queueIdx+1));
			queue[queueIdx] += M[queueIdx];
		}
		
		return String.valueOf(queueIdx+1);
	}
	
	private static int gcd(int a, int b) {
	    while (b > 0) {
	        int temp = b;
	        b = a % b;
	        a = temp;
	    }
	    return a;
	}

	private static int lcm(int a, int b) {
	    return a * (b / gcd(a, b));
	}

	private static int lcm(int[] input) {
	    int result = input[0];
	    for(int i = 1; i < input.length; i++) result = lcm(result, input[i]);
	    return result;
	}
}
