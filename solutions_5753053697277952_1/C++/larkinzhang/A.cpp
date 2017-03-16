#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <functional>
#include <algorithm>
using namespace std;

int T, N;
int P[30];

int main() {
	scanf("%d", &T);
	for (int test = 1; test <= T; test++) {
		printf("Case #%d: ", test);

		int total = 0;
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			scanf("%d", P + i);
			total += P[i];
		}

		int p1, p2;
		while (1) {
			p1 = 0; p2 = -1;
			for (int i = 1; i < N; i++) {
				if (P[i] > P[p1]) p1 = i, p2 = -1;
				else if (P[i] == P[p1]) p2 = i;
			}

			if (P[p1] == 0) break;

			putchar('A' + p1); P[p1]--; total--;
			
			if (p2 != -1 && P[p2] > total / 2) {
				putchar('A' + p2);
				P[p2]--;
				total--;
			}

			putchar(' ');
		}

		fseek(stdout, -1, SEEK_CUR);
		puts("");
	}
	return 0;
}
