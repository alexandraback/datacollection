#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstdlib>
#include <cmath>
using namespace std;

struct node {
	int data, id;
};

typedef long long LL;

node a[1005];
int n, m;

LL ok(LL ti) {
	LL total = n;
	for (int i = 0; i < n; ++i)
		total += ti / a[i].data;
	return total;
}

int main() {
	int T, cases = 0;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &a[i].data);
			a[i].id = i + 1;
		}
		printf("Case #%d: ", ++cases);
		if (m <= n) {
			printf("%d\n", m);
			continue;
		}
		LL p = 0, q = LL(m) * LL(100010);
		LL mid;
		while (p < q) {
			mid = (p + q) >> 1;
			bool prev = (ok(mid) >= m);
			bool cur = (ok(mid + 1) >= m);
			if (!prev && cur) break; 
			else if (prev) q = mid;
			else p = mid + 1;
		}
		++mid;
		LL tot = ok(mid) - m + 1;
		for (int i = n - 1; i >= 0; i--) {
			if (mid % a[i].data == 0) --tot;
			if (tot == 0) {
				printf("%d\n", a[i].id);
				break;
			}
		}
	}
	return 0;
}

