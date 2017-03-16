#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <climits>
#include <cassert>

#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <string>

#include <iostream>
#include <sstream>

#include <utility>
#include <functional>
#include <limits>
#include <numeric>
#include <algorithm> 

using namespace std;

int R, C, N;
int gb[17][17];
int opt, tot, dis;

void probeer(int i, int j) {
	if (i >= R) {
		if (tot == N)
			opt = min(opt, dis);
		/*cerr << "Tried";
		for (int ip = 0; ip < R; ip++) {
			cerr << '\n';
			for (int jp = 0; jp < C; jp++)
				cerr << gb[ip][jp];
		}
		cerr << "\n\n";*/
		return;
	}
	
	// Try first
	if (j < C-1) {
		probeer(i,j+1);
	} else {
		probeer(i+1,0);
	}
	
	// Try other
	gb[i][j] = 1;
	tot += 1;
	if (i > 0)
		if (gb[i-1][j] == 1)
			dis += 1;
	if (j > 0)
		if (gb[i][j-1] == 1)
			dis += 1;
	if (j < C-1) {
		probeer(i,j+1);
	} else {
		probeer(i+1,0);
	}	
	gb[i][j] = 0;
	if (i > 0)
		if (gb[i-1][j] == 1)
			dis -= 1;
	if (j > 0)
		if (gb[i][j-1] == 1)
			dis -= 1;
	tot -= 1;
	return;
}

void doit() {	
	cin >> R >> C >> N;
	for (int i = 0; i <= R; i++)
	for (int j = 0; j <= C; j++)
		gb[i][j] = 0;
	opt = 30*R*C;
	tot = 0;
	dis = 0;
	probeer(0,0);
	cout << opt << '\n';
}

int main () {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cout << "Case #" << t << ": ";
		doit();
	}
	return 0;
}

