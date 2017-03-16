#include <bits/stdc++.h>
using namespace std;
const int N = 6; 
int g[N][N];

void solve(int t)
{
	memset(g, 0, sizeof(g));
	int r, c, n, q;
	scanf("%d %d %d", &r, &c, &n);
	q = 0;
	int res = INT_MAX;

	for (int i = 0; i<(1 << r*c); i++){
		int cellCount = 0, ans = 0;
		for (int j = 0; j < r*c; j++){
			if (i & (1 << j)){
				cellCount++;
				g[j/c][j%c] = 1;
			}
		}
		if (cellCount == n){
			for (int k = 0; k < r; k++){
				for (int s = 0; s < c; s++){
					if (g[k][s] == 0) continue;
					if (k > 0) ans += g[k-1][s];
					if (s > 0) ans += g[k][s-1];
					if (k < r-1) ans += g[k+1][s];
					if (s < c-1) ans += g[k][s+1];
					g[k][s] = 0;
				}
			}

			res = min(res, ans);
		}
		memset(g, 0, sizeof(g));
	}
	printf("Case #%d: %d\n", t, res);
}

int main()
{
	int t;
	cin >> t;
	for (int i = 1; i<=t; i++)
		solve(i);
	return 0;
}