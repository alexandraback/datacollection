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

int main () {
	double time = getTime();

	int T;
	scanf("%d", &T);
	FOR(itr, T) {
		int R, C, N;
		scanf("%d%d%d", &R, &C, &N);

		if (R > C) {
			int t;
			SWAP(R, C, t);
		}

		int out = 0;
		if (N > (R*C+1)/2) {
			int M = R*C - N;
			N -= (R*C+1)/2;
			if (R == 1) {
				out = 2 * N;
				if (C % 2 == 0)
					--out;
			}
			else if (R == 2) {
				out = 2 * min(N, 2) + 3 * (N - min(N, 2));
			}
			else { // (R >= 3)
				// add to checkerboard
				int edges = (C/2) + ((C+(R%2==0))/2) + (R/2) + ((R+(C%2==0))/2);
				if (R % 2 == 0 || C % 2 == 0) {
					edges -= 2;
				}

				out = 3 * min(N, edges) + 4 * (N - min(N, edges));
//				cerr << edges << endl;

				//subtract from full
				int interior = ((R-2)*(C-2)+1) / 2;
				edges = 2 * ((R/2)-1) + 2 * ((C/2)-1);
				if ((R % 2 == 0) != (C % 2 == 0))
					++edges;

				int corners = 4;
				if (R % 2 == 0 || C % 2 == 0)
					corners = 2;
//				cerr << interior << " " << edges << " " << corners << endl;

				if (M <= interior + edges + corners) {
					int sub = (R-1) * C + (C-1) * R - 4 * min(M, interior);
					M -= min(M, interior);
					sub -= 3 * min(M, edges);
					M -= min(M, edges);
					sub -= 2 * min(M, corners);
					out = min(sub, out);
//					cerr << sub << endl;
				}
			}
//			cerr << endl;

		}
		printf("Case #%d: %d\n", itr+1, out);
	}
	cerr << getTime() - time << endl;
}
