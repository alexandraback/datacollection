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
int a[1000];

int main() {
	int ntc;
	cin >> ntc;
	fori(tc, 1, ntc) {
		cin >> n;
		forn(i, n) {
			cin >> a[i];
		}
		cout << "Case #" << tc << ": ";
		int s = 0;
		for (int i = 1; i < n; i++) {
			if (a[i] < a[i - 1]) {
				s += a[i - 1] - a[i];
			}
		}
		cout << s;
		int v = 0;
		for (int i = 1; i < n; i++) {
			if (a[i] < a[i - 1]) {
				int d = a[i - 1] - a[i];
				if (d > v) {
					v = d;
				}
			}
		}
		int t = 0;
		for (int i = 0; i < n - 1; i++) {
			t += min(a[i], v);
		}
		cout << " " << t;
		cout << endl;
	}
	return 0;
}
