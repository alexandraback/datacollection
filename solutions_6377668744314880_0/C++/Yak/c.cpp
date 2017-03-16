// Cygwin clang++ 3.4.2 with -std=c++1y

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
// 1.55 is used

#pragma GCC diagnostic ignored "-Wconversion"
#include <boost/range/irange.hpp>
#include <boost/range/iterator_range.hpp>
#pragma GCC diagnostic warning "-Wconversion"

#include <boost/geometry/geometry.hpp>
#include <boost/geometry/multi/geometries/multi_point.hpp>
#include <boost/geometry/geometries/polygon.hpp>
#include <boost/geometry/geometries/adapted/boost_tuple.hpp>
#include <boost/tuple/tuple_comparison.hpp>
BOOST_GEOMETRY_REGISTER_BOOST_TUPLE_CS(cs::cartesian)

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
inline boost::iterator_range< boost::range_detail::integer_iterator<Integer> >
IR(Integer first, Integer  last)
{ return boost::irange(first, last); }


namespace bg = boost::geometry;
using multipoint = bg::model::multi_point<boost::tuple<int, int>>;
using polygon = bg::model::polygon<boost::tuple<int, int>>;
using pt = boost::tuple<int, int>;

template<typename G>
bool on_boundary(G &g, const pt& p)
{
#if 0
	bool result = false;
	bg::for_each_point(g, [&result,&p](const pt &p0){ if(p0 == p) { result = true; }});
	return result;
#endif
	return bg::covered_by(p, g) && !bg::within(p, g);
}

bool make_point(const multipoint &mp, multipoint &out, int bits)
{
	int mask = 1;
	bg::for_each_point(mp, [bits, &mask, &out](const pt &p) {
		if((bits & mask) == mask) {
			bg::append(out, p);
		}
		mask <<= 1;
	});
	return bg::num_points(out) >= 3;
}

int main(void)
{
	ios_base::sync_with_stdio(false);

	UI cases; cin >> cases;
	REP(casenum, cases) {
		int N; cin >> N;
		vector<int> result(N);
		multipoint mp;
		for(auto i: IR(0, N)) {
			int x, y; cin >> x >> y;
			bg::append(mp, boost::make_tuple(x, y));
		}
		if(N > 3) {
			for(auto &val: result) { val = N; }
			for(auto bits: IR(0, 1<<N)) {
				multipoint mpt;
				if(make_point(mp, mpt, bits)) {
					polygon poly;
					bg::convex_hull(mpt, poly);
					for(auto i: IR(0, N)) {
						if(on_boundary(poly, mp[i])) {
							result[i] = min<int>(result[i], N - bg::num_points(mpt));
						}
					}
				}
			}
		}
		cout << "Case #" << casenum+1 << ":" << endl;
		for(auto val: result) { cout << val << endl; }
	}

	return 0;
}
