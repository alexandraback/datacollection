#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <string.h>

typedef long long ll;
using namespace std;

int solve(int R, int C, int N) {
	int m[20][20];
	int ans = 1<<29;
	for (int i = 0; i < 1<<(R*C); i++) {
		if (__builtin_popcount(i) != N) {
			continue;
		}
		int j = i;
		for (int y = 0; y < R; y++) {
			for (int x = 0; x < C; x++) {
				m[y][x] = (j&1);
				j >>= 1;
			}
		}
		int n = 0;
		for (int y = 0; y < R; y++) {
			for (int x = 0; x < C-1; x++) {
				if (m[y][x] && m[y][x+1])
					n++;
			}
		}
		for (int x = 0; x < C; x++) {
			for (int y = 0; y < R-1; y++) {
				if (m[y][x] && m[y+1][x])
					n++;
			}
		}
		ans = min(ans, n);
	}
	return ans;
}

int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int R, C, N;
		cin >> R >> C >> N;
		int ans;
		ans = solve(R, C, N);
		cout << "Case #" << i+1 << ": " << ans << endl;
	}
}
