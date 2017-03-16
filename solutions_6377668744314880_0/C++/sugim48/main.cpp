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

ll det(ll x1, ll y1, ll x2, ll y2) {
	return x1 * y2 - x2 * y1;
}

int main() {
	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		printf("Case #%d:\n", t);
		int N; cin >> N;
		vector<int> X(N), Y(N);
		for (int i = 0; i < N; i++)
			cin >> X[i] >> Y[i];
		for (int i = 0; i < N; i++) {
			vector<d_i> v;
			for (int j = 0; j < N; j++)
				if (j != i) {
					double dx = X[j] - X[i], dy = Y[j] - Y[i];
					v.push_back(d_i(atan2(dy, dx), j));
				}
			sort(v.begin(), v.end());
			int n = N - 1;
			vector<int> a(n * 2);
			for (int k = 0; k < n * 2; k++)
				a[k] = v[k % n].second;
			int l = 0, maxi = 0;
			for (int k = 0; k < n; k++) {
				while (l < k + n && det(X[a[k]] - X[i], Y[a[k]] - Y[i], X[a[l]] - X[i], Y[a[l]] - Y[i]) >= 0)
					l++;
				maxi = max(maxi, l - k);
			}
			cout << N - 1 - maxi << endl;
		}
	}
}