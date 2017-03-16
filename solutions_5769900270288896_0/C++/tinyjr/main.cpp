#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <list>
#include <sstream>
#include <ctime>
#include <functional>
#define pi 3.14159265358979323846264338327950288
#define pb push_back
#define mp make_pair
#define LL long long
#define LD long double
#define INF 1000000000
#define INFll 1000000000000000000ll
#define Vi vector<int>
#define VI Vi::iterator
#define Mi map<int, int>
#define MI Mi::iterator
#define Si set<int>
#define SI Si::iterator
#define FOR(i,s,e) for (int i=(s); i<(e); i++)
#define FOE(i,s,e) for (int i=(s); i<=(e); i++)
#define FOD(i,s,e) for (int i=(s)-1; i>=(e); i--)
#define CLR(a,x) memset(a, x, sizeof(a))
#define mid (l + r) / 2
#define Left k * 2, l, mid
#define Right k * 2 + 1, mid + 1, r
#define N 111111
using namespace std;
vector<int> g[N];

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
int n, r, c;
int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
	int T, cas;
	cin >> T;

	for (int cas = 1; cas <= T; cas ++) {
		cin >> r >> c >> n;
		for (int i = 1; i <= r; i++) {
			g[i].resize(c);
		}
		int tn = n;
		int ans1 = 0;
		for (int i = 1; i <= r; i++)
			for (int j = 1; j <= c; j++)
				n -= g[i][j] = (i + j) & 1;
		for (; n > 0; n--) {
            int temp = INF;
			int si = 0, sj = 0;
			for (int i = 1; i <= r; i++)
				for (int j = 1;  j <= c; j++)
					if (g[i][j] == 0){
					int cnt = 0;
					for (int k = 0; k < 4; k++) {
						int tx = i + dx[k], ty = j + dy[k];
						if (tx > 0 && tx <= r && ty > 0 && ty <= c)
							cnt += g[tx][ty];
					}
					if (cnt < temp) temp = cnt, si = i, sj = j;
			}
			ans1 += temp;
			g[si][sj] = 1;
		}
		n = tn;
		int ans2 = 0;
		for (int i = 1; i <= r; i++)
			for (int j = 1; j <= c; j++)
				n -= g[i][j] = ((i + j) & 1) == 0;

		for (; n > 0; n--) {
		    int temp = INF;
			int si = 0, sj = 0;
			for (int i = 1; i <= r; i++)
				for (int j = 1;  j <= c; j++)
					if (g[i][j] == 0){
					int cnt = 0;
					for (int k = 0; k < 4; k++) {
						int tx = i + dx[k], ty = j + dy[k];
						if (tx > 0 && tx <= r && ty > 0 && ty <= c)
							cnt += g[tx][ty];
					}
					if (cnt < temp) temp = cnt, si = i, sj = j;
			}
			ans2 += temp;
			g[si][sj] = 1;
		}
		printf("Case #%d: %d\n", cas, min(ans1, ans2));
	}
}
