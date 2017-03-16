#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <list>
#include <set>
#include <cstdio>
#include <cmath>
#include <iomanip>
#include <deque>
#include <ctime>
#include <cstring>

//#include <bits/stdc++.h>

using namespace std;

#define fr first
#define sd second
#define pb push_back
#define mp make_pair

#define endl '\n'

#define forr(i, n) for(ll (i) = 0LL; (i) < (n); (i)++)
#define mp3(a, b, c) mp(a, mp(b, c))

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> plll;
typedef vector < vector < double > > vvd;
typedef vector < double > vd;
typedef vector < pair < double, double> > vdd;
typedef vector < vector < long long > > vvl;
typedef vector < long long > vl;
typedef vector < pll > vll;

int INT_MAX_VAL = (int) 1e20;
int INT_MIN_VAL = (int) -1e20;
ll LONG_MAX_VAL = (ll) 1e20;
ll LONG_MIN_VAL = (ll) -1e20;

#define MAXN 100005

void solve(int T)
{
	cout << "Case #" << T << ": ";

	
	int r, c, n; cin >> r >> c >> n;

	int s = r * c;
	int res = INT_MAX_VAL;
	for(int m = 0; m < (1 << s); ++m) {
		vvl v(r, vl(c));


		int sn = 0;
		for(int i = 0; i < r; ++i) {
			for(int j = 0; j < c; ++j) {
				if(m & (1 << ((i * c + j)))) {
					++sn;
					v[i][j] = 1;
				}
			}
		}

		if(sn != n) continue;


		int cur = 0;
		for(int i = 0; i < r; ++i) {
			for(int j = 0; j < c; ++j) {
				if(v[i][j] == 0) continue;

				if(i > 0 && v[i - 1][j] == 1) ++cur;
				if(j > 0 && v[i][j - 1] == 1) ++cur;
				if(i + 1 < r && v[i + 1][j] == 1) ++cur;
				if(j + 1 < c && v[i][j + 1] == 1) ++cur;
			}
		}
		res = min(res, cur / 2);
	}
	cout << res << endl;
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int t; cin >> t;
	forr(i, t) solve(i + 1);

	return 0;
}
