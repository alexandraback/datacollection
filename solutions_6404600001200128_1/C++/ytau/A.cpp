#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int T, N;
	int m[1005];
	scanf("%d", &T);
	for (int tc = 1; tc <= T; ++tc) {
		scanf("%d", &N);
		for (int i = 0; i < N; ++i) {
			scanf("%d", &m[i]);
		}
		int a1 = 0;
		for (int i = 0; i < N - 1; ++i) {
			if (m[i + 1] < m[i]) {
				a1 += m[i] - m[i + 1];
			}
		}
		int ma = 0;
		for (int i = 0; i < N - 1; ++i) {
			ma = max(ma, m[i] - m[i + 1]);
		}
		int a2 = 0;
		for (int i = 0; i < N - 1; ++i) {
			a2 += min(ma, m[i]);
		}
		printf("Case #%d: %d %d\n", tc, a1, a2);
	}
	return 0;
}