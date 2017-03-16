#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#if !defined(ID)
#define ID(x)
#endif
using namespace std;
void E(){}template<class A,class...B>void E(A _,B...$){ID(cerr<<' '<<_;E($...);)}
#define E($...) E(#$,'=',$,'\n')

int main() {
	int tn;
	scanf("%d", &tn);
	for (int tc = 1; tc <= tn; ++tc) {
		vector<int> result(16);
		iota(all(result), 1);
		for (int q = 0; q < 2; ++q) {
			int row;
			scanf("%d", &row);
			--row;
			for (int i = 0; i < 4; ++i) {
				vector<int> cards(4);
				for (int j = 0; j < 4; ++j) { scanf("%d", &cards[j]); }
				sort(all(cards));
				if (i == row) {
					vector<int> res;
					set_intersection(all(result), all(cards), back_inserter(res));
					result = move(res);
				}
			}
		}
		printf("Case #%d: ", tc);
		if (result.empty()) {
			puts("Volunteer cheated!");
		} else if (result.size() > 1) {
			puts("Bad magician!");
		} else {
			printf("%d\n", result.front());
		}
	}
	ios_base::sync_with_stdio(false);
	return 0;
}
