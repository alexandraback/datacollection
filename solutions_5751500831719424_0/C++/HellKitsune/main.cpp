#include <cstdio>
#include <cmath>
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); e++)
typedef long long LL;
typedef pair<int, int> PII;

int t, n;
string s, q[2];
int cnt[100][100] = {}, cntt[100][100];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> t;
	REP(test, t) {
		cin >> n >> s;
		q[0] = s[0];
		cnt[0][0] = 1;
		REP(i, s.length() - 1)
			if (s[i + 1] != s[i]) {
				q[0] += s[i + 1];
				cnt[0][q[0].length() - 1] = 1;
			} else
				++cnt[0][q[0].length() - 1];
		bool flag = true;
		for (int z = 1; z < n; ++z) {
			cin >> s;
			q[1] = s[0];
			cnt[z][0] = 1;
			REP(i, s.length() - 1)
				if (s[i + 1] != s[i]) {
					q[1] += s[i + 1];
					cnt[z][q[1].length() - 1] = 1;
				} else
					++cnt[z][q[1].length() - 1];
			if (q[1] != q[0]) {
				flag = false;
			}
		}
		cout << "Case #" << test + 1 << ": ";
		if (!flag) {
			cout << "Fegla Won" << endl;
			continue;
		}
		int m = q[0].length();
		int ans = 0;
		REP(i, m) REP(j, n)
			cntt[i][j] = cnt[j][i];
		REP(i, m)
			sort(cntt[i], cntt[i] + n);
		REP(i, m) {
			int mid = cntt[i][n / 2];
			REP(j, n)
				ans += abs(cntt[i][j] - mid);
		}
		cout << ans << endl;
	}
	return 0;
}
