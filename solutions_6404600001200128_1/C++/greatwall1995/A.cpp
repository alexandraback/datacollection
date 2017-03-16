#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>
using namespace std;

const int N = 11111;

int n;
int a[N];

int main() {
	freopen("A_.in", "r", stdin);
	freopen("A_.out", "w", stdout);
	int TT;
	scanf("%d", &TT);
	for (int T = 1; T <= TT; ++T) {
		printf("Case #%d: ", T);
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", a + i);
		}
		int ans1, ans2;
		ans1 = ans2 = 0;
		int mn = 0;
		for (int i = 1; i <= n - 1; ++i) {
			if (a[i + 1] < a[i]) {
				ans1 += a[i] - a[i + 1];
				mn = max(mn, a[i] - a[i + 1]);
			}
		}
		for (int i = 1; i <= n - 1; ++i) {
			if (a[i] > mn) ans2 += mn;
			else ans2 += a[i];
		}
		printf("%d %d\n", ans1, ans2);
	}
	return 0;
}
