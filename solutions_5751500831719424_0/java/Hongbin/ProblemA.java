import java.util.*;
import java.io.PrintStream;
import java.awt.Point;

public class ProblemA
{
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		PrintStream out = System.out;

		//input
		int T = in.nextInt();
		for (int t = 1; t <= T; t++) {
			int N = in.nextInt();
			
			String[] strs = new String[N];
			for (int i = 0; i < N; i++) {
				strs[i] = in.next();
			}
			
			int diff = solve(strs);
			String res;
			if (diff == -1) {
				res = "Fegla Won";
			}
			else {
				res = String.valueOf(diff);
			}

			out.println("Case #" + t + ": " + res);
		}
	}
	
	static int solve(String[] strs) {
		int res = 0;
	
		String s1 = strs[0];
		String s2 = strs[1];
		
		int i1 = 0;
		int i2 = 0;
		while (i1 < s1.length() && i2 < s2.length()) {
			if (s1.charAt(i1) != s2.charAt(i2)) {
				return -1;
			}
			else {
				int count1 = 0;
				int count2 = 0;
				char c = s1.charAt(i1);
				while (i1 < s1.length() && s1.charAt(i1) == c) {
					count1++;
					i1++;
				}
				while (i2 < s2.length() && s2.charAt(i2) == c) {
					count2++;
					i2++;
				}

				res += Math.abs(count1 - count2);
			}	
		}
		
		if (i1 < s1.length() || i2 < s2.length()) {
			return -1;
		}
		else {
			return res;
		}
	}
}



