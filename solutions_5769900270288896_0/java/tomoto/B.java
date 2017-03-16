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
	private static final String FILE = "../B-small-attempt0";
	
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
		
		boolean[] occupation = new boolean[r * c];
		
		CheckUnhappinessVisitor v = new CheckUnhappinessVisitor();
		v.r = r;
		v.c = c;
		
		enumerate(occupation, 0, r*c, n, v);
		
		return v.minimumUnhappiness;
	}

	private void enumerate(boolean[] occupation, int i, int m, int n, Visitor v) {
		if (i == m) {
			v.process(occupation);
			return;
		}
		
		if (n > 0) {
			occupation[i] = true;
			enumerate(occupation, i+1, m, n-1, v);
		}
		
		if (m - i > n) {
			occupation[i] = false;
			enumerate(occupation, i+1, m, n, v);
		}
	}
	
	interface Visitor {
		void process(boolean[] occupation);
	}
	
	class CheckUnhappinessVisitor implements Visitor {
		public int minimumUnhappiness = Integer.MAX_VALUE;
		public int r;
		public int c;

		@Override
		public void process(boolean[] occupation) {
			int unhappiness = 0;
			
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c-1; j++) {
					if (occupation[i*c+j] && occupation[i*c+j+1]) {
						unhappiness++;
					}
				}
			}
			
			for (int i = 0; i < c; i++) {
				for (int j = 0; j < r-1; j++) {
					if (occupation[i+j*c] && occupation[i+j*c+c]) {
						unhappiness++;
					}
				}
			}
			
			if (unhappiness < minimumUnhappiness) {
				minimumUnhappiness = unhappiness;
			}
		}
		
	}
}

