package round1A;

import java.io.File;
import java.io.PrintWriter;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Problem2 {
	private static String inputFile = "/Users/Tuan/workspace/CodeJam/B-small-attempt1.in";
	private static String outputFile = "/Users/Tuan/workspace/CodeJam/problem2_out.txt";
	
	public static void main(String[] args) throws Exception{
		
		
		
		PrintWriter pw = new PrintWriter(outputFile);
		File file = new File(inputFile);
		Scanner scan = new Scanner(file);
		int t = scan.nextInt();
		for(int z = 0; z < t; z++){
			int b = scan.nextInt();
			long n = scan.nextLong();
			long[] a = new long[b];
			for(int i = 0; i < b; i++){
				a[i] = scan.nextLong();
			}
			//System.out.printf("Case #%d: %d\n",(z+1),determine(a,n));
			pw.printf("Case #%d: %d\n",(z+1),determine(a,n));
		}
		scan.close();
		pw.close();
		
	}
	
	private static int determine(long[] a, long n){
		
		PriorityQueue<Barber> barbers = new PriorityQueue<Barber>();
		
		for(int i = 0; i < a.length; i++){
			barbers.add(new Barber(i,0));
		}
		
		long leastCommon = lcm(a);
		//
		int oneRound = 0;
		for(int i = 0; i < a.length; i++){
			oneRound += leastCommon / a[i];
		}
		//
		
		n = n % oneRound + oneRound;
		
		Barber b = barbers.peek();
		for(int i = 0; i < n ; i++){
			//retrieve lowest id and free barber
			b = barbers.poll();
			//make him busy by adding time
			b.value += a[b.id];
			//add back into the queue
			barbers.add(b);
		}
		return (b.id + 1);		

	}
	////////////////////////
	private static long gcd(long a, long b){	
	    while (b > 0){	    
	        long temp = b;
	        b = a % b; // % is remainder
	        a = temp;
	    }
	    return a;
	}
	private static long lcm(long a, long b){
		    return a * (b / gcd(a, b));
	}

	private static long lcm(long[] input){
	
	    long result = input[0];
	    for(int i = 1; i < input.length; i++) result = lcm(result, input[i]);
	    return result;
	}
	///////
	
	private static class Barber implements Comparable<Barber>{
		int id;
		long value;

		public Barber(int id, long value){
			this.id = id;
			this.value = value;
		}
		
		@Override
		public int compareTo(Barber arg0) {
			if (value < arg0.value){
				return -1;
			}else if (value > arg0.value){
				return 1;
			}else{
				if (id < arg0.id){
					return -1;
				}else{
					return 1;
				}
			}			
			
		}
		
	}
}
