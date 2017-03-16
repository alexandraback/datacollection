#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#define OUT(x) cerr << #x << ": " << (x) << endl
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long LL;

int T, A, a[4][4], B, b[4][4];

int main() {
	scanf("%d", &T);
	REP(tid, T) {
		scanf("%d", &A), A -= 1;
		REP(i, 4) REP(j, 4) scanf("%d", &a[i][j]);
		scanf("%d", &B), B -= 1;
		REP(i, 4) REP(j, 4) scanf("%d", &b[i][j]);

		int cnt = 0, ans;
		REP(j, 4) {
			bool same = false;
			REP(k, 4) if (b[B][k] == a[A][j]) same = true;
			if (same) {
				++cnt;
				ans = a[A][j];
			}
		}
		if (cnt == 0) {
			printf("Case #%d: Volunteer cheated!\n", tid + 1);
		} else if (cnt == 1) {
			printf("Case #%d: %d\n", tid + 1, ans);
		} else {
			printf("Case #%d: Bad magician!\n", tid + 1);
		}
	}
	return 0;
}