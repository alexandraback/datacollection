#include <iostream>
#include <ctime>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <set>
#include <stack>
#include <map>
#include <string>
#include <cmath>
#include <queue>
#include <algorithm>
#include <cassert>
#include <sstream>
#include <bitset>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int inf = 1e9;
const double eps = 1e-7;
const int maxn = 1001000;
const int mod = 1000000007;

int n, m, need;
vi a;
int res;

void go(int d, int k) {
	if (k == need) {
		int sum = 0;
		for (int i = 0; i < n * m; ++i) {
			if (a[i] == 0) continue;
			if (i >= m && a[i - m]) ++sum;
			if (i % m && a[i - 1]) ++sum;
		}
		res = min(res, sum);
		return;
	}
	if (d >= n * m) return;
	a[d] = 0;
	go(d + 1, k);
	a[d] = 1;
	go(d + 1, k + 1);
}

int main() 
{
#ifdef DEBUG
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
#endif
	int T;
	cin >> T;
	for (int t = 0; t < T; ++t) {
		cin >> n >> m >> need;
		a.assign(n * m, 0);
		res = inf;
		go(0, 0);
		printf("Case #%d: %d\n", t + 1, res);
	}
	return 0;
}
