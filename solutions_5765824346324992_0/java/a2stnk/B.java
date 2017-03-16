package cj2015.r1a;
import java.io.*;
import java.util.*;

public class B {
	Scanner sc;
	PrintWriter pw;
	int B,N;
	int[] M;
	
	public static void main(String[] args) throws Exception{
		String filePrefix = args.length>0?args[0]:"B-small-attempt0 (1)";

		try {
			new B().run(filePrefix);
		} catch(Exception e) {
			System.err.println(e);
		}
	}
	
	public void run(String filePrefix) throws Exception {
		sc = new Scanner(new FileReader(filePrefix + ".in"));
		pw = new PrintWriter(new FileWriter(filePrefix + ".out"));
		int ntest = sc.nextInt();
		for(int test=1; test<=ntest; test++) {
			read(sc);
			pw.print("Case #" + test + ": ");
			System.out.print("Case #" + test + ": ");
			solve();
		}
		System.out.println("Finished.");
		sc.close();
		pw.close();
		
	}
	
	void read(Scanner sc) {
		B = sc.nextInt();
		N = sc.nextInt();
		M = new int[B];
		for(int i=0; i<B; i++)
			M[i] = sc.nextInt();
	}
	
	void print(Object s) {
		pw.print(s);
		System.out.print(s);
	}
	
	void println(Object s) {
		pw.println(s);
		System.out.println(s);
	}	
	
	public void solve() {
		if(N<=B) {
			println(N);
			return;
		}
		
		long l = 0;
		long r = (long)1e16;
		
		long queued=0;
		while(l+1<r) {
			long mid = (l+r)/2;
			queued = 0;
			for(int i=0; i<B; i++) {
				queued += mid/M[i]+1;
				if(queued>=N)
					break;
			}
			if(queued>=N)
				r = mid;
			else
				l = mid;
		}
		
		queued = 0;
		int ans = 0;
		for(int i=0; i<B; i++)
			queued += l/M[i]+1;
		for(int i=0; i<B; i++)
			if(r%M[i]==0) {
				queued++;
				if(queued==N) {
					ans = i+1;
					break;
				}
			}
		println(ans);
	}
	
}
