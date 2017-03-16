#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <string.h>
#include <functional>

using namespace std;
typedef pair<int, int> PII;


int main()
{
	int T;
	int N;
	PII S[33];
	char ans[33];
	scanf("%d", &T);
	for (int t = 1;t <= T;t++) {
		priority_queue < PII > pq;
		scanf("%d", &N);
		int sum = 0;
		for (int i = 0;i < N;i++) {
			S[i].second = i;
			scanf("%d", &S[i].first);
			pq.push(S[i]);
			sum += S[i].first;
		}
		cout << "Case #" << t << ": ";
		while (1) {
			if (sum == 0) break;
			sort(&S[0], &S[N], greater < PII >());
			S[0].first -= 1;
			sum--;
			ans[0] = 'A' + S[0].second;
			if (S[1].first * 2 > sum) {
				S[1].first -= 1;
				sum--;
				ans[1] = 'A' + S[1].second;
				printf("%c%c ", ans[0], ans[1]);
			}
			else {
				printf("%c ", ans[0]);
			}
		}
		printf("\n");
	}
	return 0;
}