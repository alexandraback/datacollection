// gcc version 4.8.2 with -std=c++11

#include <iostream>
#include <sstream>
#include <iomanip>

#include <iterator>

#include <algorithm>
#include <numeric>
#include <utility>
#include <limits>

#include <string>

#include <vector>
#include <deque>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>

#include <tuple>
#include <initializer_list>

#include <cmath>

// Boost library can be retrieved from http://www.boost.org/
// 1.52 is used

#pragma GCC diagnostic ignored "-Wconversion"
#include <boost/range/irange.hpp>
#include <boost/range/iterator_range.hpp>
#pragma GCC diagnostic warning "-Wconversion"

typedef unsigned long long ULL;
typedef long long LL;
typedef unsigned long UL;
typedef unsigned int UI;
typedef unsigned short US;
typedef unsigned char UC;

#define RNG(v) (v).begin(), (v).end()
#define REP(v, e) for(UI v = 0U; v < e; ++v)
#define REP_(v, s, e) for(UI v = s; v < e; ++v)
#define REPV(v, e) for(v = 0; v < e; ++v)
#define REPV_(v, s, e) for(v = s; v < e; ++v)

using namespace std;

template<class Integer>
inline auto
IR(Integer first, Integer  last) -> decltype(boost::irange(first, last))
{ return boost::irange(first, last); }

set<int> read()
{
	set<int> t;
	int ans; cin >> ans;
	for(int i : IR(1,5)) {
		int n;
		if(i != ans) {
			for(int j: IR(0,4)) { cin >> n; }
		} else {
			for(int j: IR(0,4)) { cin >> n; t.insert(n); }
		}
	}
	return t;
}

int main(void)
{
	ios_base::sync_with_stdio(false);

	UI cases; cin >> cases;
	REP(casenum, cases) {
		set<int> s1 = read();
		set<int> s2 = read();
		set<int> sr;
		set_intersection(RNG(s1), RNG(s2), inserter(sr, sr.end()));
		if(sr.size() > 1) {
			cout << "Case #" << casenum+1 << ": " << "Bad magician!" << endl;
		} else if(sr.size() == 0) {
			cout << "Case #" << casenum+1 << ": " << "Volunteer cheated!" << endl;
		} else {
			cout << "Case #" << casenum+1 << ": " << *sr.begin() << endl;
		}
	}

	return 0;
}
