#include <cstdio>
#include <algorithm>
using namespace std;

int n, m[1000];

int main() {
	freopen("r1a\\A-small-attempt0.in", "r", stdin);
	freopen("r1a\\A-small.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int N=1; N<=T; ++N) {
		scanf("%d", &n);
		for (int i=0; i<n; ++i)
			scanf("%d", m+i);
		int ans1 = 0, ans2 = 0;
		int gap = 0;
		for (int i=0; i+1<n; ++i) {
			if (m[i] < m[i+1])
				continue;
			ans1 += m[i] - m[i+1];
			gap = max(gap, m[i]-m[i+1]);
		}
		for (int i=0; i+1<n; ++i)
			ans2 += min(m[i], gap);
		printf("Case #%d: ", N);
		printf("%d %d\n", ans1, ans2);
	}
}