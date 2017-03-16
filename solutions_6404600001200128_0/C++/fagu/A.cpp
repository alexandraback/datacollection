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
int N;
int m[2000];

int main() {
	scanf("%d ", &T);
	for (int test = 0; test < T; test++) {
		fprintf(stderr, "Test %d/%d\n", test+1, T);
		printf("Case #%d: ", test+1);
		scanf("%d", &N);
		REP(i,0,N) {
			scanf("%d", m+i);
		}
		int res1 = 0, res2 = 0, del = 0;
		REP(i,0,N-1) {
			res1 += max(0, m[i]-m[i+1]);
			del = max(del, m[i]-m[i+1]);
		}
		REP(i,0,N-1) {
			res2 += min(m[i], del);
		}
		printf("%d %d\n", res1, res2);
	}
	return 0;
}
