#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

typedef long double db;
typedef long long ll;
typedef pair<ll, ll> poi;
const int maxn = 5005;
int n,tst;
#define x first
#define y second
poi p[maxn], q1[maxn], q2[maxn], q[maxn];

ll det(poi a, poi b)  {
	return a.x * b.y - a.y * b.x;
}
bool cmp(poi p, poi l)  { //point ,line
//	printf("cmp (%lld,%lld) (%lld,%lld)\n", p.x,p.y,l.x,l.y);
	if (l.y < 0 || (l.y == 0 && l.x < 0))  l.y *= -1, l.x *= -1;
	//printf("ret=%lld\n", det(p,l));
	return (det(l,p) >= 0);
}
bool cmp1(poi a, poi b)  {
	if ((a.y < 0) || (a.y == 0 && a.x < 0))  a.x*=-1, a.y*=-1;
	if ((b.y < 0) || (b.y==0&&b.x<0))  b.x*=-1,b.y*=-1;
	return det(a, b) > 0;
}
bool cmp2(poi a, poi b)  {
	return det(a, b) > 0;
}
bool cmp3(poi a, poi b)  {
	return det(a, b) > 0;
}

void solve()  {
	for (int st = 1; st <= n; st ++)  {
		poi o = p[st];
		int tot1 = 0, tot2 = 0, tot = 0;
		int ret = n - 1;

		//dir1
		for (int i = 1; i <= n; i ++)
			if (i != st)  {
				poi tmp = make_pair(p[i].x - o.x, p[i].y - o.y);
				q[++ tot] = tmp;
				if (tmp.y == 0)  {
					if (tmp.x > 0)  q1[++ tot1] = tmp;
					else q2[++ tot2] = tmp;
				}else  if (tmp.y > 0)  q1[++ tot1] = tmp;
				else q2[++ tot2] = tmp;
			}
		sort(q + 1, q + 1 + tot, cmp1);
		sort(q1 + 1, q1 + 1 + tot1, cmp2);
		sort(q2 + 1, q2 + 1 + tot2, cmp3);
		/*printf("st=%d, (%lld,%lld)\n", st,p[st].x,p[st].y);
		for (int i = 1;i<=tot;i++)  {
			printf("q[%d]=%lld,%lld\n", i, q[i].x,q[i].y);
		}
		for (int i =1;i <=tot1;i ++)  {
			printf("q1[%d]=%lld,%lld\n", i, q1[i].x,q1[i].y);
		}
		for (int i=1;i<=tot2;i++) {
			printf("q2[%d]=%lld,%lld\n",i,q2[i].x,q2[i].y);
		}*/
		int at1 = 0, at2 = 0;
		int cur = tot1;
		for (int i = 1; i <= tot; i ++)  {
			while (at2 + 1 <= tot2 && cmp(q2[at2 + 1], q[i])) at2 ++, cur ++;
			while (at1 + 1 <= tot1 && !cmp(q1[at1 + 1], q[i])) at1 ++, cur --;
			//printf("cur=%d, i=%d\n",cur,i);
			ret = min(ret, n - cur - 1);
		}
		//printf("ret=%d\n",ret);
		tot=tot1=tot2=0;
		//dir2
		for (int i = 1; i <= n; i ++)
			if (i != st)  {
				poi tmp = make_pair(p[i].x - o.x, p[i].y - o.y);
				tmp.x*=-1,tmp.y*=-1;
				q[++ tot] = tmp;
				if (tmp.y == 0)  {
					if (tmp.x > 0)  q1[++ tot1] = tmp;
					else q2[++ tot2] = tmp;
				}else  if (tmp.y > 0)  q1[++ tot1] = tmp;
				else q2[++ tot2] = tmp;
			}

		sort(q + 1, q + 1 + tot, cmp1);
		sort(q1 + 1, q1 + 1 + tot1, cmp2);
		sort(q2 + 1, q2 + 1 + tot2, cmp3);
	/*	printf("st=%d, (%lld,%lld)\n", st,p[st].x,p[st].y);
		for (int i = 1;i<=tot;i++)  {
			printf("q[%d]=%lld,%lld\n", i, q[i].x,q[i].y);
		}
		for (int i =1;i <=tot1;i ++)  {
			printf("q1[%d]=%lld,%lld\n", i, q1[i].x,q1[i].y);
		}
		for (int i=1;i<=tot2;i++) {
			printf("q2[%d]=%lld,%lld\n",i,q2[i].x,q2[i].y);
		}*/
		 at1 = 0, at2 = 0;
		cur = tot1;
		for (int i = 1; i <= tot; i ++)  {
			while (at2 + 1 <= tot2 && cmp(q2[at2 + 1], q[i])) at2 ++, cur ++;
			while (at1 + 1 <= tot1 && !cmp(q1[at1 + 1], q[i])) at1 ++, cur --;
			ret = min(ret, n - cur - 1);
		}
		printf("%d\n",ret);
	}
}

int main()  {
	scanf("%d", &tst);
	for (int t = 1; t <= tst; t ++)  {
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++)  
			scanf("%lld%lld", &p[i].x, &p[i].y);
		printf("Case #%d:\n", t);
		solve();
	}
	return 0;
}