#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <tuple>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <cstdlib>
#include <stack>
#include <map>

using namespace std;

#define INF 1987654321
#define MAX 10010
#define MOD 1000000007
#define CHK 1023


int main() {

		freopen("A-large.in", "r", stdin);
		freopen("large.out", "w", stdout);

	int TC;
	scanf("%d", &TC);
	for (int tc = 1; tc <= TC; tc++) {
		int alpha[26] = { 0, };
		int n;
		scanf("%d", &n);
		int maxnum = 0, maxidx = 0, total = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &alpha[i]);
			if (alpha[i] > maxnum) {
				maxidx = i; maxnum = alpha[i];
			}
			total += alpha[i];
		}


		printf("Case #%d: ", tc);

		while (total) {
			maxnum = 0;
			for (int i = 0; i < 26; i++) {
				if (alpha[i] > maxnum) {
					maxidx = i; maxnum = alpha[i];
				}
			}
			printf("%c", maxidx + 'A');
			alpha[maxidx]--; total--;
			if (total == 2) {
				printf(" ");
				continue;
			}

			maxnum = 0;
			for (int i = 0; i < 26; i++) {
				if (alpha[i] > maxnum) {
					maxidx = i; maxnum = alpha[i];
				}
			}
			printf("%c ", maxidx + 'A');
			alpha[maxidx]--; total--;
		}
		
		printf("\n");
	}


	return 0;
}