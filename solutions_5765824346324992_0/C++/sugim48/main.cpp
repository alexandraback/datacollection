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

ll f(ll t, vector<int>& M) {
	if (t < 0) return 0;
	ll sum = 0;
	for (int i = 0; i < M.size(); i++)
		sum += t / M[i] + 1;
	return sum;
}

int main() {
	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		int B; ll N; cin >> B >> N;
		vector<int> M(B);
		for (int i = 0; i < B; i++)
			cin >> M[i];
		ll lb = -1, ub = 100000000000000LL;
		while (ub - lb > 1) {
			ll mid = (lb + ub) / 2;
			if (f(mid, M) >= N) ub = mid;
			else lb = mid;
		}
		//cout << lb << ' ' << ub << endl;
		N -= f(lb, M);
		vector<int> v;
		for (int i = 0; i < B; i++)
			if (ub % M[i] == 0)
				v.push_back(i);
		printf("Case #%d: %d\n", t, v[N - 1] + 1);
	}
}