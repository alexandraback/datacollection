#include <stdio.h>

int b[1000];
int t[1000];

int GCD(int a, int b) {
	int r = a % b;
	if (r == 0)
		return b;
	return GCD(b, r);
}

int MDN(int N) {
	int lcm = b[0];

	for (int i = 1; i < N; i++) {
		int temp = GCD(lcm, b[i]);
		lcm = lcm / temp * b[i];
	}

	int total = 0;
	for (int i = 0; i < N; i++) {
		total += (lcm / b[i]);
	}

	return total;
}

int main()
{
	int T;
	scanf("%d", &T);

	for (int w = 0; w < T; w++) {
		int B, N;
		scanf("%d %d", &B, &N);

		for (int i = 0; i < B; i++) {
			scanf("%d", &b[i]);
		}

		int mdn = MDN(B);
		N = N % mdn + mdn;

		for (int i = 0; i < B; i++) t[i] = 0;
		while (1) {
			int mini = 987654321;
			int mini_index = -1;
			for (int i = 0; i < B; i++) {
				if (mini > t[i]) {
					mini = t[i];
					mini_index = i;
				}
			}

			for (int i = 0; i < B; i++)
				t[i] = t[i] == 0 ? 0 : t[i] - mini;
			t[mini_index] = b[mini_index];
			
			N--;
			if (N == 0) {
				printf("Case #%d: %d\n", w + 1, mini_index + 1);
				break;
			}
		}


	}

	return 0;
}