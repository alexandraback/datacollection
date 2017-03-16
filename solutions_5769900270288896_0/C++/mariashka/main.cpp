#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int t, r, c, n, ans;

bool m[1010][1010];

int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> r >> c >> n;
		int ans = 0;
		if (2*n > r * c) {
			ans = 2 * c * r - r - c;

			int f = r * c - n;
			for (int a = 0; a <= r + 1; a++) {
				for (int b = 0; b <= c + 1; b++) {
					if (a == 0 || b == 0 || a == r + 1 || b == c + 1)
						m[a][b] = false;
					else
						m[a][b] = true;
				}
			}
			
			for (int j = 0; j < f; j++) {

				int idxA = 0, idxB = 0, res = 0;
				for (int a = 1; a <= r; a++) {
					for (int b = 1; b <= c; b++)
						if (m[a][b]) {
						int curr = 0;
						if (m[a][b - 1])
							curr++;
						if (m[a][b + 1])
							curr++;
						if (m[a - 1][b])
							curr++;
						if (m[a + 1][b])
							curr++;

						if (curr > res) {
							res = curr;
							idxA = a;
							idxB = b;
						}
					}
				}
				m[idxA][idxB] = false;
				ans -= res;
			}
		}
		cout << "Case #" << i + 1 << ": " << ans << endl;
	}
	return 0;
}
