#include <stdio.h>
#include <queue>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <memory.h>
using namespace std;

int n, x, s;
int a[100];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int k = 1; k <= n; k++) {
		scanf("%d", &x);

		priority_queue<pair<int, int> > q;

		s = 0;
		for (int i = 1; i <= x; i++) {
			scanf("%d", &a[i]);
			s += a[i];

			q.push(make_pair(a[i], i));
		}

		printf("Case #%d: ", k);

		if (s % 2) {
			pair<int, int> t1 = q.top(); q.pop();
			printf("%c ", t1.second + 64);
			if (t1.first > 1) {
				q.push(make_pair(t1.first - 1, t1.second));
			}
		}

		for (; q.size();) {
			pair<int, int> t1 = q.top(); q.pop();
			if (q.top().first + 1 < t1.first && t1.first >= 2) {
				printf("%c%c ", t1.second + 64, t1.second + 64);
				if (t1.first > 2) {
					q.push(make_pair(t1.first - 2, t1.second));
				}
			}
			else {
				pair<int, int> t2 = q.top(); q.pop();
				printf("%c%c ", t1.second + 64, t2.second + 64);
				if (t1.first > 1) {
					q.push(make_pair(t1.first - 1, t1.second));
				}
				if (t2.first > 1) {
					q.push(make_pair(t2.first - 1, t2.second));
				}
			}
		}

		printf("\n");
	}

	return 0;
}