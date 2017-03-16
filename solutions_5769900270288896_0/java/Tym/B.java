package round1B.java;

import java.util.Scanner;

public class B {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int cases = input.nextInt();
		for(int caseno = 1; caseno <= cases; caseno++)
			System.out.printf("Case #%d: %s%n", caseno, new B().solve(input));
	}

	String solve(Scanner input) {
		int r = input.nextInt(), c = input.nextInt(), n = input.nextInt();
		int m = r*c, res = 1<<30;
		for(int mask = 0; mask < 1<<m; mask++)
			if(Integer.bitCount(mask) == n)
			{
				int noise = 0;
				
				int rowmask = 3;
				for(int i = 0; i < m; i++)
					if((mask>>i & rowmask) == rowmask && i%r != r-1)
						noise++;
				
				int colmask = (1<<r) | 1;
				for(int i = 0; i < m; i++)
					if((mask>>i & colmask) == colmask)
						noise++;
				
				res = Math.min(res, noise);
			}
		
		return ""+res;
	}
}
