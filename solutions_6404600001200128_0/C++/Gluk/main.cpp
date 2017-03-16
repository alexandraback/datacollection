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
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
typedef vector<VI> VVI;

FILE* tmp;

int main()
{
	freopen_s(&tmp, "input.txt", "r", stdin);
	freopen_s(&tmp, "output.txt", "w+", stdout);

	int tt;
	cin >> tt;
	
	REP(t, tt) {
		cout << "Case #" << t + 1 << ": ";
		int n;
		cin >> n;
		vector<int> a(n);
		REP(i, n) {
			cin >> a[i];
		}

		int r1 = 0;
		int r2 = 0;
		int d = 0;
		REP(i, n - 1)
			if (a[i + 1] < a[i]) {
				r1 += a[i] - a[i + 1];
				d = max(d, a[i] - a[i + 1]);
			}

		REP(i, n - 1) {
			r2 += min(d, a[i]);
		}

		cout << r1 << " " << r2 << endl;
	}

	return 0;
}
