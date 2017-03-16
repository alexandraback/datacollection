// Google Code Jam Round 1A 2015
// Problem B. Haircut

import java.util.*;
import java.io.*;

public class Haircut{
	static String filename = "B-small-attempt1";	// io filnename here
    static String inname = filename + ".in";    
    static String outname = filename + ".out";  
    static int n;
    public static void main(String[] args){
        try{
            Scanner in = new Scanner(new BufferedReader(new FileReader(inname)));
        	//Scanner in = new Scanner(System.in);
            BufferedWriter out = new BufferedWriter(new FileWriter(outname));
            int t = in.nextInt();
            in.nextLine();
            for (int cas = 1; cas <= t; cas++){
            	
                int b = in.nextInt();
                long n = in.nextLong();
                long[] m = new long[b];
                for (int i = 0; i < b; i++) m[i] = in.nextInt();
                long cycleLength = findCycle(m);
                n = n%cycleLength;
                int ans = -1;
                if (n == 1) ans = 1;
                else if (n == 0){
                	int fastest = 0;
                	for (int i = 0; i < b; i++){
                		if (m[i] <= m[fastest]) fastest = i; 
                	}
                	ans = fastest+1;
                }
                else ans = simul(m, n);
        		//System.out.println(lcm(m) + " " + gcd(m) + " " + cycleLength + " " + n);
                System.out.print("Case #" + cas + ": " + ans + "\n");
                out.write("Case #" + cas + ": " + ans + "\n");
            }
            in.close();
            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
	private static int simul(long[] m, long n) {
		long gcd = gcd(m);
		int b = m.length;
		long[] st = new long[b];
		for (int i = 0 ; i < b; i++) st[i] = 0;
		while (n>0){
			for (int i = 0; i < b; i++){
				if (st[i] == 0){
					n--;
					if (n <= 0) return i+1;
					st[i] = m[i];
				}
				st[i] = Math.max(0,  st[i] - gcd);
			}
		}
		return -1;
	}
	private static long findCycle(long[] m) {
		int b = m.length;
		long lcm = lcm(m);
		long tot = 0;
		for (int i = 0; i < b; i++)
			tot += lcm/m[i];
		return tot;
	}
	private static long lcm(long[] m) {
		long lcm = m[0];
		for (int i = 1; i < m.length; i++)
			lcm = lcm(lcm, m[i]);
		return lcm;
	}
	private static long gcd(long[] m) {
		long gcd = m[0];
		for (int i = 1; i < m.length; i++)
			gcd = gcd(gcd, m[i]);
		return gcd;
	}
	private static long gcd(long a, long b){
		if (b == 0) return a;
	    else return gcd(b, a%b);
	}
	private static long lcm(long a, long b){
	    return ((a*b)/gcd(a,b));
	} 
}