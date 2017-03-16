#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include "math.h"

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define fori(i, a, b) for (int i = int(a); i <= int(b); i++)

typedef long long ll;

using namespace std;

int b, n;
int m[1000];

ll g(ll t) {
	ll x = 0;
	forn(i, b) {
		x += t / m[i] + 1;
	}
	return x;
}

ll f(ll l, ll r) {
	if (l >= r) {
		return l;
	}
	ll m = (l + r) / 2;
	ll x = g(m);
	if (x < n) {
		return f(m + 1, r);
	} else {
		return f(l, m - 1);
	}
}

int main() {
	int ntc;
	cin >> ntc;
	fori(tc, 1, ntc) {
		cin >> b >> n;
		forn(i, b) {
			cin >> m[i];
		}
		cout << "Case #" << tc << ": ";
		int minm = 100000;
		forn(i, b) {
			if (m[i] < minm) {
				minm = m[i];
			}
		}
		ll maxt = n;
		maxt *= minm;
		ll t = f(0, maxt);
		ll x = g(t);
		if (x >= n) {
			t--;
		}
		x = g(t);
		int s = -1;
		forn(i, b) {
			if ((t + 1) % m[i] == 0) {
				x++;
			}
			if (x == n) {
				s = i;
				break;
			}
		}
		cout << s + 1;
		cout << endl;
	}
	return 0;
}
