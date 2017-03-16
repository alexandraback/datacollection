#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_DEPRECATE

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <limits>
#include <cfloat>
#include <ctime>
#include <cassert>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <list>
#include <iomanip>
#include <fstream>
#include <iterator>
#include <bitset>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(x) ((int)1e##x)

#pragma comment(linker,"/STACK:36777216")

template<class T> void chmax(T& l, const T r) { l = max(l, r); }
template<class T> void chmin(T& l, const T r) { l = min(l, r); }
template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }

int solve(){
	int n, b; cin >> b >> n;
	vector<ll> m(b);
	FOR(i, b) cin >> m[i];

	ll l = -1, r = 100000LL * ten(9) * 2;
	while (r - l != 1) {
		ll md = (l + r) / 2;
		ll user = 0;
		for (auto mk : m) {
			user += (md + mk) / mk;
			if (user >= n) break;
		}
		if (user >= n) r = md;
		else l = md;
	}

	ll prev_user = 0;
	for (auto mk : m) prev_user += (l + mk) / mk;
	FOR(i, b){
		if (r % m[i] == 0) prev_user++;
		if (prev_user == n) return i + 1;
	}
	return -1;
}

int main() {

	int t; cin >> t;
	FOR(i, t){
		auto ans = solve();
		printf("Case #%d: %d\n",i+1,ans);
	}
	return 0;
}