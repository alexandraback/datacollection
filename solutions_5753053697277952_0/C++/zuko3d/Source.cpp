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

int main(void) {
	int T;

	ifstream fin("A-small-attempt0 (3).in");
	ofstream fout("out.txt");
	fin >> T;
	REP(t, T) {
		int n, total;
		vector<int> sen;
		fin >> n;
		sen.resize(n);
		total = 0;
		REP(i, n) {
			fin >> sen[i];
			total += sen[i];
		}

		fout << "Case #" << t + 1 << ": ";

		while (total>0)
		{
			int best;
			best = 0;
			FOR(i, 1, n - 1) {
				if (sen[i] > sen[best]) {
					best = i;
				}
			}

			sen[best]--;
			total--;
			fout << ((char)('A' + best));

			best = 0;
			FOR(i, 1, n - 1) {
				if (sen[i] > sen[best]) {
					best = i;
				}
			}

			sen[best]--;
			total--;

			int secondBest;
			secondBest = 0;
			FOR(i, 1, n - 1) {
				if (sen[i] > sen[secondBest]) {
					secondBest = i;
				}
			}
			if (sen[secondBest] * 2 > total) {
				sen[best]++;
				total++;
			}
			else {
				fout << ((char) ('A' + best));
			}

			fout << " ";
		}

		fout << endl;
	}
	fout.close();
	fin.close();
	return 0;
}