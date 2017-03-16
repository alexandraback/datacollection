#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define FOR(i, a, b) for (int i(a), _b(b); i <= _b; ++i)
#define REP(i, n) for (int i(0), _n(n); i < _n; ++i)

vector <double> x, y;

int get_min(int cur){
	int ret;
	int n;
	n = x.size();

	double A, B, C, dx, dy;
	int up, down;
	ret = n;
	if (n == 1) return 0;
	REP(q, n){
		if (q == cur)continue;

		dx = x[cur] - x[q];
		dy = y[cur] - y[q];

		B = -dx;
		A = dy;
		C = -(A*x[q] + B*y[q]);

		up = 0;
		down = 0;
		double tmp;
		REP(w, n){
			tmp = A *x[w] + B * y[w] + C;
			if (tmp > 0) up++;
			if (tmp < 0) down++;
		}

		ret = min(ret, min(up, down));
	}

	return ret;
}

int main(void){
	ifstream fin("in.txt");
	ofstream fout("out.txt");

	int T;
	fin >> T;

	
	int n;
	REP(test, T){
		fin >> n;
		x.resize(n);
		y.resize(n);
		REP(q, n){
			fin >> x[q] >> y[q];
		}

		fout << "Case #" << test + 1 << ":" << endl;
		REP(q, n){
			fout << get_min(q) << endl;
		}
	}

	fin.close();
	fout.close();

	return 0;
}
