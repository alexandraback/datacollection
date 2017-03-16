#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)  FOR(i,0,n)

typedef double R;
typedef complex<R> P;
typedef vector<P> G; //polygon

#define X real()
#define Y imag()
#define EPS (1e-9)
#define EQ(a,b) (abs((a)-(b)) < EPS)
#define EQV(a,b) (EQ((a).real(), (b).real()) && EQ((a).imag(), (b).imag()))

inline int sgn(R a, R b = 0) { return a < b - EPS ? -1 : a > b + EPS ? 1 : 0; }
inline bool near(P a, P b) { return !sgn(abs(a - b)); }
inline R dot(P a, P b){ return real(a * conj(b)); }
inline R det(P a, P b){ return imag(conj(a) * b); }
inline R sr(R a) {return sqrt(max(a, (R)0));}

struct L{P a, b; };

#define curr(P, i) P[i]
#define next(P, i) P[(i+1)%P.size()]

//polygon,point
enum { OUT, ON, IN };
int contains(const G &vec, const P &p) {
    bool in = false;
    for (int i = 0; i < vec.size(); ++i) {
	P a = curr(vec,i) - p, b = next(vec,i) - p;
	if (imag(a) > imag(b)) swap(a, b);
	if (imag(a) <= 0 && 0 < imag(b))
	    if (det(a, b) < 0) in = !in;
	if (det(a, b) == 0 && dot(a, b) <= 0) return ON;
    }
    return in ? IN : OUT;
}

inline R cross(P a, P b){return det(a,b);} 
int convex_contains(const G &PP, const P &p) {
    const int n = PP.size();
    P g = (PP[0] + PP[n/3] + PP[2*n/3]) / 3.0; // inner-point
    int a = 0, b = n;
    while (a+1 < b) { // invariant: c is in fan g-P[a]-P[b]
	int c = (a + b) / 2;
	if (cross(PP[a]-g, PP[c]-g) > 0) { // angle < 180 deg
	    if (cross(PP[a]-g, p-g) > 0 && cross(PP[c]-g, p-g) < 0) b = c;
	    else                                                  a = c;
	} else {
	    if (cross(PP[a]-g, p-g) < 0 && cross(PP[c]-g, p-g) > 0) a = c;
	    else                                                  b = c;
	}
    }
    b %= n;
    if (cross(PP[a] - p, PP[b] - p) < 0) return 0;
    if (cross(PP[a] - p, PP[b] - p) > 0) return 2;
    return 1;
}

int ccw(P a, P b, P c) {
    b -= a; c -= a;
    R cr = det(b, c);
    if (sgn(cr) > 0) return 1;                 // counter clockwise    
    if (sgn(cr) < 0) return -1;                // clockwise 
    if (sgn(dot(b, c)) < 0) return 2;          // c--a--b on line
    if (sgn(norm(b), norm(c)) < 0) return -2;  // a--b--c on line
    return 0;
}

namespace std{
    bool cmp(const P& p, const P& q){
	if(p.X != q.X) return p.X < q.X;
	else return p.Y < q.Y;
    }
}

G convex_hull(G ps) {
    int n = ps.size(), k = 0;
    sort(ps.begin(), ps.end(), cmp);
    G ch(2*n);
    for (int i = 0; i < n; ch[k++] = ps[i++]) // lower-hull
	while (k >= 2 && ccw(ch[k-2], ch[k-1], ps[i]) <= 0) --k;
    for (int i = n-2, t = k+1; i >= 0; ch[k++] = ps[i--]) // upper-hull
	while (k >= t && ccw(ch[k-2], ch[k-1], ps[i]) <= 0) --k;
    ch.resize(k-1);
    return ch;
}

int TC;
int N;
P p[3010];
int mi[3010];

int main(){
    cin>>TC;
    rep(tc,TC){
	printf("Case #%d:\n",tc+1);
	cin>>N;
	G t;
	rep(i,N){
	    R a,b;
	    cin>>a>>b;
	    p[i]=P(a,b);
	    t.pb(p[i]);
	}
	rep(i,N)mi[i]=N;
	rep(i,N){
	    rep(j,1<<N)if((j>>i)&1){
		G a;
		rep(k,N)if((j>>k)&1)a.pb(p[k]);
		if(a.size()<=2)mi[i]=min(mi[i],N-(int)a.size());
		else if(contains(convex_hull(a),p[i])==ON)
		    mi[i]=min(mi[i],N-(int)a.size());	
	    }
	    printf("%d\n",mi[i]);
	}
    }
    return 0;
}

/*
2
5
0 0
10 0
10 10
0 10
5 5
9
0 0
5 0
10 0
0 5
5 5
10 5
0 10
5 10
10 10

1
5
0 0
10 0
10 10
0 10
5 5
*/
