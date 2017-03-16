import static org.junit.Assert.assertEquals;

import java.util.Locale;
import java.util.Scanner;

import org.junit.Test;

//jaap@beetstra-it.nl
public class Round1B2015B {
	static {
		Locale.setDefault(Locale.US);
	}

	@Test
	public void tests() throws Exception {
		assertEquals(7, solve("2 3 6"));
		assertEquals(0, solve("4 1 2"));
		assertEquals(8, solve("3 3 8"));
		assertEquals(0, solve("5 2 0"));
	}

	@Test
	public void tests3() throws Exception {
		assertEquals(12, solve("3 3 9"));
		assertEquals(8, solve("3 3 8"));
		assertEquals(6, solve("3 3 7"));
	}

	@Test
	public void tests4() throws Exception {
		assertEquals(24, solve("4 4 16"));
		assertEquals(16, solve("4 4 14"));
	}

	@Test
	public void tests4b() throws Exception {
		assertEquals(13, solve("4 4 13"));
		assertEquals(10, solve("4 4 12"));
		assertEquals(4, solve("4 4 10"));
		assertEquals(2, solve("4 4 9"));
		assertEquals(0, solve("4 4 8"));
	}

	@Test
	public void tests5() throws Exception {
		assertEquals(0, solve("16 1 8"));
		assertEquals(1, solve("16 1 9"));
		assertEquals(3, solve("16 1 10"));
	}

	@Test
	public void tests6() throws Exception {
		assertEquals(0, solve("8 2 8"));
		assertEquals(2, solve("8 2 9"));
		assertEquals(4, solve("8 2 10"));
		assertEquals(7, solve("8 2 11"));
	}

	@Test
	public void tests35() throws Exception {
		assertEquals(22, solve("3 5 15"));
		assertEquals(18, solve("3 5 14"));
		assertEquals(14, solve("3 5 13"));
		assertEquals(11, solve("3 5 12"));
		assertEquals(8, solve("3 5 11"));
		assertEquals(6, solve("3 5 10"));
	}

	@Test
	public void tests35b() throws Exception {
		assertEquals(3, solve("3 5 9"));
		assertEquals(0, solve("3 5 8"));
	}

	static int solve(String testCase) {
		return new Solver(new Scanner(testCase)).solve();
	}

	static class Solver {
		private final int r, c, n;

		public Solver(Scanner scanner) {
			this.r = scanner.nextInt();
			this.c = scanner.nextInt();
			this.n = scanner.nextInt();
		}

		public int solve() {
			return Math.min(startFromFull(), startFromEmpty());
		}

		private int startFromEmpty() {
			int max = r * c;
			if (n <= (max + 1) / 2)
				return 0;
			int apartmentsToFill = n - ((max + 1) / 2);
			int sharedWalls = 0;
			if (r >= 2 && c >= 2) {
				int twoSided = (r % 2 == 0 || c % 2 == 0) ? 2 : 0;
				int fill2 = Math.min(twoSided, apartmentsToFill);
				sharedWalls += 2 * fill2;
				apartmentsToFill -= fill2;
			}
			if (r >= 2 && c >= 2) {
				int threeSided = ((r - 1) / 2) * 2 + ((c - 1) / 2) * 2 - (r % 2) * 2 - (c % 2) * 2;
				int fill3 = Math.min(threeSided, apartmentsToFill);
				sharedWalls += 3 * fill3;
				apartmentsToFill -= fill3;
			}
			return sharedWalls + apartmentsToFill * 4;
		}

		protected int startFromFull() {
			int max = r * c;
			int sharedWalls = (r - 1) * c + (c - 1) * r;
			int emptyApartments = max - n;
			if (r > 2 && c > 2) {
				int wins4 = ((r - 2) * (c - 2) + 1) / 2;
				int empty4 = Math.min(wins4, emptyApartments);
				sharedWalls -= 4 * empty4;
				emptyApartments -= empty4;
			}
			if (emptyApartments > 0 && r >= 2 && c >= 2) {
				// keep empty 4 sided in mind
				int threeSided = ((r - 1) / 2) * 2 + ((c - 1) / 2) * 2 - (r % 2) * 2 - (c % 2) * 2;
				int empty3 = Math.min(threeSided, emptyApartments);
				sharedWalls -= 3 * empty3;
				emptyApartments -= empty3;
			}
			return Math.max(0, sharedWalls - emptyApartments * 2);
		}
	}

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int nrOfTestCases = scanner.nextInt();
		for (int caseNr = 1; caseNr <= nrOfTestCases; caseNr++) {
			Object solution = new Solver(scanner).solve();
			System.out.println("Case #" + caseNr + ": " + solution);
		}
	}
}
