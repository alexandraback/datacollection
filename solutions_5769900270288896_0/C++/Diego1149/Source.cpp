#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <queue>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

#define INF 1000000000
#define FOR(i, a, b) for(int i=int(a); i<int(b); i++)
#define FORC(cont, it) for(typeof((cont).begin()) it = (cont).begin(); it != (cont).end(); it++)
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int T, caso = 1, R, C, N, ans;
int mat[16][16], dir[2][2] = { {0,1}, {1,0} };

int c1s(int i) {
	int ret = 0;
	while (i) {
		if (i & 1) ret++;
		i >>= 1;
	}
	return ret;
}

bool valid(int ii, int jj) {
	return ii < R&&jj < C;
}

int solve(int n) {
	int mask = 1;
	FOR(i, 0, R) {
		FOR(j, 0, C) {
			mat[i][j] = n&mask;
			mask <<= 1;
		}
	}
	int ret = 0;
	FOR(i, 0, R) {
		FOR(j, 0, C) {
			if (mat[i][j]) {
				FOR(k, 0, 2) {
					int ii = i + dir[k][0];
					int jj = j + dir[k][1];
					if (valid(ii, jj) && mat[ii][jj]) {
						ret++;
					}
				}
			}
		}
	}
	return ret;
}

int main() {
	cin >> T;
	while (T--) {
		cin >> R >> C >> N;
		ans = INF;
		FOR(i, 0, 1 << R*C) {
			if (c1s(i) == N) {
				ans = min(ans, solve(i));
			}
		}
		cout << "Case #" << caso++ << ": " << ans;
		cout << endl;
	}
	return 0;
}
