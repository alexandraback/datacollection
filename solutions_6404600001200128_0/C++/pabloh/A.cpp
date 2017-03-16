#include <iostream>
#include <fstream>
#include <cassert>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <queue>
#include <cmath>
//download TTMath from http://www.ttmath.org/
//#include <ttmath/ttmath.h>
#undef max
#undef min

using namespace std;
//using namespace ttmath;

#define metafor(iter,container) \
	for ((iter) = (container).begin(); (iter) != (container).end(); ++(iter))
#define FOR(i,n) for (size_t i = 0; i < (n); ++i)
#define FORi(i,n) for (int i = 0; i < (n); ++i)
template<class C>
void show(const C & v) { FOR(i,v.size()) cout << v[i] << ' '; cout << endl; }


pair<int,int> solve_case(const vector<int> & m)
{
	const size_t N = m.size();
	int md = 0;
	pair<int,int> res(0,0);
	for (size_t i = 1; i < N; ++i)
		if (m[i] < m[i-1]) {
			int d = m[i-1] - m[i];
			if (md < d) md = d;
		}
	for (size_t i = 1; i < N; ++i) {
		if (m[i] < m[i-1]) {
			int d = m[i-1] - m[i];
			res.first += d;
		}
		res.second += min(md,m[i-1]);
	}
	return res;
}

void solve(istream & in, ostream & out)
{
	int TC_NCases;
	in >> TC_NCases;
	out.precision(18);
	out.setf(std::ios_base::fixed, std::ios_base::floatfield);
	for (int t = 1; t <= TC_NCases; ++t)
	{
		int N;
		in >> N;
		vector<int> m(N);
		FOR(i,N) { in >> m[i]; }


		pair<int,int> result = solve_case(m);
		out << "Case #" << t << ": " << result.first << " " << result.second << endl;
	}
}


int main()
{
	//ifstream in("A-sample.in");
	//ofstream out("A-sample-out.txt");

	ifstream in("A-small-attempt0.in");
	ofstream out("A-small-attempt0-out.txt");

	//ifstream in("A-large.in");
	//ofstream out("A-large-out.txt");

	solve(in,out);

	return 0;
}
