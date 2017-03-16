#include <algorithm>
#include <iostream>
#include <cstdio>
#include <map>
#include <numeric>
#include <cmath>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <complex>
#include <string.h>
#include <unordered_set>
#include <unordered_map>
#include <iomanip>
using namespace std;

#define endl '\n'
#define ALL(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define uniq(v) (v).erase(unique((v).begin(), (v).end()), (v).end())

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
struct pairhash {
public:
    template<typename T, typename U>
    size_t operator()(const pair<T, U> &x) const {
	size_t seed = hash<T>()(x.first);
	return hash<U>()(x.second) + 0x9e3779b9 + (seed<<6) + (seed>>2);
    }
};

const string yes = "YES", no = "NO";

// must template
typedef long double D;
const D INF = 1e12,EPS = 1e-8;

typedef complex<D> P;
#define X real()
#define Y imag()
istream& operator >> (istream& is,P& p){D x,y;is >> x >> y; p=P(x,y); return is;}

int sig(D a,D b=0){return a<b-EPS?-1:a>b+EPS?1:0;}
template<typename T> bool eq(const T& a,const T& b){return sig(abs(a-b))==0;}
bool compX (const P& a,const P& b){return !eq(a.X,b.X)?sig(a.X,b.X)<0:sig(a.Y,b.Y)<0;}
namespace std{
    bool operator <  (const P& a,const P& b){return compX(a,b);}
    bool operator == (const P& a,const P& b){return eq(a,b);}
};
// a×b
D cross(const P& a,const P& b){return imag(conj(a)*b);}
// a・b
D dot(const P& a,const P& b) {return real(conj(a)*b);}
int ccw(const P& a,P b,P c){
    b -= a; c -= a;
    if (sig(cross(b,c)) > 0)   return +1;       // counter clockwise
    if (sig(cross(b,c)) < 0)   return -1;       // clockwise
    if (sig(dot(b,c)) < 0)     return +2;       // c--a--b on line
    if (sig(norm(b),norm(c))<0) return -2;       // a--b--c on line
    return 0; //a--c--b on line (c==b,c==a)
}
// //must template

//射影ベクトル
P proj(P p,P b) {return b * dot(p,b) / norm(b);}


//直線・線分
struct L : public vector<P> {
    P vec() const {return this->at(1)-this->at(0);}
    L(const P &a, const P &b){push_back(a); push_back(b);}
    L(){push_back(P());push_back(P());}
};
istream& operator >> (istream& is,L& l){P s,t;is >> s >> t;l=L(s,t);return is;}

bool isIntersectLL(const L &l, const L &m) {
    return sig(cross(l.vec(), m.vec()))!=0 || // non-parallel
	sig(cross(l.vec(), m[0]-l[0])) ==0;   // same line
}
bool isIntersectLS(const L &l, const L &s) {
    return sig(cross(l.vec(), s[0]-l[0])*       // s[0] is left of l
	       cross(l.vec(), s[1]-l[0]))<=0; // s[1] is right of l
}
bool isIintersectLP(const L &l, const P &p) {return sig(cross(l[1]-p, l[0]-p))==0;}
// verified by ACAC003 B
// http://judge.u-aizu.ac.jp/onlinejudge/creview.jsp?rid=899178&cid=ACAC003
bool isIntersectSS(const L &s, const L &t) {
    return ccw(s[0],s[1],t[0])*ccw(s[0],s[1],t[1]) <= 0 &&
	ccw(t[0],t[1],s[0])*ccw(t[0],t[1],s[1]) <= 0;
}
bool isIntersectSP(const L &s, const P &p) {
    return sig(abs(s[0]-p)+abs(s[1]-p),abs(s[1]-s[0])) <=0; // triangle inequality
}

// 直線へ射影した時の点
// verified by AOJLIB
// http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=1092212
P projection(const L &l, const P &p) {
    D t = dot(p-l[0],l.vec()) / norm(l.vec());
    return l[0] + t * l.vec();
}
//対称な点
// verified by AOJLIB
// http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=1092214
P reflection(const L &l, const P &p) { return p + 2.0L * (projection(l, p) - p);}

D distanceLP(const L &l, const P &p) { return abs(p - projection(l, p));}
D distanceLL(const L &l, const L &m) { return isIntersectLL(l, m) ? 0 : distanceLP(l, m[0]);}
D distanceLS(const L &l, const L &s) {
    if (isIntersectLS(l, s)) return 0;
    return min(distanceLP(l, s[0]), distanceLP(l, s[1]));
}
D distanceSP(const L &s, const P &p) {
    const P r = projection(s, p);
    if (isIntersectSP(s, r)) return abs(r - p);
    return min(abs(s[0] - p), abs(s[1] - p));
}
D distanceSS(const L &s, const L &t) {
    if (isIntersectSS(s, t)) return 0;
    return min(min(distanceSP(s, t[0]), distanceSP(s, t[1])),
	       min(distanceSP(t, s[0]), distanceSP(t, s[1])));
}

//util
bool isPalallel(const L& s,const L& t){ return sig(cross(s.vec(),t.vec()))==0;}
bool Leq(const L& s,const L& t){ return isPalallel(s,t) && isIntersectLL(s,t);}
bool Seq(const L& s,const L& t){ return eq(min(s[0],s[1]),min(t[0],t[1])) && eq(max(s[0],s[1]),max(t[0],t[1]));}

// 交点計算
// verified by AOJLIB
// http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=1092231
P crosspoint(const L &l, const L &m) {
    D A = cross(l.vec(), m.vec());
    D B = cross(l.vec(), l[1] - m[0]);
    if (sig(A)==0 && sig(B)==0) return m[0]; // same line
    if (sig(A)==0) cerr << "error!" << endl; // !!there is no cross points!!
    return m[0] + B / A * (m[1] - m[0]);
}
template<typename T> T pmod(T v,T M){return (v%M+M)%M;}
typedef vector<P> Poly,ConvexPoly;

// verifed by AOJLIB
// http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=1092258
enum { OUT, ON, IN };
int contains(const Poly& ps, const P& p) {
    bool in = false;int n=ps.size();
    for (int i = 0; i < n; i++){
	P a = ps[i] - p, b = ps[pmod(i+1,n)] - p;
	if(a.Y > b.Y) swap(a, b);
	if(a.Y <= 0 && 0 < b.Y)if(sig(cross(a, b)) < 0) in = !in;
	if(sig(cross(a, b)) == 0 && sig(dot(a, b)) <= 0) return ON;
    }
    return in ? IN : OUT;
}

// 凸包
//O(n logn)
// verified by AOJLIB
// http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=1092743
ConvexPoly convex_hull(Poly ps) {
    int n = ps.size(), k = 0;
    sort(ALL(ps));
    Poly ch(2*n);
    for (int i = 0; i < n; i++){ // lower-hull
	while (k > 1 && cross(ch[k-1]-ch[k-2],ps[i]-ch[k-1]) < 0) --k;
	ch[k++]=ps[i];
    }
    for(int i=n-2,t=k;i>=0;i--){// upper-hull
	while (k > t && cross(ch[k-1]-ch[k-2],ps[i]-ch[k-1]) < 0) --k;
	ch[k++]=ps[i];
    }
    ch.resize(k-1);
    return ch;
}

vector<int> solve() {
    int n;
    cin >> n;
    vector<P> points(n);
    for (int i = 0; i < n; i++) {
	int x, y;
	cin >> x >> y;
	points[i] = P(x, y);
    }
    if (n == 1) {
	vector<int> res(1);
	return res;
    }
    vector<int> res(n, 1000000000);
    for (int i = 1; i < (1<<n); i++) {
	Poly ps;
	for (int j = 0; j < n; j++) {
	    if (((i>>j)&1) == 1)
		ps.push_back(points[j]);
	}
	ConvexPoly cp = convex_hull(ps);
	int num_out = 0;
	for (int j = 0; j < n; j++) {
	    if (contains(cp, points[j]) == OUT) {
		num_out++;
	    }
	}

	for (int j = 0; j < n; j++) {
	    if (contains(cp, points[j]) == ON) {
		res[j] = min(res[j], num_out);
	    }
	}
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(15);

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
	//cerr << i << endl;
	vector<int> res = solve();
	cout << "Case #" << i << ":" << endl;
	for (int j = 0; j < res.size(); j++)
	    cout << res[j] << endl;
    }
}
