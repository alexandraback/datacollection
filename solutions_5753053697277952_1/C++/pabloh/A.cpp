#include <iostream>
#include <fstream>
#include <cassert>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
// #include <queue>
#include <cmath>
//download TTMath from http://www.ttmath.org/
// #include "ttmath-0.9.3/ttmath/ttmath.h"
#undef max
#undef min

using namespace std;
// using namespace ttmath;
// typedef Int<100> num;

#define metafor(iter,container) \
	for ((iter) = (container).begin(); (iter) != (container).end(); ++(iter))
#define FOR(i,n) for (size_t i = 0; i < (n); ++i)
#define FORi(i,n) for (int i = 0; i < (n); ++i)
template<class C> void show(const C & v) { FOR(i,v.size()) cout << v[i] << ' '; cout << endl; }
ostream& operator<<(ostream& os, const pair<int,char> & v) { os << ' ' << v.first << v.second; return os; }
// ostream& operator<<(ostream& os, const vector<int> & v) { FOR(i, v.size()) os << ' ' << v[i]; return os; }

void resort(vector<pair<int,char>> & P)
{
	size_t i = 0;
	const size_t N = P.size();
	while (i+1 < N && P[i].first < P[i+1].first) {
		swap(P[i], P[i+1]);
		++i;
	}
	if (P[N-1].first == 0) P.pop_back();
}
string solve_case(size_t N, vector<pair<int,char>> P)
{
	sort(P.begin(), P.end(), greater<pair<int,char>>());
	int sum = 0; FOR(i,N) sum += P[i].first;
	//show(P);
	string res;
	while (sum > 0) {
		assert(!P.empty());
		res += ' ';
		res += P[0].second;
		--P[0].first;
		--sum;
		resort(P);
		if (!P.empty() && 2*P[0].first > sum) {
			res += P[0].second;
			--P[0].first;
			--sum;
			resort(P);
			assert(P.empty() || 2*P[0].first <= sum);
		}
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
		in >> N; assert(N >= 2);
		vector<pair<int,char>> P(N);
		FOR(i,N) { in >> P[i].first; P[i].second = static_cast<char>('A'+i); }

		string result = solve_case(N, move(P));
		out << "Case #" << t << ": " << result << endl;
	}
}


int main()
{
	// ifstream in("A-sample.in");
	// ofstream out("A-sample-out.txt");

	// ifstream in("A-small-attempt0.in");
	// ofstream out("A-small-attempt0-out.txt");

	ifstream in("A-large.in");
	ofstream out("A-large-out.txt");

	solve(in,out);
	
	return 0;
}
