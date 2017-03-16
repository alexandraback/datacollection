package round1A;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintStream;
import java.util.Scanner;


public class B {
	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(new BufferedReader(new FileReader("B.in")));
		PrintStream out = new PrintStream("B.out");
		int T = in.nextInt();
		for(int k=1; k<=T; k++){
			int B = in.nextInt();
			int[] M = new int[B];
			int N = in.nextInt();
			int max = 0;
			for(int i=0;i<B;i++){
				M[i] = in.nextInt();
				if (M[i]>max) max = M[i];
			}
			
			long l = 0;
			long r = max*((long)N-1);
			System.out.println(r);
			while (l<=r){
				long mid = (l+r)/2;
				long already = calcCustom(M,mid);
				if (already == N-1) {
					l = mid; r = mid; 
					break;
				}
				if (already<N-1) l = mid+1;
				if (already>N-1) r = mid-1;
			}
			System.out.println(l+" "+r);
			int ans = 0;
			if (l == r){
				long min = Long.MAX_VALUE;
				for(int i=0;i<B;i++)
					if ((M[i]-r%M[i])%M[i]<min){
						ans = i+1;
						min = (M[i]-r%M[i])%M[i];
					}
			}else{
				long already = calcCustom(M, r);
				long rest = N-already;
				for(int i=0;i<B;i++)
					if (r%M[i] == 0){
						rest--;
						if (rest == 0){
							ans = i+1;
							break;
						}
					}
			}
			
			
			out.println("Case #"+k+": "+ans);
		}
		in.close();
		out.close();
	}

	private static long calcCustom(int[] M, long time) {
		long sum = 0;
		for(int i=0;i<M.length;i++){
			sum += (time/M[i])+(time%M[i]>0?1:0);
		}
		return sum;
	}
}
