#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
using namespace std;

int n, r, c, T, ans;
bool a[100001];

int main() {
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
	scanf("%d", &T);
	for (int TT = 1; TT <= T; ++TT) {
		scanf("%d%d%d", &r, &c, &n);
		if (n <= (r * c + 1) / 2) {
			printf("Case #%d: 0\n", TT);
			continue;
		}
		ans = 0;
		int k = 0;
		n -= (r * c + 1) / 2;
		if (r == 1 || c == 1) {
			if (c == 1) swap(r, c);
			if (c % 2 == 1) printf("Case #%d: %d\n", TT, n * 2);
			else printf("Case #%d: %d\n", TT, n * 2 - 1);
			continue;
		}
		if (r % 2 == 1 && c % 2 == 1) k = 3; else k = 2;
		if (n <= k) {
			if (n == 1 && r * c % 2 == 1) {
				printf("Case #%d: %d\n", TT, 3);
				continue;
			}
			printf("Case #%d: %d\n", TT, r * c % 2 == 1 ? n * 2 + 2 : n * 2);
			continue;
		}
		if (r * c % 2 == 1 && n < r + c - 2) {
			printf("Case #%d: %d\n", TT, 2 * 4 + (n - 3) * 3);
			continue;
		}
		if (k == 2) n -= k; else k = 0; 
		ans += k * 2; 
		k = r + c - 2;
		if (r * c % 2 == 0) k -= 2;
		if (n <= k) {
			printf("Case #%d: %d\n", TT, ans + n * 3);
		}
		else printf("Case #%d: %d\n", TT, ans + k * 3 + (n - k) * 4);
	}
	return 0;
}
