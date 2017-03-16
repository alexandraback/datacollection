import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class B {
	public static void main(String[] args) throws FileNotFoundException {
		new B().run();
	}
	
	// private static final String FILE = "../sample";
	private static final String FILE = "../B-large";
	
	private Scanner scanner;
	private PrintWriter out;
	
	void run() throws FileNotFoundException {
		scanner = new Scanner(new File(FILE + ".in"));
		out = new PrintWriter(new File(FILE + ".out"));
		
		int n = scanner.nextInt();
		for (int i = 1; i <= n; i++) {
			solve(i);
		}
		
		scanner.close();
		out.close();
	}
	
	void solve(int index) {
		out.println("Case #" + index + ": " + solve1());
	}

	private int solve1() {
		int r = scanner.nextInt();
		int c = scanner.nextInt();
		int n = scanner.nextInt();
		
		System.err.println(r + "," + c + "," + n);
		
		if ((r * c + 1) >= n * 2) {
			return 0;
		}
		
		if (c == 1) {
			int a = c;
			c = r;
			r = a;
		}
		
		if (r == 1) {
			if (c % 2 == 0) {
				return calcUnhappiness(r, c, n, 0, 0, c/2-1, 1);
			} else {
				return Math.min(calcUnhappiness(r, c, n, 0, 0, (c-3)/2, 2), calcUnhappiness(r, c, n, 0, 0, (c-1)/2, 0));
			}
		} else if ((r % 2 == 0) || (c % 2 == 0)) {
			int na = (r-2) * (c-2) / 2;
			int nb = (r-2) + (c-2);
			return calcUnhappiness(r, c, n, na, nb, 2, 0);
		} else {
			int na1 = (r-2) * (c-2) / 2;
			int nb1 = (r-1) + (c-1);
			int na2 = na1 + 1;
			int nb2 = nb1 - 4;
			return Math.min(calcUnhappiness(r, c, n, na1, nb1, 0, 0), calcUnhappiness(r, c, n, na2, nb2, 4, 0));
		}
	}
	
	private int calcUnhappiness(int r, int c, int n, int na, int nb, int nc, int nd) {
		int result = (r-1)*c + (c-1)*r;
		int m = r*c - n;
		
		if (m <= na) {
			result -= 4 * m;
			return result;
		}
		
		result -= 4 * na;
		m -= na;
		
		if (m <= nb) {
			result -= 3 * m;
			return result;
		}
		
		result -= 3 * nb;
		m -= nb;
		
		if (m < nc) {
			result -= 2 * m;
			return result;
		}
		
		result -= 2 * nc;
		m -= nc;
		
		if (m < nd) {
			result -= m;
			return result;
		}
		
		throw new AssertionError();
	}

}

