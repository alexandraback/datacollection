#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <iostream>
#include <iomanip>
#define _USE_MATH_DEFINES
#include <cmath>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cfloat>
#include <cmath>
#include <ctime>
#include <cassert>
#include <cctype>
#include <cstdio>
#include <cassert>
using namespace std;

#define EPS 1e-12
#define ull unsigned long long
#define ll long long
#define VI vector<ll>
#define PII pair<ll, ll> 
#define VVI vector<vector<ll> >
#define REP(i,n) for(int i=0,_n=(n);(i)<(int)_n;++i)
#define RANGE(i,a,b) for(int i=(int)a,_b=(int)(b);(i)<_b;++i)
#define RANGE_R(i,a,b) for(int i=(int)b-1,_a=(int)(a);(i)>=_a;--i)
#define MIN_UPDATE(target, value) target = min(target, value)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define ALLR(c) (c).rbegin(), (c).rend()
#define PB push_back
#define MP(a, b) make_pair(a, b)
#define POPCOUNT __builtin_popcount
#define POPCOUNTLL __builtin_popcountll
#define CLEAR(table, v) memset(table, v, sizeof(table));
#define PRINT1(table, D0) REP(d0, D0) cout<<table[d0]<<" "; cout<<"\n";
#define PRINT2(table, D0, D1) REP(d0, D0) { REP(d1, D1) cout<<table[d0][d1]<<" "; cout<<"\n"; }
#define PRINT3(table, D0, D1, D2) REP(d0, D0) { REP(d1, D1) { REP(d2, D2) cout<<table[d0][d1][d2]<<" "; cout<<"\n"; } cout<<"\n"; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }


char minw[18][18];
char w[18][18];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

ll small(ll W, ll H, ll N) {
	ll all=W*H;
	ll ans = 100000;
	REP(b, 1<<all) {
		if(POPCOUNTLL(b)!=N) continue;
		CLEAR(w, 0);
		REP(y, H) REP(x, W) {
			if(b>>(y*W+x)&1) w[x+1][y+1]=1;
		}
		ll pt=0;
		REP(y, H) REP(x, W) REP(dir, 4) {
			if(w[x+1][y+1] && w[x+dx[dir]+1][y+dy[dir]+1]) pt++;
		}
		pt/=2;
//		cout<<pt<<endl;
		if(pt<ans) {
			REP(y,H)REP(x,W)minw[x+1][y+1]=w[x+1][y+1];
		}
		ans=min(ans, pt);
	}
//	cout<<"minw"<<endl;
//	REP(y,H) {
//		REP(x,W){cout<<(int)minw[x+1][y+1];}
//		cout<<endl;
//	}
	return ans;
}

char m[10010][10010];
ll large(ll W, ll H, ll N) {
	if(W>H) swap(W, H);
	// W<=H

	ll ans = 1LL<<60;
	REP(eo, 2) {
		ll NN=N;

		VI n(5);
//		vector<vector<int>> m(H+2, vector<int>(W+2));
		CLEAR(m, 0);
		REP(y,H)REP(x,W) if((x+y)%2==eo) m[y+1][x+1]=1;
		REP(y,H)REP(x,W) {
			int co=0;
			REP(dir, 4) if(m[y+dy[dir]+1][x+dx[dir]+1]) co++;
			n[co]++;
		}
//		cout<<"EO "<<eo<<endl;
//		cout<<n<<endl;
		ll lans = 0;
		REP(i, 5) {
			ll use = min(NN, n[i]);
//			cout<<"use "<<use<<endl;
			lans += use * i;
//			cout<<"lans "<<lans<<endl;
			NN -= use;
		}
//		cout<<"lans "<<lans<<endl;
		if(NN) cout<<"ERR "<<W<<" "<<H<<" "<<N<<" eo "<<eo<<endl;
		assert(NN==0);
		ans = min(ans, lans);
	}
	return ans;
}

int main() {
//	RANGE(W, 1, 6) {
//		RANGE(H, 1, 6) {
//			REP(i, W*H+1) {
//				ll ref = small(W, H, i);
//				ll ans = large(W, H, i);
//				cout<<"TRY "<<W<<" "<<H<<" "<<i<<" = "<<ans<<" "<<ref<<endl;
//				if(ref!=ans) cout<<"ERR "<<i<<" "<<ans<<" "<<ref<<endl;
//				assert(ref==ans);
//			}
//		}
//	}
//	return 0;

	int test_cases;
	cin>>test_cases;
	ll W,H,N;
	string s;
	
	REP(ttt, test_cases) {
		cin>>H>>W>>N;
//		ll ref = small(W, H, N);
//cout<<"ok"<<endl;
		ll ans = large(W, H, N);
//		if(ref!=ans) cout<<"ERR "<<W<<" "<<H<<" "<<N<<" "<<ans<<" "<<ref<<endl;
//		assert(ref==ans);
		cout<<"Case #"<<ttt+1<<": "<<ans<<endl;
//		return 0;
	}
	return 0;
}



