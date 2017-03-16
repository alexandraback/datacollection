#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

int T;
int N, R, C;
int result = 0;
int apartments[16][16];

void solve(int r, int c, int now, int tenatns) {
	if(r == R || tenatns == 0) {
		if(tenatns != 0) return;
		result = min(result, now);
		return;
	}
	if(c == C) {
		solve(r + 1, 0, now, tenatns);
		return;
	}
	
	if(now > result) return;

	solve(r, c + 1, now, tenatns);


	if(r > 0 && apartments[r - 1][c]) now++;
	if(c > 0 && apartments[r][c - 1]) now++;

	apartments[r][c] = 1;
	solve(r, c + 1, now, tenatns - 1);
	apartments[r][c] = 0;
}

int main() {

	scanf("%d", &T);
	
	for(int Case = 1; Case <= T; Case++) {
		scanf("%d %d %d", &R, &C, &N);
		memset(apartments, 0, sizeof(apartments));
		result = R*C*4;
		solve(0, 0, 0, N);
		printf("Case #%d: %d\n", Case, result);
	}

	return 0;
}

