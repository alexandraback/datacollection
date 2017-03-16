#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int maxn = 1111;
int a[maxn];

int main() {

	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);

	int T, ca = 0;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		int y = 0, z = 0;
		for (int i = 0; i + 1 < n; ++i) {
			if (a[i] > a[i + 1]) {
				y += a[i] - a[i + 1];
			}
		}
		int x = 0;
		for (int i = 0; i + 1 < n; ++i) {
			if (a[i] > a[i + 1]) {
				x = max(x, a[i] - a[i + 1]);
			}
		}
		for (int i = 0; i + 1 < n; ++i) {
			z += min(x, a[i]);
		}
		printf("Case #%d: %d %d\n", ++ca, y, z);
	}
	return 0;
}
