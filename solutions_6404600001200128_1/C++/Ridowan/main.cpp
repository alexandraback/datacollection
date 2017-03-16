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
#define psi pair< string, int >
#define vi vector< int >

const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;

int d[21200];

int main() {
	//READ("input.in");
	//READ("A-small-attempt0.in");
	//READ("A-small-attempt1.in");
	//READ("A-small-attempt2.in");
	//READ("A-small-attempt3.in");
	READ("A-large.in");
	WRITE("outputLarge.out");
	int I,T,n,i;
	cin>>T;
	for(I=1;I<=T;I++) {
		cin>>n;
		for(i=0;i<n;i++) cin>>d[i];
		int r1=0,r2=0;
		for(i=1;i<n;i++) if(d[i]<d[i-1]) r1+=d[i-1]-d[i];
		
		int q=0;
		for(i=1;i<n;i++) if(d[i]<d[i-1]) q=max(q,d[i-1]-d[i]);
		for(i=1;i<n;i++) {
			r2+=min(q,d[i-1]);
		}
		
		
		printf("Case #%d: %d %d\n",I,r1,r2);
	}
	return 0;
}
