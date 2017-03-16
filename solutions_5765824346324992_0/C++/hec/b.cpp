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

ll lcm(ll a,ll b){
	ll g=__gcd(a,b);
	return a/g*b;
}

ll m[10010];
ll cur[10010];


int main(void){
	int TestCase;
	cin >> TestCase;
	range(Number,1,TestCase+1){
		ll n,b;
		cin >> b >> n;
		rep(i,b) cin >> m[i];
		ll T=1LL;
		ll num=0LL;
		rep(i,b) T=lcm(T,m[i]);
		rep(i,b) num+=T/m[i];
		n=(n-1)%num+1;
		rep(j,b) cur[j]=0LL;
		int ans=0;
		rep(i,n){
			ll w=min_element(cur,cur+b)-cur;
			ll minus=cur[w];
			rep(j,b) cur[j]-=minus;
			cur[w]+=m[w];
			ans=w+1;
		}
		cout << "Case #"<< Number << ": ";
		cout << ans << endl;
	}
	return 0;
}