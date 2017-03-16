import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;

public class A {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new FileReader(new File("A-small-attempt1.in")));
		PrintWriter out = new PrintWriter(new File("out.out"));

		String[] sp;

		int T = Integer.parseInt(br.readLine());

		for (int i = 0; i < T; i++) {

			int n = Integer.parseInt(br.readLine());
			String[] s = new String[n];
			for (int j = 0; j < s.length; j++) {
				s[j] = br.readLine();
			}
			int[] cur = new int[n];
			int[] old = new int[n];
			int res = 0;
			boolean f = true;

			while(old[0] < s[0].length()) {
				int min = Integer.MAX_VALUE;
				int curr = 0;
				for (int l = 0; l < old.length && f; l++) {
					if(old[l] >= s[l].length() || old[0] >= s[0].length())
						f = false;
					if(f && s[l].charAt(cur[l]) != s[0].charAt(old[0]))
						f = false;
					while (cur[l] < s[l].length()
							&& s[l].charAt(cur[l]) == s[0].charAt(old[0]) && f) {
						cur[l]++;

					}
				}

				if (!f)
					break;

				for (int k = 0; k < old.length; k++) {
					curr = 0;
					for (int l = 0; l < old.length; l++) {
						curr += Math.abs((cur[k] - old[k]) - (cur[l] - old[l]));
					}
					min = Math.min(min, curr);
				}

				for (int k = 0; k < old.length; k++) {
					old[k] = cur[k];
				}

				res += min;
			}
			
			for (int j = 0; j < old.length; j++) {
				if(old[j] != s[j].length())
					f = false;
			}
			out.print("Case #" + (i + 1) + ": ");
			if (f)
				out.println(res);
			else
				out.println("Fegla Won");
		}

		br.close();
		out.close();
	}
}
