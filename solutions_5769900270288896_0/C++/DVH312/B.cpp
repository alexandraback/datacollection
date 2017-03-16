#include <bits/stdc++.h>
using namespace std;
const int Nmax = 1000000;
int T, n;
int m, k;
int res;
int f[22][22];
int dq(int x, int y, int unhappy, int cnt){
	if (cnt == k) {
		res = min(res, unhappy);
		return 0;
	}

	if (y > m) {
		dq(x + 1, 1, unhappy, cnt);
		return 0;
	}
	if (x > n) return 0;

	for (int i = 0; i <= 1; i++){
		f[x][y] = i;
		int new_unhappy = unhappy;
		if (i == 1){
			if (f[x - 1][y] == 1) new_unhappy++;
			if (f[x][y - 1] == 1) new_unhappy++;
			dq(x, y + 1, new_unhappy, cnt + 1);
		} else dq(x, y + 1, new_unhappy, cnt);
	}
}
int main(){	
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);

	scanf("%d", &T);
	for (int test = 1; test <= T; test++){
		scanf("%d %d %d", &n, &m, &k);

		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++) f[i][j] = 0;
		}

		res = 1000000;
		dq(1, 1, 0, 0);

		printf("Case #%d: %d\n", test, res);
	}
	return 0;
}