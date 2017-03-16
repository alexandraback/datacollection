#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

const int N = 55;

int n, tot;
int a[N];
priority_queue<pair<int, int> > que;

int main() {
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
	int TT;
	cin >> TT;
	for (int T = 1; T <= TT; ++T) {
		fprintf(stderr, "Now is solving %d\n", T);
		printf("Case #%d:", T);
		scanf("%d", &n);
		tot = 0;
		while (!que.empty()) que.pop();
		for (int i = 0; i < n; ++i) {
			scanf("%d", a + i);
			tot += a[i];
			que.push(pair<int, int>(a[i], i));
		}
		while (!que.empty()) {
			int a = que.top().second;
			int na = que.top().first;
			que.pop();
			int b = que.top().second;
			int nb = que.top().first;
			if (nb * 2 > tot - 1) {
				tot -= 2;
				que.pop();
				printf(" %c%c", a + 'A', b + 'A');
				if (na - 1 != 0) que.push(pair<int, int>(na - 1, a));
				if (nb - 1 != 0) que.push(pair<int, int>(nb - 1, b));
			}
			else {
				--tot;
				printf(" %c", a + 'A');
				if (na - 1 != 0) que.push(pair<int, int>(na - 1, a));
			}
		}
		puts("");
	}
	return 0;
}
