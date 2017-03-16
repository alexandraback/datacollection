//BISM ILLAHHIRRAHMANNI RRAHIM

#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <iterator>
#include <utility>
using namespace std;

template< class T > T _abs(T n) { return (n < 0 ? -n : n); }
template< class T > T _max(T a, T b) { return (!(a < b) ? a : b); }
template< class T > T _min(T a, T b) { return (a < b ? a : b); }
template< class T > T sq(T x) { return x * x; }

#define ALL(p) p.begin(),p.end()
#define MP(x, y) make_pair(x, y)
#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define MEM(p, v) memset(p, v, sizeof(p))
#define CPY(d, s) memcpy(d, s, sizeof(s))
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define SZ(c) (int)c.size()
#define PB(x) push_back(x)
#define ff first
#define ss second
#define i64 long long
#define ld long double
#define pii pair< int, int >
#define point pair< int, int >
#define psi pair< string, int >
#define vi vector< int >

const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;

#define x first
#define y second
#define MAX 10000

point P[MAX], C[MAX], P0;
 
inline int triArea2(const point &a, const point &b, const point &c) {
    return (a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y));
}
 
inline int sqDist(const point &a, const point &b) {
    return ((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}
 
inline bool comp(const point &a, const point &b) {
    int d = triArea2(P0, a, b);
    if(d < 0) return false;
    if(!d && sqDist(P0, a) > sqDist(P0, b)) return false;
    return true;
}
 
inline bool comp2(const point &a, const point &b) {
	return sqDist(P0, a) > sqDist(P0, b);
}
 
inline bool normal(const point &a, const point &b) {
    return ((a.x==b.x) ? a.y < b.y : a.x < b.x);
}
 
inline bool issame(const point &a, const point &b) {
    return (a.x == b.x && a.y == b.y);
}
 
inline void makeUnique(int &np) {
    sort(&P[0], &P[np], normal);
    np = unique(&P[0], &P[np], issame) - P;
}
 
void convexHull(const int np, int &nc) {
    int i, j, pos = 0;
    for(i = 1; i < np; i++)
        if(P[i].y<P[pos].y || (P[i].y==P[pos].y && P[i].x<P[pos].x))
            pos = i;
    swap(P[0], P[pos]);
    P0 = P[0];
    sort(&P[1], &P[np], comp);
    
    for(i=np-1;i>=0;i--) if(triArea2(P[i], P[np-1], P0)!=0) break;
    
    sort(P+i+1, P+np, comp2);
    
    for(i = 0; i < 3; i++) {
		//cerr<<'\t'<<i<<' '<<P[i].x<<' '<<P[i].y<<'\n';
		C[i] = P[i];
	}
    for(i = j = 3; i < np; i++) {
		//cerr<<'\t'<<i<<' '<<P[i].x<<' '<<P[i].y<<'\n';
        while(triArea2(C[j-2], C[j-1], P[i]) < 0) j--;
        //cerr<<j<<' '<<P[i].x<<' '<<P[i].y<<'\n';
        C[j++] = P[i];
    }
    nc = j;
}

int msk[2030000];

bool chk(int a,int b) {
	return __builtin_popcount(a)<__builtin_popcount(b);
}

pii d[MAX];

int main() {
	//READ("input.in");
	READ("C-small-attempt0.in");
	//READ("C-small-attempt1.in");
	//READ("C-small-attempt2.in");
	//READ("C-small-attempt3.in");
	//READ("C-large.in");
	WRITE("outputSmall.out");
	int I,T,n,i,j,k,l,nc,m;
	cin>>T;
	for(I=1;I<=T;I++) {
		cin>>n;
		m=1<<n;
		for(i=0;i<m;i++) msk[i]=i;
		sort(msk,msk+m,chk);
		for(i=0;i<n;i++) cin>>d[i].x>>d[i].y;
		
		//for(i=0;i<n;i++) P[i]=d[i];
		//convexHull(n, nc);
		//for(i=0;i<nc;i++) cerr<<' '<<C[i].x<<' '<<C[i].y<<'\n';
		//return 0;
		
		printf("Case #%d:\n",I);
		for(i=0;i<n;i++) {
			for(j=0;j<m;j++) if(!(j&(1<<i))) {
				l=0;
				for(k=0;k<n;k++) if(!(j&(1<<k))) P[l++]=d[k];
				convexHull(l, nc);
				for(k=0;k<nc;k++) if(C[k]==d[i]) break;
				if(k<nc) break;
			}
			cout<<__builtin_popcount(j)<<'\n';
		}
	}
	return 0;
}
