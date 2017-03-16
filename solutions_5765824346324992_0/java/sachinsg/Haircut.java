import java.util.Scanner;

public class Haircut {


	private static int gcd(int a, int b)
	{
		while (b > 0)
		{
			int temp = b;
			b = a % b; // % is remainder
			a = temp;
		}
		return a;
	}

	private static int gcd(int[] input)
	{
		int result = input[0];
		for(int i = 1; i < input.length; i++) result = gcd(result, input[i]);
		return result;
	}

	private static int lcm(int a, int b)
	{
		return a * (b / gcd(a, b));
	}

	private static int lcm(int[] input)
	{
		int result = input[0];
		for(int i = 1; i < input.length; i++) result = lcm(result, input[i]);
		return result;
	}

	private static void processInput(int c, Scanner in) {

		int B = in.nextInt();
		int M = in.nextInt();

		int[] time = new int[B];

		for (int i = 0; i < B; i++) {
			time[i] = in.nextInt();
		}

		int multiple = lcm(time);
		//System.out.println(multiple);


		int[] factor = new int[B];
		int sumInOneIteration = 0;
		for (int i = 0; i < B; i++) {
			factor[i] = multiple / time[i];
			sumInOneIteration += factor[i];
		}
//		System.out.println(sumInOneIteration);

		int iterations = M / multiple;
		int remainder = M % sumInOneIteration;
		remainder += sumInOneIteration;
//		System.out.println(remainder);

		int output = 0;
		if (remainder == 0) {
			output = B;
		} else {
			int[] nextAvailableAt = new int[B];
			for (int i = 0; i < B; i++) {
				nextAvailableAt[i] = 0;
			}



			int minB = 0;
			for (int i = 0; i < remainder; i++) {
				int min = Integer.MAX_VALUE;
				for (int j = B-1; j >= 0; j--) {
					if (nextAvailableAt[j] <= min) {
						min = nextAvailableAt[j];
						minB = j;
					}
				}
				nextAvailableAt[minB] += time[minB];
//							System.out.println(minB + 1);
//							System.out.println(nextAvailableAt[minB]);
//							System.out.println();
			}

			output = minB + 1;
		}




		/*int[] nextAvailableAt = new int[B];
		for (int i = 0; i < B; i++) {
			nextAvailableAt[i] = 0;
		}



		int minB = 0;
		for (int i = 0; i < M; i++) {
			int min = Integer.MAX_VALUE;
			for (int j = B-1; j >= 0; j--) {
				if (nextAvailableAt[j] <= min) {
					min = nextAvailableAt[j];
					minB = j;
				}
			}
			nextAvailableAt[minB] += time[minB];
//			System.out.println(minB + 1);
//			System.out.println(nextAvailableAt[minB]);
//			System.out.println();
		}

		int output = minB + 1;*/
		System.out.println("Case #" + (c + 1) + ": " + output);
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