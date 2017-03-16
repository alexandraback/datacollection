/* Author: coldcutter
 * Problem: A. Magic Trick
 * Tags:
 */
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <iostream>
using namespace std;

int r1, r2, a1[5][5], a2[5][5], cnt[20];

int main() {
	int test;
	scanf("%d", &test);
	for (int kase = 1; kase <= test; ++kase) {
		scanf("%d", &r1);
		for (int i = 1; i <= 4; ++i) {
			for (int j = 1; j <= 4; ++j) {
				scanf("%d", &a1[i][j]);
			}
		}
		scanf("%d", &r2);
		for (int i = 1; i <= 4; ++i) {
			for (int j = 1; j <= 4; ++j) {
				scanf("%d", &a2[i][j]);
			}
		}
		memset(cnt, 0, sizeof(cnt));
		for (int j = 1; j <= 4; ++j) {
			++cnt[a1[r1][j]];
			++cnt[a2[r2][j]];
		}
		int count = 0, ans;
		for (int i = 1; i <= 16; ++i) {
			if (cnt[i] == 2) {
				++count;
				ans = i;
			}
		}
		printf("Case #%d: ", kase);
		if (count == 0) {
			puts("Volunteer cheated!");
		} else if (count == 1) {
			printf("%d\n", ans);
		} else {
			puts("Bad magician!");
		}
	}
	return 0;
}

