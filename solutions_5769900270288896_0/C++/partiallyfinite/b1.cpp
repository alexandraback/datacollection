#include <iostream>

using namespace std;

int t, r, c, n;

int main ()
{
	cin >> t;
	for (int i = 0; i ++< t;) {
		cin >> r >> c >> n;
		int m = 1e9;
		for (int k = 0; k < 1 << (r * c); ++k) if (__builtin_popcount(k) == n) {
			int v = 0;
			for (int j = 0; j < r * c; ++j) if (k & 1 << j) {
				int a = j / r, b = j % r;
				if (a) v += !!(k & 1 << ((a - 1) * r + b));
				if (a < c - 1) v += !!(k & 1 << ((a + 1) * r + b));
				if (b) v += !!(k & 1 << (a * r + b - 1));
				if (b < r - 1) v += !!(k & 1 << (a * r + b + 1));
			}
			m = min(m, v);
		}
		cout << "Case #" << i << ": " << m / 2 << '\n';
	}
}

