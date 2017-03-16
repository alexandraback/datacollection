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


struct P {
	ll x, y;
	bool operator <(const P &p) const {
		return x < p.x || (x == p.x && y < p.y);
	}
};


double cross_oab(const P &O, const P &A, const P &B) {
	return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}
 
vector<P> convex_hull(vector<P> ps) {
	int n = ps.size(), k = 0;
	vector<P> H(2*n);
	sort(ALL(ps));
	REP(i, n) {
		while (k >= 2 && cross_oab(H[k-2], H[k-1], ps[i]) <= 0) k--;
		H[k++] = ps[i];
	}
	for (int i = n-2, t = k+1; i >= 0; i--) {
		while (k >= t && cross_oab(H[k-2], H[k-1], ps[i]) <= 0) k--;
		H[k++] = ps[i];
	}
	H.resize(k);
	return H;
}

double distance(P p1, P p2) {
	return pow( ( p2.x - p1.x ) * ( p2.x - p1.x ) + ( p2.y - p1.y ) * ( p2.y - p1.y ), 0.5);
}

double cross(P vl, P vr) {
	return vl.x * vr.y - vl.y * vr.x;
}

inline double line_point_l(P p, P a, P b) {
	P AB,AP;

	AB.x = b.x - a.x;
	AB.y = b.y - a.y;
	AP.x = p.x - a.x;
	AP.y = p.y - a.y;

	double D = abs( cross( AB, AP ) );
	double L = distance( a, b );
	double H = D / L;
	return H;
}

inline bool near(P a, P b) {
	return a.x==b.x && a.y==b.y;
}

inline bool check_on(P p, vector<P>& ps) {
	REP(i, ps.size()) if(near(p, ps[i])) return true;
	REP(i, ps.size()) {
		ll ni = (i+1)%ps.size();
		if(line_point_l(p, ps[i], ps[ni]) < 0.0001) return true;
	}
	return false;
}

int main() {
	int test_cases;
	cin>>test_cases;
	ll N;
	string s;
	REP(ttt, test_cases) {
		cin>>N;
		vector<P> ps(N);
		VI ans(N, N-1);
		REP(i, N) cin>>ps[i].x>>ps[i].y;
		REP(b, 1LL<<N) {
			vector<P> lps;
			REP(ti, N) if((b>>ti&1)==0) lps.PB(ps[ti]);
			vector<P> ch = convex_hull(lps);
			REP(ti, N) {
				if(b>>ti&1) continue; //dont cut myself!
				if(check_on(ps[ti], ch)) {
					ans[ti] = min<ll>(ans[ti], POPCOUNTLL(b));
				}
			}
		}
		cout<<"Case #"<<ttt+1<<": "<<endl;
		REP(ti, N) {
			cout<<ans[ti]<<endl;
		}
//		return 0;
	}
	return 0;
}



