#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <set>
#include <map>
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
// head
PII a[35];

int main() {
	freopen("out.txt", "w", stdout);
	int t, cas = 1, n;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		int sum = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i].fi);
			sum += a[i].fi;
			a[i].fi = -a[i].fi;
			a[i].se = i;
		}
		printf("Case #%d:", cas++);
		sort(a, a + n);
		if (sum & 1) printf(" %c", a[0].se + 'A'), a[0].fi++;
		sort(a, a + n);
		while (a[0].fi) {
			printf(" %c%c", a[0].se + 'A', a[1].se + 'A');
			a[0].fi++, a[1].fi++;
			sort(a, a + n);
		}
		puts("");
	}
	return 0;
}
