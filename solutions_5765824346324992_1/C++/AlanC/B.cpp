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
#define N 1005
int TC, a[N], n;
LL Q;

LL count(LL x) {
	if (x == -1) return 0;
	LL ret = 0;
	FOR(i, 0, n) ret += (x / a[i] + 1);
	return ret;
}

void test_case(int tc) {
	scanf("%d%lld", &n, &Q);
	FOR(i, 0, n) scanf("%d", &a[i]);
	
	LL h = 0, t = 1000000000LL * 100000LL + 999, tim = -1;
	while (h + 1 < t) {
		//printf("%lld %lld\n", h, t);
		LL m = h + (t - h) / 2;
		LL cnt = count(m);
		if (cnt < Q) {
			tim = max(tim, m);
		    h = m;
		}
		else t = m;
	}
	
	
	int ans = 0;
	Q -= count(tim);
	//printf("%lld %lld\n", Q, tim);
	FOR(i, 0, n)
	    if (((tim + 1) % a[i]) == 0) {
			Q--;
			if (Q == 0) {
				ans = i + 1;
				break;
			}
		}
	printf("Case #%d: %d\n", tc, ans);
}

int main(){
	scanf("%d", &TC);
	FOE(i, 1, TC) test_case(i);
	return 0;
}

