#include <bits/stdc++.h>

const int MAXN = 10001;

int T, n, a[MAXN];
std::priority_queue<std::pair<int, char> > heap;

int main() {
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
	scanf("%d", &T);
	for (int cs = 1; cs <= T; cs++) {
		scanf("%d", &n);
		while (!heap.empty()) heap.pop();
		for (int i = 1; i <= n; i++) {
			scanf("%d", a + i);
			heap.push(std::make_pair(a[i], i + 'A' - 1));
		}
		printf("Case #%d:", cs);
		while (heap.size() > 2) {
			std::pair<int, char> top = heap.top();
			heap.pop();
			printf(" %c", top.second);
			if (top.first > 1) {
				heap.push(std::make_pair(top.first - 1, top.second));
			}
		}
		if (heap.size() == 2) {
			std::pair<int, char> a = heap.top(); heap.pop();
			std::pair<int, char> b = heap.top(); heap.pop();
			for (int i = 1; i <= a.first; i++) {
				printf(" %c%c", a.second, b.second);
			}
		}
		puts("");
	}
	return 0;
}
