/**
 * 
 */
package google.codejam.fifteen.oneA;

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
				A.class.getResourceAsStream("A-small-attempt0 (1).in"), "A.out");
		int queNum = file.getLength();
		try {
			for (int t = 0; t < queNum; t++) {
				String line = file.getLine();
				line = file.getLine();
				String[] nums = line.split(" ");
				int[] numbers = new int[nums.length];
				for (int i = 0; i < nums.length; i++) {
					numbers[i] = Integer.parseInt(nums[i]);
				}

				int result[] = solve1(numbers);
				file.writeAns(t, result[0] + " " + result[1]);
			}
			file.end();
		} catch (IOException e) {
			e.printStackTrace();
		}

	}

	/**
	 * @param N
	 * @return
	 */
	public static int[] solve1(int[] nums) {
		int result = 0;
		int maxint = 0;
		int result2 = 0;
		for (int i = 0; i < nums.length - 1; i++) {
			if (nums[i] <= nums[i + 1])
				continue;
			int interval = nums[i] - nums[i + 1];
			result += interval;
			if (maxint < interval) {
				maxint = interval;
			}
		}
		for (int i = 0; i < nums.length - 1; i++) {
			result2 += maxint > nums[i] ? nums[i] : maxint;
		}
		return new int[] { result, result2 };
	}
}
