import java.io.*;
import java.util.*;

class Haircut {
	static long count(int[] aa, long m, long n) {
		long cnt = 0;
		for (int i = 0; i < aa.length; i++) {
			cnt += m / aa[i] + (m % aa[i] == 0 ? 0 : 1);
			if (cnt >= n)
				return n;
		}
		return cnt;
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);
		int T = Integer.parseInt(br.readLine());
		for (int t = 1; t <= T; t++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int b = Integer.parseInt(st.nextToken());
			long n = Long.parseLong(st.nextToken());
			int[] aa = new int[b];
			st = new StringTokenizer(br.readLine());
			int max = 0;
			for (int i = 0; i < b; i++) {
				aa[i] = Integer.parseInt(st.nextToken());
				if (max < aa[i])
					max = aa[i];
			}
			long lo = 0;
			long hi = n * max;
			while (hi - lo > 1) {
				long m = (lo + hi) / 2;
				long cnt = count(aa, m, n);
				if (cnt >= n)
					hi = m;
				else
					lo = m;
			}
			long cnt = count(aa, lo, n);
			for (int i = 0; i < b; i++)
				if (lo % aa[i] == 0) {
					cnt++;
					if (cnt == n) {
						pw.println("Case #" + t + ": " + (i + 1));
						break;
					}
				}
		}
		pw.close();
	}
}
