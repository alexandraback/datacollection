#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long LL;
int n;
int inp[1000010];
LL count(LL t) {
	if (t<0) return 0;
	LL ans = 0;
	for (int i=0; i<n; i++) {
		ans += t / inp[i] + 1;
	}
	return ans;
}
int main() {
	int cas, x;
	scanf("%d", &cas);
	for (int ii=0 ;ii<cas; ii++) {
		scanf("%d%d", &n, &x);
		for (int i=0; i<n; i++) scanf("%d", &inp[i]);
		LL L = 0, R = 100000000000000000ll, M;
		while (L+1 < R) {
			M = (L+R-1)/2;
			if (count(M) < x) L = M+1;
			else R = M+1;
		}
		LL c = count(L-1);
		int op;
		for (int i=0; i<n; i++) {
			if (L%inp[i] == 0) {
				c++;
				if (c == x) {op = i; break;}
			}
		}
		printf("Case #%d: %d\n", ii+1, op+1);
	}
	return 0;
}