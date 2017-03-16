import java.util.Arrays;
import java.util.Comparator;
import java.util.Locale;
import java.util.Scanner;

public class A {

	class X {
		char id;
		int num;
	}

	void sort(X[] p) {
		Arrays.sort(p, new Comparator<X>() {
			@Override
			public int compare(X a, X b) {
				return b.num - a.num;
			}
		});
	}

	void solve(int icase) {
		int n = si();
		X[] p = new X[n];

		int sum = 0;

		for (int i = 0; i < n; i++) {
			p[i] = new X();
			p[i].num = si();
			sum += p[i].num;
			p[i].id = (char) (i + 'A');
		}

		printf("Case #%d:", icase);

		sort(p);

		while (p[0].num > 0) {
			if (sum != 3 && p[0].num == p[1].num) {
				printf(" %c%c", p[0].id, p[1].id);
				p[0].num--;
				p[1].num--;
				sum -= 2;
			} else {
				printf(" %c", p[0].id);
				p[0].num--;
				sum--;
			}
			sort(p);
		}

		printf("\n");
	}

	public static void main(String[] args) throws Exception {
		Locale.setDefault(Locale.US);
		new A().repSolve();
	}

	void repSolve() throws Exception {
		scanner = new Scanner(System.in);
		// scanner = new Scanner(new java.io.File(""));

		int ncase = si();
		sline();

		for (int icase = 1; icase <= ncase; icase++) {
			solve(icase);
			// System.err.println("[[ " + icase + " ]]");
		}
	}

	Scanner scanner;

	int si() {
		return scanner.nextInt();
	}

	long sl() {
		return scanner.nextLong();
	}

	String ss() {
		return scanner.next();
	}

	String sline() {
		return scanner.nextLine();
	}

	void printf(String format, Object... args) {
		System.out.printf(format, args);
	}
}