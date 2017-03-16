import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class ProblemC1 {

	public static String[] letters = new String[] { "A", "B", "C", "D", "E",
			"F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R",
			"S", "T", "U", "V", "W", "X", "Y", "Z" };

	public static void main(String[] args) {
		Scanner in = new Scanner(new BufferedReader(new InputStreamReader(
				System.in)));
		int t = in.nextInt();
		System.out.println();
		for (int i = 1; i <= t; ++i) {
			int n = in.nextInt();

			int[] tab = new int[n];
			int sum = 0;
			for (int j = 0; j < n; ++j) {
				tab[j] = in.nextInt();
				sum += tab[j];
			}
			System.out.println("Case #" + i + ": " + getResponse(tab, sum));
		}
	}

	private static String getResponse(int[] tab, int sum) {
		String rep = "";
		if (sum % 2 == 0) {
			for (int i = 0; i < sum; i++) {
				int b = getBigger(tab);
				rep += letters[b];
				rep += i % 2 == 1 ? " " : "";
				tab[b]--;
			}
		} else {
			for (int i = 0; i < sum - 3; i++) {
				int b = getBigger(tab);
				rep += letters[b];
				rep += i % 2 == 1 ? " " : "";
				tab[b]--;
			}
			
			int b1 = getBigger(tab);
			rep += letters[b1];
			tab[b1]--;
			
			rep += " ";
			int b2 = getBigger(tab);
			rep += letters[b2];
			tab[b2]--;
			
			int b3 = getBigger(tab);
			rep += letters[b3];
			tab[b3]--;
		}

		return rep;
	}

	private static int getBigger(int[] tab) {
		int max = tab[0];
		int index = 0;
		for (int i = 0; i < tab.length; i++) {
			if (tab[i] > max) {
				max = tab[i];
				index = i;
			}
		}
		return index;
	}

}
