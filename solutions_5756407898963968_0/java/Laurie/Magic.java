import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;


public class Magic {

	/**
	 * @param args
	 * @throws FileNotFoundException 
	 */
	public static void main(String[] args) throws FileNotFoundException {
		Scanner in = new Scanner (new File("m.in"));
		int cases = in.nextInt();
		
		for (int caseNo = 1; caseNo <= cases; caseNo++)
		{
		   System.out.print("Case #" + caseNo + ": ");
		   solve (in);   
		}

	}

	private static void solve(Scanner in) {
		int guess1 = in.nextInt();
		int[] row1 = new int [4];
		
		for (int row = 1; row <= 4; row++) {
			for (int col = 0; col < 4; col ++) {
				int val = in.nextInt();
				if (row == guess1)
					row1[col] = val;
			}
		}
		
		int guess2 = in.nextInt();
		//int[] row1 = new int [4];
		int correct = 0;
		
		for (int row = 1; row <= 4; row++) {
			for (int col = 0; col < 4; col ++) {
				int val = in.nextInt();
				if (row == guess2) {
					if (contains (row1, val) && correct == 0)
						correct = val;
					else if (contains (row1, val) ) {
						correct = -10;
					}
				}
					
			}
		}
		if (correct > 0)
			System.out.println (correct);
		else if (correct == 0)
			System.out.println ("Volunteer cheated!");
		else
			System.out.println ("Bad magician!");
	}

	private static boolean contains(int[] row1, int val) {
		for (int i : row1)
			if (i == val)
				return true;
		return false;
	}

}
