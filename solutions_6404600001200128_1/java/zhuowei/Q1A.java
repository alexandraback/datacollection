import java.util.*;

public class Q1A {

	public static int solve1(int[] mush) {
		int count = 0;
		for (int i = 1; i < mush.length; i++) {
			if (mush[i] < mush[i-1]) {
				count += (mush[i-1] - mush[i]);
			}
		}
		return count;
	}

	public static int solve2(int[] mush) {
		// constant rate means 0 is a possible rate. Ugh
		int maxDelta = 0;
		for (int i = 1; i < mush.length; i++) {
			int newDelta = mush[i-1] - mush[i];
			if (newDelta > maxDelta) {
				maxDelta = newDelta;
			}
		}
		// max is the rate of mushrooms eaten per 10 seconds
		int count = 0;
		for (int i = 1; i < mush.length; i++) {
			int eaten = Math.min(maxDelta, mush[i - 1]);
			count += eaten;
		}
		return count;
	}

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int t = scan.nextInt();
		for (int i = 0; i < t; i++) {
			int n = scan.nextInt();
			int[] mush = new int[n];
			for (int j = 0; j < mush.length; j++) {
				mush[j] = scan.nextInt();
			}
			System.out.println("Case #" + (i + 1) + ": " + solve1(mush)
				+ " " + solve2(mush));
		}
	}
}
