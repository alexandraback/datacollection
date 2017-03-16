#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

#define MAXN 1010
#define INF 2000000000

int n, m[MAXN];

int main() {
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A1.out", "w", stdout);
	//freopen("A-large.in", "r", stdin);

	int ncas, cnt = 0;
	scanf("%d", &ncas);
	while (ncas--) {
		scanf("%d", &n);
		int max_m = -INF;
		for (int i = 0; i < n; ++i)	{
			scanf("%d", m + i);
			max_m = std::max(max_m, m[i]);
		}
    	printf("Case #%d:", ++cnt);
    	int ans = 0;
    	for (int i = 1; i < n; ++i) {
    		if (m[i] < m[i - 1]) {
    			ans += m[i - 1] - m[i];
    		}
    	}
    	printf(" %d", ans);
    	ans = INF;
    	for (int i = 0; i <= max_m; ++i) {
    		int cur = 0;
    		for (int j = 1; j < n; ++j) {
    			if (m[j - 1] - i > m[j]) {
    				cur = -1;
    				break;
    			}
    			else {
    				cur += std::min(m[j - 1], i);
    			}
    		}
    		if (cur != -1 && ans > cur) ans = cur;
    	}
    	printf(" %d\n", ans);
	}
	return 0;
}