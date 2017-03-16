#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
const double eps = 1e-10,PI = acos(-1.0);
const int Mn = 3010;
int n;
double l;
inline int dcmp(double x)
{
	if(fabs(x) < eps) return 0;
	return x > 0 ? 1 : -1;
}
struct P
{
	double x,y;
	P(double x = 0, double y = 0) : x(x), y(y) {}
}stack[Mn],a[Mn],b[Mn];
inline bool operator == (const P & a, const P & b) {return !dcmp(a.x-b.x) && !dcmp(a.y-b.y);}
inline P operator - (const P & a, const P & b){return P (a.x-b.x,a.y-b.y);}
inline double cross(const P & a, const P & b){return a.x * b.y - a.y * b.x;}
inline double dis(const P & a, const P & b){return sqrt((a.x-b.x) * (a.x-b.x) + (a.y-b.y) * (a.y-b.y));}
inline bool cmp(const P & a, const P & b)
{
	if(a.y != b.y) return a.y < b.y;
	return a.x < b.x;
}
inline int graham(P * a, int n)
{
	sort(a+1,a+n+1,cmp);
	int top(0);
	stack[++top] = a[1];
	stack[++top] = a[2];
	for(int i = 3;i <= n; i++)
	{
		while(top >= 2 && cross(stack[top]-stack[top-1],a[i]-stack[top-1]) < 0) top--;
		stack[++top] = a[i];
	}
	int tmp = top-1;
	stack[++top] = a[n-1];
	for(int i = n-2; i >= 1; i--)
	{
		while(top-tmp >= 2 && cross(stack[top] - stack[top-1],a[i] - stack[top-1]) < 0) top--;
		stack[++top] = a[i];
	}
	return --top;
}
inline int solve(int num) {
    int tot = 1 << n;
    int ans(n);
    for(int i = 0; i < tot; ++i) {
        if(i >> (num - 1) & 1) {
            int t(0);
            int cnt(0);
            for(int j = 1; j <= n; ++j)
                if(i >> (j - 1) & 1) {
                    b[++cnt] = a[j];
                    //cerr << cnt << endl;
                }
                else
                    t++;
            int top = graham(b,cnt);
            for(int i = 1; i <= top; ++i)
                if(stack[i] == a[num]) {
                    ans = min(ans,t);
                    break;
                }        
        }
    }
    return ans;
}
int main()
{
    freopen("C-small-attempt0 (1).in","r",stdin);
    freopen("C-small-attempt0 (1).out","w",stdout);
    int T;
    cin >> T;
    for(int cas = 1; cas <= T; ++cas) {
        scanf("%d",&n);
    	for(int i = 1; i <= n; i++)
    		scanf("%lf%lf",&a[i].x,&a[i].y);
    	printf("Case #%d:\n",cas);
        for(int i = 1; i <= n; ++i) {
            printf("%d\n",solve(i));
        }
    } 
	fclose(stdin);
    fclose(stdout);
	return 0;
}
