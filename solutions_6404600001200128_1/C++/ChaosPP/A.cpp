#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int m[10002];

int main()
{
	int T;
	scanf("%d", &T);

	for (int w = 0; w < T; w++) {
		int N;
		scanf("%d", &N);

		for (int i = 0; i < N; i++) {
			scanf("%d", &m[i]);
		}

		printf("Case #%d: ", w + 1);
		int ans_1 = 0;
		for (int i = 1; i < N; i++) {
			if (m[i] < m[i - 1])
				ans_1 += (m[i - 1] - m[i]);
		}
		printf("%d ", ans_1);

		int ans_2 = 0;
		int rate = 0;
		for (int i = 1; i < N; i++) {
			if (m[i] < m[i - 1]) {
				if (rate < m[i - 1] - m[i])
					rate = m[i - 1] - m[i];
			}
		}
		for (int i = 0; i < N-1; i++) {
			ans_2 += (m[i] >= rate ? rate : m[i]);
		}
		printf("%d\n", ans_2);

	}



	return 0;
}