#include<cstdio>
#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<sstream>
#include<cmath>
#include<cctype>
#include<cassert>
#include<cstring>
#include<cstdlib>

using namespace std;

#define DEBUG(x) cout<<">> "<<#x<<':'<<(x)<<endl
const int inf = 1000000000;

int checkUnhappiness(int r, int c, int n, int state) {
	int grid[20][20];
	int cnt = 0;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++) {
			if (state & (1<<cnt)) {
				grid[i][j] = 1;
			} else {
				grid[i][j] = 0;
			}
			cnt++;
		}
	int res = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (i+1 < r && grid[i][j] == 1 && grid[i+1][j] == 1) res++;
			if (j+1 < c && grid[i][j] == 1 && grid[i][j+1] == 1) res++;
		}
	}
	return res;
}

int main() {
	int test, cases = 1;
	cin >> test;
	for (cases = 1; cases <= test; cases++) {
		int r, c, n;
		cin >> r >> c >> n;
		int p = r * c;
		int res = inf;
		for (int i = 0; i < (1<<p); i++) {
			if (__builtin_popcount(i) != n) continue;
			int k = checkUnhappiness(r, c, n, i);
			res = min(res, k);
		}
		cout << "Case #" << cases << ": " << res << endl;
	}
	return 0;
}
