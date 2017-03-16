import java.util.*;
import java.io.*;
import java.text.*;
import java.math.*;

public class MushroomMonster {
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
			MushroomMonster instance = new MushroomMonster();
			instance.solve(t);
		}

	}
	
	// ****** GLOBAL VARIABLES ******
	
	
	
	public MushroomMonster() {
	}
	
	public boolean solve(int caseNumber) {
		int n = Integer.parseInt(readLine());
		int[] m = new int[n];
		StringTokenizer st = new StringTokenizer(readLine());
		for (int i = 0; i < n; ++i) {
			m[i] = Integer.parseInt(st.nextToken());
		}
		int method1Total = 0;
		int maxDecrease = 0;
		for (int i = 1; i < n; ++i) {
			int delta = m[i] - m[i-1];
			method1Total += Math.max(0, -delta);
			maxDecrease = Math.max(maxDecrease, -delta);
		}
		int method2Total = 0;
		for (int i = 1; i < n; ++i) {
			method2Total += Math.min(maxDecrease, m[i-1]);
		}
		System.out.println("Case #" + caseNumber + ": " + method1Total + " " + method2Total);
		return false;
	}


}
