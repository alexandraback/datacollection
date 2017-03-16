import java.io.*;
import java.util.*;

public class P1 {
	public static void main (String[] args) throws FileNotFoundException {
//		Scanner sc = new Scanner (System.in);
//		PrintStream op = System.out;
		Scanner sc = new Scanner (new FileInputStream ("D:\\Internet\\A-small-attempt0.in"));
		PrintStream op = new PrintStream ("D:\\Internet\\output.txt");
		int T = sc.nextInt();
		for (int t = 1; t <= T; t++) {
			int N = sc.nextInt();
			boolean pass = true;
			String[] inp = new String [N];
			String tmplt = "", prevStr = "";
			sc.nextLine();
			for (int i = 0; i < N; i++) {
				inp[i] = sc.nextLine();
				if (pass) {
					tmplt = "";
					char prev = '0';
					for (int j = 0; j < inp[i].length(); j++) {
						char c = inp[i].charAt(j);
						if (c != prev) {
							tmplt += c;
							prev = c;
						}
					}
					if (i > 0 && tmplt.compareTo(prevStr) != 0)
						pass = false;
					prevStr = tmplt;
				}
			}
			op.print("Case #" + t + ": ");
			if (!pass) {
				op.println("Fegla Won");
				continue;
			}
			int n = tmplt.length();
			Integer[][] mt = new Integer [n][N];
			for (int i = 0; i < N; i++) {
				int ind = -1;
				char prev = '0';
				for (int j = 0; j < inp[i].length(); j++) {
					char c = inp[i].charAt(j);
					if (c != prev) {
						ind++;
						mt[ind][i] = 0;
					}
					mt[ind][i]++;
					prev = c;
				}
			}
			int cost = 0;
			for (int i = 0; i < n; i++) {
				int l = Collections.min(Arrays.asList(mt[i]));
				int r = Collections.max(Arrays.asList(mt[i]));
				int min = Integer.MAX_VALUE;
				for (int j = l; j <= r; j++) {
					int sum = 0;
					for (int k = 0; k < N; k++)
						sum += Math.abs(mt[i][k] - j);
					min = Math.min(min, sum);
				}
				cost += min;
			}
			op.println(cost);
		}
	}
}