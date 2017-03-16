import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class A1 {

	static StringTokenizer st;
	static BufferedReader br;
	static PrintWriter pw;
	
	public static void main(String[] args) throws IOException{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		int testNumber = nextInt();
		for (int test = 1; test <= testNumber; test++) {
			pw.print("Case #"+test+": ");
			int n = nextInt();
			String s1 = next();
			String s2 = next();
			int begin = 0;
			int ans = 0;
			for (int i = 0; i < s1.length(); i++) {
				int ind = i;
				int cnt1 = 0;
				if (begin >= s2.length()) {
					ans = -1;
					break;
				}
				while (ind < s1.length()-1 && s1.charAt(ind)==s1.charAt(ind+1)) {
					ind++;
					cnt1++;
				}
				int ind2 = begin;
				int cnt2 = 0;
				while (ind2 < s2.length()-1 && s2.charAt(ind2)==s2.charAt(ind2+1)) {
					ind2++;
					cnt2++;
				}
				if (s1.charAt(ind) != s2.charAt(ind2)) {
					ans = -1;
					break;
				}
				ans += Math.abs(cnt1-cnt2);
				begin = ind2+1;
				i = ind;
			}
			if (begin != s2.length())
				ans = -1;
			if (ans==-1)
				pw.println("Fegla Won");
			else
				pw.println(ans);
		}
		pw.close();
	}

	private static int nextInt() throws IOException {
		return Integer.parseInt(next());
	}
	private static long nextLong() throws IOException {
		return Long.parseLong(next());
	}
	private static double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}

	private static String next() throws IOException{
		while (st==null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine());
		return st.nextToken();
	}

}
