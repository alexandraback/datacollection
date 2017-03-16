#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define eps 1e-8
#define f(x, y, z) for(int x = (y), asdf = (z); x <= asdf; ++x)
#define g(x, y, z) for(int x = (y), asdf = (z); x < asdf; ++x)
using namespace std;
typedef long long LL;
struct point{LL x, y; int id;};
int n; point p[2333], res[2333], P[2333];
inline bool cmp(point p1,point p2){
	return p1.y<p2.y||(p1.y==p2.y&&p1.x<p2.x);
}
inline bool ral(point p1,point p2,point p3){
	return (p2.x-p1.x)*(p3.y-p1.y)>=(p3.x-p1.x)*(p2.y-p1.y);
}
// inline double dis(double x1,double y1,double x2,double y2){
	// return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
// }
int ans[2333];
inline void getans(){
	// printf("asdf0\n");
	if(n <= 3) return;
	// double ans = 0;
	// int top = 1;
	res[0]=p[0];
	res[1]=p[1];
	int top=1, i;
	// printf("asdf1\n");
	for(i=2;i<n;i++)
	{
		while(top&&!ral(res[top],res[top-1],p[i]))
			top--;
		res[++top]=p[i];
	}
	// printf("asdf2\n");
	int len=top;
	// res[++top]=p[n-2];
	for(i=n-2;i>=0;i--)
	{
		while(top!=len&&!ral(res[top],res[top-1],p[i]))
			top--;
		res[++top]=p[i];
	}
	// printf("asdf3 %d\n", top);
	g(i, 0, top){
		int cid = res[i].id;
		// printf("  cid %d\n", cid);
		if(ans[cid] < n) ans[cid] = n;
	}
	// printf("asdf4\n");
	// ans+=dis(res[0].x,res[0].y,res[top-1].x,res[top-1].y);
	// for(i=0;i<top-1;i++)
		// ans+=dis(res[i].x,res[i].y,res[i+1].x,res[i+1].y);
	// return ans;
}
int N;
inline void getans(int x){
	// printf("getans %d\n", x);
	// if(!x) return 0;
	n = 0;
	g(i, 0, N) if(x & (1 << i)) p[n++] = P[i];
	//printf("gans %d = %lf\n", x, getans());
	getans();
}
int main(){
	int T; scanf("%d", &T);
	for(int cid = 1; cid <= T; cid++){
		scanf("%d", &N); //if(!N) break;
		g(i, 0, N) scanf("%I64d%I64d", &P[i].x, &P[i].y), P[i].id = i + 1;
		printf("Case #%d:\n", cid);
		if(N <= 3){
			f(i, 1, N) printf("0\n");
			continue;
		}
		sort(P, P + N, cmp);
		int tot = (1 << N) - 1;
		// memset(ans, 0, sizeof(ans));
		f(i, 1, n) ans[i] = 3;
		f(st, 0, tot) getans(st);
		f(i, 1, n) printf("%d\n", n - ans[i]);
	}
	return 0;
}