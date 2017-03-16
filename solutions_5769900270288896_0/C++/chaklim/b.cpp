#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> v;
int t, r, c, n, tx, ty, minimum, tmin;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
// int visited[16][16][4];

int main() {
	cin >> t;
	for (int C = 1; C <= t; C++) {
		printf("Case #%d: ", C);

		v.clear();
		cin >> r >> c >> n;
		// printf("%d %d\n", n, r * c);
		for (int i = 0; i < r * c; i++) {
			if (i < n) {
				v.push_back(1);
			}
			else {
				v.push_back(0);
			}
		}
		sort(v.begin(), v.end());

		minimum = 21474364;
		// memset(visited, 0, sizeof visited);
		do {
			// for (int i = 0; i < r; i++) {
			// 	for (int j = 0; j < c; j++) {
			// 		printf("%d ", v[i*c+j]);
			// 	}
			// 	puts("");
			// }

			tmin = 0;
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					for (int k = 0; k < 4; k++) {
						tx = j + dx[k];
						ty = i + dy[k];

						if (tx >= 0 && ty >= 0 && tx < c && ty < r) {
							if (v[i*c+j] == 1 && v[ty*c + tx] == 1) {
								tmin++;

								// printf("(%d,%d): %d\n", tx, ty, v[ty*c+tx]);
							}
						}
					}
				}
			}

			tmin /= 2;
			// printf("%d\n\n", tmin);
			minimum = min(minimum, tmin);
		} while (next_permutation(v.begin(), v.end()));

		printf("%d\n", minimum);
	}
	return 0;
}
