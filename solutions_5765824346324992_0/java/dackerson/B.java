import java.util.*;

public class B {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int t = sc.nextInt();

		for (int caseNum = 1;  caseNum <= t; caseNum++) {
			int b = sc.nextInt();
			int n = sc.nextInt();
			int[] bs = new int[b];
			for (int i = 0; i < b; i++) {
				bs[i] = sc.nextInt();
			}

			int lcm = bs[0];
			for (int i = 1; i < b; i++) {
				lcm = bs[i] * (lcm / gcd(lcm, bs[i]));
			}

			int numInLine = 0;
			for (int i = 0; i < b; i++) {
				numInLine += lcm / bs[i];
			}

			n = (n - 1) % numInLine;

			int[] bsWait = new int[b];

			for (int i = 0; i < n; i++) {
				int min = Integer.MAX_VALUE;
				for (int j = 0; j < b; j++) {
					if (min > bsWait[j]) {
						min = bsWait[j];
					}
				}
				for (int j = 0; j < b; j++) {
					bsWait[j] -= min;
				}
				for (int j = 0; j < b; j++) {
					if (bsWait[j] == 0) {
						bsWait[j] = bs[j];
						break;
					}
				}
			}

			int min = Integer.MAX_VALUE;
			int openBarber = 0;
			for (int j = 0; j < b; j++) {
				if (min > bsWait[j]) {
					min = bsWait[j];
				}
			}
			for (int j = 0; j < b; j++) {
				bsWait[j] -= min;
			}
			for (int j = 0; j < b; j++) {
				if (bsWait[j] == 0) {
					openBarber = j;
					break;
				}
			}

			System.out.printf("Case #%d: %d\n", caseNum, openBarber + 1);

		}
	}

	public static int gcd(int a, int b) {
		if (b == 0) {
			return a;
		}
		else {
			return gcd(b, a % b);
		}
	}
}
