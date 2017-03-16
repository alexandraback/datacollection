#include<bits/stdc++.h>
using namespace std;

int occ[20][20];
int r, c;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};

bool valid(int x, int y) {
	if (x < r && y < c && x >= 0 && y >= 0)
		return true;
	return false;
}

int calc() {
	int ret = 0;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (occ[i][j] == 0)
				continue;
			for (int k = 0; k < 4; k++) {
				if (valid(i + dx[k], j + dy[k]) && occ[i + dx[k]][j + dy[k]]) {
					ret++;
				}
			}
		}

	}
	return ret / 2;
}

int main() {
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	int id = 1;
	while (t--) {
		int n;
		cin >> r >> c >> n;
		int ans = 1000000000;
		for (int msk = 0; msk < (1 << (r * c)); msk++) {

			if (__builtin_popcount(msk) != n)
				continue;

			for (int i = 0; i < r; i++)
				for (int j = 0; j < c; j++)
					occ[i][j] = 0;

			for (int i = 0; i < r * c; i++) {
				if (msk & (1<<i))
					occ[i / c][i % c] = 1;
			}

			ans = min(ans, calc());
		}
		cout << "Case #" << id++ << ": " << ans << endl;
	}

	return 0;
}


