#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <queue>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
#define VAR(a,b) __typeof(b) a=(b)
#define FOR(i,a,b) for (int _n(b), i(a); i < _n; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define FOREACH(it,c) for(VAR(it,(c).begin());it!=(c).end();++it)
#define REP(i,n) FOR(i,0,n)
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))
#define REVERSE(c) reverse(ALL(c))
#define UNIQUE(c) SORT(c),(c).resize(unique(ALL(c))-(c).begin())
#define INF 1000000000
#define X first
#define Y second
#define pb push_back
#define SZ(c) (c).size()
typedef pair<long long, long long> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
typedef vector<VI> VVI;

FILE* tmp;

int sq(PII a) {
	if (a.X >= 0) {
		if (a.Y >= 0) {
			return 0;
		}
		else {
			return 1;
		}
	}
	if (a.Y <= 0)
		return 2;
	return 3;
}

long long operator*(PII a, PII b) {
	return a.X*b.Y - a.Y*b.X;
}

int solve(VPII b) {
	sort(ALL(b), [](PII a, PII b) {
		auto sa = sq(a);
		auto sb = sq(b);
		if (sa != sb) return sa < sb;
		return a*b < 0;
	});

	int res = b.size();
	int c = 0;

	int y = 0;
	REP(x, b.size()) {
		//cout << b[x].X << " " << b[x].Y << endl;
		if (c == 0) {
			y = x;
			c = 1;
		}
		while (c < b.size()) {
			int ny = (y + 1) % b.size();
			if (b[x] * b[ny] > 0) break;
			y = ny;
			c++;
		}

		res = min(res, (int)b.size() - c);
		c--;
	}

	return res;
}

int main()
{
	freopen_s(&tmp, "input.txt", "r", stdin);
	freopen_s(&tmp, "output.txt", "w+", stdout);

	int tt;
	cin >> tt;
	REP(t, tt) {
		cout << "Case #" << t + 1 << ":"  << endl;

		int n;
		cin >> n;
		VPII a(n);
		REP(i, n) {
			cin >> a[i].X >> a[i].Y;
		}

		REP(i, n) {
			VPII b;
			REP(j, n) {
				if (i != j) {
					b.emplace_back(a[j].X - a[i].X, a[j].Y - a[i].Y);
				}
			}
			cout << solve(b) << endl;
		}
	}

	return 0;
}
