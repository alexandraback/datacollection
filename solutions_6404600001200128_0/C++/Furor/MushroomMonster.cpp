#include <cstdio>
#include <cstring>
#include <iostream>
#define MAX 10005

using namespace std;

int M[MAX];

int main() {
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
	int a, b, c, cc, d, i, n;
	scanf("%d", &c);
	for (cc = 0; cc < c; cc++) {
		scanf("%d", &n);
		a = b = d = 0;
		for (i = 0; i < n; i++)
			scanf("%d", &M[i]);
		for (i = 1; i < n; i++) {
			if (M[i] < M[i - 1])
				a += M[i - 1] - M[i];
			d = max(d, M[i - 1] - M[i]);
		}
		for (i = 1; i < n; i++)
			b += min(d, M[i - 1]);
		printf("Case #%d: %d %d\n", cc + 1, a, b);
	}
	return 0;
}
