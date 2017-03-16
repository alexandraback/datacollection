import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class A {

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		String fileName = "A-large";
		Scanner in = new Scanner(new File(fileName + ".in"));
		PrintWriter out = new PrintWriter(new FileWriter(fileName + ".out"));
		
		int T = in.nextInt();
		
		for(int i=1; i<=T; i++) {
			out.println("Case #" + i + ": " + solve(in));
		}
		
		in.close();
		out.close();
	}

	private static String solve(Scanner in) {
		
		// Read inputs
		int x = in.nextInt();
		int[] m = new int[x];
		for(int i=0; i<x; i++) {
			m[i] = in.nextInt();
		}
		
		int tot1 = 0;
		int maxDiff = 0;
		
		// method 1 and also find max diff
		for(int i=1; i<x; i++) {
			int diff = m[i-1] - m[i];
			if(diff > 0) {
				tot1 = tot1 + diff;
			}
			if(diff > maxDiff) {
				maxDiff = diff;
			}
		}
		
		int tot2 = 0;
		
		// method 2
		// maxDiff is the rate of eating
		for(int i=0; i<x-1; i++) {
			if(m[i] <= maxDiff) {	//eat all
				tot2 = tot2 + m[i];
			} else {
				tot2 = tot2 + maxDiff;
			}
		}
		
		return tot1 + " " + tot2;
	}

}
