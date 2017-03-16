#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <assert.h>
#include <math.h>
#include <string.h>
using namespace std;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef long long ll;
#define FOREACH(it,vec) for(typeof((vec).begin()) it = (vec).begin(); it != (vec).end(); it++)
#define MODD(a,b) (((a)%(b)+(b))%(b))
#define REP(i,a,n) for (int i = (a); i < (n); i++)

int T;
int B;
ll N;
int m[2000];

int ge(ll t) {
	ll done = 0;
	REP(b,0,B)
		done += (t+m[b]-1)/m[b];
	if (done >= N)
		return B;
	REP(b,0,B) {
		if (t%m[b] == 0) {
			done++;
			if (done == N)
				return b;
		}
	}
	return -1;
}

int main() {
	scanf("%d ", &T);
	for (int test = 0; test < T; test++) {
		fprintf(stderr, "Test %d/%d\n", test+1, T);
		printf("Case #%d: ", test+1);
		scanf("%d %lld", &B, &N);
		REP(i,0,B)
			scanf("%d", m+i);
		ll t = -1; // max not working
		for (ll w = 1ll<<50; w > 0; w /= 2) {
			if (ge(t+w) == -1)
				t += w;
		}
// 		printf("t = %d %d %d\n", t, ge(t), ge(t+1));
		assert(ge(t) == -1 && ge(t+1) != -1 && ge(t+1) != B);
		printf("%d\n", ge(t+1)+1);
	}
	return 0;
}
