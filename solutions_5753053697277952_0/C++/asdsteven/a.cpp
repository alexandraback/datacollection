#include <cstdio>

int N, p[27], sum;

void solve() {
	sum = 0;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", p + i), sum += p[i];
	while (sum) {
		int mx = 0;
		for (int i = 1; i <= N; i++)
			if (p[i] > p[mx])
				mx = i;
		p[mx]--;
		sum--;
		int my = 0;
		for (int i = 1; i <= N; i++)
			if (p[i] > p[my])
				my = i;
		putchar(' ');
		putchar('A' + mx - 1);
		p[my]--;
		sum--;
		int mz = 0;
		for (int i = 1; i <= N; i++)
			if (p[i] > p[mz])
				mz = i;
		if (p[mz] + p[mz] > sum) {
			p[my]++;
			sum++;
		} else {
			putchar('A' + my - 1);
		}
	}
}

int main() {
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		printf("Case #%d:", i);
		solve();
		printf("\n");
	}
}
