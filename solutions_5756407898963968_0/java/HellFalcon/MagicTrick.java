import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Scanner;

public class MagicTrick {
	
	public static int readRow(Scanner in) {
		int rowId = in.nextInt();
		int row = 0;
		for (int i = 1; i <= 4; i++)
			for (int j = 1; j <= 4; j++) {
				int v = in.nextInt();
				if (i == rowId) row |= 1 << v;
			}
		return row;
	}
	
	public static void main(String[] args) {
		try {
			Scanner in = new Scanner(new BufferedReader(new FileReader(new File("A-small-attempt0.in")), 256 << 10));
			BufferedWriter out = new BufferedWriter(new FileWriter(new File("output.txt")), 256 << 10);

			int testsNumber = in.nextInt();
			for (int testId = 1; testId <= testsNumber; testId++) {
				int nums = readRow(in) & readRow(in);
				out.append("Case #" + testId + ": ");
				if (Integer.bitCount(nums) == 0) {
					out.append("Volunteer cheated!");
				}
				else if (Integer.bitCount(nums) > 1) {
					out.append("Bad magician!");
				}
				else {
					out.append(Integer.toString(Integer.numberOfTrailingZeros(nums)));
				}
				out.append("\n");
			}
			in.close();
			out.close();
		}
		catch (Exception e) {
			System.err.println("Error:" + e.getMessage());
		}
	}
}
