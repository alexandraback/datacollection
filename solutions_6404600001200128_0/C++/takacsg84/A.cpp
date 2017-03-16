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

void dostuff() {
	int N, r1 = 0, r2 = 0, rate = 0, cur = 0;
	scanf("%i", &N);
	vector<int> X(N);
	REP(i, N) scanf("%i", &X[i]);
	REP(i, N - 1) r1 += max(0, X[i] - X[i + 1]), rate = max(rate, X[i] - X[i + 1]);
	cur = X[0];
	REP(i, N - 1) r2 += min(X[i], rate);
	printf("%i %i\n", r1, r2);
}

int main() {
	int T;
	scanf("%i", &T);
	REP(t, T) printf("Case #%i: ", t + 1), dostuff();
}