#include<cstring>
#include <cassert>
#include<stack>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cctype>
#include<ctime>
#include<fstream>
#include<climits>
#include<memory.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<iterator>
#include<map>
#include<sstream>
#include<set>
#include<limits>
#include<queue>

#ifdef h0me
#define FILES freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#else
#define FILES //freopen("cooling.in","r",stdin);freopen("cooling.out","w",stdout);
#endif

#define all(c) (c).begin(), (c).end()

using namespace std;

typedef long long Long;
typedef long double Double;
namespace Helper
{
    template<typename T> inline string inttos(T x){ostringstream q;q << x;return q.str();}
    inline int stoint( string str){istringstream in(str);int res;in >> res;return res;}
    inline Long stolong(string str){istringstream in(str);Long res;in >> res;return res;}
    template<typename T> inline T pow(T x, T n, T MOD){T res = 1;while (n>0) {if (n & 1) {res = 1ll*res * x % MOD;}x = 1ll*x * x % MOD;n/=2;}return res;}
    template<typename T> inline T gcd(T a, T b){a=abs(a);b=abs(b);while ((a>0) && (b>0)) {if (a>b)a%=b;else b%=a;}return a+b;}
    inline int rand() { long long q = 1ll*rand()*RAND_MAX+rand(); return q % INT_MAX; }
    inline int abs(int x) { if (x<0) return -x;else return x; }
    const int MAXINT = 0x7FFFFFFF;
}


const Double EPS = 1e-10;

struct Point {
	Long x, y;
	int n;
	Point(int x, int y, int n): x(x), y(y), n(n) {}
};

bool clockwise(Point a, Point b, Point c) {
	return a.x*1ll*(b.y-c.y)+b.x*1ll*(c.y-a.y)+c.x*1ll*(a.y-b.y) <= 0;
}

bool counterclockwise(Point a, Point b, Point c) {
	return a.x*1ll*(b.y-c.y)+b.x*1ll*(c.y-a.y)+c.x*1ll*(a.y-b.y) >= 0;
}
bool online(Point a, Point b, Point c) {
	return a.x*1ll*(b.y-c.y)+b.x*1ll*(c.y-a.y)+c.x*1ll*(a.y-b.y) == 0;
}

bool comp(Point a, Point b) {
	return a.x < b.x || (a.x == b.x && a.y < b.y);
}



void convex(vector<Point>& a) {
	if (a.size() <= 1) return;
	sort(a.begin(), a.end(), &comp);
	Point p1 = a[0];
	Point p2 = a.back();
	vector<Point> up;
	vector<Point> down;
	up.push_back(p1);
	down.push_back(p1);
	for (size_t i=1; i<a.size(); ++i) {
		if (i==a.size()-1 || clockwise(p1, a[i], p2)) {
			while (up.size()>=2
          && !clockwise(up[up.size()-2], up[up.size()-1], a[i]))
				up.pop_back();
			up.push_back (a[i]);
		}
		if (i==a.size()-1 || counterclockwise(p1, a[i], p2)) {
			while (down.size()>=2
          && !counterclockwise(down[down.size()-2], down[down.size()-1], a[i]))
				down.pop_back();
			down.push_back (a[i]);
		}
	}
	a.clear();
	for (size_t i=0; i<up.size(); ++i)
		a.push_back (up[i]);
	for (size_t i=down.size()-2; i>0; --i)
		a.push_back (down[i]);
}

int bitcnt(int mask)
{
    int res = 0;
    while (mask>0) {
        res++;
        mask = (mask&(mask-1));
    }
    return res;
}
bool isBit(int mask, int i)
{
    return (mask & (1ll<<i)) >0;
}

int res[111111];
int main() {
    FILES;
    ios_base::sync_with_stdio(false);
    int tests;
    cin >> tests;
    for (int test = 0; test < tests; ++test) {
        cout << "Case #" << test+1 << ":" << endl;
        vector<Point> a,b;
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            res[i] = 1000000000;
            int x,y;
            cin >> x>>y;
            a.push_back(Point(x,y,i));
        }
        int fmask = (1<<(n))-1;
        for (int mask = 0; mask <= fmask; ++mask) {
            b.clear();
            for (int j = 0; j < n; ++j) {
                if (isBit(mask, j)) {
                    b.push_back(a[j]);
                }
            }
            convex(b);
            int q = n-bitcnt(mask);
            for (size_t i = 0; i < b.size(); ++i) {
                res[b[i].n] = min(res[b[i].n], q);
            }

        }
        for (int i = 0; i < n; ++i) {
            cout << res[i] << endl;
        }
    }
    return 0;
}
