package codejam.CJ2015.R1B;

import java.util.Scanner;

public class R1BB {

	
	private static int unhappiness(int r, int c, int n){
		if(n<=(r*c+1)/2) return 0;
		if(r>c){
			int temp = r;
			r = c;
			c = temp;
		}
		int total = (r-1)*c+(c-1)*r;
		if((r>=3)&&(n>=2*(r+c-2))){// use perimeter
			if(unhappiness(r-2,c-2,(r-2)*(c-2)-n+2*(r+c-2))==0) return total - 4*((r-2)*(c-2)-n+2*(r+c-2)); // holes are disjoint
			//still gray area, let's aim for the small input
			return 2*(r+c-2)+(n-2*(r+c-2))*2;
		} else if(r>=3){
			if(r==4) return 6+(n-8); //4x4
			// now r=3
			if(n==6) return 3;
			if(c==3) return 6;
			if(n==7) return 2;
			if(n==8) return 4;
			if(c==4) return 7;
			if(n==9) return 3;
			if(n==10) return 6;
			if(n==11) return 8;
			return 2*(r+c-2)+(n-2*(r+c-2))*2;
		} else {
			if(r==2){
				if(n>c+1) return total - 3*(r*c-n);
				return 2;
			}
			// now r=1
			return total - 2*(c-n);
		}
		
		
		
	}
	
	
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		int t = in.nextInt();
		for(int i=1; i<=t; i++){
			int r = in.nextInt();
			int c = in.nextInt();
			int n = in.nextInt();			
			
			System.out.print("Case #" + i + ": ");
			System.out.print(unhappiness(r,c,n));
			System.out.println();
		}
		
		in.close();
	}
}
