import java.io.FileInputStream;
import java.util.Scanner;

// Magic Trick
// https://code.google.com/codejam/contest/2974486/dashboard

public class A {

	private static String process(Scanner in) {
		int[] cards1 = new int[4];
		int answer1 = in.nextInt();
		for(int row = 0; row < 4; row++)
			for(int item = 0; item < 4; item++) {
				int card = in.nextInt();
				if ( row + 1 == answer1 )
					cards1[item] = card;
			}
		int answer2 = in.nextInt();
		int matchCount = 0;
		int matchCard = 0;
		for(int row = 0; row < 4; row++)
			for(int item = 0; item < 4; item++) {
				int card = in.nextInt();
				if ( row + 1 == answer2 )
					for(int i = 0; i < 4; i++)
						if ( cards1[i] == card ) {
							matchCount++;
							matchCard = card;
						}
			}
		return matchCount == 1 ? Integer.toString(matchCard) : matchCount == 0 ? "Volunteer cheated!" : "Bad magician!";
	}

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in.available() > 0 ? System.in : 
			new FileInputStream(Thread.currentThread().getStackTrace()[1].getClassName() + ".practice.in"));
		int T = in.nextInt();
		for(int i = 1; i <= T; i++) 
			System.out.format("Case #%d: %s\n", i, process(in));
	}
}
