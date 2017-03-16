#include <cstdio>
#include <cstring>
#include <iostream>
#define MAX 1005
#define INF 1000000000000000LL

using namespace std;

typedef long long LL;
typedef pair<LL, int> li;

LL B[MAX];
int b;

LL bs(LL lb, LL ub, LL n) {
	if (lb == ub)
		return lb;
	LL mid = (lb + ub) / 2LL;
	LL p = 0;
	for (int i = 0; i < b; i++)
		p += mid / B[i] + 1;
	if (p >= n)
		return bs(lb, mid, n);
	return bs(mid + 1, ub, n);
}

int main() {
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
	int c, cc, i, n;
	scanf("%d", &c);
	for (cc = 0; cc < c; cc++) {
		scanf("%d %d", &b, &n);
		for (i = 0; i < b; i++)
			scanf("%I64d", &B[i]);
		LL t = bs(0, INF, LL(n));
		int d = 0;
		for (i = 0; i < b; i++)
			d += int((t + B[i] - 1) / B[i]);
		int r = n - d - 1;
		int a = MAX;
		for (i = 0; i < b; i++) {
			if (t % B[i] == 0) {
				if (r == 0) {
					a = i;
					break;
				}
				r--;
			}
		}
		printf("Case #%d: %d\n", cc + 1, a + 1);
	}
	return 0;
}

