#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <assert.h>
#include <algorithm>
#include <math.h>
#include <ctime>
#include <functional>

#include <Windows.h>

using namespace std;

const int SZ = 17; 
int r, c, n;

bool s[SZ][SZ]; 

int ans; 

void getAns() {
	int t = 0; 

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < (c - 1); j++) {
			if (s[j][i] && s[j+1][i])
				t++;
		}
	}

	for (int i = 0; i < c; i++) {
		for (int j = 0; j < (r - 1); j++) {
			if (s[i][j] && s[i][j+1])
				t++; 
		}
	}

	ans = min(ans, t); 
}

void dfs(int num, int position) {
	if (num >= n) {
		getAns();
		return;
	}


	int e = (r*c - n + num);
	for (int i = position; i <= e; i++) {
		int tc = i / r; 
		int tr = i % r; 

		s[tc][tr] = true;
		dfs(num + 1, i + 1); 
		s[tc][tr] = false; 
	}

}

int main(int argc, char* argv[]) {
	ifstream inf(argv[1]);

	int TC = 0;
	inf >> TC;
	for (int tc = 1; tc <= TC; tc++) {
		memset(s, 0, sizeof(s)); 
		ans = 0x7fffffff; 

		inf >> r >> c >> n; 

		dfs(0, 0); 

		cout << "Case #" << tc << ": " << ans << endl;
	}

	return 0;
}