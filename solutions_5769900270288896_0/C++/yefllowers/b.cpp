#include <iostream>
#include <ctime>
#include <cmath>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define REP(i, n) for(int i(0); (i)<(int)(n); i++)
#define FOR(i, a, b) for (int i(a); i <= int(b); i++)


int n, r, c, a[17][17];

int main() {
	int CNT;
	cin >> CNT;
	FOR(T, 1, CNT) {
		cin >> r >> c >> n;
		int ans = r * c * 4;
		REP(msk, (1<<(r*c))) {
			int cnt = 0;
			REP(i, r) REP(j, c) if (msk >> (i * c + j) & 1) {
				cnt++;
				a[i][j] = 1;
			}
			if (cnt == n) {
				int tmp = 0;
				REP(i, r) REP(j, c) if (a[i][j]) {
					if (i < r - 1 && a[i + 1][j]) tmp++;
					if (j < c - 1 && a[i][j + 1]) tmp++;
				}
				ans = min(ans, tmp);
			}
			REP(i, r) REP(j, c) if (msk >> (i * c + j) & 1) {
				a[i][j] = 0;
			}
		}
		printf("Case #%d: %d\n", T, ans);
	}
	return 0;
}

