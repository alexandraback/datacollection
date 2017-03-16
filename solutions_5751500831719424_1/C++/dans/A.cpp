#define _USE_MATH_DEFINES

#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <list>
#include <iomanip>
#include <stack>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cassert>

#define all(a) a.begin(),a.end()
#define pb push_back
#define mp make_pair
#define forn(i,n) for(int i = 0; i < int(n); ++i)

using namespace std;

typedef long long li;
typedef long double ld;

typedef pair<int,int> pt;
#define ft first
#define sc second

int n;
string str[105];
int cnt[105][105];

bool read() {
	if (!(cin >> n))
		return false;
	forn(i, n)
		cin >> str[i];
	return true;
}

void solve() {
	string ptrn = str[0], tmp;
	ptrn.resize(unique(all(ptrn)) - ptrn.begin());
	forn(i, n) {
		tmp = str[i];
		tmp.resize(unique(all(tmp)) - tmp.begin());
		if (ptrn != tmp) {
			cout << "Fegla Won";
			return;
		}
		int pos = 0;
		cnt[i][0] = 0;
		forn(j, str[i].size()) {
			if (str[i][j] != ptrn[pos]) {
				pos++;
				assert(str[i][j] == ptrn[pos]);
				cnt[i][pos] = 0;
			}
			cnt[i][pos]++;
		}
	}
	int res = 0;
	forn(j, ptrn.size()) {
		int lb = 10000, rb = -1;
		forn(i, n)
			lb = min(lb, cnt[i][j]), rb = max(rb, cnt[i][j]);
		int minres = 100000;
		for (int sel = lb; sel <= rb; ++sel) {
			int curres = 0;
			forn(i, n)
				curres += abs(cnt[i][j] - sel);
			minres = min(minres, curres);
		}
		res += minres;
	}
	cout << res;	
}

int main() {
#ifdef dans
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

#ifdef TASK_NAME
	freopen(TASK_NAME ".in", "r", stdin);
	freopen(TASK_NAME ".out", "w", stdout);
#endif

	int t;
	cin >> t;
	int test = 0;
	while (read()) {
		test++;
		cout << "Case #" << test << ": ";
		solve();
		cout << endl;
	}
	
	return 0;
}
