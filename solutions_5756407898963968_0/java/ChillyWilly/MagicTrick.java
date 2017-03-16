
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.Scanner;

/**
 * @author Adrian Buturuga
 */
public class MagicTrick {
	
	private static void solveTestCase(int testCase, Scanner input, FileOutputStream output) throws IOException {
		int row = input.nextInt();
		// First selection
		int selected[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
		for (int i=1; i<=4; i++) {
			for (int j=0; j<4; j++) {
				int read = input.nextInt();
				if (i == row) {
					selected[read-1]++;
				}
			}
		}
		// Second selection
		row = input.nextInt();
		for (int i=1; i<=4; i++) {
			for (int j=0; j<4; j++) {
				int read = input.nextInt();
				if (i == row) {
					selected[read-1]++;
				}
			}
		}
		int found = 0;
		for (int i=0; i<16; i++) {
			if (selected[i] == 2) {
				if (found > 0) {
					output.write(("Case #"+testCase+": Bad magician!\n").getBytes());
					return;
				}
				found = i+1;
			}
		}
		if (found == 0) {
			output.write(("Case #"+testCase+": Volunteer cheated!\n").getBytes());
		}
		else {
			output.write(("Case #"+testCase+": "+found+"\n").getBytes());
		}
	}
	
	public static void main(String args[]) throws Exception {
		File inputFile = new File("A-small-attempt0.in");
		Scanner input = new Scanner(inputFile);
		
		File outputFile = new File("A-small-attempt0.out");
		FileOutputStream fos = new FileOutputStream(outputFile);
		
		int testCases = input.nextInt();
		
		for (int i=1; i<=testCases; i++) {
			solveTestCase(i, input, fos);
		}
		
		input.close();
		fos.close();
	}
}
