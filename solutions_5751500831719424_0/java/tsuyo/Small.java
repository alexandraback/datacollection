import static java.lang.Math.*;
import static java.util.Arrays.*;

import java.io.*;
import java.util.*;

class Value {
	char c;
	int n;

	public Value(char c, int n) {
		this.c = c;
		this.n = n;
	}
}

public class Small {
	Scanner sc = new Scanner(System.in);
	int N;
	String[] S;

	void input() {
		N = sc.nextInt();
		S = new String[N];
		for (int i = 0; i < N; i++) {
			S[i] = sc.next();
		}
	}

	void solve() {
		// Set<String> set = new HashSet<String>();
		ArrayList[] al = new ArrayList[N];
		for (int i = 0; i < N; i++) {
			al[i] = new ArrayList();
			char[] chs = (S[i] + ".").toCharArray();
			char prev = chs[0];
			int cnt = 1;
			StringBuilder sb = new StringBuilder();
			for (int j = 1; j < chs.length; j++) {
				if (chs[j] == prev) {
					cnt++;
				} else {
					sb.append(chs[j]);
					al[i].add(new Value(prev, cnt));
					prev = chs[j];
					cnt = 1;
				}
			}
			// set.add(sb.toString());
		}
		// if (set.size() == 1) {
		int ans = adj(al);
		System.out.println((ans != -1) ? ans : "Fegla Won");
		// } else {
		// System.out.println("Fegla Won");
		// }
	}

	int adj(ArrayList[] al) {
		// check # of elements first
		int size = al[0].size();
		for (int i = 1; i < al.length; i++) {
			if (al[i].size() != size)
				return -1;
		}
		int[] ans = new int[size];
		for (int j = 0; j < size; j++) {
			if (!check(al, j))
				return -1;
			int[] cnt = new int[N];
			for (int i = 0; i < N; i++) {
				cnt[i] = ((Value) al[i].get(j)).n;
			}
			Arrays.sort(cnt);
			int last = cnt[N - 1];
			ans[j] = Integer.MAX_VALUE;

			for (int i = 0; i <= last; i++) {
				int val = 0;
				for (int k = 0; k < cnt.length; k++) {
					val += Math.abs(cnt[k] - i);
				}
				ans[j] = Math.min(ans[j], val);
			}
		}

		return sum(ans);
	}

	boolean check(ArrayList[] al, int j) {
		char c = ((Value) al[0].get(j)).c;
		for (int k = 1; k < N; k++) {
			char lc = ((Value) al[k].get(j)).c;
			if (c != lc)
				return false;
		}
		return true;
	}

	int sum(int[] ans) {
		int ret = 0;
		for (int i = 0; i < ans.length; i++) {
			ret += ans[i];
		}
		return ret;
	}

	void start() {
		int T = sc.nextInt();
		for (int caseNum = 1; caseNum <= T; caseNum++) {
			input();
			System.out.printf("Case #%d: ", caseNum);
			solve();
			System.out.flush();
		}
		sc.close();
	}

	void debug(Object... os) {
		System.err.println(deepToString(os));
	}

	public static void main(String[] args) {
		new Small().start();
	}

}
