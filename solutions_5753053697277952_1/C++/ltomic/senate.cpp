#include <cstdio>

const int MAXP = 30;

int T, n, P[MAXP], sum;

bool check(int P[], int sum) {
	for (int i = 0; i < n; ++i) {
		if (P[i] > sum/2) return false;
	}
	return true;
}

int main() {
	scanf("%d", &T);
	for (int t = 1; t <= T; ++t) {
		scanf("%d", &n);
		sum = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%d", P+i);
			sum += P[i];
		}
		
		printf("Case #%d: ", t);
		while (sum > 0) {
			bool flag = 1;
			for (int i = 0; i < n && flag; ++i) {
				if (P[i] == 0) continue;
				for (int j = i; j < n && flag; ++j) {
					if (i == j && P[i] < 2) continue;
					if (P[j] == 0) continue;
					P[i]--;
					P[j]--;
					sum -= 2;
					if (check(P, sum)) {
						flag = 0;
						printf("%c%c ", i+'A', j+'A');
					} else {
						P[i]++;
						P[j]++;
						sum += 2;
					}
				}
			}

			for (int i = 0; i < n && flag; ++i) {
				if (P[i] == 0) continue;
				P[i]--;
				sum--;
				if (check(P, sum)) {
					flag = 0;
					printf("%c ", i+'A');
				} else {
					P[i]++;
					sum++;
				}
			}

			if (flag) printf("ERROR\n");
		}
		printf("\n");
	}
	return 0;
}

