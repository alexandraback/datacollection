#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <memory.h> 
#include <math.h> 
#include <assert.h> 
#include <stack> 
#include <queue> 
#include <map> 
#include <set> 
#include <algorithm> 
#include <string> 
#include <functional> 
#include <vector> 
#include <deque> 
#include <utility> 
#include <bitset> 
#include <limits.h>  
#include <unordered_map>

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
#define memset0(x) memset(x, 0, sizeof (x));
int TC, TCC;

int R, C, N;
bool a[1000][1000];
bool state[1000];
void init() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			a[i][j] = 0;
		}
	}
}

void solve() {
	scanf("%d%d%d", &R, &C, &N);

	int ans = (int)2e9;
	memset(state, 0, sizeof state);
	for (int i = 1; i <= N; i++) state[R*C - i] = true;
	do {
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				a[i][j] = state[i * C + j];
			}
		}
		int cnt = 0;
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (a[i][j] && a[i + 1][j]) ++cnt;
				if (a[i][j] && a[i][j + 1]) ++cnt;
			}
		}
		ans = min(ans, cnt);
	} while (next_permutation(state, state + R*C));
	printf("Case #%d: %d\n", TCC, ans);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &TC);
	while (++TCC <= TC) {
		init();
		solve();
	}
	return 0;
}