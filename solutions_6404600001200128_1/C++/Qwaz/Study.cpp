#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	freopen("A.out", "w", stdout);

	int numCase, nowCase;
	scanf("%d", &numCase);
	for (nowCase = 1; nowCase <= numCase; nowCase++) {
		int n;
		scanf("%d", &n);

		int i, data[1020];
		for (i = 0; i < n; i++) {
			scanf("%d", &data[i]);
		}

		int ans1 = 0, ans2 = 0, minRate = 0;
		for (i = 1; i < n; i++) {
			if (data[i] < data[i-1]) {
				ans1 += data[i-1]-data[i];
				minRate = max(minRate, data[i-1]-data[i]);
			}
		}

		for (i = 0; i < n-1; i++) {
			ans2 += min(data[i], minRate);
		}

		printf("Case #%d: %d %d\n", nowCase, ans1, ans2);
	}

	return 0;
}