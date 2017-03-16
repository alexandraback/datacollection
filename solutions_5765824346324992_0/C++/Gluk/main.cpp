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
#define INF 1000000000LL
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
		int n, p;
		cin >> n >> p;
		vector<int> a(n);
		REP(i, n) {
			cin >> a[i];
		}

		long long t1 = 0;
		long long t2 = INF*INF;

		while (t1 < t2) {
			long long t = (t1 + t2)/2;

			long long count = 0;
			REP(i, n) {
				count += t / a[i] + 1;
				count = min(count, (long long)p);
			}

			if (count < p) {
				t1 = t + 1;
			} else {
				t2 = t;
			}
		}
		
		long long t = t1;
		//cout << t << endl;
		int c = p;
		int cc = p;
		REP(i, n) {
			c -= (t + a[i]-1) / a[i];
		}

		REP(i, n) {
			if (t % a[i] == 0) {
				if (c == 1) {
					cout << i+1 << endl;
					break;
				}
				c--;
			}
		}
	}

	return 0;
}
