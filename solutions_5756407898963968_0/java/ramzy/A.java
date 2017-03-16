package codejam.qualification;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Scanner;


public class A {

	private final static boolean SMALL = true;
	
	public static void main(String[] args) throws Exception {
		Scanner input = new Scanner(new FileReader("src/A-" + (SMALL ? "small" : "big") + ".in"));
		PrintWriter output = new PrintWriter("src/A-" + (SMALL ? "small" : "big") + ".out");

		String out;
		int N = input.nextInt();
		for(int i = 1; i <= N; i++) {
			int a1 = input.nextInt();
			int[][] g1 = new int[4][4];
			for (int j = 0; j < 16; j++) {
				g1[j/4][j%4] = input.nextInt();
			}
			int a2 = input.nextInt();
			int[][] g2 = new int[4][4];
			for (int j = 0; j < 16; j++) {
				g2[j/4][j%4] = input.nextInt();
			}
			out = "Case #" + i + ": " + solve(a1, g1, a2, g2);
			output.println(out);
			System.out.println(out);
		}
		input.close();
		output.close();
	}
	
	private static String solve(int a1, int[][] g1, int a2, int[][] g2) {
		int[] n1 = g1[a1-1];
		int[] n2 = g2[a2-1];
		int number = -1;
		boolean found = false;
		boolean second = false;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (n1[i] == n2[j]) {
					number = n1[i];
					if (found) second = true;
					found = true;
				}
			}
		}
		if (found && !second) {
			return number + "";
		} else if (found) {
			return "Bad magician!";
		} else {
			return "Volunteer cheated!";
		}
	}

}
