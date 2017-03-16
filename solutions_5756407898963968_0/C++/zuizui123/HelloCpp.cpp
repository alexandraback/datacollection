#include <iostream>
#include <cstdio>
#include <cctype>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <sstream>
#include <fstream>
#include <ctime>
#include <cassert>

using namespace std;

#define fi "A-small-attempt0.in"
#define fo "out.txt"
const int MAXN = 200 + 5;
const int INF = 1e9;

int firstGrid[4][4], secondGrid[4][4];

int main() {
	freopen(fi, "r", stdin);
	freopen(fo, "w", stdout);
	int T;
	int firstRow, secondRow;
	cin >> T;
	for (int t = 0; t < T; ++t) {
		cout << "Case #" << (t + 1) << ": ";
		cin >> firstRow;
		--firstRow;
		for (int i = 0; i < 4; ++i) {
			for (int k = 0; k < 4; ++k) {
				cin >> firstGrid[i][k];
			}
		}
		cin >> secondRow;
		--secondRow;
		for (int i = 0; i < 4; ++i) {
			for (int k = 0; k < 4; ++k) {
				cin >> secondGrid[i][k];
			}
		}
		int coincidence = 0;
		int res = 0;
		for (int i = 0; i < 4; ++i) {
			for (int k = 0; k < 4; ++k) {
				if (firstGrid[firstRow][i] == secondGrid[secondRow][k]) {
					++coincidence;
					res = firstGrid[firstRow][i];
				}
			}
		}
		if (coincidence == 0) {
			cout << "Volunteer cheated!" << endl;
		} else if (coincidence > 1) {
			cout << "Bad magician!" << endl;
		} else {
			cout << res << endl;
		}
	}
}
