#include <stdio.h>
#include <algorithm>
using namespace std;
int n;
int inp[1010];

int main() {
	int cas;
	scanf("%d", &cas);
	for (int ii=0; ii<cas; ii++) {
		scanf("%d", &n);
		for (int i=0; i<n; i++) scanf("%d", &inp[i]);
		int a1 = 0, a2 = 0;
		int s = 0;
		for (int i=0; i<n-1; i++) {
			s = max(s, inp[i] - inp[i+1]);
			a1 += max(0, inp[i] - inp[i+1]);
		}
		for (int i=0; i<n-1; i++) {
			a2 += min(s, inp[i]);
		}
		printf("Case #%d: %d %d\n", ii+1, a1, a2);
	}
	return 0;
}