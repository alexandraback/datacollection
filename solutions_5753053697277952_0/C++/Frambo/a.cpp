#include <cstdio>
#include <climits>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int,int> PII;

priority_queue<PII> q;

void solve()
{
	static int casenr = 1;
	printf("Case #%d: ", casenr++);

	q = priority_queue<PII>();
	int N; scanf("%d", &N);
	int tot = 0;

	int i = 0;
	while (N--) {
		int x; scanf("%d", &x);
		tot += x;
		q.push(make_pair(x, i++));
	}

	while (q.size() > 0) {
		PII p1 = q.top(); q.pop();
		if (tot == 3) {
			printf(" %c", 'A' + p1.second);
			if (p1.first > 1) {
				q.push(make_pair(p1.first - 1, p1.second));
			}
			tot -= 1;
		} else {
			PII p2 = q.top(); q.pop();
			if (p1.first > p2.first + 1) {
				printf(" %c%c", 'A' + p1.second, 'A' + p1.second);
				if (p1.first > 2) {
					q.push(make_pair(p1.first - 2, p1.second));
				}
				q.push(make_pair(p2.first, p2.second));
			} else {
				printf(" %c%c", 'A' + p1.second, 'A' + p2.second);
				if (p1.first > 1) {
					q.push(make_pair(p1.first - 1, p1.second));
				}
				if (p2.first > 1) {
					q.push(make_pair(p2.first - 1, p2.second));
				}
			}
			tot -= 2;
		}
	}
	puts("");
}

int main() {
	int T; scanf("%d", &T);
	while (T-- > 0) {
		solve();
	}
	return 0;
}
