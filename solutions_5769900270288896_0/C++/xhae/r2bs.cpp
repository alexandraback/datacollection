#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <stack>
#include <queue>
#include <sstream>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int main(void) {
	int T;
	cin >> T;
	for(int kase = 1; kase <= T; kase++) {
		int r, c, n;
		cin >> r >> c >> n;
		int lim = r * c;
		int ans = 99999999;
		for(int i = 0; i < (1 << lim); i++) {
			int cnt = 0;
			bool field[16][16] = {false, };
			for(int j = 0; j < lim; j++)
				if(i & (1 << j)) {
					cnt++;
					field[j / c][j % c] = true;
				}

			int mov[2][2] = {{0, 1}, {1, 0}};
			if(cnt == n) {
				int cur = 0;
				for(int y = 0; y < r; y++)
					for(int x = 0; x < c; x++) {
						if(field[y][x]) {
							for(int k = 0; k < 2; k++) {
								int ny = y + mov[k][0];
								int nx = x + mov[k][1];
								if(ny >= 0 && ny < r && nx >= 0 && nx < c && field[ny][nx]) cur++;
							}
						}
					}
				ans = min(ans, cur);
			}
		}

		cout << "Case #" << kase << ": " << ans << "\n";
	}

	return 0;
}
