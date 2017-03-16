package Round1A;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class ProblemB {
	
	public static final int MAX = 1000;
	
	public static long gcd(long a, long b) {
		long t;
		while (b > 0) {
			t = b;
			b = a % b;
			a = t;
		}
		return a;
	}
	
	public static int simulate(long[] M, int B, int N) {
		long[] A = new long[B];
		int i,j, res = 1;	
		long min = Integer.MAX_VALUE;
		
		if (N == 0) {
			min = Integer.MAX_VALUE;
			for (j=0; j<B; j++) {
				if (M[j] <= min) {
					min = M[j];
					res = j;
				}
			}
			
			return res + 1;
		}
		if (N == 1)
			return 1;
		
		for (i=0; i<B; i++) {
			A[i] = 0;
		}
		
		
		while (N > 0) {
			i = 0;
			while (i < B) {
				if (A[i] == 0) {
					N--;
					//System.out.println((i+1) + " is free");
					A[i] += M[i];
					/*
					if (M[i] < min) {
						min = M[i];
					}
					*/
				}
				
				if (N == 0) {
					res = i;
					break;
				}
				i++;
			}
			
			// find min A
			if (N > 0) {
				min = Integer.MAX_VALUE;
				for (j=0; j<B; j++) {
					if (A[j] < min) {
						min = A[j];
					}
				}
				
				for (j=0; j<B; j++) {
					A[j] -= min;
				}
			}
		}
			
		return res+1;	
	}

	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		int T = Integer.parseInt(in.readLine());
		int B,N,j;
		long lcm,gc,sum,res;
		long[] M = new long[MAX]; 
		for (int i=1; i<=T; i++) {
			st = new StringTokenizer(in.readLine());
			B = Integer.parseInt(st.nextToken());
			N = Integer.parseInt(st.nextToken());
			
			st = new StringTokenizer(in.readLine());
			for (j=0; j<B; j++) {
				M[j] = Integer.parseInt(st.nextToken());
			}
			
			// compute lcm
			lcm = 1;
			for (j=0; j<B; j++) {
				gc = gcd(lcm,M[j]);
				lcm = lcm*M[j]/gc;
			}
			
			sum = 0;
			for (j=0; j<B; j++) {
				sum += lcm/M[j];
			}
			
			res = N % sum;
			//System.out.println("sum = " + sum + " modulo = " + res);
			res = simulate(M,B,(int) res);
			//res = simulate(M,B,N);
			
			System.out.println("Case #" + i + ": " + res);
		}
	}

}
