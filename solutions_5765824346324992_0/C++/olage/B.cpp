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


ll cnt(vl &v, ll t)
{
	ll res = 0;
	forr(i, v.size()) {
		res += (t + v[i]) / v[i];

		//res += (t) / v[i];
	}
	return res;
}

void solve(int T)
{
	cout << "Case #" << T + 1 << ": ";

	ll n, b; cin >> b >> n;
	vl v(b);
	forr(i, b) cin >> v[i];


	ll l = 0;
	ll r = 1000000000000000;

	while(l < r) {
//		cerr << l << " " << r << endl;
		ll med = (r + l) / 2;
		if(cnt(v, med) <= n - 1) {
			l = med + 1;
//			r = med - 1;
		} else {
			r = med;
//			l = med;
		}
	}

//	cout << l << " " << cnt(v, l) << " " << cnt(v, 21) << endl;
	int bfr = cnt(v, l);
//	cout << bfr << " " << n << endl;
	for(int i = b - 1; i >= 0; --i) {
		if(l % v[i] == 0) {
			if(bfr == n) { cout << i + 1 << endl; return; }
			else --bfr;
		}
//		cout << bfr << endl;
	}

	cout << endl;
//	cout << l << endl;
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int T; cin >> T;
	forr(t, T) solve(t);

	return 0;
}
