#include <bits/stdc++.h>

using namespace std;

int p[30];

int main() {
	int T;
	scanf("%d", &T);
	for (int tt = 1; tt <= T; tt++) {
		int n;
		scanf("%d", &n);
		int sum = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &p[i]);
			sum += p[i];
		}
		printf("Case #%d:", tt);
		while (sum > 0) {
			int t1 = 0;
			int t2 = 0;
			for (int i = 1; i <= n; i++) {
				if (p[i] > p[t1]) {
					t2 = t1;
					t1 = i;
				}
				else if(p[i] > p[t2]) {
					t2 = i;
				}
			}
			//cout << t1 << ' ' << t2 << endl;
			if (p[t1] + p[t2] == sum && p[t1] == p[t2]) {
				printf(" %c%c", 'A'+t1-1, 'A'+t2-1);
				p[t1]--;
				p[t2]--;
				sum -= 2;
			}
			else {
				printf(" %c", 'A'+t1-1);
				p[t1]--;
				sum -= 1;
			}
		}
		puts("");
	}
	return 0;
}
