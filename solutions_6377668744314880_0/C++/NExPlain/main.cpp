#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

#define PB push_back
#define MP make_pair

#define REP(i,n) for(i=0;i<(n);++i)
#define FOR(i,l,h) for(i=(l);i<=(h);++i)
#define FORD(i,h,l) for(i=(h);i>=(l);--i)
#define CLR(a,b) memset(a,b,sizeof(a))

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;
const double INF=1e100;
const double eps=1e-8;
const double pi=acos(-1.0);
#define next(i) ((i+1)%n)
inline int cmp(double x) { //≈–∂œ ˝µƒ∑˚∫≈
    return x<-eps?-1:x>eps?1:0;
}
inline double sqr(double x) { //º∆À„ ˝µƒ∆Ω∑Ω
    return x*x;
}
struct point { //µ„¿‡
    double x,y;
    point() {}
    point(double a,double b):x(a),y(b) {}
    void input() {
        scanf("%lf%lf",&x,&y);
    }
    friend point operator+(const point &a,const point &b) {
        return point(a.x+b.x,a.y+b.y);
    }
    friend point operator-(const point &a,const point &b) {
        return point(a.x-b.x,a.y-b.y);
    }
    friend bool operator==(const point &a,const point &b) {
        return cmp(a.x-b.x)==0&&cmp(a.y-b.y)==0;
    }
    friend point operator*(const point &a,const double b) {
        return point(a.x*b,a.y*b);
    }
    friend point operator*(const double a,const point &b) {
        return point(a*b.x,a*b.y);
    }
    friend point operator/(const point &a,const double b) {
        return point(a.x/b,a.y/b);
    }
    double norm() {
        return sqrt(sqr(x)+sqr(y));
    }
};
double det(const point &a,const point &b) { //º∆À„œÚ¡ø≤Êª˝
    return a.x*b.y-a.y*b.x;
}
double dot(const point &a,const point &b) { //º∆À„œÚ¡øµ„ª˝
    return a.x*b.x+a.y*b.y;
}
double dist(const point &a,const point &b) { //º∆À„¡Ωµ„æ‡¿Î
    return (a-b).norm();
}
point rotate_point(const point &p,double A) { //º∆À„œÚ¡øp»∆ƒÊ ±’Î–˝◊™Aª°∂»µ√µΩµƒœÚ¡ø
    return point(p.x*cos(A)-p.y*sin(A),p.x*sin(A)+p.y*cos(A));
}
struct line { //œﬂ∂ŒªÚ÷±œﬂ¿‡
    point a,b;
    line() {}
    line(point x,point y):a(x),b(y) {}
};
line point_make_line(const point &a,const point &b) { //…˙≥…œﬂ∂ŒªÚ÷±œﬂ
    return line(a,b);
}
double dis_point_segment(const point &p,const point &s,const point &t) { //º∆À„µ„pµΩœﬂ∂Œstæ‡¿Î
    if(cmp(dot(p-s,t-s))<0)
        return (p-s).norm();
    if(cmp(dot(p-t,s-t))<0)
        return (p-t).norm();
    return fabs(det(s-p,t-p)/dist(s,t));
}

void PointProjLine(const point &p,const point &s,const point &t,point &cp) { //º∆À„µ„pµΩœﬂ∂Œstµƒ¥π◊„£¨±£¥Ê”⁄cp
    double r=dot(t-s,p-s)/dot(t-s,t-s);
    cp=s+r*(t-s);
}
bool PointOnSegment(const point &p,const point &s,const point &t) { //≈–∂œµ„p «∑Ò‘⁄œﬂ∂Œsp…œ
    return cmp(det(p-s,t-s))==0&&cmp(dot(p-s,p-t))<=0;
}
bool parallel(const line &a,const line &b) { //≈–∂œ÷±œﬂa∫Õb «∑Ò∆Ω––
    return !cmp(det(a.a-a.b,b.a-b.b));
}
bool line_make_point(const line &a,const line &b,point &ret) { //≈–∂œ÷±œﬂa∫Õb «∑Òœ‡Ωª£¨»Ùœ‡ΩªΩªµ„±£¥Ê”⁄ret
    if(parallel(a,b))
        return false;
    double s1=det(a.a-b.a,b.b-b.a);
    double s2=det(a.b-b.a,b.b-b.a);
    ret=(s1*a.b-s2*a.a)/(s1-s2);
    return true;
}
line move_d(const line &a,const double len) { //º∆À„÷±œﬂa—ÿ∑®œÚ¡ø∆Ω“∆æ‡¿Îlenµ√µΩµƒ÷±œﬂ
    point d=a.b-a.a;
    d=d/d.norm();
    d=rotate_point(d,pi/2);
    return line(a.a+d*len,a.b+d*len);
}
double direction(const point &a,const point &b,const point &c) {
    return det(c-a,b-a);
}
bool OnSegment(const point &a,const point &b,const point &c) {
    if(c.x>=min(a.x,b.x)&&c.x<=max(a.x,b.x)&&c.y>=min(a.y,b.y)&&c.y<=max(a.y,b.y))
        return true;
    return false;
}
bool SegmentsIntersect(const line &a,const line &b) { //≈–∂œœﬂ∂Œa∫Õb «∑Òœ‡Ωª
    double d1=direction(b.a,b.b,a.a);
    double d2=direction(b.a,b.b,a.b);
    double d3=direction(a.a,a.b,b.a);
    double d4=direction(a.a,a.b,b.b);
    if(d1*d2<0&&d3*d4<0)
        return true;
    else if(d1==0&&OnSegment(b.a,b.b,a.a))
        return true;
    else if(d2==0&&OnSegment(b.a,b.b,a.b))
        return true;
    else if(d3==0&&OnSegment(a.a,a.b,b.a))
        return true;
    else if(d4==0&&OnSegment(a.a,a.b,b.b))
        return true;
    return false;
}

struct polygon_convex { //Õπ∂‡±ﬂ–Œ¿‡
    vector<point> P;
    polygon_convex(int Size=0) {
        P.resize(Size);
    }
};
struct polygon { //∂‡±ﬂ–Œ¿‡
    int n;
    point a[105];
    polygon() {}
    polygon(polygon_convex pc){
        n = pc.P.size();
        for(int i = 0 ; i < n ; i ++){
            a[i] = pc.P[i];
        }
    }
    double perimeter() { //º∆À„∂‡±ﬂ–Œ÷‹≥§
        double sum=0;
        a[n]=a[0];
        for(int i=0; i<n; ++i)
            sum+=(a[i+1]-a[i]).norm();
        return sum;
    }
    double area() { //º∆À„∂‡±ﬂ–Œ√Êª˝
        double sum=0;
        a[n]=a[0];
        for(int i=0; i<n; ++i)
            sum+=det(a[i+1],a[i]);
        return sum/2;
    }
    int Point_In(const point &t) { //≈–∂œµ„t «∑Ò‘⁄∂‡±ﬂ–Œƒ⁄≤ø£¨0±Ì æ‘⁄Õ‚£¨1±Ì æ‘⁄ƒ⁄£¨2±Ì æ‘⁄±ﬂΩÁ,O(n)
        int num=0,d1,d2,k;
        a[n]=a[0];
        for(int i=0; i<n; ++i) {
            if(PointOnSegment(t,a[i],a[i+1]))
                return 2;
            k=cmp(det(a[i+1]-a[i],t-a[i]));
            d1=cmp(a[i].y-t.y);
            d2=cmp(a[i+1].y-t.y);
            if(k>0&&d1<=0&&d2>0)
                ++num;
            if(k<0&&d2<=0&&d1>0)
                --num;
        }
        return num!=0;
    }
    point MassCenter() { //º∆À„∂‡±ﬂ–Œ÷ÿ–ƒ,O(n)
        point ans=point(0,0);
        if(cmp(area())==0) //∂‡±ﬂ–Œ√Êª˝Œ™0 ±÷ÿ–ƒŒﬁ∂®“Â£¨–ËÃÿ ‚¥¶¿Ì
            return ans;
        a[n]=a[0];
        for(int i=0; i<n; ++i)
            ans=ans+(a[i]+a[i+1])*det(a[i+1],a[i]);
        return ans/area()/6;
    }
    //“‘œ¬∫Ø ˝–Ë“™∂‡±ﬂ–Œ∂•µ„Œ™’˚µ„
    int Border_Int_Point_Num() { //º∆À„∂‡±ﬂ–Œ±ﬂΩÁ∏Òµ„£®’˚µ„£©∏ˆ ˝
        int num=0;
        a[n]=a[0];
        for(int i=0; i<n; ++i)
            num+=__gcd(abs(int(a[i+1].x-a[i].x)),abs(int(a[i+1].y-a[i].y)));
        return num;
    }
    int Inside_Int_Point_Num() { //º∆À„∂‡±ﬂ–Œƒ⁄≤ø∏Òµ„£®’˚µ„£©∏ˆ ˝
        return int(area())+1-Border_Int_Point_Num()/2;
    }
};
bool comp_less(const point &a,const point &b) {
    return cmp(a.x-b.x)<0||cmp(a.x-b.x)==0&&cmp(a.y-b.y)<0;
}
polygon_convex convex_hull(vector<point> &a) { //º∆À„µ„ºØaµƒÕπ∞¸£¨ƒÊ ±’Î–Ú≈≈¡–£¨ÀÆ∆Ω–Ú«Û∑®“‘±‹√‚æ´∂»Œ Ã‚£¨O(nlogn)
    polygon_convex ret(2*a.size()+5);
    sort(a.begin(),a.end(),comp_less);
    a.erase(unique(a.begin(),a.end()),a.end());
    int m=0;
    for(int i=0; i<a.size(); ++i) {
        while(m>1&&cmp(det(ret.P[m-1]-ret.P[m-2],a[i]-ret.P[m-2]))<=0)
            --m;
        ret.P[m++]=a[i];
    }
    int k=m;
    for(int i=int(a.size())-2; i>=0; --i) {
        while(m>k&&cmp(det(ret.P[m-1]-ret.P[m-2],a[i]-ret.P[m-2]))<=0)
            --m;
        ret.P[m++]=a[i];
    }
    ret.P.resize(m);
    if(a.size()>1)
        ret.P.resize(m-1);
    return ret;
}
bool containOn(const polygon_convex &a,const point &b) { //≈–∂œµ„b «∑Ò‘⁄Õπ∞¸aƒ⁄≤ø£¨true±Ì æ‘⁄ƒ⁄ªÚ±ﬂΩÁ£¨O(n)
    int n=a.P.size();
    int sign=0;
    for(int i=0; i<n; ++i) {
        int x=cmp(det(a.P[i]-b,a.P[next(i)]-b));
        if(x) {
            if(sign) {
                if(sign!=x)
                    return false;
            } else
                sign=x;
        }
    }
    return true;
}
int containOlogn(const polygon_convex &a,const point &b) { //≈–∂œµ„b «∑Ò‘⁄Õπ∞¸aƒ⁄≤ø£¨true±Ì æ‘⁄ƒ⁄ªÚ±ﬂΩÁ£¨O(logn)
    int n=a.P.size();
    point g=(a.P[0]+a.P[n/3]+a.P[2*n/3])/3; //’““ª∏ˆÕπ∞¸ƒ⁄≤øµƒµ„g
    int l=0,r=n;
    while(l+1<r) { //∂˛∑÷Õπ∞¸ g-a.P[a]-a.P[b]
        int mid=(l+r)/2;
        if(cmp(det(a.P[l]-g,a.P[mid]-g))>0) {
            if(cmp(det(a.P[l]-g,b-g))>=0&&cmp(det(a.P[mid]-g,b-g))<0)
                r=mid;
            else
                l=mid;
        } else {
            if(cmp(det(a.P[l]-g,b-g))<0&&cmp(det(a.P[mid]-g,b-g))>=0)
                l=mid;
            else
                r=mid;
        }
    }
    r%=n;
    int z=cmp(det(a.P[r]-b,a.P[l]-b))-1;
    if(z==-2)
        return 1;
    return z;
}
double convex_diameter(polygon_convex &a,int &First,int &Second) { //º∆À„Õπ∞¸a…œ◊Ó‘∂≈∑º∏¿Ôµ√æ‡¿Î£¨◊Ó‘∂µ„∂‘”¶±Í∫≈±£¥Ê”⁄First∫ÕSecond£¨O(n)
    vector<point> &p=a.P;
    int n=p.size();
    double maxd=0;
    if(n==1) {
        First=Second=0;
        return maxd;
    }
    for(int i=0,j=1; i<n; ++i) {
        while(cmp(det(p[next(i)]-p[i],p[j]-p[i])-det(p[next(i)]-p[i],p[next(j)]-p[i]))<0)
            j=next(j);
        double d=dist(p[i],p[j]);
        if(d>maxd) {
            maxd=d;
            First=i;
            Second=j;
        }
        d=dist(p[next(i)],p[next(j)]);
        if(d>maxd) {
            maxd=d;
            First=i;
            Second=j;
        }
    }
    return maxd;
}
double convex_perimeter(polygon_convex &a) { //º∆À„Õπ∂‡±ﬂ–Œ÷‹≥§
    double sum=0;
    for(int i=1; i<a.P.size(); ++i)
        sum+=(a.P[i]-a.P[i-1]).norm();
    sum+=(a.P[0]-a.P[a.P.size()-1]).norm();
    return sum;
}
double convex_area(polygon_convex &a) { //º∆À„Õπ∂‡±ﬂ–Œ√Êª˝
    double sum=0;
    for(int i=1; i<a.P.size(); ++i)
        sum+=det(a.P[i],a.P[i-1]);
    sum+=det(a.P[0],a.P[a.P.size()-1]);
    return sum/2;
}
bool onBound(polygon_convex pc, point p){
    polygon poly(pc);
    return poly.Point_In(p) == 2 ? true : false;
}
const int N = 105;
int n;
point p[N];
int ans[N];
void solve()
{
    scanf("%d",&n);
    for(int i = 0 ; i < n ; i ++){
        p[i].input();
        ans[i] = 0x3f3f3f3f;
    }
    for(int s = 0 ; s < 1 << n ; s ++){
        vector<point> pt;
        int cnt = 0;
        for(int i = 0 ; i < n ; i ++){
            if(s & (1<<i)){
                pt.push_back(p[i]);
                cnt ++;
            }
        }
        polygon_convex pc = convex_hull(pt);
        for(int i = 0 ; i < n ; i ++){
            if((s & (1 << i)) && onBound(pc, p[i]))ans[i] = min(ans[i], n - cnt);
        }
    }
    for(int i = 0 ; i < n ; i ++){
        printf("%d\n",ans[i]);
    }
}
int main()
{
    freopen("/Users/lizhen/Documents/Project/Cpp/cpp/cpp/input.txt", "r", stdin);
    freopen("/Users/lizhen/Documents/Project/Cpp/cpp/cpp/output.txt", "w", stdout);
    int T,cas = 0;
    scanf("%d",&T);
    while(T--){
        cas ++;
        printf("Case #%d: \n",cas);
        solve();
    }
    return 0;
}