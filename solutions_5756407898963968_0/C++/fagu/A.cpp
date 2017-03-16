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
bool ok[16];

int main() {
	scanf("%d ", &T);
	for (int test = 0; test < T; test++) {
		fprintf(stderr, "Test %d/%d\n", test+1, T);
		printf("Case #%d: ", test+1);
		fill_n(ok, 16, true);
		REP(ru,0,2) {
			int a;
			scanf("%d", &a);
			a--;
			REP(i,0,16) {
				int w;
				scanf("%d", &w);
				w--;
				if (i < 4*a || i >= 4*(a+1))
					ok[w] = false;
			}
		}
		int k = 0;
		REP(i,0,16)
			k += ok[i];
		if (k == 0)
			printf("Volunteer cheated!\n");
		else if (k > 1)
			printf("Bad magician!\n");
		else {
			REP(i,0,16)
				if (ok[i])
					printf("%d\n", i+1);
		}
	}
	return 0;
}
