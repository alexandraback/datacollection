#include <algorithm>
#include <iostream>
#include <iomanip>
#include <queue>
#include <set>
#include <vector>

using namespace std;

struct Tenant {
	int x, y;
	Tenant(){};
	Tenant(int x, int y):x(x),y(y){};
};

bool house[18][18];

int count_noise(int x, int y) {
	int noise = 0;
	if (house[x+1][y]) noise++;
	if (house[x-1][y]) noise++;
	if (house[x][y+1]) noise++;
	if (house[x][y-1]) noise++;
	return noise;
}

void choose_init(int* v, int k, int lo) {
	while (k--) v[k] = lo+k;
}

bool choose_next(int* v, int k, int lo, int hi) {
	if (--k<0) return false;
	if (++v[k] <= hi) return true;
	if (!choose_next(v, k, lo, hi-1)) { v[k] = lo+k; return false; }
	v[k] = v[k-1]+1;
	return true;
}

void solve()
{
	int r, c, n, b(1000);
	cin >> r >> c >> n;
	int v[n];
	choose_init(v, n, 0);
	do {
		for (int i=0; i<18; i++) {
			for (int j=0; j<18; j++) house[i][j] = false;
		}
		for (int k=0; k<n; k++) {
			int x = (v[k] / c) + 1;
			int y = (v[k] % c) + 1;
			house[x][y] = true;
		}
		int t = 0;
		for (int i=1; i<=r; i++) {
			for (int j=1; j<=c; j++) {
				if (house[i][j]) t += count_noise(i, j);
			}
		}
		b = min(b, t/2);
	} while (choose_next(v, n, 0, r*c - 1));
	cout << b;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	for (int tn=1; tn<=t; tn++) {
		cout << "Case #" << tn << ": ";
		solve();
		cout << "\n";
	}
	return 0;
}