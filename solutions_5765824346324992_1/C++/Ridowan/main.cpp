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
#include <gmpxx.h>
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
#define psi pair< string, int >
#define vi vector< int >

const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
int d[12344];

i64 chk(int b,i64 m) {
	if(m<0) return 0;
	int i=0;
	i64 r=0;
	for(i=0;i<b;i++) {
		//cerr<<' '<<i<<' '<<d[i]<<' '<<(m/d[i])<<'\n';
		r+=(m/d[i]+1);
	}
	return r;
}

int main() {
	//READ("input.in");
	//READ("B-small-attempt0.in");
	//READ("B-small-attempt1.in");
	//READ("B-small-attempt2.in");
	//READ("B-small-attempt3.in");
	READ("B-large.in");
	WRITE("outputLarge.out");
	int I,T,i,j,b;
	i64 n;
	i64 st, fn, md;
	
	cin>>T;
	for(I=1;I<=T;I++) {
		cin>>b>>n;
		for(i=0;i<b;i++) cin>>d[i];
		st=0;
		fn=1e15;
		while(st<fn) {
			md=(st+fn)>>1;
			//cerr<<st<<' '<<fn<<' '<<md<<' '<<chk(b,md)<<'\n';
			//break;
			if(chk(b,md)<n) st=md+1;
			else fn=md;
		}
		//cerr<<st<<' '<<fn<<'\n';
		int df=n-chk(b,st-1);
		//cerr<<df<<'\n';
		for(i=0;i<b;i++) if(!(st%d[i])) {
			//cerr<<df<<' '<<d[i]<<'\n';
			df--;
			if(!df) break;
		}
		assert(i<b);
		printf("Case #%d: %d\n",I,i+1);
	}
	return 0;
}
