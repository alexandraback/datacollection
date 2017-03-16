import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class A {

	private static final String PATH = "/home/tolstov.a.a/codejam/a/";

	private static final String TASK = "A-small";

	Scanner in;

	PrintWriter out;

	static class Struct {

		final char sym[];

		final List<Integer> count;

		Struct(char[] s) {
			this.count = new ArrayList<Integer>();
			StringBuilder sb = new StringBuilder();
			sb.append(s[0]);
			int lastCnt = 1;
			for (int i = 1; i < s.length; i++) {
				if (s[i] == s[i - 1]) {
					lastCnt++;
				} else {
					this.count.add(lastCnt);
					lastCnt = 1;
					sb.append(s[i]);
				}
			}
			this.count.add(lastCnt);
			sym = sb.toString().toCharArray();
			if (sym.length != count.size()) {
				throw new Error();
			}
		}

		boolean isGoodWith(Struct second) {
			if (this.sym.length != second.sym.length) {
				return false;
			} else {
				for (int i = 0; i < sym.length; i++) {
					if (sym[i] != second.sym[i]) {
						return false;
					}
				}
				return true;
			}
		}
	}

	void solveOne() {
		int nStrings = in.nextInt();
		char strs[][] = new char[nStrings][];
		Struct data[] = new Struct[nStrings];
		for (int i = 0; i < nStrings; i++) {
			strs[i] = in.next().toCharArray();
			data[i] = new Struct(strs[i]);
		}
		for (int i = 0; i < data.length; i++) {
			for (int j = i + 1; j < data.length;) {
				if (!data[i].isGoodWith(data[j])) {
					out.print("Fegla Won");
					return;
				}
				break;
			}
		}
		int nSym = data[0].sym.length;
		int ans = 0;
		for (int i = 0; i < nSym; i++) {
			int bestDiff = Integer.MAX_VALUE;
			for (int take = 1; take <= 100; take++) {
				int totalDiff = 0;
				for (Struct st : data) {
					int diff = Math.abs(take - st.count.get(i));
					totalDiff += diff;
				}
				if (totalDiff < bestDiff) {
					bestDiff = totalDiff;
				}
			}
			ans += bestDiff;
		}
		out.print(ans);
	}

	void solve() {
		int nTests = in.nextInt();
		for (int test = 1; test <= nTests; test++) {
			out.print("Case #" + test + ": ");
			solveOne();
			out.println();
		}
	}

	void run() {
		try {
			in = new Scanner(new FileReader(PATH + TASK + ".in"));
			out = new PrintWriter(PATH + TASK + ".out");
		} catch (IOException e) {
			in = new Scanner(System.in);
			out = new PrintWriter(System.out);
			out.println("debug>");
			out.flush();
		}

		try {
			solve();
		} finally {
			out.close();
		}
	}

	public static void main(String[] args) {
		new A().run();
	}
}
 
