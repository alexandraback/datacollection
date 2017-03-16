import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class B_2_haircut {
	private int b;
	private int n;
	private int[] m;
	
	private long count(final long t) {
		long r = 0;
		for (int x : m) {
			r += (t + x - 1) / x;
		}
		return r;
	}
	
	private long find() {
		long t1 = 0;
		long t2 = 1000000001l * 100001;
		while (t1 + 1 < t2) {
			long m = t1 + (t2 - t1) / 2;
//			System.out.println(m + ": " + count(m));
			if (count(m) < n) {
				t1 = m;
			}
			else {
				t2 = m;
			}
		}
		return t1;
	}
	
	public void solve(final Scanner sc, final PrintWriter pw) {
		b = sc.nextInt();
		n = sc.nextInt();
		m = new int[b];
		for (int j = 0; j < b; ++j) {
			m[j] = sc.nextInt();
		}
		if (n == 1) {
			pw.println(1);
			return;
		}
		long t = find();
		int c = (int) count(t);
		for (int j = 0; j < b; ++j) {
			if (t % m[j] == 0) {
				c++;
				if (c == n) {
					pw.println(j + 1);
					return;
				}
			}
		}
	}
	
	public static void main(final String... args) throws IOException {
		final String fname = "B-large";
		final Scanner sc = new Scanner(new File(fname + ".in"));
		final PrintWriter pw = new PrintWriter(fname + ".out");
		final int t = sc.nextInt();
		
		for (int i = 1; i <= t; ++i) {
			System.out.println(i);
			pw.print("Case #" + i + ": ");
			new B_2_haircut().solve(sc, pw);
		}
		pw.close();
	}
}
