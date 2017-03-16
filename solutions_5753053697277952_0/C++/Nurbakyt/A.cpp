#include <bits/stdc++.h>

#define pb push_back
#define f first
#define s second
#define mp make_pair
#define sz(a) int((a).size())
#ifdef _WIN32
#  define I64 "%I64d"
#else
#  define I64 "%lld"
#endif
#define fname "."
#define pi pair < int, int >
#define pp pop_back

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int MAX_N = (int)2e5 + 123;
const double eps = 1e-6;
const int inf = (int)1e9 + 123;

using namespace std;

int n;
set < pair < int, char > > q;

void solve(int test) {
	cin >> n;
	q.clear();
	int all = 0;
	for (int i = 1, x; i <= n; i++) {
		cin >> x;
		all += x;
		q.insert(mp(x, char(i + 'A' - 1)));
	}
	cout << "Case #" << test <<	": ";
	while(!q.empty()) {
	  bool bad = 1;
		if (sz(q) > 1) {
			pair < int, char > f, s;
			auto it = --q.end();
			f = *it;
			it--;
			s = *it;
			q.erase(f), q.erase(s);
			int hey = max(f.f - 1, s.f - 1);
			if (!q.empty())
				hey = max(hey, q.rbegin() -> f);
			if (hey > (all - 2) / 2) {
				bad = 1;	
				q.insert(f), q.insert(s);
			}
			else {
			  bad = 0;
				cout << f.s << s.s << ' ';
				f.f--, s.f--;
				all -= 2;
				if (f.f)
					q.insert(f);
				if (s.f)
					q.insert(s);					
			}
		}
		if (bad) {
			pair < int, char > now = *q.rbegin();
			q.erase(now);
			now.f--;
			all--;
			cout << now.s << ' ';
			if (now.f)
				q.insert(now);
			if (!q.empty())
				assert(q.rbegin() -> f <= all / 2);
		}
	}
	cout << endl;
}

int main() {
	#ifdef Nick
	freopen(fname"in", "r", stdin);
	freopen(fname"out", "w", stdout);
	#endif
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++)
		solve(i);	
	return 0;
}
