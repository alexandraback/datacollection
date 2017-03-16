package round1B;
import java.util.*;
import java.io.*;
import java.lang.Math;

public class A {

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(new File(args[0]));
		FileWriter out = new FileWriter(args[0].substring(0, args[0].length()-3) + ".out");
		int T = in.nextInt();
		
		for (int c = 1; c <= T; c++) {
			int N = in.nextInt();
			String str[] = new String[N];
			str[0] = in.next();
			String chopped = chop(str[0]);
			boolean poss = true;
			for (int i = 1; i < N; i++) {
				str[i] = in.next();
				if (!chop(str[i]).equals(chopped)) poss = false;
			}
			if (poss) {
				int nums[][] = new int[chopped.length()][N];
				for (int s = 0; s < N; s++) {
					int l = 0;
					for (int i = 0; i < chopped.length() - 1; i++) {
						nums[i][s] = str[s].indexOf(chopped.substring(i+1,i+2), l) - l;
						l += nums[i][s];
					}
					nums[chopped.length() - 1][s] = str[s].length() - l;
				}
				for (int i = 0; i < chopped.length(); i++) {
					Arrays.sort(nums[i]);
				}
				int mid = N / 2;
				int moves = 0;
				for (int[] num : nums) {
					int median = num[mid];
					System.out.println(median);
					for (int numba : num) {
						moves += Math.abs(median - numba);
					}
				}
				
				out.write("Case #" + c + ": " + moves + "\n");
			} else {
				out.write("Case #" + c + ": Fegla Won\n");
			}
			
		}
		
		in.close();
		out.close();
	}
	
	public static String chop(String s) {
		String o = s.substring(0, 1);
		char c = o.charAt(0);
		for (int i = 1; i < s.length(); i++) {
			if (s.charAt(i) == c);
			else {
				c = s.charAt(i);
				o += s.substring(i, i+1);
			}
		}
		return o;
	}

}
