#include <list>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <ext/hash_map>
#include <stdint.h>
#include <ctime>
#include <queue>
#include <sstream>
#include <sys/time.h>
#include <fstream>
#include <vector>

using namespace std;

typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<VI> VVI;
typedef long long LL;
typedef unsigned char BYTE;

#define FOR(i, n) for (int i = 0; i < (n); ++i)
#define FORU(i, s, e) for (int i = (s); i <= (e); ++i)
#define FORD(i, s, e) for (int i = (s); i >= (e); --i)
#define ALL(x) x.begin(),x.end()
#define FOREACH(i, v) for(__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++i)
#define SIZE(x) ((int)x.size())
#define MP make_pair
#define PB push_back
#define BIT(x, b) (((x) >> (b)) & 1)
#define SWAP(a, b, t) do {t = a; a = b; b = t;} while (0);
#define INF 1000000000
#define EPS 1e-9
#define TIME_LEFT_UNTIL(end) ((curTime=getTime()-startTime) < (end))
#define TIME_LEFT() TIME_LEFT_UNTIL(MAX_TIME)
#define INIT_TIME() startTime = getTime()

inline double getTime () {
   timeval tv;
   gettimeofday(&tv, 0);
   return tv.tv_sec + tv.tv_usec * 1e-6;
}

string x[111];

int main () {
	int T;
	cin >> T;
	FOR(itr, T) {
		int N;
		cin >> N;

		FOR(i, N)
			cin >> x[i];

		vector<char> uniques;
		VI cnts[N];
		int prev = 0;
		FOR(i, SIZE(x[0])) {
			if (x[0][i] != x[0][prev]) {
				uniques.PB(x[0][prev]);
				cnts[0].PB(i-prev);
				prev = i;
			}
		}
		uniques.PB(x[0][prev]);
		cnts[0].PB(SIZE(x[0])-prev);

		bool fail = 0;
		FORU(j, 1, N-1) {
			int prev = 0;
			FOR(i, SIZE(x[j])) {
				if (x[j][i] != x[j][prev]) {
					if (x[j][prev] != uniques[SIZE(cnts[j])]) {
						fail = 1;
						break;
					}
					cnts[j].PB(i-prev);
					prev = i;
				}
			}
			if (fail || x[j][prev] != uniques[SIZE(cnts[j])] || SIZE(cnts[j])+1 != SIZE(uniques)) {
				fail = 1;
				break;
			}
			cnts[j].PB(SIZE(x[j])-prev);
		}

		if (fail) {
			printf("Case #%d: Fegla Won\n", itr+1);
			continue;
		}

//		FOR(i, N) {
//			FOR(j, SIZE(uniques))
//				cerr << cnts[i][j] << " ";
//			cerr << endl;
//		}

		int out = 0;
		FOR(i, SIZE(uniques)) {
			int best = INF;
			FORU(goal, 1, 110) {
				int cur = 0;
				FOR(j, N)
					cur += abs(goal-cnts[j][i]);
				best = min(cur, best);
			}
			out += best;
		}

		printf("Case #%d: %d\n", itr+1, out);
	}
}
