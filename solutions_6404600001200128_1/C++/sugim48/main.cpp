#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int u, v; ll w; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

int main() {
	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		int N; cin >> N;
		vector<ll> m(N);
		for (int i = 0; i < N; i++)
			cin >> m[i];
		ll x = 0, maxi = 0;
		for (int i = 0; i + 1 < N; i++) {
			ll d = max(0LL, m[i] - m[i + 1]);
			x += d;
			maxi = max(maxi, d);
		}
		ll y = 0;
		for (int i = 0; i + 1 < N; i++)
			y += min(m[i], maxi);
		printf("Case #%d: %lld %lld\n", t, x, y);
	}
}