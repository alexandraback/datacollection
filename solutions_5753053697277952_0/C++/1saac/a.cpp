#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

int cnt[30];
char ans[100010];
int tn;

int main() {


	//freopen("A-small-attempt2.in", "r", stdin);
	//freopen("A-small-attempt2.out", "w", stdout);


	int t;
	int n;
	int i;
	int maxn, pos, rem;
	cin >> t;
	for (int cas = 1; cas <= t; cas++) {
		cin >> n;
		memset(cnt, 0, sizeof(cnt));
		memset(ans, 0, sizeof(ans));
		tn = 0;
		for (i = 0; i < n; i++)
			cin >> cnt[i];
		getchar();
		printf("Case #%d:", cas);
		while (1) {
			rem = maxn = 0;
			pos = -1;
			for (i = 0; i < n; i++) {
				if (cnt[i] > 0) {
					rem += 1;
					if (cnt[i] > maxn) {
						maxn = cnt[i];
						pos = i;
					}
				}
			}
			if (pos < 0)
				break;
			if (rem == 2 && maxn == 1) {
				for (i = 0; i < n; i++)
					if (cnt[i] > 0) {
						ans[tn++] = i+65;
						cnt[i] -= 1;
					}
			} else {
				ans[tn++] = pos+65;
				cnt[pos] -= 1;
			}
		}
		i = 0;
		if (tn % 2 == 1) {
			printf(" %c", ans[i]);
			i += 1;
		}
		for ( ; ans[i]; i += 2)
			printf(" %c%c", ans[i], ans[i+1]);
		printf("\n");
	}

	return 0;
}
