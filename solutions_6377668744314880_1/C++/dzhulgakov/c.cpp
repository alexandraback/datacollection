#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <numeric>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <cassert>
#include <cstring>

using namespace std;

#define REP(i,n) for (int i=0,_n=(n); i < _n; i++)
#define REPD(i,n) for (int i=(n)-1; i >= 0; i--)
#define FOR(i,a,b) for (int _b=(b), i=(a); i <= _b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;i--)
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))

#define CLEAR(x) memset(x,0,sizeof x);
#define CLEARA(x) memset(&x,0,sizeof x);
#define FILL(x,v) memset(x,v,sizeof x);
#define FILLA(x,v) memset(&x,v,sizeof x);

#define VAR(a,b) __typeof(b) a=(b)
#define FOREACH(it,c) for(VAR(it,(c).begin());it!=(c).end();++it)

#define REVERSE(c) reverse(ALL(c))
#define UNIQUE(c) SORT(c),(c).resize(unique(ALL(c))-(c).begin())
#define INF 0x7fffffff
#define X first
#define Y second
#define pb push_back
#define SZ(c) (int)(c).size()
#define MP make_pair
#define eps 1.0e-11
const double pi = acos(-1.0);

typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;

#define N 3333
int n;

template <typename T> struct Point {
	T x,y;
	Point(T _x=0,T _y=0) : x(_x),y(_y) {}
	void read();
	void swap() { swap(x,y); }
	double len() const;
	Point<double> asDouble() { return Point<double>(x,y); }
	Point<T> norm() const;
	Point<T> ort() const { return Point<T>(y,-x); }
};
template<> void Point<LL>::read() { scanf("%lld%lld",&x,&y); }
template<> void Point<double>::read() { scanf("%lf%lf",&x,&y); }
template <typename T> Point<T> operator- (const Point<T> &a) { return Point<T>(-a.x,-a.y); }
template <typename T> Point<T> operator+ (const Point<T> &a, const Point<T> &b) { return Point<T>(a.x+b.x,a.y+b.y); }
template <typename T> Point<T> operator- (const Point<T> &a, const Point<T> &b) { return Point<T>(a.x-b.x,a.y-b.y); }
template <typename T> Point<T> operator* (const T a, const Point<T> &b) { return Point<T>(a*b.x,a*b.y); }
template <typename T> Point<T> operator* (const Point<T> &b, const T a) { return Point<T>(a*b.x,a*b.y); }
template <typename T> Point<T> operator/ (const Point<T> &b, const T a) { return Point<T>(b.x/a,b.y/a); }
template <typename T> T operator* (const Point<T> &a, const Point<T> &b) { return a.x*b.x+a.y*b.y; }
template <typename T> T operator^ (const Point<T> &a, const Point<T> &b) { return a.x*b.y-a.y*b.x; }
template <typename T> double Point<T>::len() const { return sqrt((double)((*this)*(*this))); }
template <typename T> Point<T> Point<T>::norm() const { return (*this)/len(); }
template <typename T> bool operator< (const Point<T> &a, const Point<T> &b) { return a.x<b.x || a.x==b.x && a.y<b.y; }
bool operator== (const Point<LL> &a, const Point<LL> &b) { return a.x==b.x && a.y==b.y; }
bool operator!= (const Point<LL> &a, const Point<LL> &b) { return a.x!=b.x || a.y!=b.y; }
LL sign(LL x) { if (x==0) return 0; if (x>0) return +1; else return -1; }
int sign(double x) { if (fabs(x)<eps) return 0; if (x>0) return +1; else return -1; }
template<typename T> T sqr(T x) { return x*x; }
typedef Point<double> DPnt;
typedef Point<LL> IPnt;
const DPnt INFDPnt(1.0e30,1.0e30);

pair<IPnt,int> a[N];
int mn[N];

vector<pair<IPnt,int>> ConvexHull(vector<pair<IPnt,int>> a) {
	if (SZ(a) <= 2) return a;
	sort(ALL(a));
	vector<pair<IPnt,int>> res;
	REP(iter,2)	{
		vector<pair<IPnt,int>> hull;
		REP(i,SZ(a)) {
			while (SZ(hull)>=2 && ((a[i].first-hull.back().first)^(hull.back().first-hull[SZ(hull)-2].first)) < 0)
				hull.pop_back();
			hull.push_back(a[i]);
		}
		hull.pop_back();
		res.insert(res.end(),ALL(hull));
		reverse(ALL(a));
	}
	return res;
}

void stupid() {
		REP(mask,1<<n) {
			vector<pair<IPnt,int>> b,c;
			int rm = 0;
			REP(i,n)
				if (mask&(1<<i))
					b.push_back(a[i]);
				else
					++rm;
			c=ConvexHull(b);
			REP(ii,SZ(c))
			{
				int id = c[ii].second;
				mn[id] = min(mn[id],rm);
			}
		}
}

int solve(const vector<IPnt>& a) {
	int n = SZ(a);
	vector<pair<double,IPnt>> b;
	REP(i,n) b.push_back(make_pair(atan2((double)a[i].y, (double)a[i].x), a[i]));
	SORT(b);
	//UNIQUE(b);
	REP(i,n) b.push_back(b[i]);
	REP(i,n) b.push_back(b[i]);
	int right = 0;
	int res = 0;
	REP(base,n)
	{
		while (right<base) ++right;
		while (right+1 < base+n) {
			LL vec = b[base].second^b[right+1].second;
			//LL dot = b[base].second*b[right+1].second;
			if (vec >= 0)
				++right;
			else
				break;
		}
		res = max(res,right-base+1);
	}
	return n-res;
}

int main(int argc, char **argv)
{
	string FN = "C-large";
	if (argc>1) FN = string(argv[1]);
	int shift = 0;
	if (argc>2) sscanf(argv[2],"%d",&shift);
	freopen((FN+".in").c_str(),"r",stdin);
	freopen((FN+".out").c_str(),"w",stdout);

	int tests;
	cin >> tests;
	for (int test = 1; test<=tests; test++)
	{
		fprintf(stderr,"=== %s : %d\n", FN.c_str(), test+shift);
		printf("Case #%d:\n",test+shift);
		////////////////////////////////////////////////////////////
		scanf("%dn",&n);
		REP(i,n) a[i].first.read(),a[i].second=i;

		//n=3000; REP(i,n) a[i].first.x=rand()%1000000,a[i].first.y=rand()%1000000;

		REP(i,n) mn[i] = n;

		//stupid();
		REP(i,n)
		{
			vector<IPnt> b;
			REP(j,n) if (j != i) b.push_back(a[j].first-a[i].first);
			mn[i] = solve(b);
		}

		REP(i,n) printf("%d\n",mn[i]);
	}
	fprintf(stderr,"=== %s DONE\n", FN.c_str());
	return 0;
}