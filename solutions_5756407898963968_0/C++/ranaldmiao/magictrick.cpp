#include <bits/stdc++.h>
using namespace std;
int T, X, a[20];
vector<int> v;
int main () {
	freopen("magictrick.in", "r", stdin);
	freopen("magictrick.out", "w", stdout);
	scanf("%d", &T);
	for (int tc = 1; tc <= T; ++tc) {
		memset(a, 0, sizeof(a));
		scanf("%d", &X);
		for (int i = 1, x; i <= 4; ++i) {
			for (int j = 1; j <= 4; ++j) {
				scanf("%d", &x);
				if (i == X) ++a[x];
			}
		}
		
		scanf("%d", &X);
		for (int i = 1, x; i <= 4; ++i) {
			for (int j = 1; j <= 4; ++j) {
				scanf("%d", &x);
				if (i == X) ++a[x];
			}
		}
		for (int i = 1; i <= 16; ++i) {
			if (a[i] == 2) v.push_back(i);
		}
		printf("Case #%d: ", tc);
		if (v.size() == 0) puts("Volunteer cheated!");
		else if (v.size() == 1) printf("%d\n", v[0]);
		else puts("Bad magician!");
		v.clear();
	}
}
