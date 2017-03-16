import java.util.Scanner;


public class MagicTrick {
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		int lines1[][] = new int[4][4];
		int lines2[][] = new int[4][4];
		for (int caseNum = 1; caseNum <= T; caseNum++) {
			int a1 = in.nextInt() - 1;
			for (int r = 0; r < 4; r++) {
				for (int c = 0; c < 4; c++) {
					lines1[r][c] = in.nextInt();
				}
			}
			int a2 = in.nextInt() - 1;
			for (int r = 0; r < 4; r++) {
				for (int c = 0; c < 4; c++) {
					lines2[r][c] = in.nextInt();
				}
			}
			
			int answer = -1;
			
			for (int c1 = 0; c1 < 4 && answer >= -1; c1++) {
				for (int c2 = 0; c2 < 4 && answer >= -1; c2++) {
					if (lines1[a1][c1] == lines2[a2][c2]) {
						if (answer != -1) {
							// Bad magician.
							answer = -2;
						}
						else {
							answer = lines1[a1][c1];
						}
					}
				}
			}
			
			System.out.print("Case #" + caseNum + ": ");
			switch (answer) {
			case -2:
				System.out.println("Bad magician!");
				break;
				
			case -1:
				System.out.println("Volunteer cheated!");
				break;
				
			default:
				System.out.println(answer);
			}
		}
	}
}
