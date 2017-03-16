import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int tests = s.nextInt();
		for(int t = 0; t < tests; ++t) {
			int numParties = s.nextInt();
			int[] numbers = new int[numParties];
			int sum = 0;
			for(int i = 0; i < numParties; ++i) {
				int x = s.nextInt();
				numbers[i] = x;
				sum += x;
			}

			String answer = "";

			while(sum > 0) {
				if(sum == 3) {
					// Remove 1
					int pos = maxPos(numbers, -1);
					numbers[pos]--;
					sum--;
					answer = answer + getChar(pos) + " ";
					continue;
				}
				// Remove 2
				int pos1 = maxPos(numbers, -1);
				int pos2 = maxPos(numbers, pos1);
				numbers[pos1]--;
				numbers[pos2]--;
				sum -= 2;
				answer = answer + getChar(pos1) + getChar(pos2) + " ";
			}

			System.out.printf("Case #%d: %s\n", t + 1, answer.substring(0, answer.length()-1));
		}
	}
	
	public static int maxPos(int[] array, int exclude) {
		int max = -1;
		int pos = -1;
		for(int i = 0; i < array.length; ++i) {
			if(array[i] > max && i != exclude){
				max = array[i];
				pos = i;
			}
		}
		return pos;
	}

	public static char getChar(int x) {
		return "ABCDEFGHIJKLMNOPQRSTUVWXYZ".charAt(x);
	}

}