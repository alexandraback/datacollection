#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	for (int t = 0; t++ < T;) {
		int n, num[26], tt = 0;;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d", num+i);
			tt += num[i];
		}
		printf("Case #%d: ", t);
		while (tt) {
			int mi, mx = 0, tx = 0, yx = 0;
			for (int i = 0; i < n; ++i) if (num[i]>mx) { mx = num[i]; mi = i; tx = 1; } else if (num[i]==mx) ++tx;
			printf("%c", mi + 'A');
			num[mi]--; tt--;
			if (!tt) break;
			mi = mx = tx = 0;
			for (int i = 0; i < n; ++i) { yx += num[i] != 0; if (num[i]>mx) { mx = num[i]; mi = i; tx = 1; } else if (num[i]==mx) ++tx;}
			if (!(tx == 2 && yx == 2)) {
				printf("%c", mi + 'A');
				num[mi]--; tt--;
			}
			printf(" ");
		}
		printf("\n");
		// solution
	}
	return 0;
}
