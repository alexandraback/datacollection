#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>

using namespace std;
const int maxN = 1000009;
typedef pair<int, char> para;

int t, n, k;
set<para, greater<para> > kolej;

int main() {
	scanf("%d",&t);
	for (int i = 1; i <= t; i++) {
		scanf("%d", &n);
		int suma = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d",&k);
			suma += k;
			kolej.insert(para(k, i+65));
		}
		printf("CASE #%d: ",i);
		if (suma % 2 == 1) {
			para u = *kolej.begin();
			kolej.erase(kolej.begin());
			printf("%c ", u.second);
			kolej.insert(para(u.first - 1, u.second));
		}
		for (int i = 0; i < suma/2; i++) {
			para u = *kolej.begin();
			kolej.erase(kolej.begin());
			para x = *kolej.begin();
			kolej.erase(kolej.begin());
			printf("%c%c ", u.second, x.second);
			kolej.insert(para(u.first - 1, u.second));
			kolej.insert(para(x.first - 1, x.second));
		}
		printf("\n");
	}
	return 0;
}
