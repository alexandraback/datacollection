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

int mv[4][2]={
	1,0,
	-1,0,
	0,1,
	0,-1
};

vi d[10010];
vector<bool> vis[10010];

int chk(int r,int c,int n) {
	int i,j,k,v,a=0;
	for(i=0;i<r;i++) {
		d[i].resize(c);
		vis[i].resize(c);
	}
	set<pair<int,pii>> cs;
	for(i=0;i<r;i++) for(j=0;j<c;j++) {
		d[i][j]=0;
		vis[i][j]=0;
		d[i][j]-=bool(i);
		d[i][j]-=bool(j);
		d[i][j]-=bool(i<r-1);
		d[i][j]-=bool(j<c-1);
		a-=d[i][j];
		cs.insert(MP(d[i][j],pii(i,j)));
	}
	a>>=1;
	int x,y,tx,ty;
	int cnt=r*c-n;
	while(cnt--) {
		v=cs.begin()->ff;
		x=cs.begin()->ss.ff;
		y=cs.begin()->ss.ss;
		//cerr<<v<<' '<<x<<' '<<y<<'\n';
		cs.erase(cs.begin());
		a+=v;
		vis[x][y]=1;
		for(k=0;k<4;k++) {
			tx=x+mv[k][0];
			ty=y+mv[k][1];
			//cerr<<'\t'<<tx<<' '<<ty<<'\n';
			//if(tx==1&&ty==0) cerr<<vis[tx][ty]<<'\n';
			if(tx>=0 && ty>=0 && tx<r && ty<c && !vis[tx][ty]) {
				//cerr<<' '<<d[tx][ty]<<' '<<tx<<' '<<ty<<'\n';
				cs.erase(cs.find({d[tx][ty],{tx,ty}}));
				//cerr<<' '<<tx<<' '<<ty<<'\n';
				d[tx][ty]++;
				cs.insert({d[tx][ty],{tx,ty}});
			}
		}
	}
	return a;
}

int main() {
	//READ("input.in");
	READ("B-small-attempt0.in");
	//READ("B-small-attempt1.in");
	//READ("B-small-attempt2.in");
	//READ("B-small-attempt3.in");
	//READ("B-large.in");
	WRITE("outputSmall.out");
	int I,T,r,c,n;
	cin>>T;
	for(I=1;I<=T;I++) {
		cin>>r>>c>>n;
		int a=chk(r,c,n);
		printf("Case #%d: %d\n",I,a);
	}
	return 0;
}
