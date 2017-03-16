#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
#define MP(a, b) make_pair(a, b)
#define FOREACH(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)

const int maxn = 15 + 5 + 100;
int ch[maxn], n, mx[maxn];

#define M_PI		3.14159265358979323846	/* pi */
double my_sqrt(double d) {return sqrt(max(d, 0.0));}
double my_acos(double d) {return acos(d<-1?-1:d>1?1:d);}
#define sqr(v) ((v)*(v))
const double eps = 1E-6;
int sig(double d) {
	return (d>eps) - (d<-eps);
}
struct Point {
	double x, y;
	int id;
	Point(double x, double y) : x(x), y(y) {}
	Point() {}
	Point operator - (const Point & p) const {
		return Point(x-p.x, y-p.y);
	}
	Point operator + (const Point & p) const {
		return Point(x+p.x, y+p.y);
	}
	Point operator * (double d) const {
		return Point(x*d, y*d);
	}
	/*double operator * (const Point &b) const {
		return x * b.y - y * b.x;
	}*/
	bool operator == (const Point & p) const {
		return sig(x-p.x)==0 && sig(y-p.y)==0;
	}
	bool operator < (const Point & p) const {
		return sig(x-p.x)!=0 ? x<p.x : sig(y-p.y)<0;
	}
	Point resize(double d) {
		d /= my_sqrt(sqr(x)+sqr(y));
		return Point(x*d, y*d);
	}
	Point left90() {
		return Point(-y, x);
	}
	Point rotate(double radian) {	//逆时针转
		double c = cos(radian), s = sin(radian);
		return Point(x*c-y*s, y*c+x*s);
	}
	double mod() {
		return my_sqrt(sqr(x)+sqr(y));
	}
	void output() {
		printf("x = %.2f, y = %.2f\n", x, y);
	}
} p[maxn], grahamP[maxn];
double cross(const Point & o, const Point & a, const Point & b) {
	return (a.x-o.x)*(b.y-o.y) - (b.x-o.x)*(a.y-o.y);
}
double dot(Point o, Point a, Point b) {
	return (a.x-o.x)*(b.x-o.x) + (a.y-o.y)*(b.y-o.y);
}
double dis(Point a, Point b) {
	return my_sqrt(sqr(a.x-b.x) + sqr(a.y-b.y));
}

int graham(Point*p, int n, int*ch) {
#define push(x)     ch[len ++]=x
#define pop()		len --
	sort(p, p+n);
	int len = 0, len0 = 1, i;
	for(i = 0; i < n; i ++) {
		while(len > len0 && sig(cross(p[ch[len-1]], p[ch[len-2]], p[i]))<0)
			pop();
		push(i);
	}
	len0 = len;
	for(i = n-2; i >= 0; i --) {
		while(len > len0 && sig(cross(p[ch[len-1]], p[ch[len-2]], p[i]))<0)
			pop();
		push(i);
	}
	return len-1;
}

int main() {
//freopen("in", "r", stdin);
//freopen("C-small-attempt0.in", "r", stdin);
//freopen("C-small-attempt0.out", "w", stdout);
//freopen("B-large.in", "r", stdin);
//freopen("B-large.out", "w", stdout);
	int test;	scanf("%d", &test);
	for (int ti = 1; ti <= test; ti++) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			double x, y;	scanf("%lf %lf", &x, &y);
			p[i].x = x;	p[i].y = y;
			p[i].id = i;
			mx[i] = 1;
		}

		int ALL = 1 << n;
		for (int s = 1, sz; s < ALL; s++) {
//if (s == 27)
//	printf("s==31\n");
			sz = 0;
			for (int i = 0; i < n; i++) if (s & (1 << i)) {
				grahamP[sz].x = p[i].x;
				grahamP[sz].y = p[i].y;
				grahamP[sz].id = p[i].id;
				sz++;
			}
			int cnt = graham(grahamP, sz, ch);
//printf("%d=>%d\n", s, sz);
			for (int i = 0; i < cnt; i++) {
				int id = grahamP[ch[i]].id;
				mx[id] = max(mx[id], sz);
			}
		}

		printf("Case #%d:\n", ti);
		for (int i = 0; i < n; i++)
			printf("%d\n", n - mx[i]);
	}
}
