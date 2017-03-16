#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstring>

using namespace std;

const long long NMAX = 100000000000001;

int m[20][20];

int dx[4] = { 0, 1, -1, 1 };
int dy[4] = { 1, 0, 0, 0 };

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	vector <int> nums();

	int t;
	cin >> t;
	for (int test = 1; test <= t; test++) {
		int ans = -1;
		int r, c, n;
		cin >> r >> c >> n;
		int N = r * c;

		for (int i = 0; i < (1 << N); i++) {
			int cur = 0;
			memset(m, 0, sizeof(m));
			
			int cnt = 0;
			for (int k = 0; k < N; k++)
				if ((1 << k) & i)
					m[k / c][k % c] = 1, cnt++;

			if (cnt != n)
				continue;

			for (int k = 0; k < r; k++)
				for (int j = 0; j < c; j++)
					if (m[k][j]) {
						int newx, newy;
						for (int l = 0; l < 2; l++) {
							newx = k + dx[l];
							newy = j + dy[l];
							if (m[newx][newy])
								cur++;
						}
					}

			if (ans == -1 || cur < ans)
				ans = cur;
		}

		cout << "Case #" << test << ": " << ans << endl;
	}

	return 0;
}