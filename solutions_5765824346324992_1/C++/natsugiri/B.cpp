#include<cassert>
#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)
#define eprintf(s...) fprintf(stderr, s)

template<class T> inline void amin(T &a, const T &b) { if (a>b) a=b; }
template<class T> inline void amax(T &a, const T &b) { if (a<b) a=b; }

const LL INF = 1LL<<60;
int B, N, A[1111];
void solve() {
    scanf("%d%d", &B, &N);
    REP (i, B) scanf("%d", A+i);
    
    LL lo = -1, hi = INF;
    while (hi - lo > 1) {
	const LL m = (hi + lo) / 2;
	LL sum = 0;
	REP (i, B) {
	    sum = min(INF, sum + m / A[i] + 1);
	}
	if (sum >= N) hi = m;
	else lo = m;
    }

    if (lo >= 0) REP (i, B) N -= lo / A[i] + 1;
    REP (i, B) {
	if (hi % A[i] == 0) N--;
	if (N == 0) {
	    printf("%d\n", i+1);
	    return;
	}
    }
    eprintf("%d %lld\n", N, hi);
    assert(false);
}

int main() {
    int T;
    scanf("%d", &T);
    for (int tc=1; tc<=T; tc++) {
	printf("Case #%d: ", tc);
	solve();
    }
    return 0;
}
