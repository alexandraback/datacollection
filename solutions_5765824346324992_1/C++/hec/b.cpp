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
	if(a==-1||b==-1) return -1;
	ll g=__gcd(a,b);
	if(a/g>LONG_MAX/b) return -1;
	return a/g*b;
}

ll m[10010];

int main(void){
	int TestCase;
	cin >> TestCase;
	range(Number,1,TestCase+1){
		ll n,b;
		cin >> b >> n;
		rep(i,b) cin >> m[i];


		int ans=0;
		ll l=0LL,r=1LL<<60;
		while(r-l>0){
			ll mid=(l+r)/2;
			ll num=0LL;
			vi same;
			rep(i,b){
				num+=mid/m[i]+1;
				if(mid%m[i]==0) same.pb(i+1);
			}
			int a=same.size();
			if(num-a<n&&n<=num){
				int idx=(a-1)-(num-n);
				ans=same[idx];
				break;
			}
			if(num<n)
				l=mid;
			else if(n<=num-a)
				r=mid;
		}
		cout << "Case #"<< Number << ": ";
		cout << ans << endl;
	}
	return 0;
}