#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
struct Point {
    double x, y;
    Point(double x=0, double y=0):x(x),y(y) {}
};
bool operator < (const Point& p1, const Point& p2) {
    return p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y);
}
double Cross(const Point& A, const Point& B) {
    return A.x*B.y - A.y*B.x;
}
Point operator - (const Point& A, const Point& B) {
    return Point(A.x-B.x, A.y-B.y);
}
bool operator == (const Point& p1, const Point& p2) {
    return p1.x == p2.x && p1.y == p2.y;
}
bool ConvexHull(vector<Point> p,const Point &fff) {
    // 预处理，删除重复点
    sort(p.begin(), p.end());
    //p.erase(unique(p.begin(), p.end()), p.end());

    int n = p.size();
    int m = 0;
    vector<Point> ch(n+1);
    for(int i = 0; i < n; i++) {
        while(m > 1 && Cross(ch[m-1]-ch[m-2], p[i]-ch[m-2]) <= 0) m--;
        ch[m++] = p[i];
    }
    int k = m;
    for(int i = n-2; i >= 0; i--) {
        while(m > k && Cross(ch[m-1]-ch[m-2], p[i]-ch[m-2]) <= 0) m--;
        ch[m++] = p[i];
    }
    if(n > 1) m--;
    ch.resize(m);
    for(int i=0;i<ch.size();i++)
        if(fff==ch[i])
            return true;
    ch.push_back(ch[0]);
    for(int i=0;i<ch.size()-1;i++)
        if(Cross(fff-ch[i],fff-ch[i+1])==0)
            return true;
    return false;
}
vector<Point> point;
int main()
{
    int T,cas=1;
    freopen("c.in","r",stdin);
    freopen("c.out","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        point.clear();
        for(int i=0;i<n;i++)
        {
            Point tmp;
            scanf("%lf%lf",&tmp.x,&tmp.y);
            point.push_back(tmp);
        }
        printf("Case #%d:\n",cas++);
        for(int i=0;i<n;i++)
        {
            int ans=100;
            for(int k=0;k<(1<<n);k++)
            {
                if(k&(1<<i))
                {
                    vector<Point> tmp;
                    for(int j=0;j<n;j++)
                        if(k&(1<<j))
                            tmp.push_back(point[j]);
                    if(ConvexHull(tmp,point[i]))
                    {
                        int ttt=n;
                        for(int j=0;j<n;j++)
                            if((1<<j)&k)
                                --ttt;
                        //printf("%d %d\n",i,ttt);
                        ans=min(ans,ttt);
                    }
                }
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
