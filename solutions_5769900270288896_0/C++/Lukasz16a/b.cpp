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
#include <sstream>
#include <ext/numeric>
#include <gmpxx.h>			// -lgmpxx -lgmp
//#include <NTL/mat_lzz_p.h> 	// -lntl
using namespace std ;
using namespace __gnu_cxx ;
//using namespace NTL ;
typedef mpz_class BIGNUM ;
typedef long long LL ;
typedef pair<int,int> PII ;
typedef vector<int> VI ;
const int INF = 1e9 ;
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

template<class T1,class T2> ostream& operator<<(ostream &s, const pair<T1,T2> &x) { s<< "(" << x.FI << "," << x.SE << ")"; return s;}
template<class T>           ostream& operator<<(ostream &s, const vector<T>   &t) { FOREACH(it, t) s << *it << " " ; return s ; }
template<class T>           ostream& operator<<(ostream &s, const std::set<T> &t) { FOREACH(it, t) s << *it << " " ; return s ; }
template<class T1,class T2> ostream& operator<<(ostream &s, const map<T1, T2> &t) { FOREACH(it, t) s << *it << " " ; return s ; }

//////////////////////////////////////////////////////////////

const int MAXN = 200100 ;

int r,c, n ;
const int add_i[4] = {0,0,-1,1} ;
const int add_j[4] = {-1,1,0,0} ;
bool inRange(int a, int b) {
	return a>=0 && a<r && b>=0 && b<c ;
}
int IDX(int i, int j) {
	assert(inRange(i,j)) ;
	return i*c+j ;
}

void _main() {
	cin >> r >> c >> n ;
	int best=INF ;
	for(int mask=0 ; mask<(1<<r*c) ; mask++) {
		if(__builtin_popcount(mask)==n) {
			int now=0, i,j, k ;
			REP(i, r) {
				REP(j, c) {
					if(!(mask&(1<<IDX(i,j)))) continue ;
					REP(k, 4) {
						int i2 = i+add_i[k] ;
						int j2 = j+add_j[k] ;
						if(inRange(i2,j2) && (mask&(1<<IDX(i2,j2))))
							now++ ;
					}
				}
			}
			assert(!(now&1)) ;
			best = min(best, now/2) ;
		}
	}
	cout << best << endl ;
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

