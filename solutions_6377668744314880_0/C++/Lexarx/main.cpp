#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include "math.h"

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define fori(i, a, b) for (int i = int(a); i <= int(b); i++)

typedef long long ll;

using namespace std;

int n;
ll x[3000], y[3000];

int main() {
	int ntc;
	cin >> ntc;
	fori(tc, 1, ntc) {
		cin >> n;
		forn(i, n) {
			cin >> x[i] >> y[i];
		}
		cout << "Case #" << tc << ": " << endl;
		if (n == 1) {
			cout << 0 << endl;
		} else {
			forn(i, n) {
				int m = n;
				forn(j, n) {
					if (i == j) {
						continue;
					}
					ll a = y[i] - y[j];
					ll b = x[j] - x[i];
					ll c = x[i] * y[j] - x[j] * y[i];
					int p1 = 0;
					int p2 = 0;
					forn(k, n) {
						ll z = a * x[k] + b * y[k] + c;
						if (z > 0) {
							p1++;
						} else if (z < 0) {
							p2++;
						}
					}
					if (p1 < m) {
						m = p1;
					}
					if (p2 < m) {
						m = p2;
					}
				}
				cout << m << endl;
			}
		}
	}
	return 0;
}
