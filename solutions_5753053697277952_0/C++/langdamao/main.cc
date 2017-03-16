#include <cstdio>

int n;
int a[26];

int main() {
	int t, tt;
	scanf("%d", &t);
	for (tt = 1; tt <= t; tt++) {
		scanf("%d", &n);
		int sum = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			sum += a[i];
		}
		printf("Case #%d: ", tt);
		int out = 0;
		while (sum > 2) {
			int ans = -1;
			for (int i = 0; i < n; i++) {
				if (ans == -1 || a[i] > a[ans]) ans = i;
			}
			printf("%c", 'A' + ans);
			a[ans]--;
			sum--;
			out++;
			if (out % 2 == 0) printf(" ");
		}
		if (out % 2 != 0) printf(" ");
		for (int i = 0; i < n; i++) if (a[i]) printf("%c", 'A' + i);
		printf("\n");
	}
	return 0;
}
