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
	int n, b;
	REP(test, T){
		fin >> b >> n;
		m.resize(b);
		double spd;
		spd = 0;
		REP(q, b){
			fin >> m[q];
			spd += 1.0 / ((double)m[q]);
		}
		double time;
		time = floor((double)(n - 1) / spd);
		long long t = time;
		int cur_done;
		cur_done = 0;

		do {
			cur_done = 0;
			REP(q, b) cur_done += t / m[q];
			cur_done += b;
			t--;
		} while (cur_done >= n);
		t++;
		
		do {
			cur_done = 0;
			REP(q, b) cur_done += t / m[q];
			cur_done += b;
			t++;
		} while (cur_done < n);
		t--;
		
		int cur_got = 0;
		REP(q, b) cur_got += t / m[q] + ((t % m[q] > 0)?1:0);

		int br;
		int lastgood = 0;
		br = 0;
		while (cur_got < n){
			if (t % m[br] == 0) {
				cur_got++;
				lastgood = br;
			}
			br++;
		}

		fout << "Case #" << test + 1 << ": " << lastgood + 1<< endl;
		cout << "Case #" << test + 1 << ": " << lastgood + 1 << endl;
	}

	fin.close();
	fout.close();

	return 0;
}
