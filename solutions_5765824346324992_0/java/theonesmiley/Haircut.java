import java.util.*;
import java.io.*;
import java.text.*;
import java.math.*;

public class Haircut {
	public static BufferedReader BR;
	
	public static String readLine() {
		try {
			return BR.readLine();
		} catch(Exception E) {
			System.err.println(E.toString());
			return null;
		}
	}
	
	
	// ****** MAIN ******
	
	public static void main(String [] args) throws Exception {
		BR = new BufferedReader(new InputStreamReader(System.in));
	
		int testcases = Integer.parseInt(readLine());
		for (int t = 1; t <= testcases; t++) {
			Haircut instance = new Haircut();
			instance.solve(t);
		}
	
	}
	
	// ****** GLOBAL VARIABLES ******
	
	
	
	public Haircut() {
	}
	
	// customer who is first in line at the beginning of time t
	public long firstInLine(int[] m, long t) {
		long result = 0;
		for (int i = 0; i < m.length; ++i) {
			result += (t + m[i] - 1) / (long) m[i];
		}
		//System.out.println(t + " " + (result+1));
		return result+1;
	}
	
	public boolean solve(int caseNumber) {
		StringTokenizer st = new StringTokenizer(readLine());
		int b = Integer.parseInt(st.nextToken());
		long n = Long.parseLong(st.nextToken());
		st = new StringTokenizer(readLine());
		int[] m = new int[b];
		for (int i = 0; i < b; ++i) {
			m[i] = Integer.parseInt(st.nextToken());
		}
		
		long lo = 0, hi = 2000000000000L;
		while (lo < hi) {
			long mid = (lo + hi) / 2;
			long first = firstInLine(m, mid);
			if (first <= n) {
				lo = mid+1;
			} else {
				hi = mid;
			}
		}

		long t = lo+100001;
		while (firstInLine(m, t) > n) --t;
		// t should be the last time that the customer who is first in line is <= n
		long c = firstInLine(m, t); // the customer who is first in line at time t
		int result = -1;
		for (int i = 0; i < b; ++i) {
			if (t % m[i] == 0) {
				if (c == n) result = i;
				++c;
			}
		}
		System.out.println("Case #" + caseNumber + ": " + (result+1));
		return false;
	}


}
