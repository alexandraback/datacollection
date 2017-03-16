#include <iostream>
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

template<class T> void minimize(T &a, T b) { a = min(a,b); }
template<class T> void maximize(T &a, T b) { a = max(a,b); }

#define DEBUGGING 1

#if defined(DEBUGGING)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#else
#define debug(...)
#endif

set<int> options()
{
	int row,x;
	set<int> res;

	cin >> row;
	REP(i,4) REP(j,4) {
		cin >> x;
		if ( i+1==row ) res.insert(x);
	}
	return res;
}

int main()
{
	int nruns;
	cin >> nruns;

	for(int run=1; run<=nruns; run++) {

		set<int> res, tmp1, tmp2;

		tmp1 = options();
		tmp2 = options();

		set_intersection(ALL(tmp1),ALL(tmp2),inserter(res,res.end()));

		cout << "Case #" << run << ": ";
		if ( res.size()==0 ) {
			cout << "Volunteer cheated!";
		} else if ( res.size()==1 ) {
			cout << *res.begin();
		} else {
			cout << "Bad magician!";
		}
		cout << endl;

	}

	return 0;
}
