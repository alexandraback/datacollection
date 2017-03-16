#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <cassert>
#include <cstring>
#include <ext/numeric>
#include <gmpxx.h>			// -lgmpxx -lgmp
using namespace std ;
using namespace __gnu_cxx ;
typedef mpz_class BIGNUM ;
typedef long long LL ;
typedef pair<int,int> PII ;
typedef vector<int> VI ;
const int INF = 1000*1000*1000 ;
const LL INFLL = (LL)INF * (LL)INF ;
#define REP(i,n) for(i=0;i<(n);++i)
#define ALL(c) c.begin(),c.end()
#define VAR(v,i) __typeof(i) v=(i)
#define FOREACH(i,c) for(VAR(i,(c).begin());i!=(c).end();++i)
#define CLEAR(t) memset(t,0,sizeof(t))
#define PB push_back
#define MP make_pair
#define FI first
#define SE second

template<class T1, class T2> ostream & operator<<(ostream &s, pair<T1,T2> x) { s << "(" << x.FI << "," << x.SE << ")" ; return s ; }
template<class T> ostream & operator<<(ostream &s, const vector<T> &t) { FOREACH(it, t) s << *it << " " ; return s ; }
template<class T1, class T2> ostream & operator<<(ostream &s, const map<T1, T2> &t) { FOREACH(it, t) s << *it << " " ; return s ; }

const int MAXN = 210 ;
vector<pair<char,int> > t[MAXN] ;

void _main() {
	string s ;
	int n, i, j ;
	cin >> n ;
	REP(i,n) {
		t[i].clear() ;
		cin >> s ;
		for(j=0 ; j<s.size() ; j++) {
			int c=1 ;
			while(j+1<s.size() && s[j]==s[j+1]) {
				c++ ;
				j++ ;
			}
			t[i].PB(MP(s[j],c)) ;
		}
//		cout << i << ") " << t[i] << endl ;
	}
	REP(i,n-1) {
		if(t[i].size() != t[i+1].size()) {
			cout << "Fegla Won" << endl ;
			return ;
		}
		REP(j,t[i].size()) {
			if(t[i][j].FI != t[i+1][j].FI) {
				cout << "Fegla Won" << endl ;
				return ;
			}
		}
	}
	int ret=0 ;
	vector<int> tmp ;
	REP(j,t[0].size()) {
		tmp.clear() ;
		REP(i,n) tmp.PB(t[i][j].SE) ;
		sort(ALL(tmp)) ;
		int x=tmp[n/2] ;
		REP(i,n) ret += abs(tmp[i]-x) ;
	}
	cout << ret << endl ;
}

int main()
{
	ios_base::sync_with_stdio(0) ;
	int C ;
	cin >> C ;
	for(int tests=1 ; tests<=C ; tests++) {
//		cerr << "Case #" << tests << endl ;
		cout << "Case #" << tests << ": " ;
		_main() ;
	}
}

