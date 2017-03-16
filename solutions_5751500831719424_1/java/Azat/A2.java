import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;


public class A2 {

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
			String[]s = new String[n+1];
			for (int i = 1; i <= n; i++) {
				s[i] = next();
			}
			ArrayList<Integer>[]L = new ArrayList[n+1];
			long ans = 0;
			for (int i = 1; i <= n; i++) {
				L[i] = new ArrayList<>();
				for (int j = 0; j < s[i].length(); j++) {
					int begin = j, cnt = 1;
					while (begin < s[i].length()-1 && s[i].charAt(begin)==s[i].charAt(begin+1)) {
						begin++;
						cnt++;
					}
					L[i].add(cnt);
					j = begin;
				}
			}
A:			for (int i = 1; i <= n; i++) {
				if (L[i].size() != L[1].size()) {
					ans = -1;
					break;
				}
				int ind1 = 0, ind2 = 0;
				for (int j = 0; j < L[1].size(); j++) {
					if (s[1].charAt(ind1) != s[i].charAt(ind2)) {
						ans = -1;
						break A;
					}
					ind1 += L[1].get(j);
					ind2 += L[i].get(j);
				}
			}
			if (ans != -1) {
				for (int i = 0; i < L[1].size(); i++) {
					int min = (int)1e9;
					for (int k = 1; k <= 101; k++) {
						int cur = 0;
						for (int j = 1; j <= n; j++) {
							cur += Math.abs(L[j].get(i)-k);
						}
						min = Math.min(min, cur);
					}
					ans += min;
				}
			}
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
