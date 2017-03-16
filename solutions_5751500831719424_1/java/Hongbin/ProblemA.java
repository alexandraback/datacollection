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
			
			StringBuilder[] strs = new StringBuilder[N];
			for (int i = 0; i < N; i++) {
				strs[i] = new StringBuilder(in.next());
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
	
	static int solve(StringBuilder[] strs) {
		int res = 0;
		
		int N = strs.length;
		boolean finished = false;
		while (!finished) {
			int[] counts = new int[N];
			String first = null;
			for (int i = 0; i < strs.length; i++) {
				StringBuilder str = strs[i];
				String begin = removeBegin(str);
				counts[i] = begin.length();
				if (i == 0) {
					first = begin;
				}
				else {
					if (first.isEmpty() != begin.isEmpty()) {
						return -1;
					}
					
					if (!first.isEmpty() && !begin.isEmpty() && first.charAt(0) != begin.charAt(0)) {
						return -1;
					}
				}
			}
			
			if (first.isEmpty()) {
				finished = true;
			}
			else {
				res += nOps(counts);
			}
		}
		
		return res;
	}
	
	static int nOps(int[] counts) {
		int min = Integer.MAX_VALUE;
		for (int len = 1; len <= 100; len++) {
			int nOps = 0;
			for (Integer c : counts) {
				nOps += Math.abs(c - len);
			}
			min = Math.min(nOps, min);
		}
		
		return min;
	}
	
	static String removeBegin(StringBuilder str) {
		if (str.length() == 0) {
			return "";
		}
		
		char c = str.charAt(0);
		int i = 0;
		while (i < str.length() && str.charAt(i) == c) {
			i++;
		}
		
		String res = str.substring(0, i);
		str.replace(0, i, "");
		return res;
	}
}



