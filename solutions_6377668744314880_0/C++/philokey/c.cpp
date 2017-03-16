#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#define FI first
#define SE second
using namespace std;
const double EPS = 1e-8;
const int MAXN = 1005;
const int INF = 1111111111;
int dcmp(double x)
{
	if(fabs(x)<EPS) return 0;
	return x<0?-1:1;
}
struct Point{
	double x,y;
	Point(){}
	Point(double a,double b):x(a),y(b){}
	Point operator +(const Point &a)const{return Point(x+a.x,y+a.y);}
	Point operator -(const Point &a)const{return Point(x-a.x,y-a.y);}
	Point operator *(double k)const{return Point(x*k,y*k);}
	bool operator<(const Point&a)const
	{
		return (dcmp(x-a.x)<0)||(dcmp(x-a.x)==0&&dcmp(y-a.y)<0);
	}
	bool operator==(const Point&a)const
	{
		return dcmp(x-a.x)==0&&dcmp(y-a.y)==0;
	}
	void input(){scanf("%lf%lf",&x,&y);}
};
typedef Point Vector;
double cross(Vector a,Vector b)
{
	return a.x*b.y-a.y*b.x;
}
double dot(Vector a,Vector b)
{
	return a.x*b.x+a.y*b.y;
}
Point getinter(Point a,Vector aa,Point b,Vector bb)
{
	Vector u = a-b;
	double t = cross(bb,u)/cross(aa,bb);
	return a+aa*t;
}
int ConvexHull(Point *p,int n,Point *ch)
{
	sort(p,p+n);
	n = unique(p,p+n)-p;
	int m =0;
	for(int i = 0; i < n; i++)
	{
		while(m>1&&dcmp(cross(ch[m-1]-ch[m-2],p[i]-ch[m-2]))<0) --m;
		ch[m++] = p[i];
	}
	int k = m;
	for(int i = n-2; i >=0; i--)
	{
		while(m>k&&dcmp(cross(ch[m-1]-ch[m-2],p[i]-ch[m-2]))<0) --m;
		ch[m++] = p[i];
	}
	if(n>1) m--;
	return m;
}

int main() {
    freopen("/home/qitaishui/practice/gcj2015/in.txt", "r", stdin);
    freopen("/home/qitaishui/practice/gcj2015/c.out", "w", stdout);
    int cas;
    int n;
    Point p[20];
    Point ptmp[20];
    Point ch[20];
    int np;
    scanf("%d", &cas);
    for (int ca = 1; ca <= cas; ++ca) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            p[i].input();
        }
        //int m = ConvexHull(p, n, ch);
        //cout<<m<<endl;
        printf("Case #%d:\n", ca);
        for (int i = 0; i < n; ++i) {
            int ans = n - 1;
            for (int j = 0; j < (1<<16); ++j) {
                if (j & (1<<i) == 0) continue;
                np = 0;
                int k = 0;
                while (k < n) {
                    if (j & (1 << k)) {
                        ptmp[np] = p[k];
                        np += 1;
                    }
                    k += 1;
                }
                if (k < 3) {
                    ans = min(ans, n - np);
                    continue;
                }
                int m = ConvexHull(ptmp, n, ch);
                bool flag = false;
                for (int h = 0; h < m; ++h) {
                    if (p[i] == ch[h]) {
                        flag = true;
                        break;
                    }
                }
                if (flag) {
                    ans = min(ans, n - np);
                }
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
