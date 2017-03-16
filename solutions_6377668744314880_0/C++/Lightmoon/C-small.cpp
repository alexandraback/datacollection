#include <iostream>
#include <cstdio>
#include <cstring>
#include <complex>
#include <vector>
#include <algorithm>
using namespace std;

#define For(i,a,b) for (int i = (a); i <= (b); i++)
#define Ford(i,a,b) for (int i = (a); i >= (b); i--)
#define Rep(i,a) for (int i = 0; i < (a); i++)
#define Repd(i,a) for (int i = (int)(a) - 1; i >=0; i--)
#define PI (acos(0.0) * 2)
#define PB push_back
#define MP make_pair
#define X first
#define Y second
#define PII pair<int, int>
#define PIII pair<PII, int>
#define VI vector<int>
#define sz(a) ((int)a.size())
#define oo 1000000000
#define BUG(x) {cout << #x << " = " << x << endl;}
#define PR(a,u,v) {cout << #a << " = "; For(_,u,v) cout << a[_] << ' '; cout << endl;}
#define MAXN 100111
#define LL long long

int ntest,n;
LL x[30], y[30];
int res[30];


typedef complex<LL> Point;
namespace std {
   bool operator < (const Point& a, const Point& b) {
      return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
   }
}
double cross(const Point& a, const Point& b) { return imag(conj(a)*b); }
double dot(const Point& a, const Point& b) { return real(conj(a)*b); }


int ccw( Point a, Point b, Point c) {
	b -= a; c -= a;
   	if (cross(b, c) > 0)   return +1;       // counter clockwise
   	if (cross(b, c) < 0)   return -1;       // clockwise
	// if used for convex hull, do not include the next 2 lines
   	//if (dot(b, c) < 0)     return +2;       // c--a--b on line
   	//if (norm(b) < norm(c)) return -2;       // a--b--c on line
   	return 0;
}


vector<Point> convex_hull(vector<Point> ps) {// Wrong when there's < 3 points
   int n = ps.size(), k = 0;
   sort(ps.begin(), ps.end());
   vector< Point > ch(2*n);
   for (int i = 0; i < n; ch[k++] = ps[i++]) // lower-hull
      while (k >= 2 && ccw(ch[k-2], ch[k-1], ps[i]) < 0) --k;
   for (int i = n-2, t = k+1; i >= 0; ch[k++] = ps[i--]) // upper-hull
      while (k >= t && ccw(ch[k-2], ch[k-1], ps[i]) < 0) --k;
   ch.resize(k-1);
   return ch;
}


void update(int xx){
	if(__builtin_popcount(xx) < 3) return;
	vector<Point> vt;
	//cout << xx << endl;
	Rep(i,n){	
		if( xx & (1<<i) ){
			vt.PB( Point(x[i],y[i] ) );
		}
	}
	
	vt = convex_hull(vt);
	
	Rep(i,n){
		Point temp = Point(x[i],y[i]);
		Rep( j,vt.size() ){		
			if(temp == vt[j]){
				res[i] = max( res[i], __builtin_popcount(xx) );
				break;
			}
		}
	}
}

void solve(int test){
	cout << "Case #" << test << ":" << endl;
	cin >> n;
	memset(res,0,sizeof res);
	Rep(i,n){	
		cin >> x[i] >> y[i];
	}
	
	Rep(i,1<<n){	
		update(i);
	}
	Rep(i,n){
		cout << n-res[i] << endl;
	}
}

int main(){
	freopen("C-small-attempt1.in","r",stdin);
	freopen("test.out","w",stdout);
	cin >> ntest;
    For(test,1,ntest) {
		solve(test);
	}
	return 0;
}
