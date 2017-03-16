import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class A {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		TASK: for (int no = 1; no <= T; no++) {
			System.out.printf("Case #%d: ", no);

			int N = in.nextInt();
			String[] strs = new String[N];
			for (int i = 0; i < N; i++) {
				strs[i] = in.next();
			}

			List<Character> cs = new ArrayList<>();
			char prevc = 0;
			for (int i = 0; i < strs[0].length(); i++) {
				char c = strs[0].charAt(i);
				if (c != prevc) {
					cs.add(c);
					prevc = c;
				}
			}

			int[][] data = new int[N][];
			for (int i = 0; i < N; i++) {
				data[i] = conv(strs[i].toCharArray(), cs);
				//System.err.println(Arrays.toString(data[i]));
				if (data[i] == null) {
					System.out.println("Fegla Won");
					continue TASK;
				}
			}

			int ans = 0;
			for (int i = 0; i < cs.size(); i++) {
				int min = Integer.MAX_VALUE;
				for (int t = 0; t < N; t++) {
					int base = data[t][i];
					int sum = 0;
					for (int k = 0; k < N; k++) {
						sum += Math.abs(data[k][i] - base);
					}
					min = Math.min(min, sum);
				}
				ans += min;
			}
			System.out.println(ans);
		}
	}

	private static int[] conv(char[] str, List<Character> cs) {
		int[] res = new int[cs.size()];
		int resInd = 0;
		char prevc = 0;
		int csInd = 0;
		int count = 0;
		for (int i = 0; i < str.length; i++) {
			char c = str[i];
			if (c != prevc) {
				if (csInd >= cs.size() || c != cs.get(csInd))
					return null;
				csInd++;
				if (i != 0)
					res[resInd++] = count;
				count = 1;
				prevc = c;
			} else {
				count++;
			}
		}
		if (csInd != cs.size())
			return null;
		res[resInd] = count;
		return res;
	}
}
