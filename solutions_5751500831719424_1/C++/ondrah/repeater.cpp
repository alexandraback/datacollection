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
#define REP(i, N) for(int i = 0; i < (N); i++)

using namespace std;

char str[111][111];
int ind[111];
int len[111];
int main() {
	int T, testcase=1;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		REP(i, n) {
			ind[i] = 0;
			scanf("%s", str[i]);
			len[i] = strlen(str[i]);
		}
		int ans = 0;
		bool ok = true;
		bool done = false;
		while(!done) {
			done = true;
			REP(i, n) {
				if(ind[i] != len[i]) done = false;
			}
			if(done) break;
			REP(i, n) if(!done && ind[i] == len[i]) { ok = false; break; }
			char c = -1;
			REP(i, n) if(ind[i] < len[i]) {
				if(c != -1 && str[i][ind[i]] != c) {
					ok = false;
					break;
				}
				c = str[i][ind[i]];
			}
			vector<int> counts;
			REP(i, n) {
				int s = ind[i];
				while(ind[i] < len[i] && c == str[i][ind[i]]) {
					ind[i]++;
				}
				counts.pb(ind[i]-s);
			}
			sort(counts.begin(), counts.end());
//			printf("%d %d", counts[0], counts[1]);
			int cans = 100000;
			for(int fcount = 1; fcount <= counts[n-1]; fcount++) {
				int cnt = 0;
				REP(i, n) cnt += abs(fcount-counts[i]);			
				cans = min(cnt, cans);
			}
			ans += cans;
		}

		printf("Case #%d: ", testcase++);

		if(!ok)
			printf("Fegla Won");
		else printf("%d", ans);

		printf("\n");
	}
	
	return 0;
}
