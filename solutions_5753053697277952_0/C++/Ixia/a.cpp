#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
typedef long long ll;

int P[32], rnk[32];
bool cmp(int a, int b) {
	return P[a] > P[b];
}

int main() {
	freopen("A-small-attempt1.in", "r", stdin);
	freopen("A.out", "w", stdout);
	int _, cas = 1;
	scanf("%d", &_);
	while (_--) {
		printf("Case #%d: ", cas);
		++cas;
		
		int n, sum = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &P[i]);
			sum += P[i];
		}
		while (sum > 0) {
			int chos[2] = {-1, -1};
			int k = 0;
			if (sum <= 2) {
				for (int i = 0; i < n; ++i) {
					if (P[i]) {
						chos[k++] = i;
					}
				}
			} else {
				for (int i = 0; i < n; ++i) rnk[i] = i;
				sort(rnk, rnk + n, cmp);
				if (n >= 3 && P[rnk[2]] * 2 > sum - 2) {
					chos[0] = rnk[0];
					k = 1;
				} else {
					chos[0] = rnk[0];
					chos[1] = rnk[1];
					k = 2;
				}
			}
			if (k == 1) {
				printf("%c ", 'A' + chos[0]);
				sum -= 1;
				P[chos[0]] -= 1;
			} else {
				printf("%c%c ", 'A' + chos[0], 'A' + chos[1]);
				sum -= 2;
				P[chos[0]] -= 1;
				P[chos[1]] -= 1;
			}
		}
		puts("");
	}
 	return 0;
}