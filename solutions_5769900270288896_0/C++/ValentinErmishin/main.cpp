#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

int mas[18 * 18];
int dp[18][18][18 * 18];
int matr[20][20];

struct Int {
	int v;

	Int (int v) : v (v) { }

	bool operator < (const Int &x) const {
		if (mas[v] != mas[x.v])
			return mas[v]  < mas[x.v];
		return v < x.v;
	}
};

int r, c;
int di[] = {0, -1, 0, 1};
int dj[] = {-1, 0, 1, 0};



bool good (int i, int j) {
	return i >= 0 && i < r && j >= 0 && j < c;
}

int add (int i, int j) {
	int res = 0;
	for (int k = 0; k < 4; k++) {
		int ni = i + di[k];
		int nj = j + dj[k];

		if (good (ni, nj))
			res += matr[ni][nj];
	}
	return res;
	return matr[i - 1][j] + matr[i][j - 1] + matr[i + 1][j] + matr[i][j + 1];
}

set<Int> q;
int sum;


void refresh (int i, int j) {

	sum -= mas[i * c + j] * 2;
	for (int k = 0; k < 4; k++) {
		int ni = i + di[k];
		int nj = j + dj[k];
		if (!good (ni, nj))
			continue;
		if (matr[ni][nj]) {
			q.erase (ni * c + nj);
		}
	}

	matr[i][j] = 0;

	for (int k = 0; k < 4; k++) {
		int ni = i + di[k];
		int nj = j + dj[k];
		if (!good (ni, nj))
			continue;
		if (matr[ni][nj]) {
			mas[ni * c + nj] = add (ni, nj);
		}
	}

	for (int k = 0; k < 4; k++) {
		int ni = i + di[k];
		int nj = j + dj[k];
		if (!good (ni, nj))
			continue;
		if (matr[ni][nj]) {
			q.insert (ni * c + nj);
		}
	}
}

int main () {
#ifdef LOCAL
	freopen ("file.in", "r", stdin);  
	freopen ("file.out", "w", stdout);
#else
	freopen ("square.in", "r", stdin);  
	freopen ("square.out", "w", stdout);
#endif

	time_t st = clock ();

	for (r = 1; r <= 16; r++) {
		for (c = r; c <= 16; c++) {
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++)
					matr[i][j] = 1;
			}

			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					mas[i * c + j] = add (i, j);
					sum += mas[i * c + j];
				}
			}

			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++)
					q.insert (i * c + j);
			}

			dp[r][c][r * c] = dp[c][r][r * c] = sum / 2;

			for (int i = 0, cnt = 1; i < r; i++) {
				for (int j = 0; j < c; j++, cnt++) {
					auto it = q.rbegin ();
					int v = it -> v;
					q.erase (*it);
					int ii = v / c;
					int jj = v % c;

					refresh (ii, jj);

					dp[r][c][r * c - cnt] = dp[c][r][r * c - cnt] = sum / 2;
				}
			}
		}
	}

	int T, n;

	scanf ("%d", &T);

	for (int t = 1; t <= T; t++) {
		scanf ("%d %d %d", &r, &c, &n);
		printf ("Case #%d: %d\n", t, dp[r][c][n]);
	}

	fprintf (stderr, "%.3f\n", 1.0 * (clock () - st) / CLOCKS_PER_SEC);

	return 0;
}