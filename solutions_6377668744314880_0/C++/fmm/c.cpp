#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cfloat>
#include <climits>
#include <cctype>
#include <cmath>
#include <cassert>
#include <ctime>

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <complex>
#include <limits>
#include <functional>
#include <numeric>

#define rep(x,n) for(int x = 0; x < n; ++x)
#define print(x) cout << x << endl
#define dbg(x) cerr << #x << " == " << x << endl
#define _ << " , " <<
#define mp make_pair
#define x first
#define y second

using namespace std;

template<class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }

typedef long long ll;
typedef pair<int,int> pii;

struct P {
	int id;
	long long x,y;
	P(){}
	P(long long x, long long y): x(x), y(y) {}
	void read(int id) {
		this->id=id;
		cin>>x>>y;
	}
	P operator-(){ return P(-x, -y); }
	P operator+(P b){ return P(x+b.x, y+b.y); }
	P operator-(P b){ return *this+-b; }
	P operator*(long long k){ return P(x*k, y*k); }
	long long operator*(P b) const { return x*b.x + y*b.y; }
	long long operator%(P b){ return x*b.y - y*b.x; }
	long long operator!(){ return sqrt(*this**this); }
	P operator/(P b){ return b*(*this*b/(b*b)); }
	P operator/(long long k){ return *this*(1/k); }
	bool operator<(P b) const {
		if( x != b.x ) return x < b.x;
		return y < b.y;
	}
	bool operator==(P b) const { return x==b.x && y==b.y; }
} p[3333], tmp[3333];

bool ccw(P a, P b) {
	long long pv = a%b;
	return (pv == 0) ? a*a < b*b : pv > 0;
}
	
int convexhull(P * p, int n) {
	P o = *min_element(p,p+n);

	if(n<=2) return n;

	//rep(i,n) if( p[i].x < o.x || p[i].x == o.x && p[i].y < o.y ) o = p[i];
	rep(i,n) p[i].x = p[i].x - o.x;
	rep(i,n) p[i].y = p[i].y - o.y;
	sort(p,p+n,ccw);
	int w = n-1;
	while( w && p[w-1]%p[w] == 0 ) w--;
	reverse(p+w,p+n);
	w = 1;
	for( int i = 2 ; i < n ; ++i ) {
		while( w && (p[w]-p[w-1])%(p[i]-p[w-1]) < 0 ) w--; // ou <
		p[++w] = p[i];
	}
	return w+1;
}

int n;

void read() {
	cin>>n;
	rep(i,n) p[i].read(i);
}

int ans[3333];

int same(long long a, long long b) {
	if(a >= 0 && b >= 0) return 1;
	return 0;
}

void process(int testcase) {
	rep(i,n) ans[i]=n-1;
	rep(i,n) {
		rep(j,n) rep(k,n) if(j != i && k != i) {
			P pij = p[j] - p[i];
			P pik = p[k] - p[i];
			int cover = 0;
			rep(a,n) {
				P v = p[a] - p[i];
				cover += same(pij % v, v % pik);
			}
			ans[i] = min(ans[i], n - cover);
		}
	}
	printf("Case #%d:\n",testcase);
	rep(i,n) printf("%d\n",ans[i]);
}

int main() {
  int T;
  cin >> T;
  for(int testcase=1;testcase<=T;testcase++) {
    read();
    process(testcase);
  }
  return 0;
}

