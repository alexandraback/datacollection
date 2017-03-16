#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <ctime>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cassert>
#include <bitset>

using namespace std;

struct node {
	int x, y;
} a[10000];

int pos[10000];

node del(int i, int j) {
	node tmp;
	tmp.x = a[i].x - a[j].x;
	tmp.y = a[i].y - a[j].y;
	return tmp;
}

long long dot(node a, node b) {
	return (long long)a.x * b.y - (long long)a.y * b.x;
}

bool cmp(int i, int j) {
	return atan2(a[i].y - a[pos[0]].y, a[i].x - a[pos[0]].x) < atan2(a[j].y - a[pos[0]].y, a[j].x - a[pos[0]].x);
}

int main() {
	int cases;
	scanf("%d", &cases);
	for (int o = 0; o < cases; ++o) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d %d", &a[i].x, &a[i].y);
		}
		printf("Case #%d:\n", o + 1);
		if (n == 1) {
			printf("0\n");
			continue;
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				pos[j] = j;
			}
			swap(pos[0], pos[i]);
			sort(pos + 1, pos + n, cmp);
			int ans = n;
			int k = 1 % (n - 1) + 1;
			for (int j = 1; j < n; ++j) {
				while (k != j && dot(del(pos[j], pos[0]), del(pos[k], pos[0])) >= 0) {
					k = k % (n - 1) + 1;
				}
				int s = k - j;
				if (k <= j) s = k + n - j - 1;
				ans = min(ans, n - 1 - s);
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}