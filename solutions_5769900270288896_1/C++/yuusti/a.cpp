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

int main(){
	int T;
	cin >> T;
	for (int cas = 1; cas <= T; ++cas){
		int r, c, n;
		cin >> r >> c >> n;
		int ans = 0;
		
		int cnt[2][5] = {};
		rep(i, r) rep(j, c) rep(k, 2){
			int x = 4;
			if (i == 0) --x;
			if (i == r - 1) --x;
			if (j == 0) --x;
			if (j == c - 1) --x;
			++cnt[k][x];
		}

		int put[2] = {}, res[2] = {};
		rep(i, r) rep(j, c) {
			int x = 4;
			if (i == 0) --x;
			if (i == r - 1) --x;
			if (j == 0) --x;
			if (j == c - 1) --x;
			--cnt[i + j & 1][x];
			++put[i + j & 1];
		}

		auto f = [&](int i){
			for (int j = 0; j <= 4; ++j) if (cnt[i][j]){
				--cnt[i][j];
				res[i] += j;
				++put[i];
				return;
			}
		};

		rep(i, 2) while (put[i] < put[!i]) f(i);

		if (n <= min(put[0], put[1])) ans = 0;
		else {
			while (put[0] < n){
				rep(i, 2) f(i);
			}
			ans = min(res[0], res[1]);
		}

		printf("Case #%d: %d\n", cas, ans);
	}
}