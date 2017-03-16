package RB;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class A {

	static String trim(String str) {
		StringBuilder res = new StringBuilder();
		char bef = '!';
		for(int i = 0; i < str.length(); i++) {
			if(str.charAt(i) == bef) {
				continue;
			} else {
				res.append(str.charAt(i));
				bef = str.charAt(i);
			}
		}
		return res.toString();
	}

	static int[] toSeq(String key, String str) {
		int res[] = new int[key.length()];
		int ki = 0;
		char bef = str.charAt(0);
		int cnt = 1;
		for(int i = 1; i < str.length(); i++) {
			if(str.charAt(i) != bef) {
				res[ki] = cnt;
				ki++;
				cnt = 1;
				bef = str.charAt(i);
			} else {
				cnt++;
			}
		}
		res[ki] = cnt;
		return res;
	}

	public static void main(String[] args) throws FileNotFoundException {
		Scanner sc = new Scanner(new File("A-small-attempt0.in.txt"));
		PrintWriter pw = new PrintWriter(new File("outA"));
//		Scanner sc = new Scanner(System.in);
//		PrintWriter pw = new PrintWriter(System.out);
		int T = sc.nextInt();
		L:for(int t = 1; t <= T; t++) {
			int N = sc.nextInt();
			String in[] = new String[N];
			String key = null;
			for(int i = 0; i < N; i++) {
				in[i] = sc.next();
				String tmp = trim(in[i]);
				if(key == null) {
					key = tmp;
				} else {
					if(key.equals(tmp) == false) {
						pw.println("Case #"+t+": Fegla Won");
						continue L;
					}
				}
			}

			int mx[][] = new int[N][];
			for(int i = 0; i < N; i++) {
				mx[i] = toSeq(key, in[i]);
//				System.out.println(Arrays.toString(mx[i]));
			}

			int ans = 0;
			for(int j = 0; j < key.length(); j++) {
				int max = 0;
				for(int i = 0; i < N; i++) {
					max = Math.max(max, mx[i][j]);
				}

				int best = Integer.MAX_VALUE;
				for(int len = 1; len <= max; len++) {
					int cost = 0;
					for(int i = 0; i < N; i++) {
						cost += Math.abs(len - mx[i][j]);
					}
					best = Math.min(best, cost);
				}
				ans += best;
			}
			pw.println("Case #"+t+": "+ans);
		}
		
		pw.flush();
	}
}
