/*************************************************************************
    > File Name: c.cpp
    > Author: 
    > Created Time: 六  4/11 08:36:30 2015
 ************************************************************************/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cassert>

const int maxn = 4000;

using namespace std;

int T, n, q[maxn], X;

int top, st[maxn];

struct point {
	int x, y;
	point (int _=0, int __=0): x(_), y(__) {}

	point operator - (const point &b) {
		return point(x-b.x, y-b.y);
	}

	long long operator * (const point &b){
		return (((long long)(x))*b.y)-(((long long)y)*b.x);
	}

}points[maxn];

bool cmp(int x, int y){
	if ((points[x]-points[X])*(points[y]-points[X])!=0)
		return (points[x]-points[X])*(points[y]-points[X])>0;
	else
		return points[x].x!=points[y].x ? points[x].x < points[y].x
			: points[x].y > points[y].y;
}

int calc(int state, int cur){
	int P=0, N=0;
	for (int i=0; i<n; i++) 
		if (state & (1<<i))
			q[N++]=i;
	for (int i=0; i<N; i++)
		if (points[q[i]].x<points[q[P]].x
				|| (points[q[i]].x==points[q[P]].x && points[q[i]].y<points[q[P]].y))
			P=i;
	swap(q[0], q[P]);
	X = q[0];
	sort(q+1, q+N, cmp);
//	printf("Consider (%d,%D), P0=(%d,%d)\n", points[cur].x, points[cur].y,
//			points[P].x, points[P].y);
	top=1;
	st[0]=q[0];
	for (int i=1; i<N; i++){
		while (top>1 && (points[st[top-1]]-points[q[i]])*(points[st[top-2]]-points[q[i]])>0)
			top--;
		st[top++]=q[i];
	}
	/*printf("%d: ", top);
	for (int i=0; i<top; i++)
		printf("(%d,%d) ", points[st[i]].x, points[st[i]].y);
	putchar(10);*/
	for (int i=0; i<top; i++)
		if (st[i]==cur)
			return 1;
	return 0;
}

int main(){
	scanf("%d", &T);
	for (int cT=0; cT<T; ){
		scanf("%d", &n);
		for (int i=0; i<n; i++)
			scanf("%d%d", &points[i].x, &points[i].y);
		printf("Case #%d:\n", ++cT);
		for (int cur=0; cur<n; cur++){
			int ans = n-1;
			for (int i=0; i<(1<<n); i++)
				if ((i&(1<<cur)) && calc(i, cur)){
					int tmp=0;
					for (int k=0; k<n; k++)
						if (i&(1<<k))
							tmp++;
					ans = min(ans, n-tmp);
				}
			printf("%d\n", ans);
		}
	}
	return 0;
}

