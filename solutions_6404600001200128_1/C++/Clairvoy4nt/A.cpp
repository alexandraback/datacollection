#include <cstring>
#include <map>
#include <numeric>
#include <sstream>
#include <cmath>
#include <stack>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <queue>
#include <string>
#include <cctype>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define pb(x) push_back((x))
#define REP(i,x,y) for(int i = x; i < int(y); i++)
#define FOR(it,A) for(typeof (A.begin()) it = A.begin(); it!= A.end(); it++)
#define CUA(x) (x) * (x)
#define mp(x,y) make_pair((x),(y))
#define clr(x, y) memset(x, y, sizeof x)
#define fst first
#define snd second
#define I (1LL << 40)
#define sz size()
#define oo (1<<30)
#define EPS (1e-9)

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define si(c) ((int)(c).size())
#define forsn(i,s,n) for(int i = (int)(s); i<((int)n); i++)
#define dforsn(i,s,n) for(int i = (int)(n)-1; i>=((int)s); i--)
#define decl(v, c) typeof(c) v = c
#define forall(i, c) for(decl(i, c.begin()); i!=c.end(); ++i)
#define dforall(i, c) for(decl(i, c.rbegin()); i!=c.rend(); ++i)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<pii> vii;
typedef vector<string> vs;
typedef vector<int> vi;

void solve(int caso){
	int n;
	cin >> n;
	vector<ll> v;
	REP(i,0,n){
		int a;
		cin >>a;
		v.pb(a);
	}
	ll ans1=0, ans2=0;
	ll mx= 0;
	REP(i,0,n-1){
		if(v[i+1]>=v[i]) continue;
		else{

			ans1+= v[i]-v[i+1];
			mx = max(mx, v[i]-v[i+1]);
		}
	}
	REP(i,0,n-1){

		if(v[i]>mx) ans2 += mx;
		else ans2+=v[i];

	}
	printf("Case #%d: %lld %lld\n",caso, ans1, ans2);
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif	
	
	int T;
	cin >> T;

	REP(i,1,T+1){
		solve(i);
	}
		
	return 0;
}






