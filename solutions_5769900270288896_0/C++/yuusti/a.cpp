// BEGIN CUT HERE
#ifdef _MSC_VER
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <numeric>
#include <cctype>
#include <tuple>
#include <array>
#include <climits>
#include <bitset>
#include <cassert>
#include <unordered_map>
#include <agents.h>
#else
// END CUT HERE
#include <bits/stdc++.h>
// BEGIN CUT HERE
#endif
// END CUT HERE

#define FOR(i, a, b) for(int i = (a); i < (int)(b); ++i)
#define rep(i, n) FOR(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define REV(v) v.rbegin(), v.rend()
#define MEMSET(v, s) memset(v, s, sizeof(v))
#define UNIQUE(v) (v).erase(unique(ALL(v)), (v).end())
#define MP make_pair
#define MT make_tuple

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;

int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0, -1 };

int b[55][55];

int main(){
	int T;
	cin >> T;
	for (int cas = 1; cas <= T; ++cas){
		int r, c, n;
		cin >> r >> c >> n;
		int ans = 1e9;
		rep(i, 1 << r*c){
			int cnt = 0;
			rep(j, r*c){
				if(b[j / c][j%c] = i >> j & 1) ++cnt;
			}
			if (cnt != n) continue;
			int tmp = 0;
			rep(y, r) rep(x, c){
				rep(d, 4) {
					int ny = y + dy[d], nx = x + dx[d];
					if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
					tmp += b[y][x] && b[ny][nx];
				}
			}
			ans = min(ans, tmp / 2);
		}
		printf("Case #%d: %d\n", cas, ans);
	}
}