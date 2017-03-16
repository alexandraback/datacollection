#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>

#include<algorithm>
#include<utility>
#include<string>

#include<deque>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<vector>

using namespace std;

#define FOR(i,N) for (int i = 0; i < (N); i++)
#define FORI(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, b, a) for (int i = (b) - 1; i >= a; i--)
#define DP(arg...) fprintf(stderr, ## arg) //COMPILER SPECIFIC!!!


typedef long long ll;

int T;
int ans1, ans2;
int M1[4][4], M2[4][4];

int X[17], Y[17];
int P;
int t;

void solve() {
	FOR(s,4)
		X[M1[ans1][s]]++;

	FOR(s,4)
		Y[M2[ans2][s]]++;

	FOR(i,17) {
		if (X[i] == Y[i] && X[i] == 1) P++;
	}
	
	if (P == 0) 
		printf("Case #%d: Volunteer cheated!\n", t+1);
	if (P > 1)
		printf("Case #%d: Bad magician!\n", t+1);
	if (P == 1) {
		FOR(i,17)
			if (X[i] == Y[i] && X[i] == 1)
				printf("Case #%d: %d\n", t+1, i);
	}
}

int main() {
	scanf("%d", &T);
	for (t = 0; t < T; t++) {
		scanf("%d", &ans1);
		ans1--;
		FOR(r,4) FOR(s,4)
			scanf("%d", &M1[r][s]);

		scanf("%d", &ans2);
		ans2--;

		FOR(r,4) FOR(s,4)
			scanf("%d", &M2[r][s]);

		FOR(i,17) X[i] = Y[i] = 0;

		P = 0;

		solve();
	}
	return 0;
}
