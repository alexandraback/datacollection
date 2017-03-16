import java.io.*;
import java.util.*;

public class P2 {

	public static void main(String[] args) throws Exception {
		Scanner scan = new Scanner(new File("in.txt"));
		PrintWriter w = new PrintWriter("out.txt");

		int cases = Integer.parseInt(scan.nextLine());

		for (int i = 0; i < cases; i++) {
			int ans = 0;

			int b = scan.nextInt();
			int n = scan.nextInt();

			int[] ms = new int[b];

			for (int j = 0; j < b; j++) {
				ms[j] = scan.nextInt();
			}

			if (n <= b) {
				ans = n;
			} else {
				int lcmVal = lcm(ms);

				int covered = 0;
				for (int j = 0; j < b; j++) {
					covered += lcmVal / ms[j];
				}

				int step = n / covered;
				int cn = step * covered;

				if (cn == n) {
					cn = (step - 1) * covered;
				}

				cn++;
				int[] spent = new int[b];

				loop: for (;;) {
					int lowest = Integer.MAX_VALUE;
					int toAdd = 0;

					for (int j = 0; j < b; j++) {
						if (spent[j] < lowest) {
							toAdd = j;
							lowest = spent[j];
						}
					}

					if (cn == n) {
						ans = toAdd + 1;
						break loop;
					}
					cn++;
					spent[toAdd] += ms[toAdd];
				}
			}

			w.print("Case #");
			w.print(i + 1);
			w.print(": ");
			w.print(ans);
			w.println();
		}

		scan.close();
		w.close();
	}

	private static int gcd(int a, int b) {
		while (b > 0) {
			int temp = b;
			b = a % b;
			a = temp;
		}
		return a;
	}

	private static int lcm(int a, int b) {
		return a * (b / gcd(a, b));
	}

	private static int lcm(int[] input) {
		int result = input[0];
		for (int i = 1; i < input.length; i++) {
			result = lcm(result, input[i]);
		}
		return result;
	}

}
