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

//template<class C>
//void show(const C & v) { FOR(i,v.size()) cout << v[i] << ' '; cout << endl; }

typedef int row[4];
typedef row arrangement[4];


int solve_case(int q1, arrangement a1, int q2, arrangement a2)
{
	--q1; --q2;
	sort(a1[q1], a1[q1]+4);
	sort(a2[q2], a2[q2]+4);
	row r;
	int * begin = &r[0];
	int * end = set_intersection(a1[q1], a1[q1]+4, a2[q2], a2[q2]+4, begin);
	if (end == begin)
		return -2 ;//cheated
	else if (end == begin+1)
		return *begin;
	else
		return -1; //bad mage
}

void solve(istream & in, ostream & out)
{
	int TC_NCases;
	in >> TC_NCases;
	out.precision(18);
	out.setf(std::ios_base::fixed, std::ios_base::floatfield);
	for (int t = 1; t <= TC_NCases; ++t)
	{
		int q1, q2;
		arrangement a1, a2;
		in >> q1;
		FOR(i,4) FOR(j,4) in >> a1[i][j];
		in >> q2;
		FOR(i,4) FOR(j,4) in >> a2[i][j]; //yes, I know I don't need all this data


		int result = solve_case(q1, a1, q2, a2);
		if (result == -1)
			out << "Case #" << t << ": " << "Bad magician!" << endl;
		else if (result == -2)
			out << "Case #" << t << ": " << "Volunteer cheated!" << endl;
		else
			out << "Case #" << t << ": " << result << endl;
	}
}


int main()
{
	//ifstream in("A-sample.in");
	//ofstream out("A-sample-out.txt");

	ifstream in("A-small-attempt0.in");
	ofstream out("A-small-out.txt");

	//ifstream in("A-large.in");
	//ofstream out("A-large-out.txt");

	solve(in,out);

	return 0;
}
