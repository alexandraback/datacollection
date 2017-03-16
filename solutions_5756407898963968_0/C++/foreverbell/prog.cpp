#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <sstream>
#include <cassert>

typedef long long LL;
const int maxint = 0x7f7f7f7f, mod = 1000000007;
const double eps = 1e-8, pi = acos(-1.0);

using namespace std;

int r, a[5][5];

vector<int> get() {
	scanf("%d", &r);
	for (int i = 1; i <= 4; ++i) {
		for (int j = 1; j <= 4; ++j) scanf("%d", &a[i][j]);
	}
	vector<int> ret;
	for (int j = 1; j <= 4; ++j) ret.push_back(a[r][j]);
	return ret;
}

int main() {
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);
	int tests;
	scanf("%d", &tests);
	for (int tt = 1; tt <= tests; ++tt) {
		vector<int> v1 = get(), v2 = get(), v;
		sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end());
		v.resize(8);
		vector<int>::iterator it = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), v.begin());
		v.resize(it - v.begin());
		printf("Case #%d: ", tt);
		if (v.size() == 1) printf("%d\n", v[0]);
		else if (v.size() == 0) puts("Volunteer cheated!");
		else puts("Bad magician!");
	}
	return 0;
}
