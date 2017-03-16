#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <numeric>
#define rep(x, to) for (int x = 0; x < (to); x++)
#define REP(x, a, to) for (int x = (a); x < (to); x++)
#define foreach(itr, x) for (typeof((x).begin()) itr = (x).begin(); itr != (x).end(); itr++)

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
typedef pair<long, long> PLL;

int T, R, C, N;
int ans, tmp;

int mi[] = {1, 0, -1, 0};
int mj[] = {0, 1,  0,-1};

int not_share(int i, int j, int x, vector< vector<char> > &f) {
	int res = x > 0;
	f[i][j] = x;
	int ni = (i * C + (j + 1)) / C;
	int nj = (i * C + (j + 1)) % C;
	if (ni == R) return res;
	if (nj == 0) x = (int)f[i][0];
	x ^= 1;
	return res + not_share(ni, nj, x, f);
}


int solve(vector< vector<char> > &f, int r) {
	int corner_i[4] = {0};
	corner_i[0] = 0;
	corner_i[1] = 0;
	corner_i[2] = R-1;
	corner_i[3] = R-1;
	int corner_j[4] = {0};
	corner_j[0] = 0;
	corner_j[1] = C-1;
	corner_j[2] = 0;
	corner_j[3] = C-1;

	int res = 0;
	// äpíTçı
	//
	rep(k, 4) {
		int i = corner_i[k];
		int j = corner_j[k];
		if (f[i][j]) continue;
		f[i][j] = 1;
		r--;
		rep(t, 4) {
			int ni = i + mi[t];
			int nj = j + mj[t];
			if (ni < 0 || ni >= R) continue;
			if (nj < 0 || nj >= C) continue;
			if (f[ni][nj]) {
				res++;
			}
			//cout << ni << " " << nj << " " << res << endl;
		}
		if (r == 0) return res;
	}

#if 0
	rep(i, R) {
		rep(j, C) {
			printf("%d%c", (int)f[i][j], j == C-1 ? '\n' : ' ');
		}
	}
#endif

	// 4ï”íTçı
	// top
	rep(i, C) {
		if (f[0][i]) continue;
		f[0][i] = 1;
		r--;
		rep(k, 4) {
			int ni = 0 + mi[k];
			int nj = i + mj[k];
			if (ni < 0 || ni >= R) continue;
			if (nj < 0 || nj >= C) continue;
			if (f[ni][nj]) {
				res++;
			}
		}
		if (r == 0) return res;
	}
	// left
	rep(i, R) {
		if (f[i][0]) continue;
		f[i][0] = 1;
		r--;
		rep(k, 4) {
			int ni = i + mi[k];
			int nj = 0 + mj[k];
			if (ni < 0 || ni >= R) continue;
			if (nj < 0 || nj >= C) continue;
			if (f[ni][nj]) {
				res++;
			}
		}
		if (r == 0) return res;
	}
	// right
	rep(i, R) {
		if (f[i][C-1]) continue;
		f[i][C-1] = 1;
		r--;
		rep(k, 4) {
			int ni = i + mi[k];
			int nj = C-1 + mj[k];
			if (ni < 0 || ni >= R) continue;
			if (nj < 0 || nj >= C) continue;
			if (f[ni][nj]) {
				res++;
			}
		}
		if (r == 0) return res;
	}
	// bottom
	rep(i, C) {
		if (f[R - 1][i]) continue;
		f[R-1][i] = 1;
		r--;
		rep(k, 4) {
			int ni = R-1 + mi[k];
			int nj = i + mj[k];
			if (ni < 0 || ni >= R) continue;
			if (nj < 0 || nj >= C) continue;
			if (f[ni][nj]) {
				res++;
			}
		}
		if (r == 0) return res;
	}
	// écÇË
	return res + 4 * r;
}

int main() {
	cin >> T;
	rep(cnt, T) {
		cin >> R >> C >> N;
		ans = 0;
		tmp = 0;

		vector< vector<char> > f(R);
		rep(i, R) f[i].resize(C, 0);

		tmp = not_share(0, 0, 0, f);
		if (tmp < N) {
			ans = solve(f, N - tmp);
			tmp = not_share(0, 0, 1, f);
			if (tmp < N) {
				ans = min(ans, solve(f, N - tmp));
			} else {
				ans = 0;
			}
		} else {
			ans = 0;
		}
		printf("Case #%d: %d\n", cnt + 1, ans);
	}
	return 0;
}


