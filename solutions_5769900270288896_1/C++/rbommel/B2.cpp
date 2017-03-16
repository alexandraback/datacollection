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
int antw[12345];




void doit() {	
	cin >> R >> C >> N;
	if (R == 1) {
		int half = (C+1)/2;
		if (N <= half) {
			cout << "0\n";
			return;
		}
		cout << (C-1) - 2*(C-N) << '\n';
		return;
	}
	if (C == 1) {
		int half = (R+1)/2;
		if (N <= half) {
			cout << "0\n";
			return;
		}
		cout << (R-1) - 2*(R-N) << '\n';
		return;
	}
	int half = (R*C+1) / 2;
	if (N <= half) {
		cout << "0\n";
		return;
	}
	if ((R*C % 2) == 1) {
		antw[half+1] = 3;
		antw[half+2] = 6;
		antw[half+3] = 8;
		for (int j = 4; j <= R*C-half; j++) {
			antw[half+j] = max(antw[half+j-1] + 3, (R-1)*C + (C-1)*R - 4*(R*C-half-j));
		}
		cout << antw[N] << '\n';
		return;
	} else {
		antw[half+1] = 2;
		antw[half+2] = 4;
		for (int j = 3; j <= R*C-half; j++) {
			antw[half+j] = max(antw[half+j-1] + 3, (R-1)*C + (C-1)*R - 4*(R*C-half-j));
		}
		cout << antw[N] << '\n';
		return;
	}		
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

