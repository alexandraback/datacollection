#include <bits/stdc++.h>

using namespace std;

inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}
template<class T> inline T sqr(T x) {return x*x;}

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef long long ll;

#define all(a)  (a).begin(),(a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define pb push_back
#define mp make_pair
#define each(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define exist(s,e) ((s).find(e)!=(s).end())
#define range(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)  range(i,0,n)
#define clr(a,b) memset((a), (b) ,sizeof(a))
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

const double eps = 1e-10;
const double pi  = acos(-1.0);
const ll INF =1LL << 62;
const int inf =1 << 29;

// 以下 幾何部分
#define X real()
#define Y imag()
#define mp make_pair

typedef bool B;
typedef long long L;
typedef complex<ll> P;
typedef vector <P> Pol;

// ソートのキー
inline B cmp_x(const P &a,const P &b){ return (abs(a.X-b.X)==0 ) ?  a.Y<b.Y : a.X<b.X;}  // base x


// 基本操作
// verify
L ip(P a, P b) {return a.X * b.X + a.Y * b.Y;}
L ep(P a, P b) {return a.X * b.Y - a.Y * b.X;}


// ccw
enum CCW{FRONT = 1, RIGHT = 2, BACK = 4, LEFT = 8, MID = 16, ON=FRONT|BACK|MID };

inline int ccw(P base, P a, P b) {              //点aと点bが与えられた問いに
  a -= base; b -= base;
  if (ep(a, b) > 0)   	 return LEFT;    // counter clockwise
  if (ep(a, b) < 0)      return RIGHT;   // clockwise
  if (ip(a, b) < 0)      return BACK;    // b--base--a on line
  if (norm(a) < norm(b)) return FRONT;   // base--a--b on line
  						 return MID;      // base--b--a on line  aとbの線分判定はこれ
}


Pol convex_hull(Pol pol){
	int n=pol.size();
	sort(pol.begin(),pol.end(),cmp_x);
	Pol res(2*n);
	int k=0;

	// down
	rep(i,n){
		while( k>1 && ep(res[k-1]-res[k-2],pol[i]-res[k-1])<0) k--;
		res[k++]=pol[i];
	}
	// up
	for(int i=n-2,t=k;i>=0;i--){
		while( k>t && ep(res[k-1]-res[k-2],pol[i]-res[k-1])<0) k--;
		res[k++]=pol[i];
	}
	res.resize(k-1);
	return res;
}

P points[15];
int ans[15];

int main(void){
	int TestCase;
	cin >> TestCase;
	range(Number,1,TestCase+1){
		int n;
		cin >> n;
		rep(i,n){
			ll xx,yy;
			cin >> xx >> yy;
			points[i].real(xx);
			points[i].imag(yy);
		}
		dump(Number)
		rep(i,n){
			ans[i]=inf;
			rep(mask,1<<n){
				Pol in;
				if(mask&(1<<i)) continue;
				rep(j,n){
					if(mask&(1<<j))
						continue;
					in.pb(points[j]);
				}
				Pol chk=convex_hull(in);
				bool ok=false;
				int m=chk.size();
				rep(j,m) if(points[i]==chk[j]) ok=true;
				if(ok) ans[i]=min(ans[i],__builtin_popcount(mask));
			}
		}

		cout << "Case #"<< Number << ": " << endl;
		rep(i,n) cout << ans[i] << endl;
	}
	return 0;
}