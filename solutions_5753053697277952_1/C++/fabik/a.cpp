#include <cstdio>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

int main()
{
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		printf("Case #%d:", t);
		int N;
		scanf("%d", &N);
		priority_queue<pair<int, int> > q;
		for (int i = 0; i < N; i++) {
			int P;
			scanf("%d", &P);
			q.push(make_pair(P, i));
		}
		while (!q.empty()) {
			int P = q.top().first;
			int party = q.top().second;
			q.pop();

			printf(" %c", 'A' + party);

			if (q.size() == 1) {
				int P2 = q.top().first;
				int party2 = q.top().second;
				q.pop();

				printf("%c", 'A' + party2);

				P2--;
				if (P2 > 0) {
					q.push(make_pair(P2, party2));
				}
			}

			P--;
			if (P > 0) {
				q.push(make_pair(P, party));
			}
		}
		printf("\n");
	}
	return 0;
}
