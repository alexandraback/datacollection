#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdlib>
#include <cstring>
#include <string>

#define FOR(i, s, e) for (int i=(s);i<(e);i++)
#define FOE(i, s, e) for (int i=(s);i<=(e);i++)
#define FOD(i, s, e) for (int i=(s)-1;i>=(e);i--)
#define CLR(x, a) memset(x, a, sizeof(x))
#define LL long long int
using namespace std;

int TC;
int a[1005], n;

void test_case(int tc) {
	scanf("%d", &n);
	FOR(i, 0, n) scanf("%d", &a[i]);
	
	int RA = 0, mx = 0, RB = 0;
	FOR(i, 0, n - 1)
	    if (a[i] > a[i + 1]){
			RA += a[i] - a[i + 1];
			mx = max(mx, a[i] - a[i + 1]);
		}

	FOR(i, 0, n - 1)
	    RB += min(mx, a[i]);
	printf("Case #%d: %d %d\n", tc, RA, RB);
}

int main(){
	scanf("%d", &TC);
	FOE(i, 1, TC) test_case(i);
	return 0;
}

