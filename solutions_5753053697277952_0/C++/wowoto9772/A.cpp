#include <stdio.h>
#include <queue>

using namespace std;

class ele {
public:
	ele() {}
	ele(int a, int b) { v = a, c = b; }
	int v, c;
	bool operator<(const ele &A)const {
		return c < A.c;
	}
};

int main() {

	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);

	int t;
	scanf("%d", &t);

	int tc = 0;

	while (t--) {

		int n;
		scanf("%d", &n);

		priority_queue <ele> q;
		for (int i = 1; i <= n; i++) {

			int c;
			scanf("%d", &c);

			q.emplace(i + 'A' - 1, c);

		}

		printf("Case #%d:", ++tc);


		while (!q.empty()) {

			if (q.size() == 2) {

				ele f = q.top(); q.pop();
				ele g = q.top(); q.pop();

				while (f.c) {
					f.c--, g.c--;
					printf(" %c%c", f.v, g.v);
				}

			}
			else {

				ele f = q.top(); q.pop();
				
				f.c--;
				printf(" %c", f.v);

				if (f.c)q.emplace(f);

			}
		}

		printf("\n");
		
	}

}