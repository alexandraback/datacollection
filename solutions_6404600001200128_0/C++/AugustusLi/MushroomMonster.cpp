#include <iostream>
using namespace std;

const int N = 1004;
int a[N];

int main() {
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas ++) {
		int n;
		int y = 0;
		int z = 0;
		int maxSub = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", a+i);
		}

		for (int i = 0; i < n-1; i++) {
			if (a[i] > a[i+1]) {
				int tmp = a[i]-a[i+1];
				y += tmp;
				if (tmp > maxSub) maxSub = tmp;
			}
		}

		for (int i = 0; i < n-1; i++) {
			if (a[i] < maxSub) {
				z += a[i];
			}
			else {
				z += maxSub;
			}
		}

		printf("Case #%d: %d %d\n", cas, y, z);
	}
	return 0;
}