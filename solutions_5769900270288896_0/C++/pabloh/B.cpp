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

int unh[16][16][16];

struct board
{
	int a[16][16];
};

const board vacio = {};

int complete(int b[16][16], int r, int c, int i0, int j0, int n)
{
	if (n == 0) return 0;
	int i = i0, j = j0; int best = 1000000;
	while (i < r && j < c) {
		b[i][j] = 1;
		int ii = i, jj = j; ++jj; if (jj == c) {jj = 0; ++ii; }
		int uh = complete(b,r,c,ii,jj,n-1);
		if (i > 0 && b[i-1][j] == 1) ++uh;
		if (j > 0 && b[i][j-1] == 1) ++uh;
		if (uh < best) best = uh;
		b[i][j] = 0;
		i = ii; j = jj;
	}
	return best;
}

int precomp(int R, int C, int N)
{
	int b[16][16] = {};
	return complete(b,R,C,0,0,N);
}

void precomp()
{
	FORi(r,16+1)
		FORi(c,16+1) {
			if (r > c) continue;
			if (r*c > 16) continue;
			FORi(n,r*c+1) {
				unh[r][c][n] = precomp(r,c,n);
				//cout << r << '\t' << c << '\t' << n << '\t' << unh[r][c][n] << '\n';
			}
	}
}

int solve_case(int R, int C, int N)
{
	if (R > C) swap(R,C); 
	assert(R <= C && R*C <= 16);
	int res = unh[R][C][N];
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
		cout << "Case #" << t << endl;
		int R, C, N;
		in >> R >> C >> N; assert(0 <= N && N <= R*C);

		int result = solve_case(R,C,N);
		out << "Case #" << t << ": " << result << endl;
	}
}


int main()
{
	precomp();
	//return 0;

	//ifstream in("B-sample.in");
	//ofstream out("B-sample-out.txt");

	ifstream in("B-small-attempt0.in");
	ofstream out("B-small-attempt0-out.txt");

	//ifstream in("B-large.in");
	//ofstream out("B-large-out.txt");

	solve(in,out);

	return 0;
}
