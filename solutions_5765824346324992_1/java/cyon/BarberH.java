import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class BarberH {

	private static void debug(Object... args) {
		//System.out.println(Arrays.deepToString(args));
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out, true);
		int T = Integer.parseInt(br.readLine());
		for (int c = 1; c <= T; c++) {
			pw.println("Case #" + c + ": " + solve(br));
		}
		pw.flush();
	}

	private static String solve(BufferedReader br) throws IOException {
		StringTokenizer st = new StringTokenizer(br.readLine());
		int B = Integer.parseInt(st.nextToken());
		int N = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		int[]bar=new int[B];
		for(int i=0;i<B;i++) {
			bar[i] = Integer.parseInt(st.nextToken());
		}
		//debug(lcm);
		
		if (N <= B) {
			return "" + N;
		}
		
		long lo = 0;
		long hi = 1;
		boolean found = false;
		while (!found) {
			if (N <= calc(hi, B, bar)) {
				found = true;
			}
			if (!found) {
				lo = hi;
				hi = 2*hi;
			}
		}
		debug("found at", lo, hi);
		
		while (lo < hi) {
			long mid = lo + (hi - lo) / 2;
			int cnt = calc(mid, B, bar);
			debug(mid, cnt);
			if (cnt < N) {
				lo = mid + 1;
			}
			else {
				hi = mid;
			}
		}
		int cnt = calc(lo, B, bar);
		debug("smallest", lo, cnt);
		if (cnt >= N) {
			int dif = 0;
			for (int i = 0; i < B; i++) {
				if (lo % bar[i] == 0) {
					dif++;
				}
			}
			cnt -= dif;
			for (int i = 0; i < B; i++) {
				if (lo % bar[i] == 0) {
					cnt++;
					if (cnt == N) return "" + (i+1);
				}
			}
		}
		else {
			return "PROB1";
		}
		return "PROB2";
	}

	private static int calc(long hi, int b, int[] bar) {
		
		int cnt = 0;
		for (int i = 0; i < b; i++) {
			cnt += (hi / bar[i]) + 1;
		}
		
		return cnt;
	}
}
