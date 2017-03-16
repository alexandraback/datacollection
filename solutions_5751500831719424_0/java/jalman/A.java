import java.io.*;
import java.util.*;

public class A{
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new FileReader("in.txt"));
		PrintWriter pw = new PrintWriter(new FileWriter("out.txt"));

		int N = Integer.parseInt(br.readLine());

		for(int p = 0; p < N; p++) {
			int n = Integer.parseInt(br.readLine());

			String[] s = new String[n];

			for(int i = 0; i < n; i++) s[i] = br.readLine();


			char[] c = new char[s[0].length()];
			int at = 1;

			c[0] = s[0].charAt(0);

			for(int i = 1; i < s[0].length(); i++) {
				if(s[0].charAt(i) != s[0].charAt(i-1)) {
					c[at] = s[0].charAt(i);
					at++;
				}
			}

			int ans = 0;
			boolean imp = false;
			int[] sat = new int[n];

			Dame: for(int q = 0; q < at; q++) {

				int[] len = new int[n];
				int total = 0;

				for(int i = 0; i < n; i++) {
					while(s[i].length() > sat[i] && s[i].charAt(sat[i]) == c[q]) {
						sat[i]++;
						len[i]++;
					}
					if(len[i] == 0) {
						imp = true;
						break Dame;
					}
				}

				Arrays.sort(len);
				int dest = len[n/2];
				for(int i = 0; i < n; i++) {
					ans += Math.abs(dest - len[i]);
				}

			}

			for(int i = 0; i < n; i++) {
				if(sat[i] != s[i].length()) imp = true;
			}


			pw.println("Case #" + (p+1) + ": " + (imp ? "Fegla Won" : ans));
		}


		pw.flush();
		pw.close();

	}
}