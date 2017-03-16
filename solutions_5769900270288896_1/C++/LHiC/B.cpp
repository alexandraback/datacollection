#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>


typedef long long ll;
typedef long double ld;

using namespace std;

int up(int x) {
	return x - x / 2;
}

int h, w, n;
int bst;
int us[100][100];


void bf(int x, int y, int xx) {
	if (x == h) {
		if (xx == n) {
			int xxx = 0;
			for (int i = 0; i < h; ++i)
				for (int j = 0; j < w; ++j) {
					xxx += us[i][j] & us[i + 1][j];
					xxx += us[i][j] & us[i][j + 1];
				}
			bst = min(xxx, bst);
		}
		return;
	}
	if (y == w) {
		bf(x + 1, 0, xx);
		return;
	}
	if (xx == n)
		us[x][y] = 0, bf(x, y + 1, xx);
	else {
		us[x][y] = 0;
		bf(x, y + 1, xx);
		us[x][y] = 1;
		bf(x, y + 1, xx + 1);
	}
}

int solve2(int h, int w, int n) {
	bst = h * w * 2;
	::h = h;
	::w = w;
	::n = n;
	bf(0, 0, 0);
	for (int i = 0; i < h + 1; ++i)
		for (int j = 0; j < w + 1; ++j)
			us[i][j] = 0;
	return bst;
}



int solve(int h, int w, int n) {
	if (n <= up(h * w))
		return 0;
	if (h == 1 || w == 1) {
		n -= up(h * w);
		if ((h * w) % 2 == 1)
			return n * 2;
		else
			return n * 2 - 1;
	}
	int now = h * (w - 1) + w * (h - 1);
	int n2 = h * w - n;
	if (n2 <= up((h - 2) * (w - 2)))
		return now - n2 * 4;
	if ((h * w) % 2 == 0) {
		int xx = up((h - 2) * (w - 2));
		now -= xx * 4;
		n2 -= xx;
		xx = h - 2 + w - 2;
		if (n2 <= xx)
			return now - 3 * n2;
		else
			return now - 3 * n2 + 1;
	}
	if (n2 <= up(h * w) - 4) {
		int xx = up((h - 2) * (w - 2));
		now -= xx * 4;
		n2 -= xx;
		now -= n2 * 3;
		return now;
	}
	else {
		int xx = up((h - 2) * (w - 2)) - 1;
		now -= xx * 4;
		n2 -= xx;
		now -= n2 * 3;
		return now;
	}
}

int main() {
	int tt;
	cin >> tt;
	for (int i = 0; i < tt; ++i) {
		int h, w, n;
		cin >> h >> w >> n;
		int x = solve(h, w, n);
		//if (x != solve2(h, w, n)) {
		//	cout << "WA: " << h << " " << w << " " << n << " " << x << "\n";
		//}
		if (x < 0) {
			cout << "ERROR: " << h << " " << w << " " << n << " " << x << "\n";
		}
		cout << "Case #" << i + 1 << ": " << solve(h, w, n) << "\n";
	}
	return 0;
}


