package codejam16r1c;

import java.io.*;
import java.util.*;

public class SenateEvacuation {

	public static void main(String[] args) throws IOException {
		String problem = "senate-evacuation";
		String example = "A-large";

		File inFile = new File("data/" + problem + "/" + example + ".in");
		File outFile = new File("data/" + problem + "/" + example + ".out");

		try (Scanner in = new Scanner(inFile); PrintStream out = new PrintStream(outFile)) {
			int T = in.nextInt();

			for (int t = 0; t < T; ++t) {
				int n = in.nextInt();
				int[] counts = new int[n];
				for (int i = 0; i < n; ++i)
					counts[i] = in.nextInt();

				out.println("Case #" + (t + 1) + ": " + solve(counts));
			}
		}
	}

	private static String solve(int[] counts) {
		StringBuilder plan = new StringBuilder();

		int l = -1;
		int sl = -1;

		for (int i = 0; i < counts.length; ++i) {
			if (l < 0 || counts[i] > counts[l]) {
				sl = l;
				l = i;
			} else if (sl < 0 || counts[i] > counts[sl]) {
				sl = i;
			}
		}

		while (counts[l] > counts[sl]) {
			app(plan, l);
			counts[l] --;
		}
		
		for (int i = 0; i < counts.length; ++ i)
			if (i != l && i != sl) {
				while (counts[i]  > 0) { 
					app(plan, i);
					counts[i] --;
				}
			}
		
		while (counts[l] > 0 && counts[sl] > 0) {
			plan.append((char)('A' + l));
			plan.append((char)('A' + sl));
			plan.append(' ');
			counts[l] -- ;
			counts[sl] --;
		}
				
		for (int i = 0; i < counts.length; ++ i)
			if (counts[i] != 0)
				throw new Error();
		
		return plan.substring(0, plan.length() - 1);
	}
	
	private static void app(StringBuilder plan, int l) {
		plan.append((char)('A' + l));
		plan.append(' ');
	}

}
