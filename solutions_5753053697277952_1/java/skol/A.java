import java.io.*;
import java.math.*;
import java.util.*;
import java.text.*;
import java.util.regex.*;

import static java.lang.Math.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;
import static java.lang.Integer.*;
import static java.lang.Double.*;
import static java.lang.Character.*;


public class A {
	
	Object solve() {
		int N = sc.nextInt();
		int[] p = new int[N];
		int sum = 0;
		for (int i = 0; i < N; i++) {
			p[i] = sc.nextInt();
			sum += p[i];
		}
		
		String res = "";
		
		while (sum > 0) {
			{
				int maxi = findMax(p);
				res += (char)('A' + maxi);
				p[maxi]--;
				sum--;
			}
			
			if (sum > 0 && sum != 2) {
				int maxi = findMax(p);
				res += (char)('A' + maxi);
				p[maxi]--;
				sum--;
			}
			
			if (sum > 0)
				res += " ";
			
			if (!test(p))
				throw new RuntimeException();
		}
		
		return res;
	}
	
	private boolean test(int[] p) {
		int sum = 0;
		for (int i : p)
			sum += i;
		
		for (int i : p) {
			if (2*i > sum)
				return false;
		}
		
		return true;
	}

	int findMax(int[] p) {
		int maxi = 0;
		for (int j = 0; j < p.length; j++) {
			if (p[j] > p[maxi])
				maxi = j;
		}
		return maxi;
	}

	private static Scanner sc; private static PrintWriter fw;

	public static void main(String[] args) throws Exception {
		String inFile = "input.txt", outFile = "output.txt";
		if (args.length == 0) {
			sc = new Scanner(System.in);
	//		sc = new Scanner(new FileInputStream(inFile));
		} else {
			inFile = args[0];
			sc = new Scanner(new FileInputStream(inFile));
			if (args.length > 1)
				outFile = args[1];
			else if (inFile.endsWith(".in"))
				outFile = inFile.substring(0, inFile.length() - 2) + "out";
			System.out.println(inFile + " -> " + outFile);
		}
		
		fw = new PrintWriter(new FileWriter(outFile, false)) {
			public PrintWriter printf(String format, Object... args) {
				System.out.printf(format, args);
				return super.printf(format, args);
			}
		};
		
		int N = sc.nextInt();
		sc.nextLine();
		System.out.println(N + " cases.");
		
		int progress = 0, progress1;
		for (int cas = 1; cas <= N; cas++) {
			fw.printf("Case #" + cas + ": ");
//			fw.println("Case #" + cas + ": ");
			Object res = new A().solve();
			if (res instanceof Double) 
				fw.printf("%.10f\n", res);
			else
				fw.printf("%s\n", res);
			fw.flush();
			if ((progress1 = cas*10/N) > progress) { System.out.println("*" + progress1*10 + "% "); progress = progress1; };
		}
		fw.close();
		sc.close();
	}
}
