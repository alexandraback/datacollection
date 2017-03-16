import java.util.Locale;
import java.util.Scanner;

public class A {

	void solve(int icase) {
		int[] t = new int[17];
		inc(t);
		inc(t);

		printf("Case #%d: ", icase);

		int res = -1;
		for (int i = 1; i <= 16; i++) {
			if (t[i] == 2) {
				if (res != -1) {
					printf("Bad magician!\n");
					return;
				} else {
					res = i;
				}
			}
		}

		if (res == -1) {
			printf("Volunteer cheated!\n");
		} else {
			printf("%d\n", res);
		}
	}

	void inc(int[] t) {
		int ay = si();
		for (int iy = 1; iy <= 4; iy++) {
			for (int ix = 1; ix <= 4; ix++) {
				int k = si();
				if (iy == ay) {
					t[k]++;
				}
			}
		}
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
			System.err.println("[[ " + icase + " ]]");
		}
	}

	Scanner scanner;

	int si() {
		return scanner.nextInt();
	}

	long sl() {
		return scanner.nextLong();
	}

	double sd() {
		return scanner.nextDouble();
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
