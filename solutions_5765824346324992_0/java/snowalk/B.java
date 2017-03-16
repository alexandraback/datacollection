/**
 * 
 */
package google.codejam.fifteen.oneA;

import google.codejam.tools.QuestionFile;

import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

/**
 * @author ya
 * 
 */
public class B {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		QuestionFile file = new QuestionFile(
				B.class.getResourceAsStream("B-small-attempt1 (1).in"), "B.out");
		int queNum = file.getLength();
		try {
			for (int t = 0; t < queNum; t++) {
				System.out.println("solving: " + t);
				String line = file.getLine();
				String[] nums = line.split(" ");
				int B = Integer.parseInt(nums[0]);
				int N = Integer.parseInt(nums[1]);
				line = file.getLine();
				nums = line.split(" ");
				int[] numbers = new int[B];
				for (int i = 0; i < B; i++) {
					numbers[i] = Integer.parseInt(nums[i]);
				}

				int result = solve(numbers, N);
				file.writeAns(t, result);
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
	public static int solve(int[] nums, int N) {
		if (N <= nums.length)
			return N;
		int B = nums.length;
		List<Baber> babers = new ArrayList<Baber>();
		for (int i = 0; i < B; i++) {
			babers.add(new Baber(i + 1, nums[i]));
		}
		Collections.sort(babers);
		int time = 0;
		int n = B;
		int circle = 0;
		boolean foundcircle = false;
		int lastbaber = 0;
		while (true) {
			int reseted = 0;
			time = babers.get(0).timeremain;
			for (Baber b : babers) {
				b.timeremain -= time;
				if (b.timeremain == 0) {
					n++;
					circle++;
					if (n == N)
						return b.pos;
					else {
						reseted++;
						b.timeremain = b.time;
						lastbaber = b.pos;
					}
				}
			}
			Collections.sort(babers);
			if (reseted == B && !foundcircle) {
				n = (N - B) / circle * circle + B;
				if (n == N)
					return lastbaber;
				foundcircle = true;
			}
		}
	}
}

class Baber implements Comparable<Baber> {

	int pos;
	int time;
	int timeremain;

	public Baber(int pos, int time) {
		this.pos = pos;
		this.time = time;
		this.timeremain = time;
	}

	/*
	 * (non-Javadoc)
	 * 
	 * @see java.lang.Comparable#compareTo(java.lang.Object)
	 */
	@Override
	public int compareTo(Baber o) {
		if (timeremain - o.timeremain == 0)
			return pos - o.pos;
		return timeremain - o.timeremain;
	}

}
