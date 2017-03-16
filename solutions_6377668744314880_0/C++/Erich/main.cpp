#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
typedef double type;
using namespace std;
const double PI=acos(-1.0);
const double eps=1e-13;

struct Point
{
    type x,y;
    Point(){}
    Point(type a,type b)
    {
        x=a;
        y=b;
    }
    void read()
    {
        scanf("%lf%lf",&x,&y);
    }
    void print()
    {
        printf("%.6lf %.6lf",x,y);
    }

};
typedef Point Vector;
Vector operator + (Vector A,Vector B)
{
    return Vector(A.x+B.x,A.y+B.y);
}
Vector operator - (Point A,Point B)
{
    return Vector(A.x-B.x,A.y-B.y);
}
Vector operator * (Vector A,type p)
{
    return Vector(A.x*p,A.y*p);
}
Vector operator / (Vector A,type p)
{
    return Vector(A.x/p,A.y/p);
}
bool operator < (const Point &a,const Point &b)
{
    return a.x<b.x || (a.x==b.x && a.y<b.y);
}

int dcmp(double x)
{
    if (fabs(x)<eps) return 0;
    else return x<0?-1:1;
}
bool operator == (const Point& a,const Point b)
{
    return dcmp(a.x-b.x)==0 && dcmp(a.y-b.y)==0;
}
//atan2(x,y) :向量(x,y)的极角，即从x轴正半轴旋转到该向量方向所需要的角度。
type Dot(Vector A,Vector B)
{
    return A.x*B.x+A.y*B.y;
}
type Cross(Vector A,Vector B)
{
    return A.x*B.y-A.y*B.x;
}
type Length(Vector A)
{
    return sqrt(Dot(A,A));
}
type Angle(Vector A,Vector B)
{
    return acos(Dot(A,B))/Length(A)/Length(B);
}

type Area2(Point A,Point B,Point C)
{
    return Cross(B-A,C-A);
}
Vector Rotate(Vector A,double rad)
{
    return Vector(A.x*cos(rad)-A.y*sin(rad),A.x*sin(rad)+A.y*cos(rad));
}

Vector Normal(Vector A)//单位法线,左转90度，长度归一
{
    double L=Length(A);
    return Vector(-A.y/L,A.x/L);
}

Point GetLineIntersection(Point P,Vector v,Point Q,Vector w)
{
    Vector u=P-Q;
    double t=Cross(w,u)/Cross(v,w);
    return P+v*t;
}

double DistanceToLine(Point P,Point A,Point B)
{
    Vector v1=B-A,v2=P-A;
    return fabs(Cross(v1,v2))/Length(v1);
}
double DistanceToSegment(Point P,Point A,Point B)
{
    if (A==B) return Length(P-A);
    Vector v1=B-A,v2=P-A,v3=P-B;
    if (dcmp(Dot(v1,v2))<0) return Length(v2);
    else if (dcmp(Dot(v1,v3))>0) return Length(v3);
    else return fabs(Cross(v1,v2))/Length(v1);
}
Point GetLineProjection(Point P,Point A,Point B)//P在AB上的投影
{
    Vector v=B-A;
    return A+v*(Dot(v,P-A)/Dot(v,v));
}

bool SegmentProperIntersection(Point a1,Point a2,Point b1,Point b2)
{
    double c1=Cross(a2-a1,b1-a1),c2=Cross(a2-a1,b2-a1),
    c3=Cross(b2-b1,a1-b1),c4=Cross(b2-b1,a2-b1);
    return dcmp(c1)*dcmp(c2)<0 && dcmp(c3)*dcmp(c4)<0;
}

bool OnSegment(Point p,Point a1,Point a2)
{
    return dcmp(Cross(a1-p,a2-p))==0 && dcmp(Dot(a1-p,a2-p))<0;
}

double ConvexPolygonArea(Point* p,int n)//多边形面积
{
    double area=0;
    for (int i=1; i<n-1; i++)
    area+=Cross(p[i]-p[0],p[i+1]-p[0]);
    return area/2.0;
}
double PolygonArea(Point* p,int n)//有向面积
{
    double area=0;
    for (int i=1; i<n-1; i++)
    area+=Cross(p[i]-p[0],p[i+1]-p[0]);
    return area/2.0;
}
struct Line
{
    Point p;
    Vector v;
    double ang;
    Line(){};
    Line(Point PP,Vector vv)
    {
        p=PP;
        v=vv;
        ang=atan2(v.y,v.x);
    }
    bool operator< (const Line& L)const
    {
        return ang<L.ang;
    }
    Point point(double t)
    {
        return p+v*t;
    }
};
struct Circle
{
    Point c;
    double r;
    Circle()
    {
    }
    Circle(Point cc,double rr)
    {
        c=cc;
        r=rr;
    }
    Point point(double a)
    {
        return Point(c.x+cos(a)*r,c.y+sin(a)*r);
    }
};
int getLineCircleIntersection(Line L,Circle C,double& t1,double &t2,vector<Point>& sol)
{
    double a=L.v.x, b=L.p.x-C.c.x, c=L.v.y, d=L.p.y-C.c.y;
    double e=a*a+c*c,f=2*(a*b+c*d), g=b*b+d*d-C.r*C.r;
    double delta=f*f-4*e*g;//判别式
    if (dcmp(delta)<0) return 0;//相离
    if (dcmp(delta)==0)
    {
        t1=t2=-f/(2*e);
        sol.push_back(L.point(t1));
        return 1;
    }//相切
    t1=(-f-sqrt(delta))/(2*e); sol.push_back(L.point(t1));
    t2=(-f+sqrt(delta))/(2*e); sol.push_back(L.point(t2));
    return 2;
}
double angle(Vector v)//向量极角
{
    return atan2(v.y,v.x);
}
int getCircleCircleIntersection(Circle C1,Circle C2,vector<Point>& sol)
{
    double d = Length(C1.c-C2.c);
    if (dcmp(d)==0)
    {
        if (dcmp(C1.r-C2.r)==0) return -1;
        return 0;
    }
    if (dcmp(C1.r+C2.r-d)<0) return 0;
    if (dcmp(fabs(C1.r-C2.r)-d)>0) return 0;
    double a=angle(C2.c-C1.c);
    double da= acos((C1.r*C1.r+d*d-C2.r*C2.r)/(2*C1.r*d));
    Point p1=C1.point(a-da),p2=C1.point(a+da);
    sol.push_back(p1);
    if (p1==p2) return 1;
    sol.push_back(p2);
    return 2;
}
int getTangents(Point p,Circle C,Vector* v)
{
    Vector u=C.c-p;
    double dist=Length(u);
    if (dist<C.r) return 0;
    else if (dcmp(dist-C.r)==0)
    {
        v[0]=Rotate(u,PI/2);
        return 1;
    }
    else
    {
        double ang=asin(C.r/dist);
        v[0]=Rotate(u,-ang);
        v[1]=Rotate(u,+ang);
        return 2;
    }
}
int getTangents(Circle A,Circle B,Point* a,Point* b)
{
    int cnt=0;
    if (A.r<B.r)
    {
        swap(A,B); swap(a,b);
    }
    int d2=(A.c.x-B.c.x)*(A.c.x-B.c.x)+(A.c.y-B.c.y)*(A.c.y-B.c.y);
    int rdiff=A.r-B.r;
    int rsum=A.r+B.r;
    if (d2<rdiff*rdiff) return 0;
    double base=atan2(B.c.y-A.c.y,B.c.x-A.c.x);
    if (d2==0 && A.r==B.r) return -1;

    if (d2==rdiff*rdiff)
    {
        a[cnt]=A.point(base); b[cnt]=B.point(base); cnt++;
        return 1;
    }
    double ang=acos((A.r-B.r)/sqrt(d2));
    a[cnt]=A.point(base+ang); b[cnt]=B.point(base+ang); cnt++;
    a[cnt]=A.point(base-ang); b[cnt]=B.point(base-ang); cnt++;
    if (d2==rsum*rsum)
    {
        a[cnt]=A.point(base); b[cnt]=B.point(PI+base); cnt++;
    }
    else if (d2>rsum*rsum)
    {
        double ang=acos((A.r+B.r)/sqrt(d2));
        a[cnt]=A.point(base+ang); b[cnt]=B.point(PI+base+ang); cnt++;
        a[cnt]=A.point(base-ang); b[cnt]=B.point(PI+base-ang); cnt++;
    }
    return cnt;
}
int isPointInpolygon(Point p,Point* poly,int n)
{
    int wn=0;
    for (int i=0; i<n; i++)
    {
        if (OnSegment(p,poly[i],poly[(i+1)%n]) || p==poly[i] || p==poly[(i+1)%n]) return -1;
        int k=dcmp(Cross(poly[(i+1)%n]-poly[i],p-poly[(i+1)%n]));
        int d1=dcmp(poly[i].y-p.y);
        int d2=dcmp(poly[(i+1)%n].y-p.y);
        if (k>0 && d1<=0 && d2>0) wn++;
        if (k<0 && d2<=0 && d1>0) wn--;
    }
    if (wn!=0) return 1;
    else return 0;
}
int ConvexHull(Point *p, int n,Point *ch)
{
    sort(p,p+n);
    int m=0;
    for (int i=0; i<n; i++)
    {
        while(m>1 && Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2])<0) m--;
        ch[m++]=p[i];
    }
    int k=m;
    for (int i=n-2; i>=0; i--)
    {
        while(m>k && Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2])<0) m--;
        ch[m++]=p[i];
    }
    if (n>1) m--;
    return m;
}

int tt,cas,n;
Point p[20];
Point ap[20];
Point ch[20];
int getnum(int x){
    int res=0;
    while(x){
        if (x&1) res++;
        x>>=1;
    }
    return res;
}
int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    scanf("%d",&tt);
    for (cas = 1; cas <= tt; cas++){
            scanf("%d",&n);
            for (int i = 0; i < n; i++){
                p[i].read();
            }
            cout<<"Case #" << cas << ":" <<endl;

            for (int st = 0; st < n; st ++){
                int ans = 9999;
                int m = 0;
                for (int sta = 0; sta < (1<<n); sta++){
                    int num = getnum(sta);
                    m = 0;
                    memset(ap,0,sizeof ap);
                    memset(ch,0,sizeof ch);

                    if ((1<<st)&sta) continue;
                    for (int i = 0; i < n; i++){
                        if (((1<<i)&sta)==0){
                            ap[m++] = p[i];
                        }
                    }
                    int k = ConvexHull(ap,m,ch);
                    for (int i = 0; i < k; i++){
                        if (ch[i] == p[st]){
                            ans = min(ans,num);
                        }
                    }
                }
                cout<<ans<<endl;
            }
    }

}
