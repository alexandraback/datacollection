#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <algorithm>
#include <set>
#include <list>
#include <stack>
#include <cstdio>
#include <sstream>
#include <map>
#include <cmath>
#include <queue>
#include <ctime>

#define FOR(i,n) for(int i = 0; i < (n); ++i)
#define SZ(x) ((int)((x).size()))

using namespace std;

typedef long long int LL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<bool> VB;
typedef vector<VB> VVB;
typedef vector<double> VD;
typedef vector<VD> VVD;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;

int main() {
	ifstream fin("a1.in");
	ofstream fout("a1.out");
	int t;
	fin >> t;
	for (int tt = 1; tt <= t; ++tt) {
		vector<bool> pos(17, true);
		for (int i = 0; i < 2; ++i)
		{
			int row;
			fin >> row;
			for (int j = 1; j <= 4; ++j) for (int k = 1; k <= 4; ++k)
			{
				int num;
				fin >> num;
				if (j != row) pos[num] = false;
			}
		}
		int res = 0;
		for (int i = 1; i < 17; ++i)
		{
			if (pos[i])
			{
				if(res == 0) res = i;
				else res = -1;
			}
		}
		fout << "Case #" << tt << ": ";
		if (res == 0) {
			fout << "Volunteer cheated!";
		} else if (res == -1) {
			fout << "Bad magician!";
		} else {
			fout << res;
		}
		fout << "\n";
	}
	fin.close();
	fout.close();
	return 0;
}
