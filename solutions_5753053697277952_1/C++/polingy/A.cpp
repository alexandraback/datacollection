#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cmath>

#include <iostream>
#include <iomanip>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <utility>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int main()
{
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		set< pair<int, char>, greater< pair<int, char> > > P;
		int N, total = 0;
		cin >> N;
		for (int i = 0; i < N; ++i) {
			int x;
			cin >> x;
			total += x;
			P.insert({x, 'A' + i});
		}

		printf("Case #%d: ", tc);

		while(!P.empty()) {
			assert(P.size() > 1);
			auto fe = *P.begin();
			auto it = P.begin();
			++it;
			auto se = *(it);

			int c1 = fe.first, c2 = se.first;
			if ((2 * (c1 - 1)) > (total - 2)) {
				if ((2 * c2) > (total - 2)) {
					printf("%c ", fe.second);
					P.erase(fe);
					if(fe.first > 1)
						P.insert({fe.first - 1, fe.second});
					total--;
				} else {
					printf("%c%c ", fe.second, fe.second);
					P.erase(fe);
					if (fe.first > 2)
						P.insert({fe.first - 2, fe.second});
					total -= 2;
				}
			} else {
				if (P.size() == 3) {
					++it;
					auto te = *it;
					int c3 = te.first;
					if (2 * c3 > total - 2) {
						printf("%c ", fe.second);
						P.erase(fe);
						if (fe.first > 1)
							P.insert({fe.first - 1, fe.second});
						total--;
					}
					else {
						printf("%c%c ", fe.second, se.second);
						P.erase(fe);
						P.erase(se);

						if (fe.first > 1)
							P.insert({fe.first - 1, fe.second});
						if (se.first > 1)
							P.insert({se.first - 1, se.second});
						total -= 2;
					}
				} else {
					printf("%c%c ", fe.second, se.second);
					P.erase(fe);
					P.erase(se);

					if (fe.first > 1)
						P.insert({fe.first - 1, fe.second});
					if (se.first > 1)
						P.insert({se.first - 1, se.second});
					total -= 2;
				}
			}
		}

		printf("\n");
	}
}
