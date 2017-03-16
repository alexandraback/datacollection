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

	n -= ((r+1)/2) * ((c+1)/2);
	cout << n << endl;
	n -= (r/2) * (c/2);

	int res = 0;
	cout << n << endl;
	if(n > 0) {
		if(r % 2 == 0 || c % 2 == 0) {
			res += 2 * min(n, 2);
			n -= 2;
		}
	}


	cout << n << endl;
	if(n > 0) {
		int z = (r/2)*((c+1)/2) + (c/2)*((r+1)/2);
		res += 3 * min(n, z);
		n -= z;
	}

	cout << n << endl;
	res += 4 * max(n, 0);
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
