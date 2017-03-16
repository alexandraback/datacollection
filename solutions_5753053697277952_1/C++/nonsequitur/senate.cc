#include <bits/stdc++.h>

#define ii pair<int, int>
#define fi first
#define se second

using namespace std;

int main() {
	int T;
	scanf("%d", &T);

	for (int t = 1; t <= T; t++) {
		int n;
		scanf("%d", &n);

		printf("Case #%d: ", t);

		int total = 0;

		set<ii> s;
		for (int i = 0; i < n; i++) {
			int c;
			scanf("%d", &c);
			total += c;
			s.emplace(-c, i);
		}

		while (total) {
			auto top1 = *s.begin();
			auto top2 = *(++s.begin());

			if (-top1.fi == 1 && total != 2) {
				s.erase(top1);
				s.emplace(top1.fi + 1, top1.se);

				total -= 1;

				printf("%c ", 'A' + top1.se);
			} else if (-top2.fi > (total - 2) / 2) {
				s.erase(top1);
				s.erase(top2);
				s.emplace(top1.fi + 1, top1.se);
				s.emplace(top2.fi + 1, top2.se);

				total -= 2;

				printf("%c%c ", 'A' + top1.se, 'A' + top2.se);
			} else {
				s.erase(top1);
				s.emplace(top1.fi + 2, top1.se);

				total -= 2;

				printf("%c%c ", 'A' + top1.se, 'A' + top1.se);
			}
		}

		printf("\n");
	}

	return 0;
}