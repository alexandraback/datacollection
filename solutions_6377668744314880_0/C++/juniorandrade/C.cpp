#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <utility>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <deque>
#include <iostream>
#include <sstream>

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(x) (int((x).size()))

#define MAXSZ 1000

using namespace std;

const int INF = 0x3F3F3F3F;
const double PI = 2*acos(0);
const double EPS = 1e-10;

/*

    Funcao de Comparacao de 2 valores

    Parametros:
        double x;
        double y;

    Retorna:
        -1 se x <= y
        0 se x == y
        1 se x >= y

*/

inline int cmp(double x, double y=0, double tol=EPS)
{
    return (x<=y+tol) ? (x+tol<y) ? -1 : 0 : 1;
}

/*

    Estrutura de dados para pontos

*/

struct point
{
    double x, y;
    point(double x = 0, double y = 0): x(x), y(y) {}
    point operator +(point q) { return point(x + q.x, y + q.y); }
    point operator -(point q) { return point(x - q.x, y - q.y); }
    point operator *(double t) { return point(x * t, y * t); }
    point operator /(double t) { return point(x / t, y / t); }
    double operator *(point q) { return x * q.x + y * q.y; }
    double operator %(point q) { return x * q.y - y * q.x; }
    int cmp(point q) const {
    if (int t = ::cmp(x, q.x)) return t;
    return ::cmp(y, q.y);
    }
    bool operator ==(point q) const { return cmp(q) == 0; }
    bool operator !=(point q) const { return cmp(q) != 0; }
    bool operator < (point q) const { return cmp(q) < 0; }
    bool operator <=(point q) const { return cmp(q)<=0; }
    friend ostream& operator <<(ostream& o, point p) {
    return o << "(" << p.x << ", " << p.y << ")";
    }
    static point pivot;
};

point point::pivot;

double abs(point p) { return hypot(p.x, p.y); }
double arg(point p) { return atan2(p.y, p.x); }

typedef vector<point> polygon;
typedef pair<point, double> circle;

int ccw(point p, point q, point r)
{
    return cmp((p - r) % (q - r));
}

double distancia(point a, point b)
{
    return sqrt(pow(a.x-b.x,2.0)+pow(a.y-b.y,2.0));
}

#define REMOVE_REDUNDANT

double cross(point p, point q)
{
    return p.x*q.y-p.y*q.x;
}
double area2(point a, point b, point c)
{
    return cross(a,b) + cross(b,c) + cross(c,a);
}

#ifdef REMOVE_REDUNDANT
bool bet(const point &a, const point &b, const point &c)
{
    //Para considerar pontos colineares troque o <= por <
    return (fabs(area2(a,b,c)) < EPS && (a.x-b.x)*(c.x-b.x) <= 0 && (a.y-b.y)*(c.y-b.y) <= 0);
}
#endif

void ConvexHull(vector<point> &pts)
{
    sort(pts.begin(), pts.end());

    pts.erase(unique(pts.begin(), pts.end()), pts.end());

    vector<point> up, dn;

    for (int i = 0; i < pts.size(); i++)
    {
        //Para considerar pontos colineares troque o >= por >
        while (up.size() > 1 && area2(up[up.size()-2], up.back(), pts[i]) >= 0) up.pop_back();

        //Para considerar pontos colineares troque o <= por <
        while (dn.size() > 1 && area2(dn[dn.size()-2], dn.back(), pts[i]) <= 0) dn.pop_back();

        up.push_back(pts[i]);

        dn.push_back(pts[i]);
    }

    pts = dn;

    for (int i = (int) up.size() - 2; i >= 1; i--) pts.push_back(up[i]);

#ifdef REMOVE_REDUNDANT

    if (pts.size() <= 2) return;

    dn.clear();

    dn.push_back(pts[0]);
    dn.push_back(pts[1]);

    for (int i = 2; i < pts.size(); i++)
    {
        if (bet(dn[dn.size()-2], dn[dn.size()-1], pts[i])) dn.pop_back();
        dn.push_back(pts[i]);
    }

    if (dn.size() >= 3 && bet(dn.back(), dn[0], dn[1]))
    {
        dn[0] = dn.back();
        dn.pop_back();
    }

    pts = dn;

#endif
}

//Função alternativa - PUC-RIO

bool radial_lt(point p, point q)
{
    point P = p - point::pivot, Q = q - point::pivot;
    double R = P % Q;
    if (cmp(R)) return R > 0;
    return cmp(P * P, Q * Q) < 0;
}

polygon convex_hull(vector<point> T)
{
    int j = 0, k, n = T.size();
    polygon U(n);
    point::pivot = *min_element(ALL(T));
    sort(ALL(T), radial_lt);
    for (k = n-2; k >= 0 && ccw(T[0], T[n-1], T[k]) == 0; k--);
    reverse((k+1) + ALL(T));
    for (int i = 0; i < n; i++)
    {
// troque o >= por > para manter pontos colineares
        while (j > 1 && ccw(U[j-1], U[j-2], T[i]) > 0) j--;
        U[j++] = T[i];
    }
    U.erase(j + ALL(U));
    return U;
}

polygon p;
int n;

void main2()
{
	p.clear();
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		int a,b; scanf("%d %d",&a,&b);
		p.push_back(point(a,b));
	}

	for(int i=0;i<n;++i)
	{
		int resp = n-1;
		for(int j=0;j<(1<<n);++j)
		{
			if( !((1<<i)&j) ) continue;
			polygon aux;
			int qtd = 0;
			for(int k=0;k<n;++k) if( (1<<k)&j )
			{
				aux.push_back(p[k]);
				qtd++;
			}
			aux = convex_hull(aux);
			for(int k=0;k<aux.size();++k)
			{
				if( p[i] == aux[k] )
				{
					resp = min( resp, n-qtd );
					break;
				}
			}

		}
		printf("%d\n",resp);
	}
}

int main()
{
	//ios::sync_with_stdio(0);


	int t; scanf("%d",&t);
	for(int tt=1;tt<=t;++tt){
		printf("Case #%d:\n",tt);
		main2();
	}
	return 0;
}