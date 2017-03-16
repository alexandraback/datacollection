#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

bool apartment[17];

int work(int r, int c, int now, int mustrent, int occupied) {
	if (now < r * c - 1) {
		int res1 = 10000000;
		int res2 = 10000000;

		if (mustrent > occupied) {
			apartment[now] = true;
			res1 = work(r, c, now + 1, mustrent, occupied + 1);

			if (now >= c && apartment[now - c]) {
				++res1;
			}
			if (now % c != 0 && apartment[now - 1]) {
				++res1;
			}
		}

		if (mustrent >= occupied) {
			apartment[now] = false;
			res2 = work(r, c, now + 1, mustrent, occupied);
		}

		return min(res1, res2);
	} else {
		int res = 10000000;
		
		if (mustrent == occupied + 1) {
			res = 0;
			if (now >= c && apartment[now - c]) {
				++res;
			}
			if (now % c != 0 && apartment[now - 1]) {
				++res;
			}
		} else if (mustrent == occupied) {
			return 0;
		}

		return res;
	}
}

int main() {
	int T;
	scanf("%d", &T);
	int i, j;

	for (i = 0; i < T; ++i) {
		int R, C, N;

		scanf("%d %d %d", &R, &C, &N);

		memset(apartment, 0x00, sizeof(apartment));

		int res = work(R, C, 0, N, 0);

		printf("Case #%d: %d\n", i + 1, res);
	}
	return 0;
}