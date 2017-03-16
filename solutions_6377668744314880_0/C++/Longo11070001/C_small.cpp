#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#define pb push_back
using namespace std;

typedef long long ll;
const int maxn = 3030;
const int inf = 0x3f3f3f3f;

struct point
{
    ll x,y;
    point() {}
    point(ll x,ll y):x(x),y(y) {}
    friend point operator - (const point &a, const point &b)
    {
        return point(a.x-b.x,a.y-b.y);
    }
    friend bool operator == (const point &a, const point &b)
    {
        return a.x == b.x && a.y == b.y;
    }
} points[maxn];
int n;
int ans[maxn];

int cmp(ll x)
{
    if(x == 0) return 0;
    else if(x > 0) return 1;
    return -1;
}

ll det(const point &a, const point &b)
{
    return a.x*b.y-a.y*b.x;
}

bool comp_less(const point &a, const point &b)
{
    return a.x<b.x || (a.x==b.x && a.y<b.y);
}

vector<point> convex_hull(vector<point> a)
{
    sort(a.begin(),a.end(),comp_less);
    vector<point> res;
    res.resize(2*a.size()+5);
    int m = 0;
    for(int i=0; i<a.size(); i++)
    {
        while(m>1 && cmp(det(res[m-1]-res[m-2],a[i]-res[m-2]))<=0) --m;
        res[m++] = a[i];
    }
    int k = m;
    for(int i=a.size()-2; i>=0; i--)
    {
        while(m > k && cmp(det(res[m-1]-res[m-2],a[i]-res[m-2])<=0)) --m;
        res[m++] = a[i];
    }
    res.resize(m);
    if(a.size() > 1) res.resize(m-1);
    return res;
}

bool containOn(const vector<point> &a,const point &b)
{
    ll sign = 0;
    for(int i=0; i<a.size(); i++)
    {
        int x=cmp(det(a[i]-b,a[(i+1)%n]-b));
        if(x)
        {
            if(sign)
            {
                if(sign != x) return false;
            }
            else sign = x;
        }
    }
    for(int i=0; i<a.size(); i++)
    {
        int x=cmp(det(a[i]-b,a[(i+1)%n]-b));
        if(!x) return true;
    }
    return false;
}

inline int f(int x)
{
    int ret = 0;
    while(x)
    {
        if(x&1) ret++;
        x >>= 1;
    }
    return ret;
}

int main()
{
    freopen("C-small-attempt5.in","r",stdin);
    freopen("C-small-attempt5.out","w",stdout);
    int T,cas,i,j;
    scanf("%d",&T);
    for(cas=1; cas<=T; cas++)
    {
        scanf("%d",&n);
        for(i=0; i<n; i++)
        {
            scanf("%lld%lld",&points[i].x,&points[i].y);
        }
        memset(ans,inf,sizeof(ans));
        for(i=1; i<1<<n; i++)
        {
            int cnt = f(i);
            if(cnt < 2) continue;
            vector<point> fuck;
            for(j=0; j<n; j++)
            {
                if(i&(1<<j)) fuck.pb(points[j]);
            }
            vector<point> pol = convex_hull(fuck);
            /*if(cnt == 5){
                    printf("fuck %d\n",pol.size());
                    for(j=0; j<pol.size(); j++) cout<<pol[j].x<<" "<<pol[j].y<<endl;
            }*/
            for(j=0; j<n; j++)
            {
                if(containOn(pol,points[j]))
                {
                    /*if(i == 31 && j==4)
                    {
                        printf("fuck %d %d",pol.size(),cnt);
                    }*/
                    ans[j] = min(ans[j],n-cnt);
                }
            }
        }
        printf("Case #%d:\n",cas);
        if(n <=3)
        {
            for(i=0; i<n; i++) puts("0");
        }
        else
        {
            for(i=0; i<n; i++)
            {
                printf("%d\n",ans[i]);
            }
        }
    }
    return 0;
}
