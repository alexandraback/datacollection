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
#define N 100
struct pt {
	LL x, y;
	int id;
	bool operator < (const pt & P) const {
		if (x != P.x) return x < P.x;
		else return y < P.y;
	}
}P[N], Q[N];

int TC, n, ret[N], s[N];

LL cross(pt a, pt b, pt c) {
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

int convex_hull(int sz) {
	sort(Q, Q + sz);
	//FOR(i, 0, sz) printf(" -- [%lld %lld] %d\n", Q[i].x, Q[i].y, Q[i].id);
	int t = 0;
	FOR(i, 0, sz) {
		while (t > 1 && cross(Q[s[t-2]], Q[s[t-1]], Q[i]) < 0) t--;
		s[t++] = i;
	}
	int c = t;
	FOD(i, sz - 1, 0) {
		while (t > c && cross(Q[s[t-2]], Q[s[t-1]], Q[i]) < 0) t--;
		s[t++] = i;
	}
	return t;
}

void test_case(int tc) {
	scanf("%d", &n);
	FOR(i, 0, n) {
		scanf("%lld%lld", &P[i].x, &P[i].y);
		P[i].id = i;
		ret[i] = n + 1;
	}

	FOR(i, 0, (1<<n)) {
		int cnt = 0;
		FOR(j, 0, n) if ((1<<j) & i) Q[cnt++] = P[j];
		int sz = convex_hull(cnt);
		//printf("%d    %d\n", i, cnt);
		//FOR(j, 0, sz) printf("[%lld %lld]\n", Q[s[j]].x, Q[s[j]].y);
		FOR(j, 0, sz)
			ret[Q[s[j]].id] = min(ret[Q[s[j]].id], n - cnt);
	}
	printf("Case #%d:\n", tc);
	FOR(i, 0, n)
	    printf("%d\n", ret[i]);
}

int main(){
	scanf("%d", &TC);
	FOE(i, 1, TC) test_case(i);
	return 0;
}

