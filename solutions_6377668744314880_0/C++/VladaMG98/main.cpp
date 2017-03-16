#include <bits/stdc++.h>
#define mid (lo+hi)/2
using namespace std;
const bool SUBMIT=1;
const int INF=0x3f3f3f3f;
const int MAXN=1010;
struct point {
	long long x,y;
}P[20];
bool eq(point p1, point p2)
{
    return p1.x==p2.x&&p1.y==p2.y;
}
bool cmp(point p1,point p2)
{
    if(p1.x==p2.x) return p1.y<p2.y;
    return p1.x<p2.x;
}
long long cross(point o,point a,point b)
{
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}
vector<point> convexhull(vector<point> pts)
{
	int n = pts.size(), idx = 0;
	vector<point> hull(2*n);
	sort(pts.begin(), pts.end(),cmp);
	for (int i = 0; i < n; ++i) {
		while (idx >= 2 && cross(hull[idx-2], hull[idx-1], pts[i]) < 0) idx--;
		hull[idx++] = pts[i];
	}
	for (int i = n-2, t = idx+1; i >= 0; i--) {
		while (idx >= t && cross(hull[idx-2], hull[idx-1], pts[i]) < 0) idx--;
		hull[idx++] = pts[i];
	}
	hull.resize(idx);
	return hull;
}
vector<point> points(int MASK,int n)
{
    vector<point> ret;
    for(int i=0;i<n;i++) if(MASK&(1<<i)) ret.push_back(P[i]);
    return ret;
}
bool contains(vector<point> a,point b)
{
    for(int i=0;i<a.size();i++) if(eq(a[i],b)) return true;
    return false;
}
int ans[20];
int main()
{
    if(SUBMIT)
    {
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    }
    int t;
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++)
    {
        for(int i=0;i<20;i++) ans[i]=0;
        printf("Case #%d:\n",tt);
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%lld%lld",&P[i].x,&P[i].y);
        }
        for(int MASK=0;MASK<(1<<n);MASK++)
        {
            vector<point> h=convexhull(points(MASK,n));
            int sz=__builtin_popcount(MASK);
            for(int i=0;i<n;i++)
            {
                if(contains(h,P[i])) ans[i]=max(ans[i],sz);
            }
        }
        for(int i=0;i<n;i++) printf("%d\n",n-ans[i]);
    }
    return 0;
}
