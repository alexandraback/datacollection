#include <string>
#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define pb(x) push_back(x)
#define REP(i,x,y) for(int (i)=(x);(i)<(y);(i)++)
#define REPIT(it,A) for(typeof(A.begin()) it = (A.begin()); it!=A.end();it++)
#define sqr(x) ((x)*(x))
#define mp(x,y) make_pair((x),(y))
#define trace(x) cerr << #x << ": " << x << endl;
#define fst first
#define snd second
#define itm1 fst.fst
#define itm2 fst.snd
#define itm3 snd
#define mt(a,b,c) mp(mp(a,b),c)
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long int64;
typedef unsigned long long uint64;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<pair<ll,ll>, ll> tri;
typedef pair<ll, ll> pll;
typedef pair<pll, ll> tri64;
typedef set<int> seti;
typedef set<ii> setii;
typedef stack<int> stki;
typedef stack<ii> stkii;
typedef queue<int> qi;
typedef queue<ii> qii;
typedef map<int,int> mapii;
typedef map<string,int> mapsi;
typedef unsigned int uint;

const double PI = 3.14159265359;


int n;

ll x[1000];
ll y[1000];

ll best[1000];

vector<tri> v;

tri ch[2000];
int nch;

tri cr[2000];
int ncr;

int cntset(int msk){
	int ans = 0;
	while (msk){
		ans += (msk%2);
		msk /= 2;
	}
	return ans;
}

int wrong(tri p1, tri p2, tri p3){
	pll d1 = mp(p2.itm1 - p1.itm1, p2.itm2 - p1.itm2);
	pll d2 = mp(p3.itm1 - p2.itm1, p3.itm2 - p2.itm2);
	return (d1.fst*d2.snd - d1.snd*d2.fst > 0);
}

int main(){
	int nCases;
	cin >> nCases;
	REP(casenum,0,nCases){
		cout << "Case #" << casenum+1 << ":" << endl;
		cin >> n;
		REP(i,0,n) {
			cin >> x[i] >> y[i];
			best[i] = n-2;
		}
		if (n <= 3){
			REP(i,0,n) cout << 0 << endl;
			continue;
		}
		REP(msk,1,(1<<n)){
			v.clear();
			REP(i,0,n){
				if (msk & (1<<i)){
					v.pb(mt(x[i], y[i], i));
				}
			}
			sort(v.begin(), v.end());
			nch = 0;
			REP(i,0,v.size()){
				while (nch >= 2 && wrong(ch[nch-2], ch[nch-1], v[i])){
					nch--;	
				}
				ch[nch++] = v[i];
			}

			reverse(v.begin(), v.end());
			ncr = 0;
			REP(i,0,v.size()){
				while (ncr >= 2 && wrong(cr[ncr-2], cr[ncr-1], v[i])){
					ncr--;
				}
				cr[ncr++] = v[i];
			}

			ll ncut = n - cntset(msk);
			REP(i,0,nch){
				best[ch[i].itm3] = min(best[ch[i].itm3], ncut);
			}
			REP(i,0,ncr){
				best[cr[i].itm3] = min(best[cr[i].itm3], ncut);
			}
		}
		REP(i,0,n) cout << best[i] << endl;
	}  
	return 0;
}

