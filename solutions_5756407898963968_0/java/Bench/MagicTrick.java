import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.*;

public class MagicTrick {
	public static void main(String[] args) {
		Scanner scanner = null;
		try {
			scanner = new Scanner(new File("input.txt"));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		int T = scanner.nextInt();
		FileWriter writer = null;
		try {
			writer = new FileWriter(new File("output.txt"));
		} catch (IOException e1) {
			e1.printStackTrace();
		}
		for (int trial = 1; trial <= T; trial++) {
			try {
				writer.write("Case #" + trial + ": ");
			} catch (IOException e1) {
				e1.printStackTrace();
			}
			try {
				solveTrial(scanner, writer);
			} catch (IOException e) {
				e.printStackTrace();
			}
			try {
				writer.write("\n");
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
		try {
			writer.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
		scanner.close();
	}

	static void solveTrial(Scanner scanner, FileWriter writer)
			throws IOException {
		int row1 = scanner.nextInt();
		int[] first4 = new int[4];
		for (int i = 0; i < 4; i++) {
			if (i == row1 - 1) {
				for (int b = 0; b < 4; b++)
					first4[b] = scanner.nextInt();
			} else
				for (int b = 0; b < 4; b++)
					scanner.nextInt();
		}
		int row2 = scanner.nextInt();
		int finalAnswer = -1;
		for (int i = 0; i < 4; i++) {
			if (i == row2 - 1) {
				for (int b = 0; b < 4; b++) {
					int check = scanner.nextInt();
					for (int z = 0; z < 4 && finalAnswer != -2; z++) {
						if (first4[z] == check) {
							if (finalAnswer == -1)
								finalAnswer = check;
							else {
								writer.write("Bad magician!");
								finalAnswer = -2;
								break;
							}
						}
					}
				}
				if (finalAnswer == -1)
					writer.write("Volunteer cheated!");
				else if (finalAnswer != -2)
					writer.write(finalAnswer + " ");
			} else
				for (int b = 0; b < 4; b++)
					scanner.nextInt();
		}
	}
}
