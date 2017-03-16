#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;

int t, n, m[1024], a, b, c, d;

int main() {
	cin >> t;
	for (int C = 1; C <= t; C++) {
		printf("Case #%d: ", C);

		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> m[i];
		}

		a = 0;
		for (int i = 0; i < n - 1; i++) {
			a += max(0, m[i] - m[i+1]);
		}

		c = 0;
		for (int i = 0; i < n - 1; i++) {
			c = max(c, m[i] - m[i+1]);
		}
		b = 0;
		for (int i = 0; i < n - 1; i++) {
			b += min(c, m[i]);
		}

		printf("%d %d\n", a, b);
	}

	return 0;
}
