#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <list>
#include <set>
#include <algorithm>
#include <utility>
#include <functional>
#include <numeric>
#include <cmath>
#include <string>
#include <cctype>
#include <cstdio>
#include <cstdlib>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<VVI> VVVI;
typedef vector<string> VS;
typedef istringstream ISS;

#define ALL(x) ((x).begin()),((x).end())
#if __cplusplus >= 201103L
#define FOR(i,c) for(auto i=c.begin(); i!=c.end(); ++i)
#define REP(i,n) for(decltype(n) i=0; i<(n); ++i)
#else
#define FOR(i,c) for(typeof(c.begin()) i=c.begin(); i!=c.end(); ++i)
#define REP(i,n) for(typeof(n) i=0; i<(n); ++i)
#endif

const int infty = 999999999;

const int dx[8] = {  1, 0,-1, 0, 1,-1,-1, 1 };
const int dy[8] = {  0, 1, 0,-1, 1, 1,-1,-1 };

template<class T> void minimize(T &a, T b) { a = min(a,b); }
template<class T> void maximize(T &a, T b) { a = max(a,b); }

//#define DEBUGGING 1

#if defined(DEBUGGING)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#else
#define debug(...)
#endif

int cost(int row)
{
	int res = 0;
	for(int m=3; m<(2<<9); m*=2)
		if ( (row&m)==m ) res++;
	return res;
}

int occ(int row)
{
	int res = 0;
	for(int i=1; i<(2<<9); i*=2)
		if ( row&i ) res++;
	return res;
}


int main()
{
	int nruns;
	cin >> nruns;

	for(int run=1; run<=nruns; run++) {

		int r,c,n,res;
		cin >> r >> c >> n;

		if ( c>r ) swap(c,r);

		VVVI best(r,VVI(n+1,VI(1<<c,infty)));

		if ( n<=((r*c)/2 + (r*c)%2) ) {
			res = 0;
			goto done;
		}

		for(int i=0; i<(1<<c); i++) best[0][occ(i)][i] = cost(i);

		for(int j=1; j<r; j++) {
			debug("j=%d\n",j);
			for(int o1=0; o1<=n; o1++) {
				for(int i1=0; i1<(1<<c); i1++) {
					for(int i2=0; i2<(1<<c); i2++) {
						int o2 = o1 + occ(i2);
						if ( o2>n ) continue;
						debug("from %d (o=%d) to %d (o=%d): %d -> %d\n",
						      i1,o1,i2,o2,best[j-1][o1][i1],
						      best[j-1][o1][i1]+occ(i1&i2)+cost(i2));
						best[j][o2][i2] = min(best[j][o2][i2],
						                      best[j-1][o1][i1]+occ(i1&i2)+cost(i2));
					}
				}
			}
		}

		res = infty;
		for(int i=0; i<(1<<c); i++) res = min(res,best[r-1][n][i]);

	  done:
		cout << "Case #" << run << ": ";
		cout << res << endl;
	}

	return 0;
}
