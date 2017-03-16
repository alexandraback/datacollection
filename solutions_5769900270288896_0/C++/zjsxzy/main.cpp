#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <bitset>
#include <vector>
#include <cstdio>
#include <string>
#include <cassert>
#include <climits>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define PB push_back
#define MP make_pair
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
#define FOREACH(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
typedef long long LL;

const int MAXN = 16;
int r, c, n, m;
int mat[MAXN][MAXN];
int bit_cnt(int x) {
	int ret = 0;
	for (; x; x = x & (x - 1)) {
		ret++;
	}
	return ret;
}
int main() {
#ifndef ONLINE_JUDGE
//	freopen("in.txt", "r", stdin);
#endif
	int ts;
	cin >> ts;
	for (int cas = 1; cas <= ts; cas++) {
		cin >> r >> c >> n;
		m = r * c;
		int res = INT_MAX;
		for (int st = 0; st < (1 << m); st++) {
			int bits = bit_cnt(st);
			if (bits == n) {
				memset(mat, false, sizeof(mat));
				for (int i = 0; i < m; i++) {
					if (st & (1 << i)) {
						mat[i / c][i % c] = true;
					}
				}
				int cnt = 0;
				for (int i = 0; i < r; i++) {
					for (int j = 0; j < c; j++) {
						if (mat[i][j]) {
							if (i + 1 < r) {
								if (mat[i + 1][j]) cnt++;
							}
							if (j + 1 < c) {
								if (mat[i][j + 1]) cnt++;
							}
						}
					}
				}
				res = min(res, cnt);
			}
		}
		printf("Case #%d: %d\n", cas, res);
	}
	return 0;
}

