#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N, TC;
ll M, B[1005];
pair<long long, int> A[1005];
int main () {
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
	scanf("%d", &TC);
	for (int t = 1; t <= TC; ++t) {
		scanf("%d%lld", &N, &M);
		for (int i = 0; i < N; ++i) scanf("%I64d", &B[i]);
		ll s = 0, e = M*100000ll, m, pos;
		while (m = (s+e)/2, e-s>1) {
			pos = 0;
			for (int i = 0; i < N; ++i) {
				pos += m/B[i];
				if (m%B[i] > 0) ++pos;
			}
			//printf("%I64d %I64d\n", m, pos);
			if (pos >= M) e = m;
			else s = m;
		}
		pos = 0;
		for (int i = 0; i < N; ++i) {
			A[i] = make_pair(s%B[i], i);
			pos += s/B[i];
			if (s%B[i] > 0) {
				++pos;
				A[i].first += B[i];
			}
		}
		sort(A, A+N);
		//printf("%d\n", (int) pos);
		//printf("-- s = %d\n", (int) s);
		
		//printf("m-pos = %d\n", (int) M-pos);
		printf("Case #%d: %d\n", t, A[M-pos-1].second+1);
		
	}
}
