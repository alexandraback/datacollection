#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int N;
#define sqr(x) ((x)*(x))
const double pi=acos(-1.0);
const double eps=1e-8;
int sgn(double x)
{
    return x<-eps?-1:x>eps;
}
struct point
{
    double x,y;
    point() {}
    point(double a,double b): x(a),y(b) {}
    void read()
    {
        scanf("%lf%lf",&x,&y);
    }
    void show()
    {
        printf("(%lf,%lf)\n",x,y);
    }
    point operator + (const point &b) const
    {
        return point(x+b.x,y+b.y);
    }
    point operator - (const point &b) const
    {
        return point(x-b.x,y-b.y);
    }
    point operator * (const double &b) const
    {
        return point(x*b,y*b);
    }
    point operator / (const double &b) const
    {
        return point(x/b,y/b);
    }
    bool operator == (const point &b) const
    {
        return (sgn(y-b.y)==0&&sgn(x-b.x)==0);
    }
    bool operator < (const point &b) const
    {
        if(sgn(y-b.y)==0)
        return x<b.x;
        return y<b.y;
    }
    double operator * (const point &b) const
    {
        return x*b.x+y*b.y;
    }
    double X (const point &b) const
    {
        return x*b.y-y*b.x;
    }
    point rot (const double &ta) const
    {
        return point(cos(ta)*x-sin(ta)*y,sin(ta)*x+cos(ta)*y);
    }
    point rot90 (const double &d) const
    {
        return point(-y,x) / len()*d;
    }
    double dis (const point &b) const
    {
        return sqrt(fabs((x-b.x)*(x-b.x)+(y-b.y)*(y-b.y)));
    }
    double dis2 (const point &b) const
    {
        return fabs(sqr(x-b.x)+sqr(y-b.y));
    }
    double len() const
    {
        return sqrt(x*x+y*y);
    }
    double len2() const
    {
        return x*x+y*y;
    }
};

struct line
{
    point s,e;
    double ang;
    line () {}
    line(point a,point b): s(a),e(b),ang(atan2(e.y-s.y,e.x-s.x)) {}
    bool operator / (const line &l) const
    {
        return sgn((l.s-l.s).X(e-s))==0;
    }
    bool operator == (const line &l) const
    {
        return sgn((l.s-s).X(l.e-s))==0&&sgn((l.s-e).X(l.e-e))==0;
    }
    bool operator < (const line &b) const
    {
        if(sgn(b.ang-ang)!=0)return ang<b.ang;
        return sgn((b.e-b.s).X(e-b.s))>=0;
    }
    bool isright(const point &p) const
    {
        return sgn((p-s).X(e-s))>0;
    }
    bool ispointonline(const point &a) const
    {
        return sgn((a-s).X(a-e))==0;
    }
    bool ispointonseg(const point &a) const
    {
        return sgn((a-s).X(a-e))==0&&sgn((a-s)*(a-e))<=0;
    }
    bool iscross(const line &l) const //严格相交
    {
        int  t1=sgn((l.s-s).X(e-s));
        int  t2=sgn((l.e-s).X(e-s));
        int  t3=sgn((s-l.s).X(l.e-l.s));
        int  t4=sgn((e-l.s).X(l.e-l.s));
        return t1*t2<0&&t3*t4<0;
    }
    point crosspoint(const line &l)
    {
        double a1 = (s-l.s).X(e-l.s), a2 = -(s-l.e).X(e-l.e);
        return (l.s * a2 + l.e * a1) / (a1 + a2);
    }
    point ref(const point &p) const
    {
        point pj =s+(e - s)*((e - s)*(p - s)/(e - s).len2());
        return pj * 2 - p;
    }
    double dis(const point &p) const
    {
        return (e-s).X(p-s)/(e-s).len()/2;
    }
};

struct polygon
{
    point p[100];
    int n;
    double area()
    {
        double ans = 0;
        for(int i = 1;i <= n;i++)
        ans+=p[i - 1].X(p[i%n]);
        return ans/ 2;
    }
    point center()
    {
        double sx=0,sy=0,sa=0;
        for(int i=2;i<n;i++)
        {
            point p0=p[0];
            point p1=p[i-1];
            point p2=p[i];
            double cx=p0.x+p1.x+p2.x;
            double cy=p0.y+p1.y+p2.y;
            double A=(p1-p0).X(p2-p0);
            sa+=A;
            sx+=cx*A;
            sy+=cy*A;
        }
        return point(sx/sa/3,sy/sa/3);
    }
    void grahanm(polygon &ans)
    {
        sort(p,p+n);
        ans.p[0]=p[0];ans.p[1]=p[1];
        int now=2;
        for(int i=2;i<n;i++)
        {
            while(now>1&&sgn((ans.p[now-1]-p[i]).X(ans.p[now-2]-p[i]))>0)now--;
            ans.p[now++]=p[i];
        }
        int top=now;
        for(int i=n-2;i>=0;i--)
        {
            while(now>top&&sgn((ans.p[now-1]-p[i]).X(ans.p[now-2]-p[i]))>0)now--;
            ans.p[now++]=p[i];
        }
        ans.n=--now;
    }
    bool isin(point a)
    {
        a=a-p[0];
        if(sgn((p[1]-p[0]).X(a))<0)return 0;
        int l=1,r=n-1;
        while(l<r)
        {
            int mid=(l+r)/2+1;
            double temp=(p[mid]-p[0]).X(a);
            if(sgn(temp)==0)
            {
               line l1=line(p[0],p[mid]);
               return l1.ispointonseg(a+p[0]);
            }
            if(temp>0)l=mid;
            else r=mid-1;
        }
        if(l==n-1)return 0;
        return sgn((p[l+1]-p[l]).X(a+p[0]-p[l]))>=0;
    }
    void cut(point p1,point p2)
    {
        p[n]=p[0];
        polygon q;
        line l1, l2;
        int t1, t2;
        q.n = 0;
        for(int i = 0;i < n;i++)
        {
            t1 =sgn((p2-p1).X(p[i]-p1));
            t2 =sgn((p2-p1).X(p[i+1]-p1));
            if(t1>=0)q.p[q.n++] = p[i];
            if(t1*t2< 0)
            {
                l1 = line(p1, p2);
                l2 = line(p[i], p[i + 1]);
                q.p[q.n++] = l1.crosspoint(l2);
            }
        }
        n=q.n;
        for(int i=0;i<q.n;i++)p[i]=q.p[i];
        p[n] = p[0];
    }
};
point P[20];
int S[20];
int main(){
    freopen("inc.in","r",stdin);
    freopen("outc.out","w",stdout);
    int T;scanf("%d",&T);int tt = 0;
    while(T--){tt++;
        scanf("%d",&N);
        for(int i=0;i<N;i++){
            P[i].read();
            S[i] = N-1;
        }
        for(int n=0;n<(1<<N);n++){
            polygon pol;
            pol.n = 0;
            for(int i=0;i<N;i++){
                if(n&(1<<i)){
                    pol.p[pol.n++] = P[i];
                }
            }
            polygon py;
            pol.grahanm(py);
            for(int i=0;i<N;i++){
                if(n&(1<<i)){
                    for(int j=0;j<py.n;j++){
                        if(py.p[j] == P[i]){
                            S[i] = min(S[i],N - pol.n);
                            break;
                        }
                    }
                }
            }
        }
        printf("Case #%d:\n",tt);
        for(int i=0;i<N;i++){
            printf("%d\n",S[i]);
        }
    }
    return 0;
}
