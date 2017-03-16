#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int T = 0;
	cin >> T;

	int grid[100][100];

	for (int t = 0; t < T; t++) {
		int R, C, N;
		cin >> R >> C >> N;

		int ans = R*C*4;
		for (int i = 0; i < (1 << (R*C)); i++) {
			int cb = 0, tmp = i;
			for (int j = 0; j < R*C; j++) {
				cb += tmp & 1;
				tmp >>= 1;
			}
			if (cb != N) continue;
			
			for (int r = 0; r < R; r++) {
				for (int c = 0; c < C; c++) {
					int x = r*C + c;
					grid[r][c] = (i&(1 << x));
				}
			}

			int w = 0;
			for (int r = 0; r < R; r++) {
				for (int c = 0; c < C - 1; c++) {
					if (grid[r][c] && grid[r][c + 1]) w++;
				}
			}
			for (int r = 0; r < R-1; r++) {
				for (int c = 0; c < C; c++) {
					if (grid[r][c] && grid[r+1][c]) w++;
				}
			}
			ans = min(ans, w);
		}

		printf("Case #%d: %d\n", t + 1, ans);
	}

	return 0;
}
