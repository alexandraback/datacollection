#include <bits/stdc++.h>
#define REP(x,n)  for(int x=0;x<(int)(n);x++)
#define RREP(x,n) for(int x=(int)(n)-1;x>=0;--x)
#define FOR(x,m,n) for(int x=(int)m;x<(int)(n);x++)
#define EACH(itr, cont) for(typeof((cont).begin()) itr = (cont).begin(); itr != (cont).end(); ++itr)
#define ALL(X)    (X).begin(),(X).end()
#define mem0(X)    memset((X),0,sizeof(X))
#define mem1(X)    memset((X),255,sizeof(X))

using namespace std;
typedef long long LL;
int X[16][16];

int calc(int R, int C) {
	int result = 0;
	REP(r, R)REP(c, C) {
		if (r > 0 && X[r][c] && X[r - 1][c]) ++result;
		if (c > 0 && X[r][c] && X[r][c - 1]) ++result;
	}
	return result;
}

void dostuff() {
	int R, C, N, result = 5555555;
	scanf("%i%i%i", &R, &C, &N);
	int K = R * C;
	REP(mask, 1 << K) {
		int cnt = 0;
		REP(r, R)REP(c, C) {
			int idx = r * C + c;
			if ((1 << idx) & mask)X[r][c] = 1, ++cnt;
			else X[r][c] = 0;
		}
		if (cnt == N) result = min(result, calc(R, C));
	}
	printf("%i\n", result);
}

int main() {
	int T;
	scanf("%i", &T);
	REP(t, T) printf("Case #%i: ", t + 1), dostuff();
}