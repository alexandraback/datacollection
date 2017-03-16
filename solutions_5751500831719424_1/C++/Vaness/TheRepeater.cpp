#include <iostream>
#include <cstdio>
#include <fstream>

#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <utility>
#include <string>
#include <cstring>

#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <memory.h>
using namespace std;

#define fr(i, n) for (int i = 0; i < (int)(n); i++)
#define fb(i, n) for (int i = n - 1; i >= 0; i--)
#define all(a) (a).begin(), (a).end()
#define _(a, b) memset(a, b, sizeof(a))
#define mp make_pair
#define pb push_back
#define sz(v) ((int)(v).size())

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;

inline int ni() { int a; scanf("%d", &a); return a; }
inline double nf() { double a; scanf("%lf", &a); return a; }
template <class T> void out(T a, T b) { bool first = true; for (T i = a; i != b; i++) { if (!first) printf(" "); first = false; cout << *i; } puts(""); }
template <class T> void outl(T a, T b) { for (T i = a; i != b; i++) cout << *i << "\n"; } 

int T;
int N;
vs v;

pair<string, vi> raw(string s) {
	string ans;
	vector<int> ct;
	char last = '.';
	int c = 0;	
	fr(i, sz(s)) {
		if (last != s[i]) {
			if (c) {
				ans += last;
				ct.pb(c);
			}
			last = s[i];
			c = 1;
		} else
			c++;
	}
	ans += last;
	ct.pb(c);
	return mp(ans, ct);
}

int solve() {
	N = ni();
	v.clear();
	v.resize(N);
	fr(i, N)
		cin >> v[i];

	vector<pair<string, vi> > q(N);
	fr(i, N)
		q[i] = raw(v[i]);
	
	fr(i, N - 1)
		if (q[i].first != q[i + 1].first)
			return -1;
	
	string s = q[0].first;
	int ans = 0;
	fr(i, sz(s)) {
		int best = 1000000000;
		int mx = -1;
		fr(j, N)
			mx = max(mx, q[j].second[i]);
		for (int p = 1; p <= mx; p++) {
			int cur = 0;
			fr(j, N)
				cur += abs(p - q[j].second[i]);
			if (cur < best)
				best = cur;
		}
		ans += best;
	}
	return ans;
}

int main() {
	freopen("therepeater.in", "r", stdin);
	freopen("therepeater.out", "w", stdout);
	T = ni();
	fr(test, T) {
		int ans = solve();
		if (ans < 0)
			printf("Case #%d: Fegla Won\n", test + 1);
		else
			printf("Case #%d: %d\n", test + 1, ans);			
	}	  
}
        