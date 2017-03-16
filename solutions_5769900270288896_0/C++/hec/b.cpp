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

int r,c,n;
int appart[16][16];

int main(void){
	int TestCase;
	cin >> TestCase;
	range(Number,1,TestCase+1){
		cin >> r >> c >> n;
		int ans=inf;
		rep(mask,1<<(r*c)){
			if(__builtin_popcount(mask)!=n) continue;
			rep(i,r*c){
				if(mask&(1<<i))
					appart[i/c][i%c]=1;
				else
					appart[i/c][i%c]=0;
			}

			int cur=0;
			rep(i,r)rep(j,c){
				if(i+1<r&&appart[i][j]&&appart[i+1][j]) cur++;
				if(j+1<c&&appart[i][j]&&appart[i][j+1]) cur++;
			}
			ans=min(ans,cur);
		}
		cout << "Case #"<< Number << ": ";
		cout << ans << endl;
	}
	return 0;
}