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
#define POPCOUNT(v) __builtin_popcountll((ll)(v))
#define IN_RANGE(v, a, b) ((a)<=(v) && (v)<(b))
#define CLEAR(table, v) memset(table, v, sizeof(table));
#define PRINT1(table, D0) REP(d0, D0) cout<<table[d0]<<" "; cout<<"\n";
#define PRINT2(table, D0, D1) REP(d0, D0) { REP(d1, D1) cout<<table[d0][d1]<<" "; cout<<"\n"; }
#define PRINT3(table, D0, D1, D2) REP(d0, D0) { REP(d1, D1) { REP(d2, D2) cout<<table[d0][d1][d2]<<" "; cout<<"\n"; } cout<<"\n"; }
#define DD(v) cout<<#v<<": "<<v<<endl
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }


bool check(VI& w, bool as=false) {
	int N=w.size();
	int all = accumulate(ALL(w), 0LL);
	REP(i, N) if(!(w[i] <= all/2)) {
		if(as) {
			DD(i);DD(w[i]);DD(all);
			assert(false);
		} else {
			return false;
		}
	}
	return true;
}

vector<string> solve(VI w) {
	int N = w.size();
	int all = accumulate(ALL(w), 0LL);
	vector<string> ans;
	while(all) {
//		DD(w);
		vector<PII> ww;
		REP(i, N) ww.PB(MP(w[i], i));
		sort(ALL(ww));
		reverse(ALL(ww));
		int no = 2;
		if(ww.size()<2) no=1;
		if(no==2 && ww[1].first==0) no=1;
		string lans;
		if(no==2 && ww[0].first > ww[1].first+1) {
			lans = string(2, 'A'+ww[0].second);
			w[ww[0].second]-=2;
			all-=2;
		} else {
			VI tw(w);
			REP(i, no) {
				tw[ww[i].second]--;
			}
			bool ok = check(tw);
			if(!ok) no=1;
			REP(i, no) {
				lans.PB('A'+ww[i].second);
				w[ww[i].second]--;
				all--;
			}
		}
		ans.PB(lans);
//		cout<<lans<<endl;
		check(w, true);
	}
	return ans;
}

int main() {
//	REP(i, 100) REP(j, 100) REP(k, 100) {
//		VI w = VI{i, j, k};
//		if(check(w)) {
//			DD("solve");
//			DD(w);
//			solve(w);
//		}
//	}
//	return 0;
//	REP(loop, 100) {
//		VI w(26);
//		REP(i, 26) w[i]=rand()%1000;
//		if(check(w)) {
//			DD("solve");
//			DD(w);
//			solve(w);
//		}
//	}
//	return 0;

	int test_cases;
	cin>>test_cases;
	ll N;
	string s;
	REP(ttt, test_cases) {
		cin>>N;
		VI w(N);
		REP(i, N) cin>>w[i];
		cout<<"Case #"<<ttt+1<<": ";
		auto ans = solve(w);
//		DD(ans);
		REP(i, ans.size()) {
			cout<<ans[i];
			if(i<ans.size()-1) cout<<" ";
		}
		cout<<endl;
//		return 0;
	}
	return 0;
}



