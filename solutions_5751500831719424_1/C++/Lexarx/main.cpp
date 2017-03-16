#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include "math.h"

using namespace std;

typedef long long ll;

const int N = 110;

int main() {
	int ntc;
	cin >> ntc;
	for (int tc = 1; tc <= ntc; tc++) {
		int n;
		cin >> n;
		string a[N];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		cout << "Case #" << tc << ": ";
		char d[N];
		int h[N][N];
		int m = 0;
		char c = 0;
		string s = a[0];
		for (int i = 0; i < s.length(); i++) {
			if (s[i] != c) {
				c = s[i];
				d[m] = c;
				m++;
			}
		}
		bool f = true;
		for (int i = 0; i < n; i++) {
			string s = a[i];
			int k = 0;
			bool g = true;
			for (int j = 0; j < m; j++) {
				if (k >= s.length() || s[k] != d[j]) {
					g = false;
					break;
				}
				int p = 0;
				while (k < s.length() && s[k] == d[j]) {
					p++;
					k++;
				}
				h[i][j] = p;
			}
			if (k < s.length()) {
				g = false;
			}
			if (!g) {
				f = false;
				break;
			}
		}
		if (!f) {
			cout << "Fegla Won";
		} else {
			int e[N];
			for (int i = 0; i < m; i++) {
				int d[N];
				for (int j = 0; j < n; j++) {
					d[j] = h[j][i];
				}
				sort(d, d + n);
				e[i] = d[n / 2];
			}
			int s = 0;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					s += abs(h[i][j] - e[j]);
				}
			}
			cout << s;
		}
		cout << endl;
	}
	return 0;
}

