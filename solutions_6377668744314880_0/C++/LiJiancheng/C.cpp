#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll inf = 1e9;
struct point
{
    ll x,y;
    point() {}
    point(ll _x,ll _y):x(_x),y(_y) {}
    point operator+(const point &i)const
    {
        return point(x+i.x,y+i.y);
    }
    point operator-(const point &i)const
    {
        return point(x-i.x,y-i.y);
    }
    ll operator^(const point &i)const
    {
        return x*i.y-y*i.x;
    }
    ll operator*(const point &i)const
    {
        return x*i.x+y*i.y;
    }
    point operator*(ll k)const
    {
        return point(x*k,y*k);
    }
    point operator/(ll k)const
    {
        return point(x/k,y/k);
    }
    bool operator<(const point &i)const
    {
        return x<i.x || (x==i.x && y<i.y);
    }
    ll len()
    {
        return sqrt(*this **this);
    }
    point normal()
    {
        ll l=len();
        return point(x/l,y/l);
    }
    ll dis2line(point a,point b)
    {
        point d1=b-a,d2=*this-a;
        return fabs(d1^d2)/d1.len();
    }
};

vector<point> convex(vector<point>& p)
{
    sort(p.begin(),p.end());
    int n=p.size();
    vector<point> f(n*3);
    int m=0;
    for (int i=0; i<n; ++i)
    {
        while (m>1 && ((f[m-1]-f[m-2])^(p[i]-f[m-2]))<0) --m;
        f[m++]=p[i];
    }
    int k=m;
    for (int i=n-2; i>=0; --i)
    {
        while (m>k && ((f[m-1]-f[m-2])^(p[i]-f[m-2]))<0) --m;
        f[m++]=p[i];
    }
    if (n>1) --m;
    if (m < 0)
        m = 0;
    f.resize(m);
    return f;
}

bool check(vector<point> p, int x, int y)
{
    // for (int i = 0; i < p.size(); ++i)
    //     printf("   %lld,%lld  ", p[i].x, p[i].y);
    // puts("");
    vector<point> q = convex(p);
    // for (int i = 0; i < q.size(); ++i)
    //     printf("%lld,%lld  ", q[i].x, q[i].y);
    // puts("");
    for (int i = 0; i < q.size(); ++i)
        if (q[i].x == x && q[i].y == y)
                return 1;
    return 0;
}

void pbit(int x)
{
    for (int i = 0; i < 5; ++i)
        if ((x >> i) & 1)
            printf("1");
        else
            printf("0");
    puts("");
}
void solve()
{
    int n;
    scanf("%d", &n);
    vector<point> p;
    for (int i=0; i < n; ++i)
    {
        ll x,y;
        scanf("%lld%lld",&x,&y);
        p.push_back(point(x,y));
    }
    int nn = 1 << n;
    for (int i = 0; i < n; ++i)
    {
        if (check(p, p[i].x, p[i].y))
            printf("0\n");
        else
        {
            int ans = n - 1;
            for (int s = 1; s < nn; ++s)
                if ((s >> i) & 1)
                {
                    // pbit(s);
                    vector<point> temp;
                    int tot = 0;
                    for (int k = 0; k < n; ++k)
                        if ((s >> k) & 1)
                        {
                            temp.push_back(p[k]);
                            ++tot;
                        }
                    if (n - tot >= ans)
                        continue;
                    if (check(temp, p[i].x, p[i].y))
                        ans = min(ans, n - tot);
                }
            printf("%d\n", ans);
        }
    }
}

int main()
{
    int t;
    freopen("1.txt", "r", stdin);
    freopen("2.txt", "w", stdout);
    scanf("%d", &t);
    for (int tt = 1; tt <= t; ++tt)
    {
        printf("Case #%d:\n", tt);
        solve();
    }
    return 0;
}