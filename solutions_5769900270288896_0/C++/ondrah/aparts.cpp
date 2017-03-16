#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <string>

#define pb push_back
#define mp make_pair
#define FOR(i, A, N) for(int (i) = (A); (i) < (N); (i)++)
#define REP(i, N) for(int (i) = 0; (i) < (N); (i)++)

using namespace std;
int d[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
int main() {
	int T;
	scanf("%d", &T);
	for(int testc = 1; testc <= T; testc++) {
		int r,c,n;
		scanf("%d%d%d", &r, &c, &n);
		int ans = 1<<30;
		REP(i, 1<<(r*c)) {
			int k = 0;
			REP(j, r*c) if(i&(1<<j)) k++;;
			if(k!=n)
				continue;
			int val = 0;
			REP(j, r*c) {
				int k = j/r, l=j%r;
				if(!(i&(1<<j)))
					continue;
				REP(dd, 4) {
					int kk = k+d[dd][0], ll = l+d[dd][1];
					if(kk < 0 || ll < 0 || kk >= c || ll >= r)
						continue;
					if(i&(1<<(kk*r+ll)))
						val++;
				}
			}
			ans = min(ans, val);
		}
		printf("Case #%d: %d\n", testc, ans/2);
	}
	return 0;
}
