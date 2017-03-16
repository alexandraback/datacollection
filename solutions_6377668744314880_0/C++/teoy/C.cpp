#include "iostream"
#include "cstring"
#include "cstdio"
#include "cmath"
using namespace std;
typedef long long ll;
const int N = 20;
struct Point
{
	ll x,y;
};
Point pt[N], pln[N], rin[N];
ll dlcmp(ll x)
{
	return x < 0 ? -1:x > 0;
}
ll cross(Point a, Point b, Point s)
{
	ll x1 = a.x - s.x, y1 = a.y - s.y;
	ll x2 = b.x - s.x, y2 = b.y - s.y;
	return x1 * y2 - x2 * y1;
}
ll dis(Point a, Point b)
{
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
int cmp(Point a, Point b)
{
	if(dlcmp(cross(a, b, pt[0])) == 1||
		(dlcmp(cross(a, b, pt[0])) == 0&& dis(pt[0], a) < dis(pt[0], b)))
		return 1;
	else
		return 0;
}
int graham_scan(int n)
{
	int i, top, t;
	if(n <= 1) return n;
	for(t = 0, i = 1; i < n; ++ i){
		if(dlcmp(pt[i].y - pt[t].y) == 1 ||
			(dlcmp(pt[i].y - pt[t].y) == 0 && dlcmp(pt[i].x - pt[t].x) == -1))
			t = i;
	}
	swap(pt[0], pt[t]);
	sort(pt + 1, pt + n, cmp);
	top = 2;
	for(i = 0; i < 2; ++ i){
		pln[i] = pt[i];
	}
	for(i = 2; i < n; ++ i){
		while(top > 1 && dlcmp(cross(pln[top - 1],pt[i],pln[top - 2]))<=0)
			top --;
		pln[top ++] = pt[i];
	}
	return top;
}
ll gcross(ll x1, ll y1, ll x2, ll y2)
{
	return x1 * y2 - x2 * y1;
}
int on_segment(Point a, Point b, Point k)
{
	if(gcross(k.x-a.x,k.y-a.y,b.x-a.x,b.y-a.y) == 0 &&
		k.x>=min(a.x,b.x)&&k.x<=max(a.x,b.x)&&
		k.y>=min(a.y,b.y)&&k.y<=max(a.y,b.y))
		return 1;
	else
		return 0;
}
int result[N];
int num[N];
int main(void)
{
	int g = 0, T, n;
	scanf("%d", &T);
	while(T--){
		printf("Case #%d:\n", ++g);
		scanf("%d", &n);
		for(int i = 1; i <= n; ++ i){
			scanf("%lld %lld", &rin[i].x, &rin[i].y);
			result[i] = 1000;
		}
		if(n == 1){
			printf("0\n");
			continue;
		}
		for(int i = 0; i < (1 << n); ++ i){
			int now = 0;
			for(int j = 1; j <= n; ++ j){
				if(i & (1 << (j - 1))){
					pt[now++] = rin[j];
				}
			}
			int m = graham_scan(now);
			for(int k = 1; k <= n; ++ k){
				for(int j = 1; j < m; ++ j){
					if(on_segment(pln[j - 1], pln[j],rin[k])){
						result[k] = min(result[k], n - now);
					}
				}
				if(on_segment(pln[0],pln[m - 1],rin[k])){
					result[k] = min(result[k], n - now);
				}
			}
		}
		for(int i = 1; i <= n; ++ i){
			printf("%d\n", result[i]);
		}
	}
	return 0;
}