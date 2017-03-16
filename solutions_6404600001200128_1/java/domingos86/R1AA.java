package codejam.CJ2015.R1A;

import java.util.Scanner;

public class R1AA {

	
	
	
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		int t = in.nextInt();
		for(int i=1; i<=t; i++){
			
			int n = in.nextInt();
			
			long leastEaten = 0;
			long secondMethod = 0;
			int eatRate = 0;
			int[] m = new int[n];
			m[0]=in.nextInt();
			
			for(int j=1; j<n; j++){
				m[j]=in.nextInt();
				if(m[j]<m[j-1]){
					leastEaten+= m[j-1]-m[j];
					if(eatRate<m[j-1]-m[j]) eatRate = m[j-1]-m[j];
				}
			}
			
			for(int j=0; j<n-1; j++) secondMethod+=(m[j]>=eatRate)? eatRate: m[j];
			
			
			System.out.print("Case #" + i + ": ");
			System.out.print(leastEaten + " " + secondMethod);
			System.out.println();
		}
		
		in.close();
	}
}
