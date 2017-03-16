#include<bits/stdc++.h>

using namespace std;

#define dbg(x) (cout<<#x<<" = "<<(x)<<'\n')

typedef long long int lld;
const int INF = (1LL << 30) - 1;
const lld LINF = (1LL << 62) - 1;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int numberOfTests;
int R, C, N;
int P[20][20];
int S[20];
int sol;

void back(int top) {
	if (top > N) {
		int ans = 0;
		int i, j, k, a, b;

		for (i = 1; i <= R; i++)
			for (j = 1; j <= C; j++) {
				if (!P[i][j])
					continue;

				for (k = 0; k < 4; k++) {
					a = i + dx[k];
					b = j + dy[k];
					ans += P[a][b];
				}
			}

		sol = min(sol, ans / 2);

		return;
	}

	int i, x, y;

	for (i = S[top - 1] + 1; i <= R * C; i++) {
		S[top] = i;

		y = i % C;
		if (!y) y = C;
		x = (i - y) / C + 1;

		P[x][y] = 1;

		back(top + 1);

		P[x][y] = 0;
	}
}

int solve() {
	if (N <= (R * C + 1) / 2)
		return 0;

	sol = INF;

	back(1);

	return sol;
}

int main() {
	cin.sync_with_stdio(false);

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	scanf("%d", &numberOfTests);

	for (int testcase = 1; testcase <= numberOfTests; testcase++) {
		scanf("%d%d%d", &R, &C, &N);

		printf("Case #%d: %d\n", testcase, solve());
	}

	return 0;
}