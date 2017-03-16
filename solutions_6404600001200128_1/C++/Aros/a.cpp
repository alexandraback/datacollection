#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1000+5;
int T, N, m[MAXN];
int main() {
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++) {
		scanf("%d", &N);
		int ans[2] = {}, maxi = 0;
		for (int i = 1; i <= N; i++) {
			scanf("%d", &m[i]);
			if (i == 1)
				continue;
			int x = m[i]-m[i-1];
			if (x < 0) {
				ans[0] += -x;
				maxi = max(maxi, -x);
			}
		}
		for (int i = 1; i < N; i++) {
			ans[1] += min(m[i], maxi);
		}
		printf("Case #%d: %d %d\n", cas, ans[0], ans[1]);
	}
	return 0;
}