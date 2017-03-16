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

int cards1[4][4];
int cards2[4][4];

int main () {
	int T;
	scanf("%d", &T);
	FOR(itr, T) {
		int row1, row2;
		scanf("%d", &row1);
		FOR(i, 4)
			FOR(j, 4)
				scanf("%d", &cards1[i][j]);
		scanf("%d", &row2);
		FOR(i, 4)
			FOR(j, 4)
				scanf("%d", &cards2[i][j]);

		int out = -1, count = 0;
		FOR(i, 4)
			FOR(j, 4)
				if (cards1[row1-1][i] == cards2[row2-1][j]) {
					++count;
					out = cards1[row1-1][i];
				}

		if (count == 0)
			printf("Case #%d: Volunteer cheated!\n", itr+1);
		else if (count > 1)
			printf("Case #%d: Bad magician!\n", itr+1);
		else
			printf("Case #%d: %d\n", itr+1, out);
	}
}
