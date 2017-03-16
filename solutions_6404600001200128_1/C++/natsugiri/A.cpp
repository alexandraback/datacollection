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

int N, A[1011];
void solve() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);
    LL ans = 0;
    REP (i, N-1) ans += max(0, A[i] - A[i+1]);
    printf("%lld ", ans);

    ans = 0;
    LL r = 0;
    REP (i, N-1) amax(r, (LL)A[i]-A[i+1]);
    REP (i, N-1) {
	if (A[i] > r) ans += r;
	else ans += A[i];
    }
    printf("%lld\n", ans);
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
