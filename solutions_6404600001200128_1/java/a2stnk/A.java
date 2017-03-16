package cj2015.r1a;
import java.io.*;
import java.util.*;

public class A {
	Scanner sc;
	PrintWriter pw;
	int N;
	int[] m;
	
	public static void main(String[] args) throws Exception{
		String filePrefix = args.length>0?args[0]:"A-large (1)";

		try {
			new A().run(filePrefix);
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
		N = sc.nextInt();
		m = new int[N];
		for(int i=0; i<N; i++)
			m[i] = sc.nextInt();
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
		int ans1 = 0,ans2 = 0;
		int maxrate = 0;
		for(int i=1; i<N; i++) {
			ans1 += Math.max(m[i-1]-m[i], 0);
			maxrate = Math.max(m[i-1]-m[i], maxrate);
		}
		
		for(int i=1; i<N; i++) {
			ans2 += Math.min(m[i-1], maxrate);
		}
		
		println(ans1 + " " + ans2);
	}
	
}
