/**
 * 
 */
package google.codejam.fourteen.qua;

import google.codejam.tools.QuestionFile;
import java.io.IOException;

/**
 * @author ya
 * 
 */
public class A {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		QuestionFile file = new QuestionFile(
				A.class.getResourceAsStream("A-small-attempt0.in"), "A.out");
		int queNum = file.getLength();
		try {
			for (int t = 0; t < queNum; t++) {
				String line = file.getLine();
				int ans1 = Integer.parseInt(line);
				int[][] matrix1 = new int[4][4];
				for (int i = 0; i < 4; i++) {
					line = file.getLine();
					String[] nums = line.split(" ");
					for (int j = 0; j < 4; j++) {
						matrix1[i][j] = Integer.parseInt(nums[j]);
					}
				}

				line = file.getLine();
				int ans2 = Integer.parseInt(line);
				int[][] matrix2 = new int[4][4];
				for (int i = 0; i < 4; i++) {
					line = file.getLine();
					String[] nums = line.split(" ");
					for (int j = 0; j < 4; j++) {
						matrix2[i][j] = Integer.parseInt(nums[j]);
					}
				}

				int result = solve(ans1, matrix1, ans2, matrix2);
				if (result == -1)
					file.writeAns(t, "Volunteer cheated!");
				else if (result == 0)
					file.writeAns(t, "Bad magician!");
				else
					file.writeAns(t, result);
			}
			file.end();
		} catch (IOException e) {
			e.printStackTrace();
		}

	}

	static int solve(int ans1, int[][] matrix1, int ans2, int[][] matrix2) {
		int[] line1 = matrix1[ans1 - 1];
		int[] line2 = matrix2[ans2 - 1];

		int count = 0;
		int num = -1;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (line1[i] == line2[j]) {
					count++;
					num = line1[i];
				}
			}
		}
		if (count == 0)
			return -1;
		else if (count == 1)
			return num;
		else
			return 0;
	}
}
