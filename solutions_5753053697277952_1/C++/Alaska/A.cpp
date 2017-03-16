#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

priority_queue<pair<int, char>> Q;

void A() {
	freopen("a.out", "w", stdout);
	int t, n, m;
	scanf("%d", &t);
	for (int cas = 1; cas <= t; cas++) {
		scanf("%d", &n);
		int left = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &m);
			if (m > 0)
				Q.push(make_pair(m, 'A' + i));
			left += m;
		}
		char x[3] = { 0 };
		int idx = 0;
		printf("Case #%d:", cas);
		while (!Q.empty()) {
			auto top = Q.top();
			Q.pop();
			if (top.first > 1) {
				--top.first;
				Q.push(top);
			}
			--left;
			x[idx++] = top.second;
			if (idx == 2) {
				printf(" %s", x);
				idx = 0;
			}
			else {
				if (left == 2) {
					x[1] = 0;
					printf(" %s", x);
					idx = 0;
				}
			}
		}
		printf("\n");
	}
}

int main() {
	A();
}