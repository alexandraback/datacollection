import java.util.Scanner;

public class Mush {

	private static void processInput(int c, Scanner in) {

		int N = in.nextInt();
		int[] mush = new int[N];
		for (int i = 0; i < N; i++) {
			mush[i] = in.nextInt();
		}
		int firstOutput = 0;
		for (int i = 0; i < N - 1; i++) {
			int diff = mush[i] - mush[i+1];
			if (diff > 0) {
				firstOutput += diff;
			}
		}
		
		int secondOutput = 0;
		int maxDiff = 0;
		for (int i = 0; i < N - 1; i++) {
			int diff = mush[i] - mush[i+1];
			if (diff > maxDiff) {
				maxDiff = diff;
			}
		}
		
		for (int i = 0; i < N - 1; i++) {
			if (mush[i] > maxDiff) {
				secondOutput += maxDiff;
			} else {
				secondOutput += mush[i];
			}
		}
		
		
		
		System.out.println("Case #" + (c + 1) + ": " + firstOutput + " " + secondOutput);
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Scanner in = new Scanner(System.in);
		int T = in.nextInt();

		for (int i = 0; i < T; i++) {
			processInput(i, in);
		}
		in.close();

	}

}