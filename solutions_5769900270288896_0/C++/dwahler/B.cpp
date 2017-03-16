#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <functional>
#include <iostream>

#define D(x) x

using namespace std;

int main() {
	int numTestCases;
	cin >> numTestCases;
	
	for (int T = 1; T <= numTestCases; T++) {
		int R, C, N;
		cin >> R >> C >> N;
		
		int best = R*C*4;
		
		vector<vector<bool>> grid(R, vector<bool>(C));
		for (int mask = 0; mask < 1<<(R*C); mask++) {
			int count = 0;
			for (int r = 0; r < R; r++) {
				for (int c = 0; c < C; c++) {
					if ((mask & (1<<(r*C+c))) != 0) {
						grid[r][c] = true;
						count++;
					} else {
						grid[r][c] = false;
					}
				}
			}
			if (count != N) continue;
			
			int score = 0;
			for (int i = 0; i < R; i++) {
				for (int j = 0; j < C; j++) {
					if (!grid[i][j]) continue;
					if (i < R-1 && grid[i+1][j]) score++;
					if (j < C-1 && grid[i][j+1]) score++;
				}
			}
			
			best = min(best, score);
		}
		cout << "Case #" << T << ": " << best << endl;
	}
}