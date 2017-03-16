#include <cstdio>
#include <algorithm>

int T, N, m[1010];

int main() {
	scanf("%d", &T);
	for(int tc=1; tc<=T; tc++) {
		scanf("%d", &N);
		for(int i=0; i<N; i++) {
			scanf("%d", &m[i]);
		}
		int ans1 = 0, max2 = 0, pre = m[0];
		for(int i=1; i<N; i++) {
			ans1 += std::max( 0, pre-m[i] );
			max2 = std::max( max2, pre-m[i] );
			pre = m[i];
		}
		int ans2 = 0;
		pre = m[0];
		for(int i=1; i<N; i++) {
			ans2 += std::min( pre, max2 );
			pre = m[i];
		}
		printf("Case #%d: %d %d\n", tc, ans1, ans2);
	}
	return 0;
}