// -Wl,--stack,9001 
#include <iostream>
#include <sstream>
#include <cmath>
#include <string>
#include <string.h>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <cassert>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define sz(x) ((int)((x).size()))
#define rep(i, N) for (int i = 0; i < N; ++i)
#define foreach(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();++it)
typedef long long lint;
typedef vector<string> vs;
typedef vector<int> vi;
typedef pair<int, int> pii;

int R, C, N;
int CB[1 << 20];
int F[1 << 20];

int dp[16][1 << 16][16 + 1];

vi G[(1 << 16) + 1];

bool testBit(int use, int p) {
	return (use >> p) & 1;
}

void init() {
	for (int i = 1; i < (1 << 16); ++i) {
		CB[i] = CB[i >> 1] + (i & 1);
	}
	for (int use = 0; use < (1 << 16); ++use) {
		G[CB[use]].pb(use);
	}
	for (int use = 0; use < (1 << 16); ++use) {
		for (int i = 0; i <= 15; ++i) {
			if (testBit(use, i) && testBit(use, i + 1)) {
				F[use]++;
			}
		}
	}
}

int rec(int k, int prev, int left) {
	if (k == R) return left == 0 ? 0 : 1 << 30;
	if (dp[k][prev][left] != -1) return dp[k][prev][left];
	int res = 1 << 30;
	for (int use = 0; use < (1 << C); ++use) {
	//	
	// for (int i = 0; i <= left; ++i) 
	// for (int j = 0; j < sz(G[i]); ++j) {
	// 	int use = G[i][j];				
		if (CB[use] > left) continue;
		int cur = CB[prev & use] + F[use];
		int tmp = rec(k + 1, use, left - CB[use]);
		if (tmp == 1<<30) continue;
		res = min(res, tmp + cur);
	}
	return dp[k][prev][left] = res;
}


void solve(int num) {	
	cin >> R >> C >> N;
	memset(dp, -1, sizeof(dp));
	int ans = rec(0, 0, N);	
	printf("Case #%d: %d\n", num, ans);
}

int main() {
	init();

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tst;
	cin >> tst;
	for (int i = 1; i <= tst; ++i) {
		solve(i);
	}
    return 0;
}
