package gcj;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;

public class question1 {
	static long ME, B;
	static ArrayList<Long> M;
	static ArrayList<Boolean> avail;
	static long min;
	
	public static void main(String[] args) throws FileNotFoundException, IOException {	
		String file = "small1.in";
		
		try (BufferedReader br = new BufferedReader(new FileReader(file))) {
		    String line;
		    Integer N = Integer.parseInt(br.readLine());
		    for (int n = 0; n < N; n++) {
		    	String[] BN = br.readLine().split(" ");
		    	B = Long.parseLong(BN[0]);
		    	ME = Long.parseLong(BN[1]);
		    	
		    	M = new ArrayList<Long>();
		    	avail = new ArrayList<Boolean>();
		    	min = -1;;
		    	for (String s : br.readLine().split(" ")) {
		    		long mins = Long.parseLong(s);
		    		M.add(mins);
		    		avail.add(true);
		    		if (min == -1 || mins < min) {
		    			min = mins;
		    		}
		    	}
		    	
		    	//System.out.println((min * (ME/2)));
		    	long guess = min * ME;
		    	int ret = binary(guess, (guess+1)/2, n);
		    	
		    	

				System.out.println("Case #" + (n+1) + ": " + (ret));
		    }
		}
		


	}
	
	public static int binary(long guess, long change, int n) {
		
		long served = 0;
		for (int i = 0; i < B; i++) {
			served += (guess/M.get(i)) + 1;
		}
		
		if (guess < 0) {
			served = -1;
		}
		//if (n == 4) {
		//System.out.println(guess + "  " + change + "  : " + served);
		//}
		if (served >= ME) {
			long last_served = 0;
			for (int j = 0; j < B; j++) {
				last_served += ((guess-1)/M.get(j))+1;
			}
			if (last_served < ME) {
				//System.out.println(last_served +"=="+ served);
				if (guess <= 0) {
					return (int) ME;
				}
				int my_turn = (int) (ME - last_served);
				for (int k = 0; k < B; k++) {
					if ( (guess) % M.get(k) == 0 ) {
						if (my_turn <= 1) {
							return (k+1);
						} else {
							my_turn -= 1;
						}
					}
				}
				return -2;
			} else {
				return binary(guess-change, (change+1)/2,n);
			}
		} else if (served < ME) {
			long next_served = 0;
			for (int j = 0; j < B; j++) {
				next_served += ((guess+1)/M.get(j))+1;
			}
			if (next_served >= ME) {
				//System.out.println(served +"=="+ next_served);
				if (guess <= 0) {
					return (int) ME;
				}
				int my_turn = (int) (ME - served);
				for (int k = 0; k < B; k++) {
					if ( (guess+1) % M.get(k) == 0 ) {
						if (my_turn <= 1) {
							return (k+1);
						} else {
							my_turn -= 1;
						}
					}
				}
				return -3;
			} else {
				return binary(guess + change, (change+1)/2,n);
			}
		} else {
			//long last_served = 0;
			//for (int j = 0; j < B; j++) {
			//	last_served += (guess-min)/M.get(j);
			//}
			//System.out.println(last_served == served);
			//return (int) (ME - last_served);
			return -1;
		}
	}
	
	public static int brute_force() {
		int front = 0;
		int minute = 0;
		while (front < ME) {		
			boolean assign = false;
			for (int i = 0; i < B; i++) {
				if (avail.get(i)) {
					if (front == ME-1) {
						return i;
					}
					//System.out.println(front + " to " +i);
					front++;
					avail.set(i, false);
					assign = true;
					break;
				}
			}
			if (!assign) {
				minute++;
				for (int i = 0; i < B; i++) {
					if ( minute % M.get(i) == 0) {
						avail.set(i, true);
					}
				}
			}
		}
		return -1;
	}
}
