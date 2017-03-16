#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int, int> pr;
priority_queue<pr > q;
int p[28];
int main() {
	int i, n;
	int tmp;
	int t, cnt = 0;
	int k;
	int sz;
	pr tmp1, tmp2, tmp3;
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &t);
	while (t--) {
		sz = 0;
		scanf("%d", &n);
		printf("Case #%d:", ++cnt);
		for (i = 0; i < n; i++) {
			scanf("%d", &p[i]);
			q.push(make_pair(p[i], i));
			sz+=p[i];
		}
		while (sz) {
			if (q.size() > 2) {
				tmp1 = q.top();
				q.pop();
				tmp2 = q.top();
				q.pop();

				if (tmp1.first > (sz >> 1) + 1) {
					printf(" %c%c", tmp1.second + 65, tmp1.second + 65);
					if (tmp1.first - 2 > 0) q.push(make_pair(tmp1.first - 2, tmp1.second));
					q.push(tmp2);
				}
				else {
					if (tmp1.first - 1 == 0 && tmp2.first - 1 == 0 && q.size() <= 1) {
						printf(" %c", tmp1.second + 65);
						q.push(tmp2);
						sz--;
						continue;
					}
					else {
						printf(" %c%c", tmp1.second + 65, tmp2.second + 65);
						if (tmp1.first - 1 > 0) q.push(make_pair(tmp1.first - 1, tmp1.second));
						if (tmp2.first - 1 > 0) q.push(make_pair(tmp2.first - 1, tmp2.second));
					}
				}
				sz -= 2;
			}
			else {
				tmp1 = q.top();
				q.pop();
				tmp2 = q.top();
				q.pop();
				if (tmp1.first > tmp2.first) {
					i = tmp1.first - tmp2.first;
					while (i) {
						if (i > 2) {
							printf(" %c%c", tmp1.second + 65, tmp1.second + 65);
							tmp1.first -= 2;
							i -= 2;
						}
						else {
							printf(" %c", tmp1.second + 65);
							tmp1.first--;
							i--;
						}
					}
				}
				else {
					i = tmp2.first - tmp1.first;
					while (i) {
						if (i > 2) {
							printf(" %c%c", tmp2.second + 65, tmp2.second + 65);
							tmp2.first -= 2;
							i -= 2;
						}
						else {
							printf(" %c", tmp1.second + 65);
							tmp1.first--;
							i--;
						}
					}
				}
				while (tmp1.first--) {
					tmp2.first--;
					printf(" %c%c", tmp1.second + 65, tmp2.second + 65);
				}

				sz = 0;
			}
		}
		printf("\n");
	}
	return 0;
}