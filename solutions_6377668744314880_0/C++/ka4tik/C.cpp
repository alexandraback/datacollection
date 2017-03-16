/*
 *Kartik Singal @ ka4tik
 */
#include<bits/stdc++.h>
using namespace std;
#define s(n) scanf("%d",&n);
typedef pair<double, double> point;
#define x first
#define y second

bool cw(const point &a, const point &b, const point &c) {
    return (b.first - a.first) * (c.second - a.second) - (b.second - a.second) * (c.first - a.first) < 0;
}

vector<point> convexHull(vector<point> p) {
    int n = p.size();
    if (n <= 1)
        return p;
    int k = 0;
    sort(p.begin(), p.end());
    vector<point> q(n * 2);
    for (int i = 0; i < n; q[k++] = p[i++])
        for (; k >= 2 && !cw(q[k - 2], q[k - 1], p[i]); --k)
            ;
    for (int i = n - 2, t = k; i >= 0; q[k++] = p[i--])
        for (; k > t && !cw(q[k - 2], q[k - 1], p[i]); --k)
            ;
    q.resize(k - 1 - (q[0] == q[1]));
    return q;
}
#define epsilon 1e-8
bool isBetween(point a, point b, point c)
{
    double crossproduct = (c.y - a.y) * (b.x - a.x) - (c.x - a.x) * (b.y - a.y);
    if( abs(crossproduct) > epsilon ) return false;

    double dotproduct = (c.x - a.x) * (b.x - a.x) + (c.y - a.y)*(b.y - a.y);
    if(dotproduct < 0 ) return false;

    double squaredlengthba = (b.x - a.x)*(b.x - a.x) + (b.y - a.y)*(b.y - a.y);
    if(dotproduct > squaredlengthba) return false;

    return true;
}
int main() {
    freopen("in","r",stdin);
    freopen("out","w",stdout);
    int t;s(t);
    int kase=0;
    while(t--)
    {
        kase++;
        printf("Case #%d:\n",kase);
        int n;s(n);
        vector<point> points(n);
        for(int i=0;i<n;i++)
        {
            cin>>(points[i].first);
            cin>>(points[i].second);
        }
        for(int l=0;l<n;l++)
        {
            int mn=n-1;
            for(int i=0;i<(1<<n);i++)
            {
                if(i&(1<<l)==0)
                    continue;
                vector<point> p;
                for(int j=0;j<n;j++)
                    if(i&(1<<j))
                        p.push_back(points[j]);
                vector<point> hull = convexHull(p);
                int flag=false;
                for(int k=0;k<hull.size();k++)
                {
                    if(isBetween(hull[k],hull[(k+1)%hull.size()],points[l]))
                    {
                        flag=true;
                        break;
                    }
                }
                if(flag)
                    mn=min(mn,n-__builtin_popcount(i));
            }
            cout<<mn<<endl;
        }
    }

}
