import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class B_1_neighbors {
	public int check(final int r, final int c, final int[] a) {
		final List<Integer> l = new ArrayList<Integer>();
		for (int x : a) {
			l.add(x);
		}
		int n = 0;
		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < c - 1; ++j) {
				if (l.contains(i * c + j) && l.contains(i * c + j + 1)) {
					n++;
				}
			}
		}
		for (int i = 0; i < r - 1; ++i) {
			for (int j = 0; j < c; ++j) {
				if (l.contains(i * c + j) && l.contains(i * c + j + c)) {
					n++;
				}
			}
		}
		return n;
	}
	
	public void solve(final Scanner sc, final PrintWriter pw) {
		final int r = sc.nextInt();
		final int c = sc.nextInt();
		final int n = sc.nextInt();
		
		int x = r * c;
		
		int[] a = new int[n];
		for (int i = 0; i < n; ++i) {
			a[i] = i;
		}
		
		int best = Integer.MAX_VALUE;
		while (true) {
			int t = check(r, c, a);
			if (t < best) {
				best = t;
			}
			int i;
			for (i = n - 1; i >= 0; --i) {
				if (a[i] + n - i < x) {
					break;
				}
			}
			if (i < 0) {
				break;
			}
			a[i]++;
			while (++i < n) {
				a[i] = a[i - 1] + 1;
			}
		}
		pw.println(best);
	}
	
	public static void main(final String... args) throws IOException {
		final String fname = "B-small-attempt0";
		final Scanner sc = new Scanner(new File(fname + ".in"));
		final PrintWriter pw = new PrintWriter(fname + ".out");
		final int t = sc.nextInt();
		
		for (int i = 1; i <= t; ++i) {
			System.out.println(i);
			pw.print("Case #" + i + ": ");
			new B_1_neighbors().solve(sc, pw);
		}
		pw.close();
	}
}
