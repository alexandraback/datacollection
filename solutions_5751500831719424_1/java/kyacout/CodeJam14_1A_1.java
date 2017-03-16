import java.io.BufferedReader;
import java.io.File;
import java.io.InputStreamReader;
import java.io.PrintWriter;


public class CodeJam14_1A_1 {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(new File("output"));
		int t = Integer.parseInt(br.readLine());

		for (int tc = 1; tc <= t; tc++) {
			int n = Integer.parseInt(br.readLine());
			String[] words = new String[n];
			for (int i = 0; i < n; i++)
				words[i] = br.readLine();
			
			int[] ps = new int[n];
			char[] cs;
			int[] counts;
			boolean finish = false, ans = true;
			int anss = 0;
			while (!finish) {
				finish = true;
				cs = new char[n];
				counts = new int[n];
				for (int i = 0; i < n; i++) {
					if (ps[i] == words[i].length())
						continue;
					finish = false;
					cs[i] = words[i].charAt(ps[i]);
					counts[i] = 1;
					while (ps[i] < words[i].length() && words[i].charAt(ps[i]) == cs[i]) {
						counts[i]++;
						ps[i]++;
					}
				}
				
				for (int i = 1; i < n; i++) {
					if (cs[i] != cs[i - 1]) {
						ans = false;
						break;
					}
				}
				
				int min = Integer.MAX_VALUE;
				for (int i = 0; i < n; i++) {
					int cur = 0;
					for (int j = 0; j < n; j++)
						cur += Math.abs(counts[i] - counts[j]);
					min = cur < min ? cur : min;
				}
				anss += min;
			}
			out.print("Case #" + tc + ": ");
			out.println(ans ? anss : "Fegla Won");
		}
		out.close();
	}
}
