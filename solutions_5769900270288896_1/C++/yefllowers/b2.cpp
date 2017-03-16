#include <iostream>
#include <ctime>
#include <cmath>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define REP(i, n) for(int i(0); (i)<(int)(n); i++)
#define FOR(i, a, b) for (int i(a); i <= int(b); i++)


const int N = 10005;
const int M = N * 20;
int n, r, c, a[17][17];
map<pair<int, int> , int> Q;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
vector<pair<int, int> > A;

int main() {
	int CNT;
	cin >> CNT;
	FOR(T, 1, CNT) {
		cin >> r >> c >> n;
		int ans = 0;
		if (n <= (r * c + 1) / 2)
			ans = 0;
		else {
			ans = r * (c - 1) + c * (r - 1);
			REP(z, 2) {
				int zans = r * (c - 1) + c * (r - 1);
				Q.clear();
				A.clear();
				REP(i, r) REP(j, c) {
					int tmp = 0;
					REP(k, 4) {
						int x = i + dx[k];
						int y = j + dy[k];
						if (0 <= x && x < r && 0 <= y && y < c)
							tmp++;
					}
					if ((i + j) % 2 == z)
						A.push_back(make_pair(tmp, i * c + j));
				}
				sort(A.begin(), A.end());
				reverse(A.begin(), A.end());
				int cnt = 0;
				int m = r * c - n;
				REP(R, A.size()) {
					if (cnt == m) break;
					int tmp = A[R].first;
					int i = A[R].second / c;
					int j = A[R].second % c;
					int ok = 1;
					REP(k, 4) {
						int x = i + dx[k];
						int y = j + dy[k];
						if (0 <= x && x < r && 0 <= y && y < c && Q.count(make_pair(x, y)))
							ok = false;
					}
					if (ok) {
						zans -= tmp;
						Q[make_pair(i, j)] = 1;
						cnt++;
					}
				}
				ans = min(ans, zans);
			}
		}
		printf("Case #%d: %d\n", T, ans);
	}
	return 0;
}

