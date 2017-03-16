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

int main(void){
	ifstream fin("in.txt");
	ofstream fout("out.txt");

	int T;
	fin >> T;
	vector <int> m;
	int n;
	REP(test, T){
		fin >> n;
		m.resize(n);

		REP(q, n) fin >> m[q];
		int dmax, dcur, d;
		dcur = 0;
		dmax = 0;
		REP(q, n - 1){
			d = m[q + 1] - m[q];
			if (d < 0) dcur -= d;
			dmax = max(dmax, -d);
		}
		int ret;
		ret = 0;
		REP(q, n-1){
			ret += min(dmax, m[q]);
		}

		fout << "Case #" << test + 1 << ": " << dcur << " " << ret << endl;
	}

	fin.close();
	fout.close();

	return 0;
}
